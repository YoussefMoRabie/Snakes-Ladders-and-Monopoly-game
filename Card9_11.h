#pragma once
#include "Card.h"
class Card9_11 : public Card
{
public :
	Card9_11(const CellPosition& pos); // A Constructor takes card position
	
	virtual void ReadCardParameters(Grid* pGrid)=0; // Reads the parameters 

	Card* CopyCard(CellPosition)=0;
	
	virtual void Apply(Grid* pGrid, Player* pPlayer);


	virtual void Save(ofstream& OutFile)=0;
	virtual void Load(ifstream& Infile)=0;
	void BuyStation(Grid* pGrid, Player* pPlayer, int StationPrice, Player*& Owner);
	void PayStation(Grid* pGrid, Player* pPlayer, int Fees, Player* Owner);
	bool StationIsBought(Player* Owner);

	virtual ~Card9_11(); // A Virtual Destructor

};

