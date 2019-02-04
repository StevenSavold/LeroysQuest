#include "RedChasm.h"

namespace LeroysQuest {

	RedChasm::RedChasm()
	{
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
		return "";
	} 

	const char* RedChasm::ConditionalDescription() const
	{
		return ""; 
	}



	void RedChasm::OnEnter()
	{}

	void RedChasm::OnExit()
	{}

	bool RedChasm::OnEvent(Item item)
	{
		return false;
	}

}