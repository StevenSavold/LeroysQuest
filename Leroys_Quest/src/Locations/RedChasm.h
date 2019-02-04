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

		void OnEnter() override ;
		void OnExit() override ;
		bool OnEvent(Item item) override ;

	};

}

