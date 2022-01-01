#pragma once
#include "Player.h"

// Base Class of All Types of Attacks (ice, Fire, Poison, Lighting)
class Attack
{
protected:
	Player* Attacker;		// The player who is using their special attack

	Grid* pGrid;            // Attacks need Grid to function 
public:

	Attack(Grid* pGrid, Player* attacker);

	Player* getAttacker();

	virtual void Execute() = 0;

	virtual ~Attack();  // Virtual Destructor
};

