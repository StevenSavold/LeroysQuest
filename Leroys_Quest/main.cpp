//STL includes
#include <iostream>
#include <string>
#include <algorithm>
#include <memory>

// Core includes
#include "Core.h"

// Command includes
#include "Commands/Command.h"
#include "Commands/MovementCommand.h"
#include "Commands/ActionCommand.h"
#include "Commands/InventoryCommand.h"
#include "Commands/SystemCommand.h"

// Parser includes
#include "Parsers/SimpleParser.h"

//Game System includes
#include "Systems/MovementSystem.h"
#include "Systems/ActionSystem.h"
#include "Systems/InventorySystem.h"
#include "Systems/LanguageSystem.h"
#include "Systems/AchievementSystem.h"

std::string GetUserInput();
std::string PreprocessInput(const std::string& rawInput);
std::unique_ptr<LeroysQuest::Command> ProcessInputToCommand(const std::string& processedInput);

int main()
{
	using namespace LeroysQuest;

	/* Init code should be here */

	/* Create initial instance of game systems */
	MovementSystem&  MoveSystem = GetInstanceOf(MovementSystem);
	ActionSystem&    ActSystem  = GetInstanceOf(ActionSystem);
	InventorySystem& InvSystem  = GetInstanceOf(InventorySystem);
	LanguageSystem&  LangSystem = GetInstanceOf(LanguageSystem);
	AchievementSystem& AchieveSystem = GetInstanceOf(AchievementSystem);

	bool shouldQuit = false;
	std::string userInput;
	std::string processedInput;
	std::unique_ptr<Command> command;


	/* Begin core Game Loop */
	while (!shouldQuit && !AchieveSystem.Completed)
	{
		/* 
		 * Returns a copy of the users entered string,
		 * and has side effect of printing "> " to prompt
		 * the user.
		 */
		userInput = GetUserInput();

		/* 
		 * Takes a const reference to the RAW input and returns
		 * a copy of the input preprocessed into a more
		 * manageable form for the game to handle.
		 */
		processedInput = PreprocessInput(userInput);

		/* 
		 * Takes a const reference to the preprocessed 
		 * string and uses it to create a 'Command'
		 * object to pass into the game systems.
		 */
		command = ProcessInputToCommand(processedInput);

		/*
		 * Create a CommandDispatcher to pass commands to all the Game Systems 
		 */
		CommandDispatcher Dispatcher(*command);

		/* Dispatch command to handle system commands */
		Dispatcher.Dispatch<SystemCommand>([&](SystemCommand& command) -> bool {
			switch (command.GetSystemActionType())
			{
			case SystemActionType::Exit:
				shouldQuit = true;
				break;
			case SystemActionType::Help:
				LangSystem.DisplayCommandList();
				break;
			case SystemActionType::Error:
				[]() { std::cerr << "Command Error!\n"; }();
				break;
			default:
				[]() { std::cerr << "Cleanup code?\n"; }();
				LEROY_DEBUG_BREAK();
			}
			return true;
		});

		/* Dispatch command to handle movement commands */
		Dispatcher.Dispatch<MovementCommand>([&](MovementCommand& command) -> bool {
			MoveSystem.Move(command);
			return true;
		});

		/* Dispatch command to handle action commands */
		Dispatcher.Dispatch<ActionCommand>([&](ActionCommand& command) -> bool {

			switch (command.GetActionType())
			{
			case ActionType::Look:
				ActSystem.Look(command.GetIdentifierString());
				break;
			case ActionType::Go:
				ActSystem.Go(command.GetIdentifierString());
				break;
			default:
				return false;
			}
			return true;
		
		});

		/* Dispatch command to handle inventory commands */
		Dispatcher.Dispatch<InventoryCommand>([&](InventoryCommand& command) -> bool {

			switch (command.GetInventoryActionType())
			{
			case InventoryActionType::Inventory:
				InvSystem.PrintInventory();
				break;
			case InventoryActionType::Use:
				InvSystem.Use(command.GetIdentifierString());
				break;
			case InventoryActionType::Get:
				InvSystem.Get(command.GetIdentifierString());
				break;
			case InventoryActionType::Drop:
				InvSystem.Drop(command.GetIdentifierString());
				break;
			default:
				/* Unsupported Inventory Command! */
				return false;
			};
			return true;

		});
	}

	return 0;

}


std::string GetUserInput()
{
	std::string rawInput;
	/* make prompt for user */
	std::cout << "> ";
	/* get RAW user input up to '\n' and discard the '\n' */
	std::getline(std::cin, rawInput); 

	return rawInput;
}

std::string PreprocessInput(const std::string& rawInput)
{
	/* Make a copy of the RAW input data to manipulate */
	std::string output = rawInput;

	/* Convert the whole string to lower case */
	std::transform(output.begin(), output.end(), output.begin(), ::tolower);

	return output;
}

std::unique_ptr<LeroysQuest::Command> ProcessInputToCommand(const std::string& processedInput)
{
	using namespace LeroysQuest;
	SimpleParser parser;
	std::unique_ptr<Command> output = nullptr;

	/* Parse the user input into two parts (ActionWord and Identifier) */
	auto parsedInput = parser.parse(processedInput);

	if (parsedInput.ActionWord.empty())
	{
		//TODO: handle this error better then just 'throwing' an error command
		//   this should inform the user of the invalid command
		return SystemCommand(SystemActionType::Error).clone();
	}
	else
	{
		if (IsTypeOf(MovementCommand, parsedInput.ActionWord))
		{
			output = MovementCommand(parsedInput.ActionWord).clone();
		}
		else if (IsTypeOf(ActionCommand, parsedInput.ActionWord))
		{
			output = ActionCommand(parsedInput.ActionWord, parsedInput.Identifier).clone();
		}
		else if (IsTypeOf(InventoryCommand, parsedInput.ActionWord))
		{
			output = InventoryCommand(parsedInput.ActionWord, parsedInput.Identifier).clone();
		}
		else
		{
			output = SystemCommand(parsedInput.ActionWord).clone();
		}
		return output;
	}
}
