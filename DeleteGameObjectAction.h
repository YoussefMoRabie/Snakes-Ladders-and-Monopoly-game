#pragma once
#include "Action.h"
class DeleteGameObjectAction :public Action
{
	CellPosition DeletedObj; //the position of the object to be deleted

	GameObject* Obj; //points to the object to be deleted

public:

	DeleteGameObjectAction(ApplicationManager* pApp);  // Constructor

	// ============ Virtual Functions ============

	virtual void ReadActionParameters(); // Reads parameters required for action to execute 
											 // (code depends on action type so virtual)

	virtual void Execute() ;  // Executes action (code depends on action type so virtual)

	virtual ~DeleteGameObjectAction();  // Virtual Destructor
};

