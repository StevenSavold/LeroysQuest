#pragma once
#include <string>

namespace LeroysQuest {

	class ActionSystem
	{
		ActionSystem(ActionSystem& copy) = delete;
		ActionSystem(ActionSystem&& move) = delete;
		ActionSystem& operator=(ActionSystem& copy) = delete;
		ActionSystem& operator=(ActionSystem&& move) = delete;

	public:
		static ActionSystem& GetInstance()
		{
			static ActionSystem instance;
			return instance;
		}

		void Look(const std::string& objectString) const ;
		void Go(const std::string& objectString) const ;

	private:
		ActionSystem();
		~ActionSystem();

	};

}