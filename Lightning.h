#pragma once
#include "Attack.h"

class Lightning :
    public Attack
{
public:
    Lightning(Grid* pGr, Player* attacker);

    virtual void Execute();
};

