#include "AddLadderAction.h"
#include"Snake.h"
#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	isValid = true; //Intializing 
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter

	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	Snake* pSnake; //points on a snake (if exists) on the start or end of the ladder

	bool thereSnake = false; // if there is end of a Snake at the start of the ladder

	if (startPos.VCell() == 0 ) // the start of the ladder on last row
	{
		pGrid->PrintErrorMessage("Invalid Ladder, Click to Continue ...");
		isValid = false;
		return;
	}
	
	
	

		
		for (int i = 0; i < NumVerticalCells - 1; i++) {                
			                                                              // loops on the vertical column and checks if there are snakes whose end
			                                                              // overlapps with the start of the ladder
			pSnake = pGrid->GetCell(i, startPos.HCell())->HasSnake();

			if (pSnake != NULL) {
				if (pSnake->GetEndPosition().GetCellNum() == startPos.GetCellNum())
				{
					thereSnake = true;
					break;
				}
			}
		}
		
		

		if (thereSnake)  // checks for the condition above
		{
			pGrid->PrintErrorMessage("Invalid Ladder,here is a snake, Click to Continue ...");
			isValid = false;
			return;
		}

	



	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();
	
	pSnake = pManager->GetGrid()->GetCell(endPos.VCell(), endPos.HCell())->HasSnake();  // if there is a start of a snake at the end of the ladder

	
	if (startPos.VCell() <= endPos.VCell() || startPos.HCell() != endPos.HCell()|| pSnake!=NULL) // validation
	{
		pGrid->PrintErrorMessage("Invalid Ladder, Click to Continue ...");
		isValid = false;
		return;
	}
	
	///TODO: Make the needed validations on the read parameters
		//Done


	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	
	if (!isValid)
		return; // if the ladder not valid, do not add it to the grid

	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (! added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
