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
	saveGrid.open("Grid.txt");
	Grid* pGrid = pManager->GetGrid();
	Cell* pCell;
	CellPosition* ptr;
	int ladderCells[99];
	int SnakeCells [99];
	int CardCells [99];
	int c = 0, l = 0, s = 0;;
	for (int i = NumVerticalCells - 1; i >= 0; i--) {
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
	saveGrid << l << endl;
	for (int i = 0; i < l; i++) {
		pGrid->GetCell(ptr->GetCellPositionFromNum(ladderCells[i]).VCell(), ptr->GetCellPositionFromNum(ladderCells[i]).HCell())->GetGameObject()->Save(saveGrid);
	}
	saveGrid << s << endl;
	for (int i = 0; i < s; i++) {
		pGrid->GetCell(ptr->GetCellPositionFromNum(SnakeCells[i]).VCell(), ptr->GetCellPositionFromNum(SnakeCells[i]).HCell())->GetGameObject()->Save(saveGrid);
	}
	saveGrid << c << endl;
	for (int i = 0; i < c; i++) {
		pGrid->GetCell(ptr->GetCellPositionFromNum(CardCells[i]).VCell(), ptr->GetCellPositionFromNum(CardCells[i]).HCell())->GetGameObject()->Save(saveGrid);
	}
	
	saveGrid.close();
	pGrid->PrintErrorMessage("Saved!...");
}
SaveGridAction:: ~SaveGridAction() {

 }