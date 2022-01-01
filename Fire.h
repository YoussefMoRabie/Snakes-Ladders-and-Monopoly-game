#pragma once
#include "Attack.h"

class Fire :
    public Attack
{
    Player* AttackTarget;
public:
    Fire(Grid* pGr, Player* attacker);

    void ReadAttackTarget();

    Player* getAttackTarget();

    virtual void Execute();
};

