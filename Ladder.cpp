#include "Ladder.h"
#include "Player.h"
#include<iostream>
#include <cmath>
#include<fstream>
using namespace std;
Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	
	this->endCellPos = endCellPos;
	
	
	size =abs( -endCellPos.VCell() + startCellPos.VCell()); // the number of vertical cells on the ladder path
	cellsCounter = new int[size+1];
	for (int i = 0; i <= size; i++) 
	{
		cellsCounter[i] = CellPosition::GetCellNumFromPosition(position) + i * 11;  // getting the cell number of the cells on the ladder path 
	}
	///TODO: Do the needed validation  // the validation of the overlapping is below in function "IsOverlapping" 
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	
	pGrid->PrintErrorMessage("You have reached a ladder. Click to continue ...");
	pGrid->UpdatePlayerCell(pPlayer, endCellPos); // upadates the player cell to the end cell of the ladder

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	//Done

	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	
}

bool Ladder::IsOverlapping(GameObject*p)
{
	int h = endCellPos.HCell();
		
		Ladder* L = dynamic_cast<Ladder*>(p);
		if (L != NULL)
		{
			for (int i = 0; i < size; i++)
			{


				for (int k = 0; k <= L->size; k++) {
			
						if (cellsCounter[i] == L->cellsCounter[k])   // checks if there is at least one cell overlapping between the existing ladder
							                                         //and the ladder to be created
							return true;
				}

			}
		}
	
	return false;
}
 void Ladder:: Save(ofstream& OutFile) {

	 OutFile << position.VCell()<<" " << endCellPos.VCell()<<" " << position.HCell()<<endl; //save the ladder information
		 

}
 void Ladder::Load(ifstream & Infile) {
	 
	 int vstart = -1, vend = -1, h = -1;                               
	                                         // loads the ladder information and setting the members
	 Infile >> vstart >> vend >> h;
	 position.SetVCell(vstart);
	 position.SetHCell(h);
	 endCellPos.SetVCell(vend);
	 endCellPos.SetHCell(h);
	 
 }
CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
	delete[]cellsCounter;
}
