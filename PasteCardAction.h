#pragma once
#include "Action.h"
class PasteCardAction :
    public Action
{

	CellPosition PasteTo;
public:

	PasteCardAction(ApplicationManager* pApp);  // Constructor

	virtual void ReadActionParameters(); // Reads parameters required for action to execute 
											 // (code depends on action type so virtual)

	virtual void Execute();  // Executes action (code depends on action type so virtual)

	virtual ~PasteCardAction();
};

