#pragma once
#include "Action.h"
#include<fstream>
class OpenGridAction :
    public Action
{
	ifstream LoadGrid;  //object of ifstrean to read the information of the grid objects

public:
	OpenGridAction(ApplicationManager* pApp);



	virtual void ReadActionParameters() ;
	virtual void Execute() ;
	virtual ~OpenGridAction();
};

