#include "CardNine.h"
int CardNine::StationPrice = 0;

int CardNine::Fees = 0;

Player* CardNine::Owner = NULL;

CardNine::CardNine(const CellPosition & pos) : Card9_11(pos) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number 

}
CardNine::~CardNine(void)
{
}