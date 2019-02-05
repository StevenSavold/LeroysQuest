#include "HeavensPeak.h"
#include "Systems/AchievementSystem.h"
#include "Systems/LanguageSystem.h"
#include "Core.h"
#include <iostream>

namespace LeroysQuest {

	HeavensPeak::HeavensPeak()
	{
		LanguageSystem& ls = GetInstanceOf(LanguageSystem);

		m_Inventory.push_back(Item("feather"));
		ls.AddIdentifier("feather");
	}


	HeavensPeak::~HeavensPeak()
	{
	}


	const char* HeavensPeak::Name() const
	{
		return "Heaven's Peak";
	}

	const char* HeavensPeak::Description() const
	{
		return 
			"The tall mountains tower above the surrounding landscapes.\n"
			"They make passage through the area difficult, but not impossible.\n"
			"The snow topped peaks and treacherous cliff sides leave little room\n"
			"for land dwelling creatures to live here.\n";
	} 

	const char* HeavensPeak::ConditionalDescription() const
	{
		AchievementSystem& as = GetInstanceOf(AchievementSystem);
		static bool gotFeather = false;

		if (!as.SetBirdFree)
		{
			return "Looking up you see an empty birds nest \n"
				"just out of reach...\n";
		}
		else if (as.SetBirdFree && !gotFeather)
		{
			gotFeather = true;
			return 
				"As you climb up Heaven's Peak you hear the familiar calling\n"
				"of the bird you freed from the Braids. It flies over head of\n"
				"you and a single FEATHER drops at your feet. It then lands in\n"
				"its nest on the cliff side and almost seems to smile at you\n"
				"thankfully.\n";
		}
		else
		{
			return "You look up at the nest to find the bird sleeping soundly.\n";
		}
	}

	const char* HeavensPeak::TransDiscription() const
	{
		return "A range of mountains...\n";
	}


	void HeavensPeak::OnEnter()
	{}

	bool HeavensPeak::OnExit(MovementDirection exitDir)
	{
		return true;
	}

	bool HeavensPeak::OnEvent(Item item)
	{
		return false;
	}

}