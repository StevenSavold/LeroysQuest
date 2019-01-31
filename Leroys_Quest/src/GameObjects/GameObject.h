#pragma once 
#include <string>

namespace LeroysQuest {
	
	class GameObject
	{
	protected:
		std::string m_Name;
		std::string m_Description;
	public:
		GameObject(const std::string& name)
			: m_Name(name) {}

		GameObject(const std::string& name, const std::string& desc)
			: m_Name(name), m_Description(desc) {}

		virtual ~GameObject() 
		{}

		inline const std::string& GetName() const { return m_Name; }
		inline const std::string& GetDiscription() const { return m_Description; }
	};

}