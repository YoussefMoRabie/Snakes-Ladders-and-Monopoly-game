#include "CardSeven.h"
#include "RollDiceAction.h"

CardSeven::CardSeven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number 
}

CardSeven::~CardSeven(void)
{
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{
	//This card has no parameters
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	//2- 
	CellPosition *NextPlayerCell = pGrid->GetNextCellWithPlayers(position);
	//3-
	if (NextPlayerCell != NULL)
	{
		pGrid->RestartPlayersOnCell(NextPlayerCell);
	}
}
