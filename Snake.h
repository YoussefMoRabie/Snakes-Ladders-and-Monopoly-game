#pragma once
#include "GameObject.h"
class Snake :public GameObject
{
	CellPosition endCellPos; // here is the ladder's End Cell Position
	int *cellsCounter;  // an array with all cells on the snake's path
	int size; // the size of the array


public:

	Snake(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization
	virtual bool IsOverlapping(GameObject*); // checks if there is two snakes overlapping

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	virtual void Save(ofstream& OutFile); // saves the snake's information in grid text file
	virtual void Load(ifstream& Infile); // loads the snake's information from grid text file


	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	virtual ~Snake(); // Virtual destructor
};

