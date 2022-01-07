#include "AddSnakeAction.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"
#include"Ladder.h"

AddSnakeAction::AddSnakeAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
	isValid = true;
}
void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Ladder* end;
	bool thereLadder = false;
	// Read the startPos parameter

	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	if (startPos.VCell() == NumVerticalCells - 1 || startPos.GetCellNum() == NumHorizontalCells * NumVerticalCells)
	{
		pGrid->PrintErrorMessage("Invalid Snake, Click to continue  ...");
		isValid = false;
		return;
		
	}
	for (int i = 0; i < NumVerticalCells - 1; i++) {
		end = pGrid->GetCell(i, startPos.HCell())->HasLadder();
		if (end != NULL) {
			if (end->GetEndPosition().GetCellNum() == startPos.GetCellNum())
			{
				thereLadder = true;
				break;
			}
		}
	}
	if (thereLadder) {
		pGrid->PrintErrorMessage("Invalid Snake, Click to continue  ...");
		isValid = false;
		return;
	}
	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();
	 end = pGrid->GetCell(endPos.VCell(), endPos.HCell())->HasLadder();
	int x = -1;
	if (end != NULL)
		x = end->GetPosition().GetCellNum();
	if (startPos.VCell() >= endPos.VCell() || startPos.HCell() != endPos.HCell()|| x == endPos.GetCellNum()) {
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

	Grid* pGrid = pManager->GetGrid();
	if (!isValid) {
		return;
	}

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