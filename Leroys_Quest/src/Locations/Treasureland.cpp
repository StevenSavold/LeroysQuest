#include "Treasureland.h"
#include "GameObjects/Item.h"
#include <iostream>
//temp
#include "Core.h"
#include "Systems/LanguageSystem.h"

namespace LeroysQuest {

	Treasureland::Treasureland()
	{
		LanguageSystem& ls = GetInstanceOf(LanguageSystem);

		/* Add the Silver Key Item to the inventory upon creation */
		m_Inventory.push_back(Item("silver-key"));
		ls.AddIdentifier("silver-key");

		m_Inventory.push_back(Item("song-stone"));
		ls.AddIdentifier("song-stone");
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
			return "As the trees become more dense you find a stone with \n"
				   "carvings of lyrics. You feel the forest wanted you to\n"
				   "find this SONG-STONE. You feel it wanted you to sing \n"
				   "this song before it allows you to move further into  \n"
				   "this place...\n";
		}
		else
		{
			return "You have already sang treasureland's theme song, \n"
				"and gotten the key. It seems you have done everything \n"
				"there is to do here.\n";
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

	bool Treasureland::OnExit(MovementDirection exitDir)
	{
		return true;
	}

	bool Treasureland::OnEvent(Item item)
	{
		// Event should be singing the treasureland theme song.
		// and this should give the player the silver key item
		if (item.GetName() == "song-stone" && m_SongSang == false)
		{
			/* The text when the even is the correct song */
			std::cout <<
				"You hold the SONG-STONE in your hand and begin to recite\n"
				"the lyrics written upon it\n\n";

			std::cout <<
				"\tTreasureland is the place to be, \n"
				"\tTreasureland, where the acorns are free.\n"
				"\tTreasureland is for you and me and\n"
				"\tall the fuzzy creatures in the world.\n\n";

			std::cout <<
				"A strong wind blows in response to the singing of the \n"
				"treasureland theme song. The forest seems pleased with \n"
				"your performance. You look up in time to see a SILVER-KEY\n"
				"fall from the sky and land at your feet.\n";

			m_SongSang = true;
			return true;
		}
		else if (item.GetName() == "song-stone" && m_SongSang == true)
		{
			/* after the player has already sang the song correctly */
			std::cout <<
				"The forest is pleased you are singing for it again. \n"
				"However it has nothing else to give you in return.  \n";

			return true;
		}
		else
		{
			/* when you did not sing the song correctly */
			std::cout <<
				"The forest goes silent and still, you feel that was \n"
				"not the correct thing to do here.\n";

			return false;
		}
	}

}