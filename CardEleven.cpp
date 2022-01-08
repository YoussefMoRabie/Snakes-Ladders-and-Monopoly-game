#include "CardEleven.h"

CardEleven::CardEleven(const CellPosition & pos) : Card9_11(pos) // set the cell position of the card
{
	cardNumber = 11; // set the inherited cardNumber data member with the card number 

}
CardEleven::~CardEleven(void)
{
}


