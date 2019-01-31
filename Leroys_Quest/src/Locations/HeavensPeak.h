#pragma once
#include "Location.h"

namespace LeroysQuest {

	class HeavensPeak : public Location
	{

		bool m_BirdFreed = false;

	public:
		HeavensPeak();
		~HeavensPeak();

		const char* Name() const override ;
		const char* Description() const override ;
		const char* ConditionalDescription() const override ;

		void OnEnter() override ;
		void OnExit() override ;
		void OnEvent() override ;

	};

}

