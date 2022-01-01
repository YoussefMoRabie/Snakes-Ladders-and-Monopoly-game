#pragma once
#include "Card.h"
class CardTwelve : public Card
{
public:
	CardTwelve(const CellPosition& pos,const int); // A Constructor takes card position


	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual ~CardTwelve(); // A Virtual Destructor
};

