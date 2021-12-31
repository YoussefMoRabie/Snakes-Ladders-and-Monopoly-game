#include "ToPlayModeAction.h"

#include"Grid.h"

ToPlayModeAction::ToPlayModeAction(ApplicationManager* pApp) :Action(pApp) {

}
ToPlayModeAction::~ToPlayModeAction() {

}
void ToPlayModeAction::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreateDesignModeToolBar();
}
void ToPlayModeAction::Execute() {
	ReadActionParameters();
}
