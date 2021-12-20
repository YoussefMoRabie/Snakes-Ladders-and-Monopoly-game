#ifndef INPUT_H
#define INPUT_H

#include "DEFS.h"
#include "UI_Info.h" 
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CellPosition.h"

// forward declarations (their includes are in the cpp)
class Output;  

class Input		// The application manager & grid (phase 2) should have a pointer to this class
{
private:

	window *pWind;	// Pointer to the Graphics Windo

public:

	// ========== General Functions ==========

	Input(window *pW);  // Consturctor: Points to the passed window pointer

	void GetPointClicked(int &x, int &y) const; // Wait for a Mouse Click and Gets the real coordinates (x,y) of it

	string GetString(Output* pO) const;  // Returns a string entered by the user

	///TODO: IMPLEMENT THE FOLLOWING FUNCTION
	int GetInteger(Output* pO) const;    // Returns an integer entered by the user
	
	// ========== Game Functions ==========
	
	///TODO: COMPLETE THE IMPLEMENTATIN OF THE FOLLOWING FUNCTION
	ActionType GetUserAction() const;	 // Reads a user click and map it to its corresponding ActionType

	///TODO: COMPLETE THE IMPLEMENTATIN OF THE FOLLOWING FUNCTION
	CellPosition GetCellClicked() const; // Wait for a Mouse Click and Gets the CellPosition of it (VCell and HCell)
										 // This function is needed only in Design Mode
										 // If the click is NOT on a cellposition, (-1,-1) is returned
										 // This function is like GetPointClicked but returns Cell Position NOT Real Coordinates
};

#endif