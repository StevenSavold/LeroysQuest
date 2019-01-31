#pragma once
#include "Command.h"
#include <algorithm>
#include <array>

namespace LeroysQuest {

	enum InventoryActionType
	{
		Inventory_None = 0,
		Inventory,
		Get,
		Use,
		Drop,
		MAX_InvActionTypes
	};

	class InventoryCommand : public Command
	{

		InventoryActionType ToInvActionType(std::string word)
		{
			auto it = std::find(commandWords.begin(), commandWords.end(), word);
			size_t idx = std::distance(commandWords.begin(), it);
			return static_cast<InventoryActionType>(idx);
		}

	public:
		InventoryCommand(InventoryActionType type, std::string id)
			: m_Type(type), m_Identifer(id)
		{}

		InventoryCommand(std::string type, std::string id)
			: InventoryCommand(ToInvActionType(type), id) 
		{}

		inline const InventoryActionType& GetInventoryActionType() const { return m_Type; }
		inline const std::string& GetIdentifierString() const { return m_Identifer; }

		std::unique_ptr<Command> clone() const override
		{
			return std::make_unique<InventoryCommand>(*this);
		}

		static bool HasCommandWord(std::string word)
		{
			/* return true if word is contained in the array */
			return (std::find(commandWords.begin(), commandWords.end(), word) != commandWords.end());
		}


		COMMAND_CLASS_TYPE(InventoryCommand)
	private:
		InventoryActionType m_Type;
		std::string m_Identifer;

		inline static std::array<std::string, InventoryActionType::MAX_InvActionTypes> commandWords = {
				"none",
				"inventory",
				"get",
				"use",
				"drop"
		};
	};

}