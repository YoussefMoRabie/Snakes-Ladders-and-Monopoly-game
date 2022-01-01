#pragma once
#include "Attack.h"

class Poison :
    public Attack
{
    Player* AttackTarget;
public:
    Poison(Grid* pGr, Player* attacker);

    void ReadAttackTarget();

    Player* getAttackTarget();

    virtual void Execute();
};

