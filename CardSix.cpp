#include "CardSix.h"
CardSix::CardSix(CellPosition& p, const int num) :Card(p) {
	SetCardNumber(6);
}
void CardSix::ReadCardParameters(Grid * pGrid) {
	pGrid->GetOutput()->PrintMessage("Please, Click on a Cell....");
	pGrid->GetOutput()->PrintMessage("Please, Click on the destination cell....");
	cellNumToMove= pGrid->GetInput()->GetCellClicked().GetCellNum();
}
void CardSix::Save(ofstream& OutFile) {
	OutFile << GetCardNumber() << " " << position.VCell() << " " << position.HCell() << " "  << cellNumToMove<< endl;
}
void CardSix::Load(ifstream& Infile) {
	int vstart = -1, h = -1;
	int cellTomove = -1;
	
	Infile >> vstart >> h>>cellNumToMove;
	position.SetHCell(h);
	position.SetVCell(vstart);
	

}
void CardSix::Apply(Grid* pGrid, Player * pPlayer) {
	
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	pPlayer->MoveWithoutDice(pGrid, pPlayer->GetCell()->GetCellPosition().GetCellPositionFromNum(cellNumToMove));
}