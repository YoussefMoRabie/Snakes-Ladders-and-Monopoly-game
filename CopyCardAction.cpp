#include "CopyCardAction.h"
#include"Grid.h"
#include"CellPosition.h"
CopyCardAction::CopyCardAction(ApplicationManager* pApp) :Action(pApp) {

}  

void CopyCardAction::ReadActionParameters() {

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	

		pOut->PrintMessage("Click On A Card...");
		CellPosition CopiedPos = pIn->GetCellClicked();
		CopiedCard = pGrid->GetCell(CopiedPos.VCell(), CopiedPos.HCell())->HasCard();
		while (CopiedCard == NULL) {
			pGrid->PrintErrorMessage("No Cards Here! Click on a Card...");
			CellPosition CopiedPos = pIn->GetCellClicked();
			CopiedCard = pGrid->GetCell(CopiedPos.VCell(), CopiedPos.HCell())->HasCard();
	 }
	pOut->ClearStatusBar();


} // Reads parameters required for action to execute 
										 // (code depends on action type so virtual)

void CopyCardAction::Execute() {
	ReadActionParameters();
	pManager->GetGrid()->SetClipboard(CopiedCard);
	pManager->UpdateInterface();
	pManager->GetGrid()->PrintErrorMessage("Coppied!...");



}  // Executes action (code depends on action type so virtual)
CopyCardAction:: ~CopyCardAction() {

}