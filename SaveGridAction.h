#pragma once
#include "Action.h"
#include<fstream>
using namespace std;
class SaveGridAction :
    public Action
{
	ofstream saveGrid; //object of ofstream that saves the information of grid objects (ladder,snakes,cards) in text file

	public:

	SaveGridAction(ApplicationManager* pApp);

	virtual void ReadActionParameters() ; 
	virtual void Execute() ;  
	virtual ~SaveGridAction();
};

