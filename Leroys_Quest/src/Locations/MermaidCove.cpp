#include "MermaidCove.h"
#include <iostream>

//temp
#include "Core.h"
#include "Systems/LanguageSystem.h"

namespace LeroysQuest {

	MermaidCove::MermaidCove()
	{
		LanguageSystem& ls = GetInstanceOf(LanguageSystem);

		m_Inventory.push_back(Item("bucket"));
		ls.AddIdentifier("bucket");
	}


	MermaidCove::~MermaidCove()
	{
	}


	const char* MermaidCove::Name() const
	{
		return "Mermaid Cove";
	}

	const char* MermaidCove::Description() const
	{
		return "In a small grove held within a patch of green lies a small lake\n"
			   "of crystal blues and whites. The water is still except for the \n"
			   "small rings of disturbance coming from behind a rock near the  \n"
			   "lakes edge.\n";
	} 

	const char* MermaidCove::ConditionalDescription() const
	{
		if (!m_HelpedMermaid)
		{
			return
				"You hear a mermaid crying behind the rock. When you call out to\n"
				"her to ask what is wrong, she tells you that her hair is terribly\n"
				"knotted. She tells you that in her desperate attempts to find a\n"
				"solution, she instead found a bucket. Through her continued sobs,\n"
				"she begs you to help her. Before she sinks down under the water \n"
				"leaving you standing alone in the clearing\n";
		}
		else
		{
			return
				"You call out to the mermaid once more; this time she seems joyful.\n"
				"She thanks you graciously for helping her earlier.\n";
		}

	}

	const char* MermaidCove::TransDiscription() const
	{
		return "A small lake surround by trees\n";
	}


	void MermaidCove::OnEnter()
	{}

	bool MermaidCove::OnExit(MovementDirection exitDir)
	{
		return true;
	}

	bool MermaidCove::OnEvent(Item item)
	{
		if (item.GetName() == "hair-brush")
		{
			std::cout <<
				"As you hold up the hair brush about to call out to the crying\n"
				"mermaid, She comes rushing over to the shore to grab it from \n"
				"your hand. She is filled with such excitement and joy, that she\n"
				"accidentally pushes you to the ground trying to take it out of\n"
				"your hand. She throws the BUCKET next to you, and with the hair\n"
				"brush in hand, swims back into the lake.\n";
			m_HelpedMermaid = true;

			return true;
		}
		else
		{
			std::cout <<
				"You hold up the item and call out to the mermaid. She looks at\n"
				"what you have and her face fills with rage. She screams at you\n"
				"and her hair becomes engulfed in flames. She quickly dives back\n"
				"under the water to quench her flaming hair.\n";

			return false;
		}
	}

}