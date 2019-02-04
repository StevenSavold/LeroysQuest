#pragma once
#include "Location.h"

namespace LeroysQuest {

	class FalconKeep : public Location
	{
	public:
		FalconKeep();
		~FalconKeep();

		const char* Name() const override ;
		const char* Description() const override ;
		const char* ConditionalDescription() const override ;

		void OnEnter() override ;
		void OnExit() override ;
		bool OnEvent(Item item) override ;

	};

}

