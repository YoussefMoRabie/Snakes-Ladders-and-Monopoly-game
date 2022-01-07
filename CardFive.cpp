#include "CardFive.h"
CardFive::CardFive(CellPosition& pos) :Card(pos) {
	cardNumber= 5;

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
	//2- Calculating the justrolledDice value
	int x = pPlayer->getJustRolledDice();
	//returning the player number of cells equal to the just rolled dice

	int newCell = pPlayer->GetCell()->GetCellPosition().GetCellNum() - x;
	pGrid->UpdatePlayerCell(pPlayer, CellPosition::GetCellPositionFromNum(newCell));
}
