#pragma once
#include "Card.h"
class CardSix :public Card
{
	CellPosition cellToMove; //the chosen cell to move to

public:
	CardSix(CellPosition&);
	virtual void Apply(Grid*, Player*);
	virtual void ReadCardParameters(Grid * );
	Card* CopyCard(CellPosition);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};

