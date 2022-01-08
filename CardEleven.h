#pragma once
#include "Card9_11.h"
class CardEleven :public Card9_11
{
	static int StationPrice;// The amount of coins needed to  buy the cell
	static int Fees; // The amount of coins needed  to pay fees to the player who owns the cell.
	static Player* Owner;
public:
	CardEleven(const CellPosition & pos); // A Constructor takes card position
	virtual ~CardEleven(); // A Virtual Destructor
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount
	static void SetOwner(Player* p);
	static Player* GetOwner();
	static int GetStationPrice();
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	Card* CopyCard(CellPosition);

};

