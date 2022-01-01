#include "DeleteGameObjectAction.h"
#include"CellPosition.h"
#include"Grid.h"
DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) :Action(pApp) {

}  // Constructor

void DeleteGameObjectAction:: ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	pOut->PrintMessage("Click on an Object To Delete...");
	
		DeletedObj = pIn->GetCellClicked();
		pOut->ClearStatusBar();
	
}

void DeleteGameObjectAction::Execute() {
	ReadActionParameters();
	if (pManager->GetGrid()->RemoveObjectFromCell(DeletedObj)) {
		pManager->UpdateInterface();
		pManager->GetGrid()->PrintErrorMessage("ObjectDeleted!...");

	}

} 
DeleteGameObjectAction:: ~DeleteGameObjectAction() {

}