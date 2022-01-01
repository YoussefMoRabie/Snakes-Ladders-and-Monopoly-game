#include "InputDiceValue.h"

#include "Grid.h"
#include "Player.h"

InputDiceValue::InputDiceValue(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceValue::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("please enter a dice value between 1-6");
	diceValue = pIn->GetInteger(pOut);
	while (diceValue > 6 || diceValue < 1)
	{
		pOut->PrintMessage("Invalid input, please enter a dice value between 1-6");
		diceValue = pIn->GetInteger(pOut);
	}
	pOut->ClearStatusBar();
}

void InputDiceValue::Execute()
{
	ReadActionParameters();

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	Grid* pGrid = pManager->GetGrid();
	if (!pGrid->GetEndGame())
	{
		// -- If not ended, do the following --:

		// 2- Get the "current" player from pGrid
		Player* current = pGrid->GetCurrentPlayer();
		// 3- if the player is poisoned deduct one from the diceroll
		if (current->poisonCheck(pGrid))
		{
			diceValue--;
		}
		// 4- Move the currentPlayer using function Move of class player
		current->Move(pGrid, diceValue);
		// 5- Advance the current player number of pGrid
		pGrid->AdvanceCurrentPlayer();
	}
	else
		pGrid->PrintErrorMessage("The game is over, click on NewGame to start a new one!");
}

InputDiceValue::~InputDiceValue()
{
}