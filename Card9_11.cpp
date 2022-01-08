#include "Card9_11.h"


Card9_11::Card9_11(const CellPosition& pos) : Card(pos) // set the cell position of the card
{}
Card9_11::~Card9_11(void)
{
}



bool Card9_11::StationIsBought(Player* Owner)
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


void Card9_11::BuyStation(Grid* pGrid, Player* pPlayer, int StationPrice, Player*& Owner)
{
	if (!StationIsBought( Owner))
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("Do you want to buy this station for " + to_string(StationPrice) + " coins? (Y / N)");
		string x = pIn->GetString(pOut);
		while (x != "y" && x != "Y" && x != "N" && x != "n")
		{
			pOut->PrintMessage("You entered an invalid Charcter: Do you want to buy this station? (Y / N) ...");
			string x = pIn->GetString(pOut);
		}
		if (x == "y" || x == "Y")
		{
			if (pPlayer->GetWallet() < StationPrice)
				pOut->PrintMessage("You can't buy this station because you don't have enough coins in wallet");
			else
			{
				pPlayer->SetWallet(pPlayer->GetWallet() - StationPrice);
				Owner = pPlayer;
				pOut->PrintMessage("Congratulations, you have purchased that station");
			}
		}
		pOut->ClearStatusBar();
	}

}

void Card9_11::PayStation(Grid* pGrid, Player* pPlayer,int Fees, Player* Owner)
{
	if (StationIsBought(Owner))
		if (Owner != pPlayer)
		{
			Output* pOut = pGrid->GetOutput();
			Input* pIn = pGrid->GetInput();
			pGrid->PrintErrorMessage("Player NO." + to_string(pPlayer->getPlayerNum()) + " has to pay " + to_string(Fees) + " coins to the player NO." + to_string(Owner->getPlayerNum()) + " who owns the cell.");
			pPlayer->SetWallet(pPlayer->GetWallet() - Fees);
			Owner->SetWallet(Owner->GetWallet() + Fees);
			pOut->ClearStatusBar();

		}
}
void Card9_11::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
}
