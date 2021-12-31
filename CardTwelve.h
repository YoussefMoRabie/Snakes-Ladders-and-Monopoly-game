#pragma once
#include "Card.h"
class CardTwelve : public Card
{
public:
	CardTwelve(const CellPosition& pos); // A Constructor takes card position


	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual ~CardTwelve(); // A Virtual Destructor
};

