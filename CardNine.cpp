#include "CardNine.h"
int CardNine::StationPrice = 0;

int CardNine::Fees = 0;

Player* CardNine::Owner = NULL;

CardNine::CardNine(const CellPosition & pos) : Card9_11(pos) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number 

}
CardNine::~CardNine(void)
{
}
void CardNine::Save(ofstream& OutFile) {
	OutFile << GetCardNumber() << " " << position.VCell() << " " << position.HCell() << " " << StationPrice << " " << Fees << endl;
}
void CardNine::Load(ifstream& Infile) {
	int vstart = -1, h = -1;


	Infile >> vstart >> h >> StationPrice >> Fees;
	position.SetHCell(h);
	position.SetVCell(vstart);


}
void CardNine::ReadCardParameters(Grid* pGrid)
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
void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	Card9_11::Apply(pGrid, pPlayer);
	BuyStation(pGrid, pPlayer, StationPrice, Owner);
	PayStation(pGrid, pPlayer, Fees, Owner);
}
Card* CardNine::CopyCard(CellPosition pos)
{
	CardNine* ptr = new CardNine(pos);
	ptr->Fees = Fees;
	ptr->StationPrice = StationPrice;
	ptr->Owner = Owner;
	return ptr;
}

void CardNine::SetOwner(Player* p)
{
	Owner = p;
}

Player* CardNine::GetOwner()
{
	return Owner;
}

int CardNine::GetStationPrice()
{
	return StationPrice;
}



