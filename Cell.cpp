#include "Cell.h"

#include "Grid.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Card.h"
#include "Player.h"

Cell::Cell(const CellPosition & pos) : position(pos)
{
	// initializes the data members (position & pGameObject)
	pGameObject = NULL;
}

Cell::Cell(int v, int h) : position(v, h)
{
	// initializes the data members (position & pGameObject)
	pGameObject = NULL;
}


// ======= Setters and Getters Functions ======= 


CellPosition Cell::GetCellPosition() const
{
	return position;
}

bool Cell::SetGameObject(GameObject * pGObj)
{
	if (pGameObject != NULL && pGObj != NULL) // already contains one
		return false; // do NOT add it and return false

	pGameObject = pGObj;
	return true;
}

GameObject * Cell::GetGameObject() const
{
	return pGameObject;
}

Ladder * Cell::HasLadder() const
{
	return dynamic_cast<Ladder *>(pGameObject);
}

Snake * Cell::HasSnake() const
{

	///TODO: Implement the following function like HasLadder() function

	return false; // THIS LINE SHOULD CHANGED WITH YOUR IMPLEMENTATION
}

Card * Cell::HasCard() const
{

	///TODO: Implement the following function like HasLadder() function

	return false; // THIS LINE SHOULD CHANGED WITH YOUR IMPLEMENTATION

}


// ======= Drawing Functions ======= 

void Cell::DrawCellOrCard(Output* pOut) const
{
	// Checks if there is a Card on the cell
	if (HasCard()) // means if not NULL
		pGameObject->Draw(pOut); // draw the card then
	else
		pOut->DrawCell(position, -1); // draw empty cell (no card -1)
}

// separate from the above function because ladders/snakes should be drawn AFTER All Cells are drawn
void Cell::DrawLadderOrSnake(Output* pOut) const
{
	if (HasLadder() || HasSnake())
		pGameObject->Draw(pOut); // draw it either ladder or snake

}
