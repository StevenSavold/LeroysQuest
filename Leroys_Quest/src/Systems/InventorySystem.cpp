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
		MovementSystem& ms = GetInstanceOf(MovementSystem);

		auto itemItr = FindItemByString(itemString);
		Optional<Item> roomItem = ms.GetItemInCurrentRoom(itemString);

		if ((itemItr != m_Inventory.end()))
		{
			long idx = std::distance<std::vector<Item>::const_iterator>(m_Inventory.begin(), itemItr);
			if (ms.UseRemoteItem(m_Inventory[idx]))
			{
				// if the item was used, remove it
				m_Inventory.erase(itemItr);
			}
			else 
			{ 
				// otherwise keep it and print something like "that item has no use here"
				std::cout << "That seems like a bad idea here...\n";
			}
		}
		else if (roomItem) // if the item specified was not in the players inventory maybe it was within the room
		{
			/* 
			 * NOTE: this is kind of a round about way of doing this.
			 * I am currently removing the item from the rooms inventory, 
			 * to make this check here. Then if it was the proper item I'm 
			 * passing it all the way back into the room for it to handle 
			 * whether it needs to be deleted or put back.
			 */
			ms.UseLocalItem(*roomItem);
		}
		else // if item was not on the player or in the room
		{
			std::cout << "You cannot use what is not available to you!\n";
		}

		return;
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
		if (item) // If the optional item was returned properly
			m_Inventory.push_back(std::move(*item));
		// else
			// Do nothing because item doesn't exist
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
