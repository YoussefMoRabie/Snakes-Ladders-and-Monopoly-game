#include "Ladder.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	
	this->endCellPos = endCellPos;
	setStart_End(position, this->endCellPos);
	
	size = endCellPos.VCell() - startCellPos.VCell();
	cellsCounter = new int[size];
	for (int i = 0; i < size; i++) {
		cellsCounter[i] = CellPosition::GetCellNumFromPosition(position) + i * 11;
		
	}
	if (IsOverlapping(this))
		return;



	

	///TODO: Do the needed validation
}
void Ladder::setStart_End(CellPosition start, CellPosition End) {

	if (start.GetCellNum() <= 1 || start.VCell() == 0)
		return;

	if (start.HCell() != End.HCell() || start.VCell() <= End.VCell())
		return;
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
	Grid * ptr=NULL;
	
	if (dynamic_cast<Ladder*>(p) != NULL)
	{
		Ladder *Ladders[4];
		int count = 0;
		ptr->GetVerticalLadder(p->GetPosition(), count, Ladders);
		for (int i = 0; i < 9; i++)
		{
			

				for (int k = 0; k < size; k++) {
					for (int j = 0; j < Ladders[i]->size; j++)
						if (cellsCounter[k] == Ladders[i]->cellsCounter[j])
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
}
