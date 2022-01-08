#include "CardSix.h"
CardSix::CardSix(CellPosition& p) :Card(p) {
	cardNumber= 6;
}
void CardSix::ReadCardParameters(Grid * pGrid) {

	pGrid->GetOutput()->PrintMessage("Please, Click on the destination cell...."); //read the cell to move to
	cellToMove = pGrid->GetInput()->GetCellClicked();
	while(cellToMove.GetCellNum() == position.GetCellNum())
	{
		pGrid->GetOutput()->PrintMessage("The destination cell can't be the card's own cell, click on another!");
		cellToMove = pGrid->GetInput()->GetCellClicked();
	}
	
	pGrid->GetOutput()->ClearStatusBar();
}

Card* CardSix::CopyCard(CellPosition pos)
{
	CardSix* ptr = new CardSix(pos);
	ptr->cellToMove = cellToMove;
	return ptr;
}

void CardSix::Save(ofstream& OutFile) {
	OutFile << GetCardNumber() << " " << position.VCell() << " " << position.HCell() << " "  << cellToMove.GetCellNum() << endl;
}
void CardSix::Load(ifstream& Infile) {
	int vstart = -1, h = -1;
	
	int cellNum = cellToMove.GetCellNum();
	Infile >> vstart >> h >> cellNum;

	cellToMove = CellPosition(cellNum);
	position.SetHCell(h);
	position.SetVCell(vstart);
}
void CardSix::Apply(Grid* pGrid, Player * pPlayer) {
	
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	//2- moving the player to the cell chosen in the design mode
	pGrid->UpdatePlayerCell(pPlayer, cellToMove);
}