#pragma once
#include "Card.h"
class CardFive :
	public Card
{
	
public :
	CardFive(CellPosition&, const int num);
	virtual void Apply(Grid* , Player* );
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	
};

