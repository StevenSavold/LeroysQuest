#include "SimpleParser.h"
#include "Core.h"
#include "Systems/LanguageSystem.h"
#include <sstream>

namespace LeroysQuest {
	SimpleParser::SimpleParser()
	{}

	SimpleParser::~SimpleParser()
	{}

	ParsedCommand SimpleParser::parse(const std::string& processedInput) const
	{
		LanguageSystem& langSpec = GetInstanceOf(LanguageSystem);
		ParsedCommand output;

		std::stringstream ss(processedInput);
		std::string word;

		/* split the string by whitespace */
		while (ss >> word)
		{
			/* Give langSpec a word, it will translate it to a command word */
			//word = langSpec.Translate(word);

			if (langSpec.isActionWord(word))
			{
				output.ActionWord = word;
			}
			if (langSpec.isIdentifier(word))
			{
				output.Identifier = word;
			}
		}

		return output;
	}
}