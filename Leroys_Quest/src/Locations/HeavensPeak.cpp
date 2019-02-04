#include "HeavensPeak.h"

namespace LeroysQuest {

	HeavensPeak::HeavensPeak()
	{
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
		return "";
	} 

	const char* HeavensPeak::ConditionalDescription() const
	{
		if (!m_BirdFreed)
		{
			return "Looking up you see an empty birds nest \n"
				"just out of reach...\n";
		}
		else
		{
			return "Looking at the birds nest again, you \n"
				"see the bird happily sleeping.\n";
		}
	}

	const char* HeavensPeak::TransDiscription() const
	{
		return "A range of mountains...\n";
	}


	void HeavensPeak::OnEnter()
	{}

	void HeavensPeak::OnExit()
	{}

	bool HeavensPeak::OnEvent(Item item)
	{
		// when the bird caught in the braids is freed, 
		// it will come here and give the player a key?
		return false;
	}

}