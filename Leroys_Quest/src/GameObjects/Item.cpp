#include "Item.h"
#include <string>

namespace LeroysQuest {

	Item::Item(const std::string& name) 
		: GameObject(name)
	{}

	Item::Item(const Item& copy)
		: GameObject(copy)
	{}

	Item::Item(Item&& itemToMove)
		: GameObject(itemToMove)
	{}

	Item::~Item()
	{}

	Item& Item::operator=(const Item& copy)
	{
		this->m_Name = copy.m_Name;
		this->m_Description = copy.m_Description;

		return *this;
	}

	Item& Item::operator=(Item&& move)
	{
		this->m_Name = move.m_Name;
		this->m_Description = move.m_Description;

		move.m_Name.clear();
		move.m_Description.clear();

		return *this;
	}

	void Item::Use() const
	{
		//m_Usage();
	}

	std::ostream& operator<<(std::ostream& stream, const Item& item)
	{
		stream << item.m_Name;
		return stream;
	}

}