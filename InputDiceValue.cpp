#include "InputDiceValue.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

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
		// 3- Move the currentPlayer using function Move of class player
		current->Move(pGrid, diceValue);
		// 4- Advance the current player number of pGrid
		pGrid->AdvanceCurrentPlayer();
		// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	}
}

InputDiceValue::~InputDiceValue()
{
}