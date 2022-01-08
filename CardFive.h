#pragma once
#include "Card.h"
class CardFive :
	public Card
{
	
public :
	CardFive(CellPosition&);
	virtual void Apply(Grid* , Player* );
	Card* CopyCard(CellPosition);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	
};

