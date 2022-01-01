#include "SaveGridAction.h"
#include"GameObject.h"
#include"Grid.h"
#include"Cell.h"
SaveGridAction::SaveGridAction(ApplicationManager* pApp) :Action(pApp) {

}



void SaveGridAction::ReadActionParameters() {

 }
void SaveGridAction::Execute() {
	saveGrid.open("Grid.txt");
	Grid* pGrid = pManager->GetGrid();
	Cell* pCell;
	for (int i = NumVerticalCells - 1; i >= 0; i--) {
		for (int j = 0; j < NumHorizontalCells - 1; j++) {
			pCell = pGrid->GetCell(i, j);
			
			if (pCell->GetGameObject() != NULL)
				pCell->GetGameObject()->Save(saveGrid);
		}
	}
	saveGrid.close();
	pGrid->PrintErrorMessage("Saved!...");
}
SaveGridAction:: ~SaveGridAction() {

 }