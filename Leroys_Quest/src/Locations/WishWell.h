#pragma once
#include "Location.h"

namespace LeroysQuest {

	class WishWell : public Location
	{

		bool m_BucketUsed = false;

	public:
		WishWell();
		~WishWell();

		const char* Name() const override ;
		const char* Description() const override ;
		const char* ConditionalDescription() const override ;
		const char* TransDiscription() const override ;

		void OnEnter() override ;
		bool OnExit(MovementDirection exitDir) override ;
		bool OnEvent(Item item) override ;

	};

}

