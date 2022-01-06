#include "NewGame.h"
#include "Grid.h"
#include "Player.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"


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
	pGrid->RestartAllPlayers();
	pGrid->SetCurrentPlayer(0);

	// All stations must return without an owner
	CardNine::SetOwner(NULL);
	CardTen::SetOwner(NULL);
	CardEleven::SetOwner(NULL);
}

NewGame::~NewGame()
{
}