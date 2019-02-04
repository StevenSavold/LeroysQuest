#include "FalconKeep.h"

namespace LeroysQuest {

	FalconKeep::FalconKeep()
	{
	}

	FalconKeep::~FalconKeep()
	{
	}


	const char* FalconKeep::Name() const
	{
		return "Falcon Keep";
	}

	const char* FalconKeep::Description() const
	{
		return "";
	}

	const char* FalconKeep::ConditionalDescription() const
	{
		return "";
	}

	const char* FalconKeep::TransDiscription() const
	{
		return "A metal door inset into a cliff wall...\n";
	}


	void FalconKeep::OnEnter()
	{}

	void FalconKeep::OnExit()
	{}

	bool FalconKeep::OnEvent(Item item)
	{
		return false;
	}

}