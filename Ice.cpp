#include "Ice.h"

Ice::Ice(Grid* pGr, Player* attacker) : Attack(pGr, attacker)
{
	AttackTarget = NULL;
}

void Ice::ReadAttackTarget()
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

Player* Ice::getAttackTarget()
{
	return AttackTarget;
}

void Ice::Execute()
{
	ReadAttackTarget();

	// make the attacked player skip his next turn 
	AttackTarget->setTurnsToSkip(1);

	pGrid->AdvanceCurrentPlayer();
}