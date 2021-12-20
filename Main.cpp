
#include "ApplicationManager.h"

// This Main Function Must NOT be Changed

int main()
{
	ActionType ActType;

	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the drawings of the window after executing the action
		AppManager.UpdateInterface();

	} while(ActType != EXIT);


	return 0;
}


