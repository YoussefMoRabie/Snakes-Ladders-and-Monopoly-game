#pragma once
#include "Card9_11.h"


	class CardTen : public Card9_11
{
	static int StationPrice;// The amount of coins needed to  buy the cell
	static int Fees; // The amount of coins needed  to pay fees to the player who owns the cell.
	static Player* Owner;
	
public:
	CardTen(const CellPosition & pos); // A Constructor takes card position
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount
	static void SetOwner(Player* p);
	static Player* GetOwner();
	static int GetStationPrice();
	virtual ~CardTen(); // A Virtual Destructor
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	Card* CopyCard(CellPosition);

};

