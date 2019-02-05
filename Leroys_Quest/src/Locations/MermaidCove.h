#pragma once
#include "Location.h"

namespace LeroysQuest {

	class MermaidCove : public Location
	{

		bool m_HelpedMermaid = false;

	public:
		MermaidCove();
		~MermaidCove();

		const char* Name() const override ;
		const char* Description() const override ;
		const char* ConditionalDescription() const override ;
		const char* TransDiscription() const override ;

		void OnEnter() override ;
		bool OnExit(MovementDirection exitDir) override ;
		bool OnEvent(Item item) override ;

	};

}

