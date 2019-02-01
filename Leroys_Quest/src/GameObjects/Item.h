#pragma once
#include "GameObjects/GameObject.h"
#include <functional>

namespace LeroysQuest {

	class Item : public GameObject
	{
		//using UsageFn = std::function<void()>;

		//UsageFn m_Usage;

	public:
		Item(const std::string& name);

		Item(const Item& copy);
		Item(Item&& itemToMove);

		Item& operator=(const Item& copy);
		Item& operator=(Item&& move);

		~Item();

		void Use() const ;

		friend std::ostream& operator<<(std::ostream& stream, const Item& item);
	};

}