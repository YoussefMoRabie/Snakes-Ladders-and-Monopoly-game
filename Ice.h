#pragma once
#include "Attack.h"

class Ice :
    public Attack
{
    Player* AttackTarget;
public:
    Ice(Grid* pGr, Player* attacker);

    void ReadAttackTarget();

    Player* getAttackTarget();

    virtual void Execute();
};

