#include "Item.h"
#include <string>

namespace LeroysQuest {

	Item::Item(const std::string& name) 
		: GameObject(name)
	{}

	Item::~Item()
	{}

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