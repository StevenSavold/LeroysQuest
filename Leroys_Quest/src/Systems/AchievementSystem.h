#pragma once

namespace LeroysQuest {

	class AchievementSystem
	{
		AchievementSystem(AchievementSystem& copy) = delete;
		AchievementSystem(AchievementSystem&& move) = delete;
		AchievementSystem& operator=(AchievementSystem& copy) = delete;
		AchievementSystem& operator=(AchievementSystem&& move) = delete;

	public:
		static AchievementSystem& GetInstance()
		{
			static AchievementSystem instance;
			return instance;
		}

		bool SetBirdFree = false;
		bool Completed = false;

	private:
		AchievementSystem() {}
		~AchievementSystem() {}

	};

}