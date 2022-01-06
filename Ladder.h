#pragma once

#include "GameObject.h"
using namespace std;
class Ladder :	public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"

	CellPosition endCellPos; // here is the ladder's End Cell Position
	 int *cellsCounter;
	int size;
	

public:

	Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization
	virtual bool IsOverlapping(GameObject*);
	int getSize();
	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell
	
	virtual void Save(ofstream & OutFile);	
	virtual void Load(ifstream & Infile);
	

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	virtual ~Ladder(); // Virtual destructor
};

