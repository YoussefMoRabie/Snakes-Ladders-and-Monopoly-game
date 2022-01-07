#pragma once

#include "GameObject.h"
using namespace std;
class Ladder :	public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"

	CellPosition endCellPos; // here is the ladder's End Cell Position
	 int *cellsCounter;  //an array with all cells on the ladder's path
	int size; // the array size
	

public:

	Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization
	virtual bool IsOverlapping(GameObject*); // checks if there is two ladders overlapping
	
	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell
	
	virtual void Save(ofstream & OutFile);	// saves the ladder's information in grid text file
	virtual void Load(ifstream & Infile); // loads the ladder's information from grid text file
	

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	virtual ~Ladder(); // Virtual destructor
};

