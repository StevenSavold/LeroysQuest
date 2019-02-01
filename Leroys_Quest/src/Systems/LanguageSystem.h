#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace LeroysQuest { 

	class LanguageSystem
	{
	private:
		std::unordered_map<std::string, std::string> m_LangMap;
		std::vector<std::string> m_ActionWords;
		std::vector<std::string> m_KnownIdentifiers;
		std::vector<std::string> m_CommandDescs;

		LanguageSystem(LanguageSystem& copy) = delete;
		LanguageSystem(LanguageSystem&& move) = delete;
		LanguageSystem& operator=(LanguageSystem& copy) = delete;
		LanguageSystem& operator=(LanguageSystem&& move) = delete;

	public:
		static LanguageSystem& GetInstance()
		{
			static LanguageSystem instance;
			return instance;
		}

		bool isActionWord(std::string word) const ;
		bool isIdentifier(std::string word) const ;

		std::string Translate(std::string word) const ;

		void DisplayCommandList() const;

		void AddIdentifier(const std::string& id);

	private:
		LanguageSystem();
		~LanguageSystem();

		void LoadLangFile(std::string filepath);
		void LoadActionWordList(std::string filepath);
	};

}