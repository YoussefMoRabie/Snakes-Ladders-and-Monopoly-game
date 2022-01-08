#pragma once
#include "Card.h"
class Card9_11 : public Card
{
protected:
	// Card9_11 Parameters:
	static int StationPrice;// The amount of coins needed to  buy the cell
	static int Fees; // The amount of coins needed  to pay fees to the player who owns the cell.
	static Player* Owner;
public :
	Card9_11(const CellPosition& pos); // A Constructor takes card position
	static void SetOwner(Player* p);
	static Player* GetOwner();
	static int GetStationPrice();
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount
	bool StationIsBought();
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	void BuyStation(Grid* pGrid, Player* pPlayer);
	void PayStation(Grid* pGrid, Player* pPlayer);

	virtual ~Card9_11(); // A Virtual Destructor

};

