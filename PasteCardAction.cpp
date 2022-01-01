#include "PasteCardAction.h"
#include"Card.h"
#include"Grid.h"
PasteCardAction::PasteCardAction(ApplicationManager* pApp) :Action(pApp) {
	
}  // Constructor

void PasteCardAction::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click On your selected Cell...");
	PasteTo = pIn->GetCellClicked();
	pOut->ClearStatusBar();
 }

void PasteCardAction::Execute() {
	ReadActionParameters();
	Card* PastedCard = pManager->GetGrid()->GetClipboard();
	if (PastedCard == NULL)
		pManager->GetGrid()->PrintErrorMessage("No Cards In Clipboard!...");
	else {
		if (PastedCard->setPos(PasteTo))

			pManager->GetGrid()->AddObjectToCell((GameObject*)PastedCard);
		else
		{
			pManager->GetGrid()->PrintErrorMessage("Can not Paste here....");
		}
	}
} // Executes action (code depends on action type so virtual)

PasteCardAction:: ~PasteCardAction() {


}