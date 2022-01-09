#include "CardThree.h"

CardThree::CardThree(const CellPosition& pos, ApplicationManager* pApp) : Card(pos), pManager(pApp) // set the cell position of the card
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
void CardThree::Save(ofstream& OutFile) {
	OutFile <<GetCardNumber()  << " "  << position.VCell() << " " << position.HCell() << endl;
}
void CardThree::Load(ifstream& Infile) {
	int vstart = -1, h = -1;
	
	Infile >> vstart >> h;
	position.SetHCell(h);
	position.SetVCell(vstart);
	

}

Card* CardThree::CopyCard(CellPosition pos)
{
	CardThree* ptr = new CardThree(pos, pManager);
	return ptr;
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Call appmanager's ExecuteAction to execute an extra dice roll
	pGrid->PrintErrorMessage("You get an extra dice roll, click to continue...");
	pManager->ExecuteAction(ROLL_DICE);
}
