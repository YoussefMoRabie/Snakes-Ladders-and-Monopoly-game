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
	PasteTo = pIn->GetCellClicked();
	if (pGrid->GetCell(PasteTo.VCell(), PasteTo.HCell())->GetGameObject() != NULL) {
		pManager->GetGrid()->PrintErrorMessage("Can not Paste here, Click to continue....");
		return;
	}
	pOut->ClearStatusBar();
 }

void PasteCardAction::Execute() {
	ReadActionParameters();
	if (pManager->GetGrid()->GetClipboard() != NULL) {
		int num=pManager->GetGrid()->GetClipboard()->GetCardNumber();
		AddCardAction* ptr=new AddCardAction(pManager);
		ptr->setCardNum_Pos(num, PasteTo);
		ptr->Execute();
	}

		


	else 
		pManager->GetGrid()->PrintErrorMessage("No Cards In Clipboard! click to continue...");
	

	

	
	
} // Executes action (code depends on action type so virtual)

PasteCardAction:: ~PasteCardAction() {


}