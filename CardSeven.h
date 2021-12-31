#pragma once
#include "Card.h"

/*
[ CardSeven ] Summary:
Restarts the game for the first player whose cell is after the current player in the grid.
Restarting the game for a player makes him go to cell number 1.
*/

class CardSeven : public Card
{
public:
	CardSeven(const CellPosition & pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual ~CardSeven(); // A Virtual Destructor


};
