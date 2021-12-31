#include "CardNine.h"
int CardNine::StationPrice = 0;

int CardNine::Fees = 0;

Player* CardNine::Owner = NULL;

CardNine::CardNine(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number 

}
CardNine::~CardNine(void)
{
}
void CardNine::SetOwner(Player * p)
{
	Owner = p;
}

Player * CardNine::GetOwner()
{
	return Owner;
}

int CardNine::GetStationPrice()
{
	return StationPrice;
}

void CardNine::ReadCardParameters(Grid * pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output *pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	pOut->PrintMessage("New CardNine: Enter The amount of coins needed to  buy the cell ...");
	StationPrice = pIn->GetInteger(pOut);
	while (StationPrice < 1)
	{
		pOut->PrintMessage("You entered an invalid Number: Plase enter The amount of coins needed to  buy the cell ...");
		StationPrice = pIn->GetInteger(pOut);
	}

	//---------------------------------------------------------------------------
	pOut->PrintMessage("New CardNine: Enter The amount of coins needed  to pay fees to the player who owns the cell ...");
	Fees = pIn->GetInteger(pOut);
	while (Fees < 1)
	{
		pOut->PrintMessage("You entered an invalid Number: Plase enter The amount of coins needed  to pay fees to the player who owns the cell ...");
		Fees = pIn->GetInteger(pOut);
	}


	// 3- Clear the status bar
	pOut->ClearStatusBar();
}
bool CardNine::StationIsBought()
{
	if (Owner == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}


void CardNine::BuyStation(Grid * pGrid, Player * pPlayer)
{
	if (!StationIsBought())
	{
		Output *pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("Do you want to buy this station for "+ to_string(StationPrice) +" coin ? (Y / N)");
		string x = pIn->GetString(pOut);
		while (x !="y"&&x != "Y"&&x != "N"&&x != "n")
		{
			pOut->PrintMessage("You entered an invalid Charcter: Do you want to buy this station ? (Y / N) ...");
			string x = pIn->GetString(pOut);
		}
		if (x == "y" || x == "Y")
		{
			if (pPlayer->GetWallet() < StationPrice)
				pOut->PrintMessage("You can't buy this station because you don't have enough coins in wallet");
			else
				pPlayer->SetWallet(pPlayer->GetWallet() - StationPrice);
			SetOwner(pPlayer);
			pOut->PrintMessage("Congratulations, you have purchased that station");
		}
		pOut->ClearStatusBar();
	}

}

void CardNine::PayStation(Grid * pGrid, Player * pPlayer)
{
	if(StationIsBought())
	if (Owner != pPlayer)
	{
		Output *pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("Player NO." + to_string(pPlayer->getPlayerNum()) + " has to pay "+ to_string(Fees)+" coins to the player NO." + to_string(Owner->getPlayerNum()) + " who owns the cell.");
		pPlayer->SetWallet(pPlayer->GetWallet() - Fees);
		Owner->SetWallet(Owner->GetWallet() + Fees);
		pOut->ClearStatusBar();

	}
}
void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	BuyStation(pGrid, pPlayer);
	PayStation(pGrid, pPlayer);
}
