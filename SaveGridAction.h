#pragma once
#include "Action.h"
#include<fstream>
using namespace std;
class SaveGridAction :
    public Action
{
	ofstream saveGrid;
	public:
	SaveGridAction(ApplicationManager* pApp);

	

	virtual void ReadActionParameters() ; 
	virtual void Execute() ;  
	virtual ~SaveGridAction();
};

