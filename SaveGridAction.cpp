#include "SaveGridAction.h"
#include"GameObject.h"
#include"Ladder.h"
#include"Snake.h"
#include"Card.h"
#include"Grid.h"
#include"Cell.h"
SaveGridAction::SaveGridAction(ApplicationManager* pApp) :Action(pApp) {

}



void SaveGridAction::ReadActionParameters() {

 }
void SaveGridAction::Execute() {

	saveGrid.open("Grid.txt"); //opens the file to save into

	Grid* pGrid = pManager->GetGrid();

	Cell* pCell; //points on a cell in the grid

	CellPosition objPos; // the object position

	int ladderCells[99]; //stores the cells numbers that contain ladders
	int SnakeCells [99];  //stores the cells numbers that contain Snakes
	int CardCells [99]; //stores the cells numbers that contain Cards

	int c = 0, l = 0, s = 0; //conters for number of cards,ladders, snakes

	for (int i = NumVerticalCells - 1; i >= 0; i--) //loop on the grid cells and count the objects & store their cell numbers in the arrays
	{
		for (int j = 0; j < NumHorizontalCells - 1; j++) {
			pCell = pGrid->GetCell(i, j);
			
			if (pCell->HasLadder())
				ladderCells[l++] = pCell->HasLadder()->GetPosition().GetCellNum();
			else if (pCell->HasSnake())
				SnakeCells[s++] = pCell->HasSnake()->GetPosition().GetCellNum();
			else if (pCell->HasCard())
				CardCells[c++]= pCell->HasCard()->GetPosition().GetCellNum();
			

		}
	}
	// the following is storing the information in the file grid.txt as in the project document

	saveGrid << l << endl; 
	for (int i = 0; i < l; i++) {
		objPos = CellPosition::GetCellPositionFromNum(ladderCells[i]);
		pGrid->GetCell(objPos.VCell(),objPos.HCell())->GetGameObject()->Save(saveGrid);
	}
	saveGrid << s << endl;
	for (int i = 0; i < s; i++) {
		objPos = CellPosition::GetCellPositionFromNum(SnakeCells[i]);
		pGrid->GetCell(objPos.VCell(),objPos.HCell())->GetGameObject()->Save(saveGrid);
	}
	saveGrid << c << endl;
	for (int i = 0; i < c; i++) {
		objPos = CellPosition::GetCellPositionFromNum(CardCells[i]);
		pGrid->GetCell(objPos.VCell(),objPos.HCell())->GetGameObject()->Save(saveGrid);
	}
	
	saveGrid.close(); // close the file

	pGrid->PrintErrorMessage("Saved!...");
}
SaveGridAction:: ~SaveGridAction() {

 }