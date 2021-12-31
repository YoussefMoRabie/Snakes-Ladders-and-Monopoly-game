#include "CardFive.h"
CardFive::CardFive(CellPosition& pos) :Card(pos) {
	SetCardNumber(5);

}

void CardFive::Apply(Grid* pGrid, Player* pPlayer) {
	int x = pPlayer->getJustRolledDice();
	
	pPlayer->Move(pGrid, -x);

}
