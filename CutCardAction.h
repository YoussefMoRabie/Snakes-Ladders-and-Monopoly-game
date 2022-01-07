#pragma once
#include "Action.h"
#include"Card.h"
class CutCardAction :public Action
{
	CellPosition CuttedPos; //the postion of the card to be cutted
	Card* CuttedCard; //point to the card to be cutted (if exist)
	
public:

	CutCardAction(ApplicationManager* pApp);  // Constructor

	virtual void ReadActionParameters(); // Reads parameters required for action to execute 
											 // (code depends on action type so virtual)

	virtual void Execute();  // Executes action (code depends on action type so virtual)

	virtual ~CutCardAction();
};