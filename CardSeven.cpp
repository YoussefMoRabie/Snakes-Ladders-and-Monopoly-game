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

Card* CardSeven::CopyCard(CellPosition pos)
{
	CardSeven* ptr = new CardSeven(pos);
	return ptr;
}

void CardSeven::Save(ofstream& OutFile) {
	OutFile  << GetCardNumber() << " " << position.VCell() << " " << position.HCell()  << endl;
}
void CardSeven::Load(ifstream& Infile) {
	int vstart = -1, h = -1;
	
	Infile >> vstart >> h;
	position.SetHCell(h);
	position.SetVCell(vstart);
	

}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	//2- find the next cell that has player(s) on it
	CellPosition NextPlayerCell = pGrid->GetNextCellWithPlayers(position);
	//3- move the player(s) back to the first cell
	if (&NextPlayerCell != NULL)
	{
		pGrid->RestartPlayersOnCell(&NextPlayerCell);
	}
}
