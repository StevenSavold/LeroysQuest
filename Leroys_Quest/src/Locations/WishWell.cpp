#include "WishWell.h"
#include <iostream>

//temp
#include "Core.h"
#include "Systems/LanguageSystem.h"

namespace LeroysQuest {

	WishWell::WishWell()
	{
		LanguageSystem& ls = GetInstanceOf(LanguageSystem);

		m_Inventory.push_back(Item("bucket"));
		ls.AddIdentifier("bucket");

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
		return "Alone a top a small hill sits a well made of wood and stone.";
	} 

	const char* WishWell::ConditionalDescription() const
	{
		if (!m_BucketUsed)
		{
			// if the bucket has not been used
			return "A small metal BUCKET sits off on the side of the well.\n"; 
		}
		else
		{
			// if it has been used, you can say nothing? 
			return "";
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
				"You pick up the BUCKET and put it on the dangling rope.  \n"
				"Once the BUCKET is securely fastened to the it, you lower\n"
				"the BUCKET down into the water below. Upon pulling the   \n"
				"BUCKET back out of the water. You find in the now water  \n"
				"filled bucket a pair of SCISSORS. They seem sharp enough \n"
				"to be able to cut through even the thickest woven materials.\n";

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