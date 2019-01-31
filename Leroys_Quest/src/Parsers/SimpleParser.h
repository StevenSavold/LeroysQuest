#pragma once
#include <array>
#include <string>

namespace LeroysQuest {

	struct ParsedCommand
	{
		std::string ActionWord;
		std::string Identifier;
	};

	#define NUM_KEYWORDS 12

	class SimpleParser
	{
	private:

	public:
		SimpleParser();
		~SimpleParser();

		ParsedCommand parse(const std::string& processedInput) const ;
	};

}