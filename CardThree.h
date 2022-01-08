#pragma once

#include "Card.h"
#include "ApplicationManager.h"

class CardThree : public Card
{
	ApplicationManager* pManager; //This card needs to utilize Appmanager to execute an extra RollDiceAction

public:
	CardThree(const CellPosition& pos, ApplicationManager* pApp); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardThree which is: walletAmount
	Card* CopyCard(CellPosition);

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual ~CardThree(); // A Virtual Destructor
};

