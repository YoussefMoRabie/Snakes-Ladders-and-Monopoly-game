#include "CardSix.h"
CardSix::CardSix(CellPosition& p) :Card(p) {
	SetCardNumber(6);
}
void CardSix::ReadCardParameters(Grid * pGrid) {
	pGrid->GetOutput()->PrintMessage("Please, Click on a Cell....");
	cellNumToMove= pGrid->GetInput()->GetCellClicked().GetCellNum();
}
void CardSix::Apply(Grid* pGrid, Player * pPlayer) {
	
	
	pPlayer->MoveWithoutDice(pGrid, pPlayer->GetCell()->GetCellPosition().GetCellPositionFromNum(cellNumToMove));
}