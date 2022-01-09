#include "CardTen.h"
int CardTen::StationPrice = 0;

int CardTen::Fees = 0;

Player* CardTen::Owner = NULL;

CardTen::CardTen(const CellPosition & pos) : Card9_11(pos) // set the cell position of the card
{
	cardNumber = 10; // set the inherited cardNumber data member with the card number 

}
CardTen::~CardTen(void)
{
}
void CardTen::Save(ofstream& OutFile) {
	OutFile << GetCardNumber() << " " << position.VCell() << " " << position.HCell() << " " << StationPrice << " " << Fees << endl;
}
void CardTen::Load(ifstream& Infile) {
	int vstart = -1, h = -1;


	Infile >> vstart >> h >> StationPrice >> Fees;
	position.SetHCell(h);
	position.SetVCell(vstart);


}
void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	Card9_11::Apply(pGrid, pPlayer);
	BuyStation(  pGrid, pPlayer,  StationPrice, Owner);
	PayStation(  pGrid,  pPlayer, Fees,Owner);
}
void CardTen::ReadCardParameters(Grid* pGrid)
{


	// check if station Parameters take value before or not

	if (Fees != 0 || StationPrice != 0)
		return;


	// Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New Station Ten : Enter The amount of coins needed to  buy the cell ...");
	// Get a StationPrice
	StationPrice = pIn->GetInteger(pOut);
	while (StationPrice < 1)
	{
		pOut->PrintMessage("You entered an invalid Number: Plase enter The amount of coins needed to  buy the cell ...");
		StationPrice = pIn->GetInteger(pOut);
	}

	//---------------------------------------------------------------------------
	pOut->PrintMessage("New Station Ten : Enter The amount of coins needed  to pay fees to the player who owns the cell ...");
	// Get Fees
	Fees = pIn->GetInteger(pOut);
	while (Fees < 1)
	{
		pOut->PrintMessage("You entered an invalid Number: Plase enter The amount of coins needed  to pay fees to the player who owns the cell ...");
		Fees = pIn->GetInteger(pOut);
	}


	//  Clear the status bar
	pOut->ClearStatusBar();
}
Card* CardTen::CopyCard(CellPosition pos)
{
	CardTen* ptr = new CardTen(pos);
	ptr->Fees = Fees;
	ptr->StationPrice = StationPrice;
	ptr->Owner = Owner;
	return ptr;
}

void CardTen::SetOwner(Player* p)
{
	Owner = p;
}

Player* CardTen::GetOwner()
{
	return Owner;
}

int CardTen::GetStationPrice()
{
	return StationPrice;
}


