#include "Braids.h"
#include <iostream>

namespace LeroysQuest {

	Braids::Braids()
	{
	}

	Braids::~Braids()
	{
	}


	const char* Braids::Name() const
	{
		return "The Braids";
	}

	const char* Braids::Description() const
	{
		return "You approach an area with many hair like fibers \n"
			   "stretching high into the sky. They are woven together \n"
			   "making them very tough to pull apart and move past. \n";
	} 

	const char* Braids::ConditionalDescription() const
	{
		if (!m_BirdFreed)
		{
			return "Looking up you find a bird trapped in the braids above.\n"
				   "It must have gotten stuck when flying nearby. It seems \n"
				   "you wont be able to move through the area with these braids\n"
				   "in the way. If you found something sharp enough you could \n"
				   "probably cut them down, freeing the bird and allowing passage\n"
				   "though the area once again.\n"; 
		}
		else
		{
			return "The area once covered with thick woven braids now lays near \n"
				   "barren from your ruthless cutting away of the rare local flora.\n";
		}
	}

	const char* Braids::TransDiscription() const
	{
		if (!m_BirdFreed)
		{ 
			return "There appears to be some tall woven structures...\n";
		}
		else 
		{
			return "A barren field, once full of rare plants...\n";
		}
	}


	void Braids::OnEnter()
	{}

	bool Braids::OnExit(MovementDirection exitDir)
	{
		if (m_BirdFreed == false && exitDir == MovementDirection::South)
		{
			std::cout <<
				"The thick braids block your path south. You could probably \n"
				"cut them down to get past if you had something sharp.\n";
			return false;
		}
		return true;
	}

	bool Braids::OnEvent(Item item)
	{
		if (item.GetName() == "scissors")
		{
			std::cout <<
				"You begin to mercilessly cut away at the braids in your path,  \n"
				"stripping the landscape of the tall plants. Upon cutting away  \n"
				"a particularly large piece of the braids, you release the bird \n"
				"trapped above. It gives out a few chirps which you translate to\n"
				"a thank you, as you continue to clear your path. After a few   \n"
				"more minutes of this you finally clear a large enough path to  \n"
				"to travel through, opening the path to the south.\n";

			m_BirdFreed = true;
			return true;
		}
		else 
		{
			std::cout <<
				"You think to yourself, maybe this is not the place to be using that...\n";
			return false;
		}

	}

}