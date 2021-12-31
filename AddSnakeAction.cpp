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
}
void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter

	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();
	
	while (startPos.VCell() == NumVerticalCells-1 || pGrid->GetCell(startPos.VCell(), startPos.HCell())->HasCard() != NULL)
	{
		pGrid->PrintErrorMessage("Invalid Snake, Click to retry  ...");
		pOut->PrintMessage("New Snake: Click on its Start Cell ...");
		startPos = pIn->GetCellClicked();
	}

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();
	Ladder* end = pGrid->GetCell(endPos.VCell(), endPos.HCell())->HasLadder();
	int x = -1;
	if (end != NULL)
		x = end->GetPosition().GetCellNum();
	while (startPos.VCell() >= endPos.VCell() || startPos.HCell() != endPos.HCell()||x==endPos.GetCellNum()) {
		pGrid->PrintErrorMessage("Invalid Snake, Click to retry ...");
		pOut->PrintMessage("New Snake: Click on its Start Cell ...");
		startPos = pIn->GetCellClicked();
		pOut->PrintMessage("New Snake: Click on its End Cell ...");
		endPos = pIn->GetCellClicked();
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

	// Create a Ladder object with the parameters read from the user
	Snake * pSnake = new Snake(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

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