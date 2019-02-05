#include "FalconKeep.h"
#include <iostream>
//temp
#include "Core.h"
#include "Systems/LanguageSystem.h"

namespace LeroysQuest {

	FalconKeep::FalconKeep()
	{
		LanguageSystem& ls = GetInstanceOf(LanguageSystem);

		m_Inventory.push_back(Item("fireproof-clothes"));
		ls.AddIdentifier("fireproof-clothes");
	}

	FalconKeep::~FalconKeep()
	{
	}


	const char* FalconKeep::Name() const
	{
		return "Falcon Keep";
	}

	const char* FalconKeep::Description() const
	{
		return "You walk out onto a beach of pale yellow sand.  \n"
			   "The tall cliffs above you seem almost as if they\n"
			   "could crumble any second. Inset into these cliffs\n"
			   "is a metal alter. Once used to give gifts to the \n"
			   "those who ruled this forgotten place, Falcon Keep.\n";
	}

	const char* FalconKeep::ConditionalDescription() const
	{
		return "";
	}

	const char* FalconKeep::TransDiscription() const
	{
		return "A long forgotten beach below tall cliffs.\n";
	}


	void FalconKeep::OnEnter()
	{}

	bool FalconKeep::OnExit(MovementDirection exitDir)
	{
		return true;
	}

	bool FalconKeep::OnEvent(Item item)
	{
		if (item.GetName() == "feather")
		{
			std::cout <<
				"You place the feather on the alter, and the alter spins around,\n"
				"revealing a set of FIREPROOF-CLOTHES.\n";

			return true;
		}
		else
		{
			std::cout <<
				"You place the item on the alter... and nothing happens.\n";

			return false;
		}
	}

}