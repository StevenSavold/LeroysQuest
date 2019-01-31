#pragma once 
#include <vector>
#include <utility>
#include "Commands/MovementCommand.h"
#include "GameObjects/GameObject.h"
#include "Locations/Location.h"


namespace LeroysQuest {

	class MovementSystem
	{
		std::vector<Location*> m_Map;
		Location* currentLocation;

		MovementSystem(MovementSystem& copy) = delete;
		MovementSystem(MovementSystem&& move) = delete;
		MovementSystem& operator=(MovementSystem& copy) = delete;
		MovementSystem& operator=(MovementSystem&& move) = delete;

	public:
		static MovementSystem& GetInstance() 
		{ 
			static MovementSystem instance;
			return instance;
		}

		void Move(MovementCommand command);
		void LookAtCurrentRoom() const ;
		void LookAtRoomItem(const std::string& itemName) const ;

	private:
		MovementSystem();
		~MovementSystem();

	};

}