#pragma once
#include "Action.h"
#include"Card.h"
class CopyCardAction :public Action
{
	Card* CopiedCard; //points to the card copied

public: 

	CopyCardAction(ApplicationManager* pApp);  // Constructor

	virtual void ReadActionParameters() ; // Reads parameters required for action to execute 
											 // (code depends on action type so virtual)

	virtual void Execute() ;  // Executes action (code depends on action type so virtual)

	virtual ~CopyCardAction();
};

