#include "RedChasm.h"
#include <iostream>

//temp
#include "Core.h"
#include "Systems/LanguageSystem.h"

namespace LeroysQuest {

	RedChasm::RedChasm()
	{
		LanguageSystem& ls = GetInstanceOf(LanguageSystem);

		m_Inventory.push_back(Item("tower-key"));
		ls.AddIdentifier("tower-key");
	}

	RedChasm::~RedChasm()
	{
	}


	const char* RedChasm::Name() const
	{
		return "The Red Chasm";
	}

	const char* RedChasm::Description() const
	{
		return 
			"You walk up to the chasms edge, the heat from the red flames\n"
			"pours into the air around you. If you walk any closer you might\n"
			"just burst into flames yourself.";
	} 

	const char* RedChasm::ConditionalDescription() const
	{
		return ""; 
	}

	const char* RedChasm::TransDiscription() const
	{
		return "A ravine, with dark smoke wisps emanating from it\n";
	}


	void RedChasm::OnEnter()
	{}

	bool RedChasm::OnExit(MovementDirection exitDir)
	{
		return true;
	}

	bool RedChasm::OnEvent(Item item)
	{
		if (item.GetName() == "fireproof-clothes")
		{
			std::cout <<
				"You don the fireproof clothes. Allowing you to enter the \n"
				"chasm at last to retrieve the TOWER-KEY, allowing you to \n"
				"enter Leroy's Tower.\n";
            return true;
		}
		else 
		{
			return false;
		}
	}

}
