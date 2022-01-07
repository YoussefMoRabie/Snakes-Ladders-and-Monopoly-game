#pragma once
#include "Card.h"

// [ CardEight ] Summary:
	// This card is a prison. 
	// When a player stops at a Card8 cell, the player should choose either to pay specific amount of coins to go out of the prison, or stay in prison and not playing for 3 turns.
	// Input data in design mode: i.The amount of coins needed to go out of the prison

 

class CardEight : public Card
{
	
		// CardEight Parameters:
		int GoOut; // The amount of coins needed to go out of the prison

	public:
		CardEight(const CellPosition & pos, const int num); // A Constructor takes card position

		virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardEight which is: GoOut

		virtual void Apply(Grid* pGrid, Player* pPlayer); 
		virtual void Save(ofstream& OutFile);
		virtual void Load(ifstream& Infile);

		virtual ~CardEight(); // A Virtual Destructor
	


};

