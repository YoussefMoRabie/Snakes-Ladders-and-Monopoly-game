#include "Fire.h"

Fire::Fire(Grid* pGr, Player* attacker) : Attack(pGr, attacker)
{
	AttackTarget = NULL;
}

void Fire::ReadAttackTarget()
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	while (AttackTarget == NULL)
	{
		pOut->PrintMessage("Enter the number of the player you want to attack (from 0 to " + to_string(MaxPlayerCount - 1) + ")");
		int targetNum = pIn->GetInteger(pOut);
		pOut->ClearStatusBar();

		// get the player pointer with the num the user has entered
		Player* targetPlayer = pGrid->GetPlayerWithNum(targetNum);
		if (targetPlayer != NULL)
		{
			if (targetPlayer != Attacker)
				AttackTarget = targetPlayer;
			else
				pGrid->PrintErrorMessage("You can't attack yourself! click to continue...");
		}
		else
		{
			pGrid->PrintErrorMessage("Invalid player number! click to continue...");
		}
	}
}

Player* Fire::getAttackTarget()
{
	return AttackTarget;
}

void Fire::Execute()
{
	ReadAttackTarget();

	// set the burning datamember of the attacked player to 3
	AttackTarget->setBurning(3);

	pGrid->AdvanceCurrentPlayer();
}