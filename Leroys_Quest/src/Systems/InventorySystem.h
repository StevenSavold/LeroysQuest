#pragma once
#include <vector>
#include "Platform/Optional.h"
#include "GameObjects/Item.h"

namespace LeroysQuest {

	class InventorySystem
	{
		/* This might be able to be an unordered map for faster lookup */
		using Inventory = std::vector<Item>;

		InventorySystem(InventorySystem& copy) = delete;
		InventorySystem(InventorySystem&& move) = delete;
		InventorySystem& operator=(InventorySystem& copy) = delete;
		InventorySystem& operator=(InventorySystem&& move) = delete;

		Optional<Item> FindItemByString(const std::string& itemString) const;

	public:
		static InventorySystem& GetInstance()
		{
			static InventorySystem instance;
			return instance;
		}

		void PrintInventory() const ; 
		void Use(const std::string& itemString);
		void Get(const std::string& itemString);
		void Drop(const std::string& itemString);

	private:
		InventorySystem();
		~InventorySystem();

		Inventory m_Inventory;

	};

}
