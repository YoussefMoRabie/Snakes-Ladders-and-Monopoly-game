#pragma once
#include "Attack.h"

class Fire :
    public Attack
{
    Player* AttackTarget;
public:
    Fire(Grid* pGr, Player* attacker);

    void ReadAttackTarget();            // Read the attack target from the user

    Player* getAttackTarget();          

    virtual void Execute();
};

