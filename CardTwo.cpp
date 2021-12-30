#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (1 here)
}

CardTwo::~CardTwo(void)
{
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
	//This card has no parameters
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Get the Player's next ladder
	Ladder* nextLadder = pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition());
	// 3- If a nextLadder exists, move the player to it
	if (nextLadder != NULL) {

	}
		
}
