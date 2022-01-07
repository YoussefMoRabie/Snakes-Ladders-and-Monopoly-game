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

	LoadGrid.open("Grid.txt"); //opens the grid text file to read

	pManager->GetGrid()->GetOutput()->ClearGridArea();
	Grid* pGrid = pManager->GetGrid();
	int count; //count of the objects (ladder,snakes,cards)
	LoadGrid >> count;

	GameObject* pObj; 
	for (int i = 0; i < count; i++) {
		pObj = new Ladder(-1, -1); //empty object of ladder
		pObj->Load(LoadGrid);
		pGrid->AddObjectToCell(pObj); //add the read ladder to the grid
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
		int num; //Card number
		LoadGrid >> num; 
		switch (num)  //determine the card typr, then create an empty object of it
		{
		case1: pObj = new CardOne(pos);
			break;
		case 2: pObj = new CardTwo(pos);
			break;
		case 3: pObj = new CardThree(pos,pManager);
			break;
		case 4: pObj = new CardFour(pos);
			break;
		case 5: pObj = new CardFive(pos);
			break;
		case 6: pObj = new CardSix(pos);
			break;
		case 7: pObj = new CardSeven(pos);
			break;
		case 8: pObj = new CardEight(pos);
			break;
		case 9: pObj = new CardNine(pos);
			break;
		case 10: pObj = new CardTen(pos);
			break;
		case 11:pObj = new CardEleven(pos);
			break;
		case 12: pObj = new CardTwelve(pos);
			break;
		}

		pObj->Load(LoadGrid); // loads the card information
		pGrid->AddObjectToCell(pObj); //adds the card to the grid

	}
	
		
	}
	
		
		
		

OpenGridAction:: ~OpenGridAction() {

}