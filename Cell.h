#pragma once 

#include "UI_Info.h"
#include "CellPosition.h"

// Class forward declarations (their #include is in the .cpp file)
class Grid;
class Output;
class GameObject;
class Ladder;
class Snake;
class Card;
class Player;

class Cell
{
	const CellPosition position;	// the cell position (vCell and hCell) --> will not change after the Cell is constructed

	GameObject * pGameObject;       // a pointer to the GameObject existing in the Cell (if any)
	                                // if no GameObject in this Cell, pGameObject should be NULL

public:

	Cell(const CellPosition & pos); // A constructor initializes the cell position with the passed CellPosition
	Cell(int v, int h);		        // A constructor initializes the cell position with the passed vCell and hCell

	// ======= Setters and Getters Functions ======= 

	CellPosition GetCellPosition() const;   // A getter for the "position" data member
	
	bool SetGameObject(GameObject * pGObj);	// A setter for pGameObject of the cell
	                                        // It does NOT add the object and returns false if the cell already contains one
	GameObject * GetGameObject() const;     // A getter for pGameObject of the cell
		
	Ladder * HasLadder() const;	// Checks if pGameObject is a Ladder Then returns it if a ladder or returns NULL if not ladder
	Snake * HasSnake() const;	// Checks if pGameObject is a Snake Then returns it if a snake or returns NULL if not snake
	Card * HasCard() const;	    // Checks if pGameObject is a Card Then returns it if a card or returns NULL if not card
	
	// ======= Drawing Functions ======= 

	void DrawCellOrCard(Output* pOut) const;	// Draws the Cell either has Card or No Card (No ladders/snakes are drawn here)
	void DrawLadderOrSnake(Output* pOut) const;	// Draws the Ladder/Snake of the Cell if found
	                                            // The two Draw functions are separated because we should draw all cells first
	                                            // then draw all ladders/snake, in order to avoid overlapping 
	                                            // or drawing cell's background over existing ladders/snakes
};

