#include "AddSnakeAction.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"
#include"Ladder.h"

AddSnakeAction::AddSnakeAction(ApplicationManager *pApp) : Action(pApp)
{
	isValid = true; //intializing
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
	
}
void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	Ladder* pLadder; //points to a ladder at the start or the end of the snake (if exist)

	bool thereLadder = false; // if there is end of a ladder at the start of the snake

	// Read the startPos parameter
	//..

	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	if (startPos.VCell() == NumVerticalCells - 1 || startPos.GetCellNum() == NumHorizontalCells * NumVerticalCells) //Validation
	{
		

		pGrid->PrintErrorMessage("Invalid Snake, Click to continue  ...");
		isValid = false;
		return;
		
	}
	for (int i = 0; i < NumVerticalCells - 1; i++) {
		// loops on the vertical column and checks if there are snakes whose end
		// overlapps with the start of the ladder
		pLadder = pGrid->GetCell(i, startPos.HCell())->HasLadder();
		if (pLadder != NULL) {
			if (pLadder->GetEndPosition().GetCellNum() == startPos.GetCellNum())
			{
				thereLadder = true;
				break;
			}
		}
	}
	if (thereLadder) //Check the condition
	{
		pGrid->PrintErrorMessage("Invalid Snake, Click to continue  ...");
		isValid = false;
		return;
	}

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	pLadder = pGrid->GetCell(endPos.VCell(), endPos.HCell())->HasLadder(); //if there is a start of a ladder at the end of the snake
	
	if (startPos.VCell() >= endPos.VCell() || startPos.HCell() != endPos.HCell()|| pLadder!= NULL)  //Validation
	{
		pGrid->PrintErrorMessage("Invalid Snake, Click to continue  ...");
		isValid = false;
		return;
	}
	


	///TODO: Make the needed validations on the read parameters
		//Done


	// Clear messages
	pOut->ClearStatusBar();
}

// Execute the action

void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	if (!isValid) //if it is invalid , do not add it to the grid
	{
		return;
	}


	Grid* pGrid = pManager->GetGrid();
	

		// Create a Ladder object with the parameters read from the user
		Snake* pSnake = new Snake(startPos, endPos);
 // We get a pointer to the Grid from the ApplicationManager

		// Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pSnake);

		// if the GameObject cannot be added
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
		// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
	
		
		
	
}