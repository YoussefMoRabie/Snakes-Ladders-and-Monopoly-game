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

<<<<<<< HEAD
		


	else 
		pManager->GetGrid()->PrintErrorMessage("No Cards In Clipboard! click to continue...");
	

	

	
	
=======
			pManager->GetGrid()->AddObjectToCell((GameObject*)PastedCard);
		else
		{
			pManager->GetGrid()->PrintErrorMessage("Can not Paste here....");
		}
	}
>>>>>>> ee8da039276902a1ebc915462b1e345201278eda
} // Executes action (code depends on action type so virtual)

PasteCardAction:: ~PasteCardAction() {


}