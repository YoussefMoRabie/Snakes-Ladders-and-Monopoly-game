#include "Lighting.h"

Lighting::Lighting(Grid* pGr, Player* attacker) : Attack(pGr, attacker)
{
}

void Lighting::Execute()
{
	if (Attacker->UseAttack(lighting))
	{
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			if (i != Attacker->getPlayerNum())
			{
				Player* target = pGrid->GetPlayerWithNum(i);
				target->SetWallet(target->GetWallet() - 20);
			}
		}
		Attacker->setTurnCount(0);
		pGrid->AdvanceCurrentPlayer();
	}
	else
		pGrid->PrintErrorMessage("You have already used your (Lighting Attack) for this game!");
}