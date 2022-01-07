#include "Snake.h"
#include"Player.h"

#include <cmath>
Snake::Snake(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{

	this->endCellPos = endCellPos;


	size = abs(-endCellPos.VCell() + startCellPos.VCell());

	cellsCounter = new int[size + 1];   // the number of vertical cells on the ladder path

	for (int i = 0; i <= size; i++) {

		cellsCounter[i] = CellPosition::GetCellNumFromPosition(position) - i * 11;  // getting the cell number of the cells on the ladder path

	}







	///TODO: Do the needed validation // the validation of the overlapping is below in function "IsOverlapping" 
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	pGrid->PrintErrorMessage("You have reached a snake. Click to continue ...");
	pGrid->UpdatePlayerCell(pPlayer, endCellPos); // upadates the player cell to the end cell of the snake
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

}
bool Snake::IsOverlapping(GameObject*p)
{
	int h = endCellPos.HCell();

	Snake* L = dynamic_cast<Snake*>(p);
	if (L != NULL)
	{
		for (int i = 0; i < size; i++)
		{


			for (int k = 0; k <= L->size; k++) {

				if (cellsCounter[i] == L->cellsCounter[k]) // checks if there is at least one cell overlapping between the existing snake and the snake to be created
					return true;
			}

		}
	}

	return false;
}


CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}
void Snake::Save(ofstream& OutFile) {
	OutFile << position.VCell()<<" " << endCellPos.VCell() << " " << position.HCell() <<endl;
}
void Snake::Load(ifstream& Infile) {
	int vstart = -1, vend = -1, h = -1; 
	Infile >> vstart >> vend >> h;  // loads the snake's information and setting the members
	position.SetVCell(vstart);
	position.SetHCell(h);
	endCellPos.SetVCell(vend);
	endCellPos.SetHCell(h);
	
}
 

Snake::~Snake()
{
	delete[]cellsCounter;
}