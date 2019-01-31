#include <iostream>
#include "MovementSystem.h"
#include "Locations/LeroysTower.h"
#include "Locations/Treasureland.h"
#include "Locations/HeavensPeak.h"
#include "Locations/MermaidCove.h"

#undef break

namespace LeroysQuest {

	MovementSystem::MovementSystem()
	{
		LeroysTower  *lt = new LeroysTower();
		Treasureland *tr = new Treasureland();
		HeavensPeak  *hp = new HeavensPeak();
		MermaidCove  *mc = new MermaidCove();

		//                { North,   South,   East,    West    }
		lt->SetTransitions({ tr,      nullptr, nullptr, hp      });
		tr->SetTransitions({ nullptr, lt,      nullptr, hp      });
		hp->SetTransitions({ mc,      lt,      tr,      nullptr });
		mc->SetTransitions({ nullptr, hp,      nullptr, nullptr });


		m_Map.push_back(lt);
		m_Map.push_back(tr);
		m_Map.push_back(hp);
		m_Map.push_back(mc);

		currentLocation = m_Map[0];
		
		std::cout << "Location: " << currentLocation->Name() << '\n';
		LookAtCurrentRoom();
		currentLocation->OnEnter();

	}

	MovementSystem::~MovementSystem()
	{}

	void MovementSystem::Move(MovementCommand command) 
	{
		Location* temp = currentLocation;
		currentLocation = currentLocation->Move(command.GetMovementDirection());
		if (currentLocation == nullptr)
		{
			std::cout << "You feel it would not make sense to move that way.\n";
			currentLocation = temp;
			return;
		}
		temp->OnExit();
		std::cout << "Location: " << currentLocation->Name() << '\n';
		LookAtCurrentRoom();
		currentLocation->OnEnter();
	}

	void MovementSystem::LookAtCurrentRoom() const
	{
		std::cout << currentLocation->Description() << '\n';
		std::cout << currentLocation->ConditionalDescription();
	}

	void MovementSystem::LookAtRoomItem(const std::string& itemName) const
	{
		currentLocation->OnItemLook(itemName);
	}
}