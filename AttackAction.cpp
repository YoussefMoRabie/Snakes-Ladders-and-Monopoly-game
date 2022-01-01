#include "AttackAction.h"

#include "Grid.h"
#include "Player.h"
#include "Ice.h"
#include "Fire.h"
#include "Poison.h"
#include "Lighting.h"

AttackAction::AttackAction(ApplicationManager* pApp) : Action(pApp)
{
}

void AttackAction::ReadActionParameters()
{
	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	Grid* pGrid = pManager->GetGrid();
	if (!pGrid->GetEndGame())
	{
		// -- If not ended, do the following --:
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		// 2- Get the "current" player from pGrid
		Player* current = pGrid->GetCurrentPlayer();
		// 3- Check if it's the player's wallet turn "can AttackAction or not"
		if (current->GetTurnCount() != 2)
			pGrid->PrintErrorMessage("You can't attack unless it's your wallet turn!");
		// 4- If they can, make them choose the type
		else
		{
			Attacker = current;

			pOut->PrintMessage("Choose the type of attack ('I'ce - 'F'ire - 'P'oison - 'L'ighting)");
			string type = pIn->GetString(pOut);
			pOut->ClearStatusBar();

			if (type == "i" || type == "I")
				attack = ice;
			else if (type == "f" || type == "F")
				attack = fire;
			else if (type == "p" || type == "P")
				attack = poison;
			else if (type == "l" || type == "L")
				attack = lighting;
			else
				pGrid->PrintErrorMessage("Invalid input, click to continue...");
		}
	}
	else
		pGrid->PrintErrorMessage("The game is over, click on NewGame to start a new one!");
}

void AttackAction::Execute()
{

	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Player* current = pGrid->GetCurrentPlayer();

	Attack* pAtk = NULL;

	switch (attack)
	{
	case(ice):
		pAtk = new Ice(pGrid, current);
		break;
	case(fire):
		pAtk = new Fire(pGrid, current);
		break;
	case(poison):
		pAtk = new Poison(pGrid, current);
		break;
	case(lighting):
		pAtk = new Lighting(pGrid, current);
		break;

	}
	if (pAtk != NULL)
	{
		pAtk->Execute(); // Execute
		delete pAtk;	 // Attack is not needed any more after executing ==> delete it
		pAtk = NULL;
	}
	
}

AttackAction::~AttackAction()
{
}
