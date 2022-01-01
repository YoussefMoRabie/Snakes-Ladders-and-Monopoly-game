#include "CardThree.h"
#include "RollDiceAction.h"

CardThree::CardThree(const CellPosition& pos, ApplicationManager* pApp,const int num) : Card(pos), pManager(pApp) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number 
}

CardThree::~CardThree(void)
{
}

void CardThree::ReadCardParameters(Grid* pGrid)
{
	//This card has no parameters
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Call appmanager's ExecuteAction to execute an extra dice roll
	pManager->ExecuteAction(ROLL_DICE);
}
