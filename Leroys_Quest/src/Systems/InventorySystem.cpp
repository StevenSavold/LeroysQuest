#include "InventorySystem.h"
#include <iostream>

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
		std::optional<Item> item = FindItemByString(itemString);
		if (!item)
		{
			std::cout << "You cannot use that, you don't have one in your inventory!\n";
			return;
		}
		item->Use();
	}
	
	void InventorySystem::Get(const std::string& itemString)
	{
		/* 
		 * Going to need an editable reference to the rooms 
		 * inventory to move the item from the room to the 
		 * players inventory.
		 */

	}
	
	void InventorySystem::Drop(const std::string& itemString)
	{
		/*
		 * Going to need an editable reference to the rooms
		 * inventory to move the item from the players 
		 * inventory to the rooms inventory.
		 */

	}

	std::optional<Item> InventorySystem::FindItemByString(const std::string& itemString) const
	{
		for (size_t i = 0; i < m_Inventory.size(); ++i)
		{
			if (m_Inventory[i].GetName() == itemString)
			{
				return std::optional<Item>(m_Inventory[i]);
			}
		}
		/* Item not in inventory */
		return std::optional<Item>(/* No Value */);
	}

}