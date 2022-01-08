#include "CardTen.h"

CardTen::CardTen(const CellPosition & pos) : Card9_11(pos) // set the cell position of the card
{
	cardNumber = 10; // set the inherited cardNumber data member with the card number 

}
CardTen::~CardTen(void)
{
}
