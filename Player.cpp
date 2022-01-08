#include "Player.h"
#include "GameObject.h"
#include "Attack.h"
#include "Ice.h"
#include "Fire.h"
#include "Poison.h"
#include "Lightning.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(1), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	turnCount = 0;
	turnsToSkip = 0;
	AttackCounter = 2;
	burning = 0;
	poisoned = 0;
	for (int i = 0; i < 4; i++)
	{
		SpecialAttacks[i] = 1;
	}
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

void Player::turnIncrement()
{
	turnCount++;
	if (turnCount == 3)
		turnCount = 0;
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

void Player::setBurning(int turns)
{
	if (turns > 0)
	{
		burning = turns;
	}
}

void Player::setPoisoned(int turns)
{
	if (turns > 0)
	{
		poisoned = turns;
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
		turnIncrement();
		pGrid->PrintErrorMessage("Player " + to_string(getPlayerNum()) + " skips the turn this round! click to continue...");
		pGrid->AdvanceCurrentPlayer();
	}
}

void Player::burnCheck(Grid* pGrid)
{
	if (burning > 0)
	{
		burning--;
		pGrid->PrintErrorMessage("You are burning, you lose 20 coins!");
		this->SetWallet(GetWallet() - 20);
		pGrid->UpdateInterface();
	}
}

bool Player::poisonCheck(Grid* pGrid)
{
	if (poisoned > 0)
	{
		poisoned--;
		pGrid->PrintErrorMessage("You are poisoned, you lose 1 from your dice roll!");
		return true;
	}
	return false;
}

void Player::AttackChoice(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (AttackCounter == 0)
	{
		pGrid->PrintErrorMessage("You already used your 2 special attacks for this game, click to continue...");
		return;
	}

	pOut->PrintMessage("Do you wish to launch a special attack instead of recharging? y/n");
	string choice = pIn->GetString(pOut);
	pOut->ClearStatusBar();
	while (choice != "y" && choice != "Y" && choice != "N" && choice != "n")
	{
		pOut->PrintMessage("You entered an invalid Charcter: Do you wish to launch a special attack instead of recharging? y/n");
		choice = pIn->GetString(pOut);
		pOut->ClearStatusBar();
	}
	if (choice == "y" || choice == "Y")
	{
		pOut->PrintMessage("Choose the type of attack ('I'ce - 'F'ire - 'P'oison - 'L'ighting)");
		string type = pIn->GetString(pOut);
		pOut->ClearStatusBar();

		bool used = false;
		if (type == "i" || type == "I")
		{
			if (UseAttack(ice, pGrid))
				used = true;
		}
		else if (type == "f" || type == "F")
		{
			if (UseAttack(fire, pGrid))
				used = true;
		}
		else if (type == "p" || type == "P")
		{
			if (UseAttack(poison, pGrid))
				used = true;
		}
		else if (type == "l" || type == "L")
		{
			if (UseAttack(lightning, pGrid))
				used = true;
		}
		else
		{
			pGrid->PrintErrorMessage("Invalid input, click to continue...");
			AttackChoice(pGrid);
		}
		if (used == false)
		{
			pGrid->PrintErrorMessage("You can use each special attack once per game, click to continue...");
			AttackChoice(pGrid);
		}
	}
}

bool Player::UseAttack(AttackType atk, Grid* pGrid)
{
	Attack* attack = NULL;
	if (atk == ice)
	{
		if (SpecialAttacks[ice] > 0)
		{
			SpecialAttacks[ice]--;
			attack = new Ice(pGrid, this);
		}
	}
	else if (atk == fire)
	{
		if (SpecialAttacks[fire] > 0)
		{
			SpecialAttacks[fire]--;
			attack = new Fire(pGrid, this);
		}
	}
	else if (atk == poison)
	{
		if (SpecialAttacks[poison] > 0)
		{
			SpecialAttacks[poison]--;
			attack = new Poison(pGrid, this);
		}
	}
	else if (atk == lightning)
	{
		if (SpecialAttacks[lightning] > 0)
		{
			SpecialAttacks[lightning]--;
			attack = new Lightning(pGrid, this);
		}
	}
	if (attack != NULL)			// No going back now
	{
		AttackCounter--;		// Used one of his two attacks
		turnCount = 0;			// End of wallet turn

		attack->Execute();		// virtual func.
		delete attack;			// Not needed anymore 
		attack = NULL;
		return true;
	}
	return false;
}


void Player::restart(Grid* pGrid)
{
	CellPosition firstCell(1);
	pGrid->UpdatePlayerCell(this, firstCell);
	wallet = 100;
	turnCount = 0;
	turnsToSkip = 0;
	AttackCounter = 2;
	burning = 0;
	poisoned = 0;
	for (int i = 0; i < 4; i++)
	{
		SpecialAttacks[i] = 1;
	}
}

void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	turnIncrement();
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (turnCount == 0) {
		wallet += diceNumber * 10;
		return;
	}
	// 3- Set the justRolledDiceNum with the passed diceNumber
	justRolledDiceNum = diceNumber;

	// Players can't move if their wallet is at 0
	if (wallet == 0)
	{
		pGrid->PrintErrorMessage("Player NO." + to_string(playerNum) + " doesn't have any coins so they can't move");
		return;
	}

	// Check if the player won
	if (GetStepCount() >= 94)
	{
		if (GetStepCount() + justRolledDiceNum == 100)
		{
			pGrid->SetEndGame(true);
			pGrid->UpdatePlayerCell(this,CellPosition::GetCellPositionFromNum(99));
			pGrid->PrintErrorMessage("Player No." + to_string(getPlayerNum()) + " wins, better luck next time for other players!");
			return;
		}
		else if (GetStepCount() + justRolledDiceNum > 100)
		{
			pGrid->PrintErrorMessage("too much, you need to reach exactly 100 to win!");
			return;
		}
	}
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	CellPosition pos = pCell->GetCellPosition();
	pos.AddCellNum(justRolledDiceNum);
	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	pGrid->UpdatePlayerCell(this, pos);
	
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}