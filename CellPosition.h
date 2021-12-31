#pragma once

class CellPosition
{
	int vCell; // the vertical cell number: starts from 0 to NumVerticalCells - 1
	int hCell; // the horizontal cell number: starts from 0 to NumHorizontalCells - 1

public:
	CellPosition (); // Initializes the cell to (-1,-1) indicating not initialized with valid values
	CellPosition (int v, int h); // Sets vCell and hCell if valid
	CellPosition (int cellNum);  // Sets vCell and hCell from the passed cellNum if valid

	// Note: this class does NOT deal with real coordinates, it deals with the "vCell", "hCell" and "cellNum" instead

	// assuming NumVerticalCells = 9 and NumHorizontalCells = 11 
	// Cell Numbers (CellNum) should be from 1 to 99
	// Numbered from [left-to-right] [bottom-up], as follows:

	// hCell (right):   0    1   ...   10
	// vCell (below):
	//   0             C89  C90  ...  C99
	//   1             C78  C79  ...  C88
	//  ...            ...  ...  ...  ...
	//   7             C12  C13  ...  C22
	//   8             C1   C2   ...  C11

	// In the Grid above, C13 has vCell = 7 and hCell = 1
	

	///TODO: IMPLEMENT THE FOLLOWING FUNCTION
	bool SetVCell(int v); // The setter of vCell (the setter here sets only if "v" is in grid range)
	                      // It returns true, if the parameter is valid and the setting is applied, 
	                      // Otherwise, return false with no setting

	///TODO: IMPLEMENT THE FOLLOWING FUNCTION
	bool SetHCell(int h); // The setter of hCell (the setter here sets only if the "h" is in grid range)
						  // It returns true, if the parameter is valid and the setting is applied, 
	                      // Otherwise, return false with no setting

	int VCell() const; // The getter of vCell
	int HCell() const; // The getter of hCell

	///TODO: IMPLEMENT THE FOLLOWING FUNCTION
	bool IsValidCell() const; // Checks if the current cell position (vCell and hCell) both are valid then return true
	                          // Otherwise, return false

	int GetCellNum() const;   // Gets the cellNum from the vCell and hCell of the cell position

	///TODO: IMPLEMENT THE FOLLOWING FUNCTION
	static int GetCellNumFromPosition(const CellPosition & cellPosition);  // Calculates the cellNum of the passed "cellPosition"
																		   // It is a static function (no need for a calling obj)

	///TODO: IMPLEMENT THE FOLLOWING FUNCTION
	static CellPosition GetCellPositionFromNum(int cellNum); // Returns the corresponding CellPosition (vCell, hCell) of the passed cellNum
															 // It is a static function (no need for a calling obj)

	///TODO: IMPLEMENT THE FOLLOWING FUNCTION
	void AddCellNum (int addedNum); // Adds the passed "addedNum" to the "cellNum" of the current cell position
	                                // and updates the data members (vCell and hCell) accordingly
	                                // for example, if cellNum = 50 and the passed num = 6
	                                // this will make cellNum = 56 which updates the data members: vCell = 3 and hCell = 0 
	                                // (assuming NumVerticalCells = 9 and NumHorizontalCells = 11 )
};

