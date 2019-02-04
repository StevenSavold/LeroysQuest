#pragma once
#include <vector>
#include <string>

#include "GameObjects/Item.h"
#include "Commands/MovementCommand.h"
#include "Platform/Optional.h"

namespace LeroysQuest {

	class Location
	{
	protected:
		std::vector<Item> m_Inventory;
		std::array<Location*, 4> m_Transitions;

		bool m_FirstVisit = true;

	public:
		Location();
		virtual ~Location();

		virtual const char* Name() const ;
		virtual const char* Description() const ;
		virtual const char* ConditionalDescription() const ;
		virtual const char* TransDiscription() const ;

		virtual void OnEnter();
		virtual void OnExit();
		virtual bool OnEvent(Item item);

		virtual Location* Move(MovementDirection direction) const ;

		Optional<Item> OnItemGet(const std::string& itemName);
		void OnItemDrop(Item item);
		void OnItemLook(const std::string& itemName) const ;

		void SetTransitions(std::array<Location*, 4> trans);
		void PrintAreaTransitions() const ;
	}; 

}

