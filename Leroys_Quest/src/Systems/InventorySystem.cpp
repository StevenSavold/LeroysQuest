#include "InventorySystem.h"
#include <iostream>
#include <iterator>
#include "Core.h"
#include "Systems/MovementSystem.h"

namespace LeroysQuest {

	InventorySystem::InventorySystem()
	{}

	InventorySystem::~InventorySystem()
	{}

	void InventorySystem::PrintInventory() const
	{
		std::cout << "Inventory:\n";
		for (const auto& item : m_Inventory)
			std::cout << "\t" << item << "\n";
 	}

	void InventorySystem::Use(const std::string& itemString)
	{
		auto itemItr = FindItemByString(itemString);
		if (itemItr == m_Inventory.end())
		{
			std::cout << "You cannot use that, you don't have one in your inventory!\n";
			return;
		}
		long idx = std::distance<std::vector<Item>::const_iterator>(m_Inventory.begin(), itemItr);
		m_Inventory[idx].Use();
	}
	
	void InventorySystem::Get(const std::string& itemString)
	{
		/* 
		 * Going to need an editable reference to the rooms 
		 * inventory to move the item from the room to the 
		 * players inventory.
		 */
		MovementSystem&  ms = GetInstanceOf(MovementSystem);

		Optional<Item> item = ms.GetItemInCurrentRoom(itemString);
		if (item)
			m_Inventory.push_back(std::move(*item));
		//else 
			//Do nothing because item doesn't exist
		return;

	}
	
	void InventorySystem::Drop(const std::string& itemString)
	{
		/*
		 * Going to need an editable reference to the rooms
		 * inventory to move the item from the players 
		 * inventory to the rooms inventory.
		 */
		MovementSystem&  ms = GetInstanceOf(MovementSystem);

		auto itemItr = FindItemByString(itemString);
		if (itemItr != m_Inventory.end())
		{
			long idx = std::distance<std::vector<Item>::const_iterator>(m_Inventory.begin(), itemItr);
			Item droppedItem = m_Inventory[idx];
			m_Inventory.erase(itemItr);
			ms.DropItemInCurrentRoom(droppedItem);
		}
		else 
		{
			std::cout << "You can't drop something you don't have!\n";
		}

	}

	std::vector<Item>::const_iterator InventorySystem::FindItemByString(const std::string& itemString) const
	{
		return std::find_if(m_Inventory.begin(), m_Inventory.end(),
			[&](const Item& item) -> bool {
				return item.GetName() == itemString;
			}
		);
	}

}
