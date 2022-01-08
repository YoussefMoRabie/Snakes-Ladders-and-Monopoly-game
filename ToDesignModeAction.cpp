#include "ToDesignModeAction.h"
#include"Grid.h"

ToDesignModeAction::ToDesignModeAction(ApplicationManager* pApp) :Action(pApp) {

}
ToDesignModeAction::~ToDesignModeAction() {

}
void ToDesignModeAction::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput(); //gets pointer to the output
	pOut->CreateDesignModeToolBar(); // creates the design mode tool bar
}
void ToDesignModeAction::Execute() {
	ReadActionParameters();
}
