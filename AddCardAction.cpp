#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"

AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	cardNumber = -1;
	
	// Initializes the pManager pointer of Action with the passed pointer
}
void AddCardAction::setCardNum_Pos(int num,CellPosition pos) {
	cardNumber = num;
	cardPosition = pos;

}

void AddCardAction::ReadActionParameters() 
{	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	/// 1- Get a Pointer to the Input / Output Interfaces

	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	/// 2- Read the "cardNumber" parameter and set its data member

	// Read the cardNumber parameter
	pOut->PrintMessage("New Card: Please enter the Card number from 1 to 12 ...");
	cardNumber = pIn->GetInteger(pOut);
	while(cardNumber<1|| cardNumber>12)
	{
		pOut->PrintMessage("You entered an invalid number : Please enter the Card number from 1 to 12 ...");
		cardNumber = pIn->GetInteger(pOut);
	}


	/// 3- Read the "cardPosition" parameter (its cell position) and set its data member
	
	// Read the cardPosition parameter
	pOut->PrintMessage("New Card: Please click on its Cell (Except for Cell No. 1 to Cell No. 99) ...");
	
	cardPosition = pIn->GetCellClicked();
	
	while(!cardPosition.IsValidCell())
	{
		pOut->PrintMessage("You didn't click on the  Cell : Please click on Card Cell (Except for Cell No. 1 to Cell No. 99) ...");
	cardPosition = pIn->GetCellClicked();
}
	while (CellPosition::GetCellNumFromPosition(cardPosition) == 1 || CellPosition::GetCellNumFromPosition(cardPosition) == 99)
	{
		pOut->PrintMessage("You entered an invalid Cell : Please click on Card Cell (Except for Cell No. 1 to Cell No. 99) ...");
		cardPosition = pIn->GetCellClicked();
	}
	
	/// 4- Make the needed validations on the read parameters

	/// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddCardAction::Execute() 
{

	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	if (cardNumber == -1) {
		ReadActionParameters();
	}

	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card * pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition,1);
		break;
	case 2:
		pCard = new CardTwo(cardPosition,2);
		break;
	case 3:
		pCard = new CardThree(cardPosition, pManager,3);
		break;
	case 4:
		pCard = new CardFour(cardPosition,4);
		break;
	case 5:
		pCard = new CardFive(cardPosition,5);
		break;
	case 6:
		pCard = new CardSix(cardPosition,6);
		break;
	case 7:
		pCard = new CardSeven(cardPosition,7);
		break;
	case 8:
		pCard = new CardEight(cardPosition,8);
		break;
	case 9:
		pCard = new CardNine(cardPosition,9);
		break;
	case 10:
		pCard = new CardTen(cardPosition,10);
		break;
	case 11:
		pCard = new CardEleven(cardPosition,11);
		break;
	case 12:
		pCard = new CardTwelve(cardPosition,12);
		break;
		// A- Add the remaining cases

	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		/// A- We get a pointer to the Grid from the ApplicationManager

		Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

		/// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type

		pCard->ReadCardParameters(pGrid);

		/// C- Add the card object to the GameObject of its Cell:

		bool added = pGrid->AddObjectToCell(pCard);

		/// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}

	}
	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}


AddCardAction::~AddCardAction()
{
	

}
