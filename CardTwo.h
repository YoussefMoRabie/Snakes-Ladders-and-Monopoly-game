#pragma once

#include "Card.h"

class CardTwo : public Card
{
public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTwo which is: walletAmount
	Card* CopyCard(CellPosition);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	// Applies the effect of CardTwo on the passed Player
		// by decrementing the player's wallet by the walletAmount data member

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual ~CardTwo(); // A Virtual Destructor
};

