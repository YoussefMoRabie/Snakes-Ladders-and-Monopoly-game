#pragma once
#include "Attack.h"

class Lighting :
    public Attack
{
    Player* AttackTarget;
public:
    Lighting(Grid* pGr, Player* attacker);

    virtual void Execute();
};

