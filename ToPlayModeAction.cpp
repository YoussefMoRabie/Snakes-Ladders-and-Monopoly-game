#include "ToPlayModeAction.h"

#include"Grid.h"

ToPlayModeAction::ToPlayModeAction(ApplicationManager* pApp) :Action(pApp) {

}
ToPlayModeAction::~ToPlayModeAction() {

}
void ToPlayModeAction::ReadActionParameters() 
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput(); //gets pointer to the output
	pOut->CreatePlayModeToolBar();  //creates the play mode tool bar
}
void ToPlayModeAction::Execute() {
	ReadActionParameters();
}
