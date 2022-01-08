#pragma once
#include "Card9_11.h"
class CardEleven :public Card9_11
{

public:
	CardEleven(const CellPosition & pos); // A Constructor takes card position
	virtual ~CardEleven(); // A Virtual Destructor
};

