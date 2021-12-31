#include "ToDesignModeAction.h"
#include"Grid.h"

ToDesignModeAction::ToDesignModeAction(ApplicationManager* pApp) :Action(pApp) {

}
ToDesignModeAction::~ToDesignModeAction() {

}
void ToDesignModeAction::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreateDesignModeToolBar();
}
void ToDesignModeAction::Execute() {
	ReadActionParameters();
}
