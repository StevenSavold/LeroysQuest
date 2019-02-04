#pragma once
#include "Location.h"

namespace LeroysQuest {

	class Treasureland : public Location
	{

		bool m_SongSang = false;

	public:
		Treasureland();
		~Treasureland();

		const char* Name() const override ;
		const char* Description() const override ;
		const char* ConditionalDescription() const override ;
		const char* TransDiscription() const override ;

		void OnEnter() override ;
		void OnExit() override ;
		bool OnEvent(Item item) override ;

	};

}

