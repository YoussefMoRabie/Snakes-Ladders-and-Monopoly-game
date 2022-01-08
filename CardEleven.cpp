#include "CardEleven.h"
int CardEleven::StationPrice = 0;

int CardEleven::Fees = 0;

Player* CardEleven::Owner = NULL;

CardEleven::CardEleven(const CellPosition & pos) : Card9_11(pos) // set the cell position of the card
{
	cardNumber = 11; // set the inherited cardNumber data member with the card number 

}
CardEleven::~CardEleven(void)
{
}
void CardEleven::Save(ofstream& OutFile) {
	OutFile << GetCardNumber() << " " << position.VCell() << " " << position.HCell() << " " << StationPrice << " " << Fees << endl;
}
void CardEleven::Load(ifstream& Infile) {
	int vstart = -1, h = -1;


	Infile >> vstart >> h >> StationPrice >> Fees;
	position.SetHCell(h);
	position.SetVCell(vstart);


}
void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card9_11::Apply(pGrid, pPlayer);
	BuyStation(pGrid, pPlayer, StationPrice, Owner);
	PayStation(pGrid, pPlayer, Fees, Owner);
}
void CardEleven::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	if (Fees != 0 || StationPrice != 0)
		return;


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New Station No." + to_string(cardNumber) + " : Enter The amount of coins needed to  buy the cell ...");
	StationPrice = pIn->GetInteger(pOut);
	while (StationPrice < 1)
	{
		pOut->PrintMessage("You entered an invalid Number: Plase enter The amount of coins needed to  buy the cell ...");
		StationPrice = pIn->GetInteger(pOut);
	}

	//---------------------------------------------------------------------------
	pOut->PrintMessage("New Station No." + to_string(cardNumber) + " : Enter The amount of coins needed  to pay fees to the player who owns the cell ...");
	Fees = pIn->GetInteger(pOut);
	while (Fees < 1)
	{
		pOut->PrintMessage("You entered an invalid Number: Plase enter The amount of coins needed  to pay fees to the player who owns the cell ...");
		Fees = pIn->GetInteger(pOut);
	}


	// 3- Clear the status bar
	pOut->ClearStatusBar();
}
Card* CardEleven::CopyCard(CellPosition pos)
{
	CardEleven* ptr = new CardEleven(pos);
	ptr->Fees = Fees;
	ptr->StationPrice = StationPrice;
	ptr->Owner = Owner;
	return ptr;
}

void CardEleven::SetOwner(Player* p)
{
	Owner = p;
}

Player* CardEleven::GetOwner()
{
	return Owner;
}

int CardEleven::GetStationPrice()
{
	return StationPrice;
}




