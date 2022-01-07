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

		CellPosition CopiedPos = pIn->GetCellClicked(); //the postion of the card copied

		CopiedCard = pGrid->GetCell(CopiedPos.VCell(), CopiedPos.HCell())->HasCard(); //checks if the cell clicked contains a card

		if (CopiedCard == NULL) // if there is a card in the cell clicked
		{
			pGrid->PrintErrorMessage("No Cards Here! Click to continue...");
			return;
		}
		
	pOut->ClearStatusBar();


} // Reads parameters required for action to execute 
										 // (code depends on action type so virtual)

void CopyCardAction::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();

	

	pGrid->SetClipboard(CopiedCard);
	pManager->UpdateInterface();

	if (CopiedCard!= NULL)
	pGrid->PrintErrorMessage("Coppied!...");



}  // Executes action (code depends on action type so virtual)
CopyCardAction:: ~CopyCardAction() {

}