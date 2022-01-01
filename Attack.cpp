#include "Attack.h"
#include "Grid.h"


Attack::Attack(Grid* pGr, Player* attacker) : pGrid(pGr), Attacker(attacker)
{
	// The constructor initializes the Player pointer data member
}

Player* Attack::getAttacker()
{
	return Attacker;
}

Attack::~Attack()
{
}