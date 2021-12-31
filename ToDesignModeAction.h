#pragma once
#include "Action.h"
class ToDesignModeAction :
    public Action
{
	ToDesignModeAction(ApplicationManager* pApp);  // Constructor

	// ============ Virtual Functions ============

	virtual void ReadActionParameters() = 0; // Reads parameters required for action to execute 
											 // (code depends on action type so virtual)

	virtual void Execute() = 0;  // Executes action (code depends on action type so virtual)

	virtual ~ToDesignModeAction();  // Virtual Destructor
};


