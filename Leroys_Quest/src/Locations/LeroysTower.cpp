#include "LeroysTower.h"
#include "Systems/AchievementSystem.h"
#include "Core.h"
#include <iostream>

namespace LeroysQuest {

	LeroysTower::LeroysTower()
	{
	}


	LeroysTower::~LeroysTower()
	{
	}


	const char* LeroysTower::Name() const
	{
		return "Leroy's Tower";
	}

	const char* LeroysTower::Description() const
	{
		return "You stand before a tall tower. It looks old and weathered,\n"
			"but based on the rumors there is a large sum of treasure inside.\n"
			"It is locked behind the towers door. The key to which is said to\n"
			"have been lost in the Red Chasm. A place no mortal has ever returned\n"
			"from...";
	} 

	const char* LeroysTower::ConditionalDescription() const
	{
		return ""; 
	}

	const char* LeroysTower::TransDiscription() const
	{
		return "Leroy's Tower...\n";
	}


	void LeroysTower::OnEnter()
	{}

	bool LeroysTower::OnExit(MovementDirection exitDir)
	{
		return true;
	}

	bool LeroysTower::OnEvent(Item item)
	{
		AchievementSystem& as = GetInstanceOf(AchievementSystem);

		if (item.GetName() == "tower-key")
		{
			std::cout <<
				"You unlock the door with the tower key; the tower door swings open\n"
				"and reveals a mirror behind it. You are confused at first by the lack\n"
				"of treasure in the tower. As you stand there looking at your own \n"
				"reflection, it dawns on you that you were the treasure the whole time.\n"
				"You traveled this world, helping those in need. The bird stuck in the \n"
				"Braids... the mermaid having a bad hair day... The forest spirit at the\n"
				"heart of treasureland. You have made all of them happy once more. You \n"
				"have done great work here, and you realize you can do great work anywhere.\n"
				"If you just put your mind to it, you can solve any problem presented to you.\n";

			as.Completed = true;

			return true;
		}

		return false;
	}

}