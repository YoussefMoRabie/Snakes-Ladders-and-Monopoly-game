#pragma once

#include "Action.h"

class RollDiceAction : public Action
{

	// No parameters for this action

public:
	RollDiceAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~RollDiceAction();
};

