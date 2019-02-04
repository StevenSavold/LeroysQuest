#include "Treasureland.h"
#include "GameObjects/Item.h"

//temp
#include "Core.h"
#include "Systems/LanguageSystem.h"

namespace LeroysQuest {

	Treasureland::Treasureland()
	{
		LanguageSystem& ls = GetInstanceOf(LanguageSystem);

		/* Add the Silver Key Item to the inventory upon creation */
		m_Inventory.push_back(Item("silver_key"));
		ls.AddIdentifier("silver_key");
	}

	Treasureland::~Treasureland()
	{
	}



	const char* Treasureland::Name() const
	{
		return "Treasureland";
	}

	const char* Treasureland::Description() const
	{
		return "Laid out before you is a vast expanse of trees as \n"
			   "tall as giants. This forest known as treasureland \n"
			   "is filled with acorns and all sorts of small creatures.\n";
	} 

	const char* Treasureland::ConditionalDescription() const
	{
		if (!m_SongSang)
		{
			return "As the trees become more dense you feel there \n"
				   "is a song you must sing, before you can move further \n"
				   "into this place...\n";
		}
		else
		{
			return "You have already sang treasureland's theme song, \n"
				"and gotten the key. It seems you have done everything \n"
				"there is to do here\n";
		}
	}

	const char* Treasureland::TransDiscription() const
	{
		return "A forest with plenty of acorns\n";
	}


	void Treasureland::OnEnter()
	{
		m_FirstVisit = false;
	}

	void Treasureland::OnExit()
	{}

	bool Treasureland::OnEvent(Item item)
	{
		// Event should be singing the treasureland theme song.
		// and this should give the player the silver key item

		/* The text when the even is the correct song */
		"A strong wind blows in response to the singing of the \n"
			"treasueland theme song. The forest seems pleased with \n"
			"your performance. You look up in time to see a silver \n"
			"key fall from the sky and land at your feet. You pick \n"
			"it up and put it in your pocket.\n"

			/* when you did not sing the song correctly */
			"The forest goes silent and still, you feel that was \n"
			"not the correct thing to do here.\n"

			/* after the player has already sang the song correctly */
			"The forest is pleased you are singing for it again. \n"
			"However it has nothing else to give you in return.  \n";

		return false;

	}

}