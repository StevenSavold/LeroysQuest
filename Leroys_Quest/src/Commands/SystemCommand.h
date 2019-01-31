#pragma once
#include "Command.h"
#include <algorithm>
#include <array>

namespace LeroysQuest {

	enum SystemActionType
	{
		System_None = 0,
		Help,
		Exit,
		Error,
		MAX_SystemActionTypes
	};

	class SystemCommand : public Command
	{
		SystemActionType ToSysActionType(std::string word)
		{
			auto it = std::find(commandWords.begin(), commandWords.end(), word);
			size_t idx = std::distance(commandWords.begin(), it);
			return static_cast<SystemActionType>(idx);
		}

	public:
		SystemCommand(SystemActionType type)
			: m_Type(type) {}

		SystemCommand(std::string type)
			: SystemCommand(ToSysActionType(type)) 
		{}

		inline const SystemActionType& GetSystemActionType() const { return m_Type; }
		
		std::unique_ptr<Command> clone() const override
		{
			return std::make_unique<SystemCommand>(*this);
		}
		
		static bool HasCommandWord(std::string word)
		{
			/* return true if word is contained in the array */
			return (std::find(commandWords.begin(), commandWords.end(), word) != commandWords.end());
		}


		COMMAND_CLASS_TYPE(SystemCommand)
	private:
		SystemActionType m_Type;

		inline static std::array<std::string, SystemActionType::MAX_SystemActionTypes> commandWords = {
				"none",
				"help",
				"exit",
				"error"
		};
	};

}