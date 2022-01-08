
#include "CardTen.h"
int CardTen::StationPrice = 0;

int CardTen::Fees = 0;

Player* CardTen::Owner = NULL;

CardTen::CardTen(const CellPosition & pos) : Card9_11(pos) // set the cell position of the card
{
	cardNumber = 10; // set the inherited cardNumber data member with the card number 

}
CardTen::~CardTen(void)
{
}
