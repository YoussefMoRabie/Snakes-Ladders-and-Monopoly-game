#include "OpenGridAction.h"
#include"GameObject.h"
#include"Grid.h"
#include"Ladder.h"
#include "Snake.h"
#include"Card.h"
#include"Cell.h"
#include"AddCardAction.h"
OpenGridAction::OpenGridAction(ApplicationManager* pApp) :Action(pApp) {

}



void OpenGridAction::ReadActionParameters() {

}
void OpenGridAction::Execute() {
	LoadGrid.open("Grid.txt");
	char typ;
	int num1, num2, num3;
	GameObject* pObj = NULL;;
	while (!LoadGrid.eof()) {
		LoadGrid >> num1 >> num2 >> num3 >> typ;
		switch (typ) {
		case 'L': {CellPosition start(num1, num3);
			CellPosition end(num2, num3);
			pObj = new Ladder(start, end);
			break; }
		case 'S': {
			CellPosition start(num1, num3);
			CellPosition end(num2, num3);
			pObj = new Snake(start, end);
			break;
		}
		case 'C': {
			CellPosition start(num1, num2);

			AddCardAction* ptr = new AddCardAction(pManager);
			ptr->setCardNum_Pos(num3, start);
			ptr->Execute();
			
	
			break;
		}

		}
		Grid* pGrid = pManager->GetGrid();


		pGrid->AddObjectToCell(pObj);
	}
	
		
		
		
}
OpenGridAction:: ~OpenGridAction() {

}