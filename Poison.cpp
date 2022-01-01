#include "Poison.h"

Poison::Poison(Grid* pGr, Player* attacker) : Attack(pGr, attacker)
{
	AttackTarget = NULL;
}

void Poison::ReadAttackTarget()
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Enter the number of the player you want to attack (from 0 to " + to_string(MaxPlayerCount - 1) + ")");
	int targetNum = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();

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

Player* Poison::getAttackTarget()
{
	return AttackTarget;
}

void Poison::Execute()
{
	ReadAttackTarget();

	if (AttackTarget == NULL)
		return;

	if (Attacker->UseAttack(poison))
	{
		AttackTarget->setPoisoned(5);
		Attacker->setTurnCount(0);
		pGrid->AdvanceCurrentPlayer();
	}
	else
		pGrid->PrintErrorMessage("You have already used your (Poison Attack) for this game!");
}