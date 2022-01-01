#include "CopyCardAction.h"
#include"Grid.h"
#include"CellPosition.h"
CopyCardAction::CopyCardAction(ApplicationManager* pApp) :Action(pApp) {

}  

void CopyCardAction::ReadActionParameters() 
{

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	pOut->PrintMessage("Click On A Card...");
	CellPosition CopiedPos = pIn->GetCellClicked();
	CopiedCard = pGrid->GetCell(CopiedPos.VCell(), CopiedPos.HCell())->HasCard();

} // Reads parameters required for action to execute 
										 // (code depends on action type so virtual)

void CopyCardAction::Execute() 
{
	Grid* pGrid = pManager->GetGrid();
	ReadActionParameters();
	if (CopiedCard == NULL)
	{
		pGrid->PrintErrorMessage("No Cards Here! Click to Continue...");
		return;
	}

	pManager->GetGrid()->SetClipboard(CopiedCard);
	pManager->UpdateInterface();
	pManager->GetGrid()->PrintErrorMessage("Copied!...");



}  // Executes action (code depends on action type so virtual)
CopyCardAction:: ~CopyCardAction() 
{

}