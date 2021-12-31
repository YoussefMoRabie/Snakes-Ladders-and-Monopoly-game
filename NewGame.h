#pragma once

#include "Action.h"

class NewGame : public Action
{

	// No parameters for this action

public:
	NewGame(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~NewGame();
};