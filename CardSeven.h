#pragma once

#include "Card.h"
#include "ApplicationManager.h"

/*
[ CardSeven ] Summary:
Restarts the game for the first player whose cell is after the current player in the grid.
Restarting the game for a player makes him go to cell number 1.
*/


class CardSeven : public Card
{
	ApplicationManager* pManager; //This card needs to utilize Appmanager to execute an extra RollDiceAction

public:
	CardSeven(const CellPosition& pos, const int num); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardSeven which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSeven on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~CardSeven(); // A Virtual Destructor
};

