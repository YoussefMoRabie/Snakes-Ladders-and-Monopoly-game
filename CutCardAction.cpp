#include "CutCardAction.h"
#include"Grid.h"
#include"CellPosition.h"
CutCardAction::CutCardAction(ApplicationManager* pApp) :Action(pApp) {
	
}

void CutCardAction::ReadActionParameters() {

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	
		pOut->PrintMessage("Click On A Card...");
		CuttedPos = pIn->GetCellClicked();

		CuttedCard = pGrid->GetCell(CuttedPos.VCell(), CuttedPos.HCell())->HasCard();

		if(CuttedCard == NULL) //if there is no card in the cell
		{
			
				pGrid->PrintErrorMessage("No Cards Here! Click on a Card...");
				
				return;
			
	 }
	pOut->ClearStatusBar();


} // Reads parameters required for action to execute 
										 // (code depends on action type so virtual)

void CutCardAction::Execute() {
	ReadActionParameters();
	
	if (CuttedCard != NULL) // if there card on the cell clicked
	{
		pManager->GetGrid()->SetClipboard(CuttedCard);
		pManager->GetGrid()->RemoveObjectFromCell(CuttedPos);
		pManager->UpdateInterface();
		pManager->GetGrid()->PrintErrorMessage("Cutted!...");

	}

}  // Executes action (code depends on action type so virtual)
CutCardAction:: ~CutCardAction() {

}