#include "CardFive.h"
CardFive::CardFive(CellPosition& pos, const int num) :Card(pos) {
	SetCardNumber(5);

}
void CardFive::Save(ofstream& OutFile) {
	OutFile << GetCardNumber() << " " << position.VCell() << " " << position.HCell() << endl;
}
void CardFive::Load(ifstream& Infile) {
	int vstart = -1, h = -1;
	
	Infile >> vstart >> h;
	position.SetHCell(h);
	position.SetVCell(vstart);
	

}
void CardFive::Apply(Grid* pGrid, Player* pPlayer) {
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	//
	int x = pPlayer->getJustRolledDice();
	//
	int newCell = pPlayer->GetCell()->GetCellPosition().GetCellNum() - x;
	pPlayer->MoveWithoutDice(pGrid, pPlayer->GetCell()->GetCellPosition().GetCellPositionFromNum(newCell));

}
