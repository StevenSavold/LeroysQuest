#include <iostream>
#include "MovementSystem.h"
#include "Locations/Braids.h"
#include "Locations/FalconKeep.h"
#include "Locations/HeavensPeak.h"
#include "Locations/LeroysTower.h"
#include "Locations/MermaidCove.h"
#include "Locations/RedChasm.h"
#include "Locations/Treasureland.h"
#include "Locations/WishWell.h"

#include "Core.h"

namespace LeroysQuest {

	MovementSystem::MovementSystem()
	{
		LeroysTower*  lt = new LeroysTower();
		Treasureland* tr = new Treasureland();
		HeavensPeak*  hp = new HeavensPeak();
		MermaidCove*  mc = new MermaidCove();
		WishWell*     ww = new WishWell();
		RedChasm*     rc = new RedChasm();
		FalconKeep*   fk = new FalconKeep();
		Braids*       br = new Braids();

		//                 { North,   South,   East,    West    }
		lt->SetTransitions({ tr,      rc,      br,      hp      });
		tr->SetTransitions({ nullptr, lt,      br,      hp      });
		hp->SetTransitions({ mc,      lt,      tr,      rc      });
		mc->SetTransitions({ nullptr, hp,      nullptr, nullptr });
		ww->SetTransitions({ nullptr, nullptr, rc,      nullptr });
		rc->SetTransitions({ hp,      br,      lt,      ww      });
		br->SetTransitions({ lt,      fk,      tr,      rc      });
		fk->SetTransitions({ nullptr, nullptr, br,      nullptr });

		m_Map.push_back(lt);
		m_Map.push_back(tr);
		m_Map.push_back(hp);
		m_Map.push_back(mc);
		m_Map.push_back(ww);
		m_Map.push_back(rc);
		m_Map.push_back(br);
		m_Map.push_back(fk);

		currentLocation = m_Map[0];
		
		std::cout << "Location: " << currentLocation->Name() << '\n';
		LookAtCurrentRoom();
		currentLocation->OnEnter();
	}

	MovementSystem::~MovementSystem()
	{
		for (auto& e : m_Map)
		{
			SAFE_DELETE(e);
		}
	}

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
		std::cout << currentLocation->ConditionalDescription() << '\n';
		currentLocation->PrintAreaTransitions();
	}

	void MovementSystem::LookAtRoomItem(const std::string& itemName) const
	{
		currentLocation->OnItemLook(itemName);
	}

	Optional<Item> MovementSystem::GetItemInCurrentRoom(const std::string& itemName)
	{
		return currentLocation->OnItemGet(itemName);
	}

	void MovementSystem::DropItemInCurrentRoom(Item item)
	{
		currentLocation->OnItemDrop(item);
	}

	bool MovementSystem::UseRemoteItem(Item item) const
	{
		return currentLocation->OnEvent(item);
	}

	void MovementSystem::UseLocalItem(Item item)
	{
		if (!currentLocation->OnEvent(item))
		{
			currentLocation->OnItemDrop(item);
			std::cout << "That seems like a bad idea...\n";
		}
	}

}