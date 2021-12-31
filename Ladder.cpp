#include "Ladder.h"
#include <cmath>
Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	
	this->endCellPos = endCellPos;
	
	
	size =abs( -endCellPos.VCell() + startCellPos.VCell());
	cellsCounter = new int[size+1];
	for (int i = 0; i <= size; i++) {
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
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


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


CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
	delete[]cellsCounter;
}
