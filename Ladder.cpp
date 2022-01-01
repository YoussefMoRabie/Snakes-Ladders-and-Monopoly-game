#include "Ladder.h"
#include "Player.h"
#include<iostream>
#include <cmath>
#include<fstream>
using namespace std;
Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	
	this->endCellPos = endCellPos;
	
	
	size =abs( -endCellPos.VCell() + startCellPos.VCell());
	cellsCounter = new int[size+1];
	for (int i = 0; i <= size; i++) 
	{
		cellsCounter[i] = CellPosition::GetCellNumFromPosition(position) + i * 11;
	}
	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	
	pGrid->PrintErrorMessage("You have reached a ladder. Click to continue ...");
	pPlayer->MoveWithoutDice(pGrid, endCellPos);
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
			for (int i = 0; i < 9; i++)
			{


				for (int k = 0; k <= L->size; k++) {
			
						if (cellsCounter[i] == L->cellsCounter[k])
							return true;
				}

			}
		}
	
	return false;
}
 void Ladder:: Save(ofstream& OutFile) {

	 OutFile << position.VCell()<<" " << endCellPos.VCell()<<" " << position.HCell()<<" " << 'L'<<endl;
		 

}
 void Ladder::Load(ifstream & Infile) {
	 
	 int vstart = -1, vend = -1, h = -1; char type;
	 Infile >> vstart >> vend >> h>>type;
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
