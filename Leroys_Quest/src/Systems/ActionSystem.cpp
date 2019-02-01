#include "ActionSystem.h"
#include <iostream>
#include "Core.h"
#include "Systems/MovementSystem.h"

namespace LeroysQuest {

	ActionSystem::ActionSystem()
	{}

	ActionSystem::~ActionSystem()
	{}

	void ActionSystem::Look(const std::string& objectString) const
	{
		const MovementSystem& ms = GetInstanceOf(MovementSystem);
		if (objectString.empty())
			ms.LookAtCurrentRoom();
		else
			ms.LookAtRoomItem(objectString);
	}

	void ActionSystem::Go(const std::string& objectString) const
	{
		std::cout << "Go! " << objectString << '\n';
	}

}