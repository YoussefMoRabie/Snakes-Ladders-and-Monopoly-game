#include "Lightning.h"

Lightning::Lightning(Grid* pGr, Player* attacker) : Attack(pGr, attacker)
{
}

void Lightning::Execute()
{
	// decrement the wallet of all players other than the attacker by 20
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		if (i != Attacker->getPlayerNum())
		{
			Player* target = pGrid->GetPlayerWithNum(i);
			target->SetWallet(target->GetWallet() - 20);
		}
	}
	pGrid->AdvanceCurrentPlayer();
}