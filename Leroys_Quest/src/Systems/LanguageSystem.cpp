#include "LanguageSystem.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

namespace LeroysQuest {

	LanguageSystem::LanguageSystem()
	{
		LoadLangFile("res/LeroysQuest.lang");
		LoadActionWordList("res/ActionWord.list");
	}

	LanguageSystem::~LanguageSystem()
	{
	}

	bool LanguageSystem::isActionWord(std::string word) const
	{
		return (std::find(m_ActionWords.begin(), m_ActionWords.end(), word) != m_ActionWords.end());
	}

	bool LanguageSystem::isIdentifier(std::string word) const
	{
		return (std::find(m_KnownIdentifiers.begin(), m_KnownIdentifiers.end(), word) != m_KnownIdentifiers.end());
	}

	std::string LanguageSystem::Translate(std::string word) const 
	{
		/* 
		 * Will translate a given word into a 
		 * 'Command Word' (e.g. 'north', 
		 * 'look', etc.) using a dictionary 
		 * built from a given '.lang' file
		 */
		if (m_LangMap.find(word) == m_LangMap.end())
		{
			/* The word is not in the map, map the word to nothing */
			return "";
		}
		else
		{
			return m_LangMap.at(word);
		}
	}

	void LanguageSystem::DisplayCommandList() const
	{
		for (size_t i = 0; i < m_ActionWords.size(); ++i)
		{
			std::cout << m_ActionWords[i] << " -";
			std::cout << m_CommandDescs[i] << '\n';
		}
	}

	void LanguageSystem::LoadLangFile(std::string filepath) 
	{
		std::ifstream langFile(filepath);
		std::string line;

		/* For all lines in the file */
		while (getline(langFile, line))
		{
			std::stringstream ss(line);
			std::string idxWord;
			std::string mappedWord;

			/* The first word is the idx into the map */
			ss >> idxWord;

			/* The second word it the keyword it maps to */
			ss >> mappedWord;

			/* Add that mapping to the LangSystem */
			m_LangMap[idxWord] = mappedWord;
		}
	}

	void LanguageSystem::LoadActionWordList(std::string filepath) 
	{
		std::ifstream listFile(filepath);
		std::string line;

		std::string actionWord;
		std::string garbage;
		std::string desc;

		while (getline(listFile, line))
		{
			std::stringstream ss(line);
			ss >> actionWord;
			ss >> garbage;
			getline(ss, desc);

			m_ActionWords.push_back(actionWord);
			m_CommandDescs.push_back(desc);
		}
	}
}