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
		~Item();

		inline const std::string& GetName() const { return m_Name; }

		void Use() const ;

		friend std::ostream& operator<<(std::ostream& stream, const Item& item);
	};

}