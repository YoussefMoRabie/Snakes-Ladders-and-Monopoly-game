#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	Grid* pGrid = pManager->GetGrid();
	if (!pGrid->GetEndGame())
	{
		// -- If not ended, do the following --:
		Output* pOut = pGrid->GetOutput();
		// 2- Generate a random number from 1 to 6 --> This step is done for you
		srand((int)time(NULL)); // time is for different seed each run
		int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
		pOut->PrintMessage("Player " + to_string(pGrid->GetCurrentPlayer()->getPlayerNum()) + " rolled a " + to_string(diceNumber)+"!");

		// 3- Get the "current" player from pGrid
		Player * current = pGrid->GetCurrentPlayer();
		// 4- Move the currentPlayer using function Move of class player
		current->Move(pGrid, diceNumber);
		// 5- Advance the current player number of pGrid
		pGrid->AdvanceCurrentPlayer();

		// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	}
}

RollDiceAction::~RollDiceAction()
{
}
