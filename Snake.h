#pragma once
#include "GameObject.h"
class Snake :public GameObject
{
	CellPosition endCellPos; // here is the ladder's End Cell Position
	int *cellsCounter;
	int size;


public:

	Snake(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization
	virtual bool IsOverlapping(GameObject*);

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);


	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	virtual ~Snake(); // Virtual destructor
};

