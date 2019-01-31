#pragma once
#include <string>
#include <memory>
#include <functional>

namespace LeroysQuest {

	enum class CommandType
	{
		None = 0,
		MovementCommand,
		ActionCommand,
		InventoryCommand,
		SystemCommand,
		MAX_CommandTypes
	};

	#define COMMAND_CLASS_TYPE(type) static CommandType GetStaticType() { return CommandType::##type; }\
								virtual CommandType GetCommandType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

	class Command
	{
	public:

		bool Handled = false;

		virtual CommandType GetCommandType() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }
		virtual std::unique_ptr<Command> clone() const = 0;

	};

	class CommandDispatcher
	{
		template<typename T>
		using CommandFn = std::function<bool(T&)>;
	public:
		CommandDispatcher(Command& command)
			: m_Command(command)
		{
		}

		template<typename T>
		bool Dispatch(CommandFn<T> func)
		{
			if (m_Command.GetCommandType() == T::GetStaticType())
			{
				m_Command.Handled = func(*(static_cast<T*>(&m_Command)));
				return true;
			}
			return false;
		}
	private:
		Command& m_Command;
	};

	inline std::ostream& operator<<(std::ostream& os, const Command& e)
	{
		return os << e.ToString();
	}
}