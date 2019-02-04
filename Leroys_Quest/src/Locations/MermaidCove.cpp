#include "MermaidCove.h"

namespace LeroysQuest {

	MermaidCove::MermaidCove()
	{
		// add item "Rock" to room inventory
	}


	MermaidCove::~MermaidCove()
	{
	}


	const char* MermaidCove::Name() const
	{
		return "Mermaid Cove";
	}

	const char* MermaidCove::Description() const
	{
		return "In a small grove held within a patch of green lies a small lake\n"
			   "of crystal blues and whites. The water is still except for the \n"
			   "small rings of disturbance coming from behind a rock near the  \n"
			   "lakes edge.\n";
	} 

	const char* MermaidCove::ConditionalDescription() const
	{
		return ""; 
	}

	const char* MermaidCove::TransDiscription() const
	{
		return "A small lake surround by trees\n";
	}


	void MermaidCove::OnEnter()
	{}

	void MermaidCove::OnExit()
	{}

	bool MermaidCove::OnEvent(Item item)
	{
		// look at the rock to find the mermaid. it will do something... 
		return false;
	}

}