#pragma once
#include "Location.h"

namespace LeroysQuest {

	class RedChasm : public Location
	{
	public:
		RedChasm();
		~RedChasm();

		const char* Name() const override ;
		const char* Description() const override ;
		const char* ConditionalDescription() const override ;
		const char* TransDiscription() const override ;

		void OnEnter() override ;
		bool OnExit(MovementDirection exitDir) override ;
		bool OnEvent(Item item) override ;

	};

}

