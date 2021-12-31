#include "NewGame.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

NewGame::NewGame(ApplicationManager* pApp) : Action(pApp)
{
}

void NewGame::ReadActionParameters()
{
	// no parameters to read from user
}

void NewGame::Execute()
{
	
	Grid* pGrid = pManager->GetGrid();
	CellPosition firstCell(1);

	for (int i = 0; i < MaxPlayerCount; i++) {
		Player* current = pGrid->GetCurrentPlayer();
		pGrid->UpdatePlayerCell(current, firstCell);
		current->SetWallet(100);
		current->setTurnCount(0);
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->SetCurrentPlayer(0);
}

NewGame::~NewGame()
{
}