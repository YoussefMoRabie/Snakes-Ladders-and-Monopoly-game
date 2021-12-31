#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 12; // set the inherited cardNumber data member with the card number 
}

CardTwelve::~CardTwelve(void)
{
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	//  Get a Pointer to the Input / Output Interfaces from the Grid
	Output *pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	int p1=0, p2=0, p3=0;
	if(pPlayer == CardNine::GetOwner())
	{
		p1 = CardNine::GetStationPrice();
	}
	if (pPlayer == CardTen::GetOwner())
	{
		p2 = CardTen::GetStationPrice();
	}
	if (pPlayer == CardEleven::GetOwner())
	{
		p3 = CardEleven::GetStationPrice();
	}
	if (p1 == 0 && p2 == 0 && p3 == 0)
	{
		pGrid->PrintErrorMessage("You don't have Station to lose ...");
		return;
	}
	if (p1 >= p2 && p1 >= p3)
	{
		CardNine::SetOwner(pGrid->GetPlayerWithLeastMoney(pPlayer));
		pOut->PrintMessage("Now Player NO."+ to_string((pGrid->GetPlayerWithLeastMoney(pPlayer))->getPlayerNum) +"take station NO.9 from Player NO."+ to_string(pPlayer->getPlayerNum) +"  ...");
	}
	else if (p2 >= p1 && p2 >= p3)
	{
		CardTen::SetOwner(pGrid->GetPlayerWithLeastMoney(pPlayer));
		pOut->PrintMessage("Now Player NO." + to_string((pGrid->GetPlayerWithLeastMoney(pPlayer))->getPlayerNum) + "take station NO.10 from Player NO." + to_string(pPlayer->getPlayerNum) + "  ...");

	}
	else if (p3 >= p1 && p3 >= p2)
	{
		CardEleven::SetOwner(pGrid->GetPlayerWithLeastMoney(pPlayer));
		pOut->PrintMessage("Now Player NO." + to_string((pGrid->GetPlayerWithLeastMoney(pPlayer))->getPlayerNum) + "take station NO.11 from Player NO." + to_string(pPlayer->getPlayerNum) + "  ...");

	}
	pOut->ClearStatusBar();

}