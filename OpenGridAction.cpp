#include "OpenGridAction.h"
#include"GameObject.h"
#include"Grid.h"
#include"Ladder.h"
#include "Snake.h"
#include"Card.h"
#include"Cell.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include"AddCardAction.h"
OpenGridAction::OpenGridAction(ApplicationManager* pApp) :Action(pApp) {

}



void OpenGridAction::ReadActionParameters() {

}
void OpenGridAction::Execute() {
	LoadGrid.open("Grid.txt");
	Grid* pGrid = pManager->GetGrid();
	int count;
	LoadGrid >> count;
	GameObject* pObj;
	for (int i = 0; i < count; i++) {
		pObj = new Ladder(-1, -1);
		pObj->Load(LoadGrid);
		pGrid->AddObjectToCell(pObj);
	}
	LoadGrid >> count;
	for (int i = 0; i < count; i++) {
		pObj = new Snake(-1, -1);
		pObj->Load(LoadGrid);
		pGrid->AddObjectToCell(pObj);
	}
	CellPosition pos;
	LoadGrid >> count;
	for (int i = 0; i < count; i++) {
		int num;
		LoadGrid >> num; 
		switch (num) {
		case1: pObj = new CardOne(pos, -1);
			break;
		case 2: pObj = new CardTwo(pos, -1);
			break;
		case 3: pObj = new CardThree(pos,pManager, -1);
			break;
		case 4: pObj = new CardFour(pos, -1);
			break;
		case 5: pObj = new CardFive(pos, -1);
			break;
		case 6: pObj = new CardSix(pos, -1);
			break;
		case 7: pObj = new CardSeven(pos, -1);
			break;
		case 8: pObj = new CardEight(pos, -1);
			break;
		case 9: pObj = new CardNine(pos, -1);
			break;
		case 10: pObj = new CardTen(pos, -1);
			break;
		case 11:pObj = new CardEleven(pos, -1);
			break;
		case 12: pObj = new CardTwelve(pos, -1);
			break;
		}
		pObj->Load(LoadGrid);
		pGrid->AddObjectToCell(pObj);

	}
	
		
	}
	
		
		
		

OpenGridAction:: ~OpenGridAction() {

}