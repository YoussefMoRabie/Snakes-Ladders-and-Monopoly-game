#include "Player.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(1), wallet(100), playerNum(playerNum), turnsToSkip(0)
{
	this->pCell = pCell;
	this->turnCount = 0;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	if (wallet >= 0)
		this->wallet = wallet;
	else
		this->wallet = 0;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

void Player::setTurnCount(int t)
{
	if (t >= 0 && t < 3) {
		turnCount = t;
	}
}

int Player::GetStepCount() const
{
	return stepCount;
}

void Player::setStepCount(int cellNum)
{
	if (cellNum > 0 && cellNum <= NumVerticalCells * NumHorizontalCells)
		stepCount = cellNum;
}

void Player::setTurnsToSkip(int turns)
{
	if (turns > 0)
	{
		turnsToSkip = turns;
	}
}

int Player::getPlayerNum() const {
	return playerNum;
}
int Player::getJustRolledDice()const{
	return justRolledDiceNum;
}
// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;


	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
}

// ====== Game Functions ======
void Player::skipCheck(Grid * pGrid)
{
	//This function checks if the player should skip this turn, and if that's the case, 
	//calls AdvanceCurrentPlayer() to give the turn to the next player

	if (turnsToSkip > 0)
	{
		turnsToSkip--;
		pGrid->PrintErrorMessage("Player " + to_string(getPlayerNum()) + " skips the turn this round! click to continue...");
		pGrid->AdvanceCurrentPlayer();
	}
}
void Player:: MoveWithoutDice(Grid* pGrid,CellPosition & toCell) {
	pGrid->UpdatePlayerCell(this, toCell);
	stepCount = pCell->GetCellPosition().GetCellNum();
	CellPosition pos = pCell->GetCellPosition();
	if (pCell->GetGameObject() != NULL)
	{
		pCell->GetGameObject()->Apply(pGrid, this);
	}
	// 8- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	if (pos.GetCellNum() == NumHorizontalCells * NumVerticalCells)
		pGrid->SetEndGame(true);
}

void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	turnCount++;
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (turnCount == 3) {
		wallet += diceNumber * 10;
		turnCount = 0;
		return;
	}
	// 3- Set the justRolledDiceNum with the passed diceNumber
	justRolledDiceNum = diceNumber;
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	CellPosition pos = pCell->GetCellPosition();
	pos.AddCellNum(justRolledDiceNum);
	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	pGrid->UpdatePlayerCell(this, pos);
	// 6- Apply() the game object of the reached cell (if any)
	if (pCell->GetGameObject() != NULL)
	{
		pCell->GetGameObject()->Apply(pGrid, this);
	}
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	if (pos.GetCellNum() == NumHorizontalCells * NumVerticalCells)
		pGrid->SetEndGame(true);
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}