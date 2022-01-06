#include "DeleteGameObjectAction.h"
#include"CellPosition.h"
#include"Grid.h"
DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) :Action(pApp) {
	thereObj = true;
}  // Constructor

void DeleteGameObjectAction:: ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	pOut->PrintMessage("Click on an Object To Delete...");
	
		DeletedObj = pIn->GetCellClicked();
		if (pGrid->GetCell(DeletedObj.VCell(), DeletedObj.HCell())->GetGameObject() == NULL) {

			pGrid->PrintErrorMessage("There is no Object here!...");
			thereObj = false;
			return;
		}
		pOut->ClearStatusBar();
	
}

void DeleteGameObjectAction::Execute() {
	ReadActionParameters();
	if (!thereObj ) {
		return;

	}
	if (pManager->GetGrid()->RemoveObjectFromCell(DeletedObj)) {
		pManager->UpdateInterface();
		pManager->GetGrid()->PrintErrorMessage("ObjectDeleted!...");

	}

} 
DeleteGameObjectAction:: ~DeleteGameObjectAction() {

}