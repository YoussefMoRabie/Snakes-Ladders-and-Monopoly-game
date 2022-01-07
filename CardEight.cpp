#include "CardEight.h"
CardEight::CardEight(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number 
}

CardEight::~CardEight(void)
{
}
void CardEight::Save(ofstream& OutFile) {
	OutFile << " " << GetCardNumber() << position.VCell() << " " << position.HCell()  <<" " << GoOut << endl;
}
void CardEight::Load(ifstream& Infile) {
	int vstart = -1, h = -1;
	
	Infile >> vstart >> h>>GoOut;
	position.SetHCell(h);
	position.SetVCell(vstart);
	

}
void CardEight::ReadCardParameters(Grid * pGrid)
{




	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output *pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New CardEight : Enter The amount of coins needed to go out of the prison ...");
	GoOut = pIn->GetInteger(pOut);
	//Check if the prison release fee is valid
	while (GoOut < 1)
	{
		pOut->PrintMessage("You entered an invalid Number: Plase enter The amount of coins needed to go out of the prison ...");
		GoOut = pIn->GetInteger(pOut);
	}


	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number

	Card::Apply(pGrid, pPlayer);


	Output *pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Now you have to choose 1- Pay " + to_string(GoOut) + " coins and continue playing 2- Don't play for 3 turns ...");
	int x = pIn->GetInteger(pOut);
	while (x != 1&&x!=2)
	{
		pOut->PrintMessage("Incorrect selection, please choose again: 1- Pay " + to_string(GoOut) + " coins and continue playing 2- Don't play for 3 turns...");
		GoOut = pIn->GetInteger(pOut);
	}
	
	// 2- Decrement the wallet of pPlayer by the GoOut data member of CardEight
	if(x==1)
	pPlayer->SetWallet(pPlayer->GetWallet() - GoOut);
	// 3- Make the turnskip of the player who stood on the card = 3
	if(x==2)
	pPlayer->setTurnsToSkip(3);
	pOut->ClearStatusBar();

}
