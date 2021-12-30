#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number 
}

void CardSeven::Apply(Grid * pGrid, Player * pPlayer)
{
	
}

CardSeven::~CardSeven()
{
}
