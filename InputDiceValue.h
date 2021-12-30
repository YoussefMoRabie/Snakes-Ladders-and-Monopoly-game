#pragma once

#include "Action.h"

class InputDiceValue : public Action
{

	int diceValue;

public:
	InputDiceValue(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~InputDiceValue();
};
