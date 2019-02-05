#include "WishWell.h"
#include <iostream>

//temp
#include "Core.h"
#include "Systems/LanguageSystem.h"

namespace LeroysQuest {

	WishWell::WishWell()
	{
		LanguageSystem& ls = GetInstanceOf(LanguageSystem);

		m_Inventory.push_back(Item("scissors"));
		ls.AddIdentifier("scissors");
	}


	WishWell::~WishWell()
	{
	}


	const char* WishWell::Name() const
	{
		return "Wish Well";
	}

	const char* WishWell::Description() const
	{
		return "Alone a top a small hill sits a well made of wood and stone.\n";
	} 

	const char* WishWell::ConditionalDescription() const
	{
		if (!m_BucketUsed)
		{
			// if the bucket has not been used
			return 
				"When you peer down the well, you see light glinting off of\n"
				"something shiny and metallic in the water below\n"; 
		}
		else
		{
			// if it has been used, you can say nothing? 
			return 
				"Looking down into the well once more you find nothing but water\n";
		}
	}

	const char* WishWell::TransDiscription() const
	{
		return "A small water well...\n";
	}


	void WishWell::OnEnter()
	{}

	bool WishWell::OnExit(MovementDirection exitDir)
	{
		return true;
	}

	bool WishWell::OnEvent(Item item)
	{
		if (item.GetName() == "bucket" && m_BucketUsed == false)
		{
			std::cout <<
				"You take the BUCKET and put it on the dangling rope. Once\n"
				"the BUCKET is securely fastened to the it, you lower it  \n"
				"down into the waters below. Upon pulling it back out of  \n"
				"the water. You find in the now water filled bucket a pair\n"
				"of SCISSORS. They seem sharp enough to be able to cut even\n"
				"the thickest woven materials.\n";

			m_BucketUsed = true;
			return true;
		}
		else 
		{
			std::cout <<
				"You stand by the well listening to the wind blow past and \n"
				"think to yourself that there is something different you   \n"
				"need to do here";
			return false;
		}
	}

}