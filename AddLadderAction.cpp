#include "AddLadderAction.h"
#include"Snake.h"
#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	isValid = true;
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
	Snake* end;
	bool thereSnake = false;
	if (startPos.VCell() == 0 )
	{
		pGrid->PrintErrorMessage("Invalid Ladder, Click to Continue ...");
		isValid = false;
		return;
	}
	
	if (pGrid->GetCell(startPos.VCell(), startPos.HCell())->HasCard() != NULL) {
		pGrid->PrintErrorMessage("Invalid Ladder,here is a Card, Click to Continue ...");
		isValid = false;
		return;
	}
	

		
		for (int i = 0; i < NumVerticalCells - 1; i++) {
			end = pGrid->GetCell(i, startPos.HCell())->HasSnake();
			if (end != NULL) {
				if (end->GetEndPosition().GetCellNum() == startPos.GetCellNum())
				{
					thereSnake = true;
					break;
				}
			}
		}
		
		

		if (thereSnake)
		{
			pGrid->PrintErrorMessage("Invalid Ladder,here is a snake, Click to Continue ...");
			startPos.SetVCell(-1);
			pGrid->GetOutput()->ClearStatusBar();
			isValid = false;
			return;
		}

	



	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();
	
	 end = pManager->GetGrid()->GetCell(endPos.VCell(), endPos.HCell())->HasSnake();
	int x = -1;
	if (end != NULL)
		x = end->GetPosition().GetCellNum();
	if (startPos.VCell() <= endPos.VCell() || startPos.HCell() != endPos.HCell()|| x == endPos.GetCellNum())
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
		return;
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
