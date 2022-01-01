#pragma once
#include "Card.h"
class CardSix :public Card
{
	int cellNumToMove;
public:
	CardSix(CellPosition&, const int num);
	virtual void Apply(Grid*, Player*);
	virtual void ReadCardParameters(Grid * );
};

