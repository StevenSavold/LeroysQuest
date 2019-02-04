#include "WishWell.h"

//temp
#include "Core.h"
#include "Systems/LanguageSystem.h"

namespace LeroysQuest {

	WishWell::WishWell()
	{
		LanguageSystem& ls = GetInstanceOf(LanguageSystem);

		m_Inventory.push_back(Item("bucket"));
		ls.AddIdentifier("bucket");
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
		// if the bucket has not been used
		return "A small metal BUCKET sits off on the side of the well.\n"; 

		// if it has been used, you can say nothing? 
	}

	const char* WishWell::TransDiscription() const
	{
		return "A small water well...\n";
	}


	void WishWell::OnEnter()
	{}

	void WishWell::OnExit()
	{}

	bool WishWell::OnEvent(Item item)
	{
		// on the use of the bucket some text will print about 
		// putting the bucket onto the rope and casting it into the 
		// well. when you pull it back up you find scissors or 
		// something to use to cut the braids and move past it into 
		// falcon keep
		return false;
	}

}