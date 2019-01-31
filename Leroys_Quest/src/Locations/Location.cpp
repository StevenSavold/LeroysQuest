#include "Location.h"
#include <algorithm>
#include <iterator>
#include <iostream>

namespace LeroysQuest {

	Location::Location()
	{}

	Location::~Location()
	{}

	const char* Location::Name() const
	{
		return "Nowhere important...";
	}

	const char* Location::Description() const
	{
		return "As the fog sets in it becomes harder to see... \n"
			"Maybe if you keep going it will clear.\n";
	}

	const char* Location::ConditionalDescription() const
	{
		return "";
	}



	void Location::OnEnter()
	{ /* Leave empty so if the subclass doesnt implement it will do nothing */ }

	void Location::OnExit()
	{ /* Leave empty so if the subclass doesnt implement it will do nothing */ }

	void Location::OnEvent()
	{ /* Leave empty so if the subclass doesnt implement it will do nothing */ }



	Location* Location::Move(MovementDirection direction) const
	{
		return m_Transitions[static_cast<size_t>(direction) - 1];
	}



	Item Location::OnItemGet(const std::string& itemName)
	{
		auto it = std::find_if(m_Inventory.begin(), m_Inventory.end(), 
			[&](const Item& item) -> bool {
				return item.GetName() == itemName;
			}
		);

		auto idx = std::distance(m_Inventory.begin(), it);
		Item out = m_Inventory.at(idx);
		m_Inventory.erase(it);

		return out;
	}

	void Location::OnItemDrop(Item item)
	{
		m_Inventory.push_back(item);
	}

	void Location::OnItemLook(const std::string& itemName) const
	{
		auto it = std::find_if(m_Inventory.begin(), m_Inventory.end(),
			[&](const Item& item) -> bool {
				return item.GetName() == itemName;
			}
		);

		auto idx = std::distance(m_Inventory.begin(), it);

		const Item& item = m_Inventory[idx];

		std::cout << item.GetDiscription();
	}

	void Location::SetTransitions(std::array<Location*, 4> trans)
	{
		m_Transitions = trans;
	}

}
