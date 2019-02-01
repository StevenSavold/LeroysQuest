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

		GameObject(const GameObject& copy) 
			: m_Name(copy.m_Name), 
			  m_Description(copy.m_Description)
		{}

		GameObject(GameObject&& move)
			: m_Name(move.m_Name),
			  m_Description(move.m_Description)
		{
			move.m_Name.clear();
			move.m_Description.clear();
		}

		GameObject& operator=(const GameObject& copy)
		{
			this->m_Name = copy.m_Name;
			this->m_Description = copy.m_Description;

			return *this;
		}

		GameObject& operator=(GameObject&& move)
		{
			this->m_Name = move.m_Name;
			this->m_Description = move.m_Description;

			move.m_Name.clear();
			move.m_Description.clear();

			return *this;
		}

		virtual ~GameObject() 
		{}

		inline const std::string& GetName() const { return m_Name; }
		inline const std::string& GetDiscription() const { return m_Description; }
	};

}