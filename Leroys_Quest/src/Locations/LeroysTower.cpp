#include "LeroysTower.h"

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
			"It is locked behind the towers BIG_DOOR.\n";
	} 

	const char* LeroysTower::ConditionalDescription() const
	{
		return ""; 
	}



	void LeroysTower::OnEnter()
	{}

	void LeroysTower::OnExit()
	{}

	bool LeroysTower::OnEvent(Item item)
	{
		return false;
	}

}