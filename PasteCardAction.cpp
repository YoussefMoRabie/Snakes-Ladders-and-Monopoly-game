#include "PasteCardAction.h"
#include"Card.h"
#include"Grid.h"
#include"AddCardAction.h"
PasteCardAction::PasteCardAction(ApplicationManager* pApp) :Action(pApp) {
	
}  // Constructor

void PasteCardAction::ReadActionParameters() {

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click On your selected Cell...");

	PasteTo = pIn->GetCellClicked();//gets the postion to paste in
	
	
	pOut->ClearStatusBar();
 }

void PasteCardAction::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (pGrid->GetClipboard() != NULL) //checks if there is card in the clipboard
	{
		int num=pGrid->GetClipboard()->GetCardNumber();
		AddCardAction* ptr=new AddCardAction(pManager); //add a new card same to the one in the clipboard
		ptr->setCardNum_Pos(num, PasteTo);
		ptr->Execute();
	}

		


	else 
		pManager->GetGrid()->PrintErrorMessage("No Cards In Clipboard! click to continue...");
	

	

	
	
} // Executes action (code depends on action type so virtual)

PasteCardAction:: ~PasteCardAction() {


}