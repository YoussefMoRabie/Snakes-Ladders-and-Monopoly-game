#pragma once

#include "Action.h"
#include "Player.h"

class AttackAction : public Action
{
protected:

	AttackType attack;		// The type of attack the player will choose

	Player* Attacker;		//The player who is using their special attack

	Player* Attacked;		//The player "Attacker" chose as their target

public:
	AttackAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~AttackAction();
};

