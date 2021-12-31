#pragma once
#include "Card.h"
class CardSix :public Card
{
	int cellNumToMove;
public:
	CardSix(CellPosition&);
	virtual void Apply(Grid*, Player*);
	virtual void ReadCardParameters(Grid * );
};

