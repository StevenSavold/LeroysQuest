#pragma once
#include "Command.h"
#include <algorithm>
#include <array>

namespace LeroysQuest {

	enum MovementDirection
	{
		Movement_None = 0,
		North,
		South,
		East,
		West,
	 /* NorthWest, */
	 /* NorthEast, */
	 /* SouthWest, */
	 /* SouthEast, */
	 /* Up,        */
	 /* Down,      */
		MAX_MovementDirections
	};

	class MovementCommand : public Command
	{
		MovementDirection ToDirection(std::string word)
		{
			auto it = std::find(commandWords.begin(), commandWords.end(), word);
			size_t idx = std::distance(commandWords.begin(), it);
			return static_cast<MovementDirection>(idx);
		}

	public:
		MovementCommand(MovementDirection direction)
			: m_Direction(direction) 
		{}

		MovementCommand(std::string direction)
			: MovementCommand(ToDirection(direction)) 
		{}

		inline const MovementDirection& GetMovementDirection() const { return m_Direction; }

		std::unique_ptr<Command> clone() const override
		{
			return std::make_unique<MovementCommand>(*this);
		}

		static bool HasCommandWord(std::string word)
		{
			/* return true if word is contained in the array */
			return (std::find(commandWords.begin(), commandWords.end(), word) != commandWords.end());
		}


		COMMAND_CLASS_TYPE(MovementCommand)
	private:
		MovementDirection m_Direction;

		inline static std::array<std::string, MovementDirection::MAX_MovementDirections> commandWords = {
				"none",
				"north",
				"south",
				"east",
				"west"
		};
	};

}