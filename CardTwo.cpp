#include "CardTwo.h"
#include "Ladder.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number 
}

CardTwo::~CardTwo(void)
{
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
	//This card has no parameters
}

Card* CardTwo::CopyCard(CellPosition pos)
{
	CardTwo* ptr = new CardTwo(pos);
	return ptr;
}

void CardTwo:: Save(ofstream& OutFile) {
	OutFile << GetCardNumber() << " " << position.VCell() << " " << position.HCell() << endl;
}
void CardTwo::Load(ifstream& Infile) {
	int vstart = -1, h = -1;
	
	Infile >> vstart >> h;
	position.SetHCell(h);
	position.SetVCell(vstart);
	

}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Get the Player's next ladder
	Ladder* nextLadder = pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition());
	// 3- If a nextLadder exists, move the player to it then applay it
	if (nextLadder != NULL) {
		pGrid->UpdatePlayerCell(pPlayer, nextLadder->GetPosition());
		nextLadder->Apply(pGrid, pPlayer);
	}
		
}
