#pragma once
#include "Command.h"
#include <algorithm>
#include <array>

namespace LeroysQuest {

	enum ActionType
	{
		Action_None = 0,
		Look,
		Go,
		MAX_ActionTypes
	};

	class ActionCommand : public Command
	{

		ActionType ToActionType(std::string word)
		{
			auto it = std::find(commandWords.begin(), commandWords.end(), word);
			size_t idx = std::distance(commandWords.begin(), it);
			return static_cast<ActionType>(idx);
		}

	public:
		ActionCommand(ActionType type, std::string identifer)
			: m_Type(type), m_Identifer(identifer)
		{}

		ActionCommand(std::string type, std::string id)
			: ActionCommand(ToActionType(type), id) 
		{}

		inline const ActionType& GetActionType() const { return m_Type; }
		inline const std::string& GetIdentifierString() const { return m_Identifer; }

		std::unique_ptr<Command> clone() const override
		{
			return std::make_unique<ActionCommand>(*this);
		}

		static bool HasCommandWord(std::string word)
		{
			

			/* return true if word is contained in the array */
			return (std::find(commandWords.begin(), commandWords.end(), word) != commandWords.end());
		}

		COMMAND_CLASS_TYPE(ActionCommand)
	private:
		ActionType m_Type;
		std::string m_Identifer;

		inline static std::array<std::string, ActionType::MAX_ActionTypes> commandWords = {
				"none",
				"look",
				"go"
		};
	};

}