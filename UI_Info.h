#ifndef UI_INFO_H
#define UI_INFO_H

#include "CMUgraphicsLib\CMUgraphics.h"

// User Interface information file.
// This file contains info that is needed by Input and Output classes to
// handle the user interface

#define NumHorizontalCells 11
#define NumVerticalCells 9
#define MaxPlayerCount 4

enum GUI_MODE		// Graphical user interface mode
{
	MODE_DESIGN,	// Design mode (startup mode)
	MODE_PLAY       // Play mode
};

enum DESIGN_MODE_ITEMS // The items of the Design Mode (you should add more items)
{
	// Note: Items MUST be ordered here as they appear in menu
	// If you want to change the menu items order, change the order here
	ITM_OPEN_GRID,
	ITM_ADD_LADDER,
	ITM_ADD_SNAKE,
	ITM_ADD_CARD,
	ITM_COPY_CARD,
	ITM_CUT_CARD,
	ITM_PASTE_CARD,
	ITM_DELETE_GAME_OBJECT,
	ITM_SAVE_GRID,
	ITM_SWITCH_TO_PLAY_MODE,
	ITM_EXIT,
	

	

	///TODO: Add more items names here

	DESIGN_ITM_COUNT	// no. of items ==> This should be the last line in this enum
};

enum PLAY_MODE_ITEMS // The items of the Play Mode (you should add more items)
{
	// Note: Items are ordered here as they appear in menu
	// If you want to change the menu items order, change the order here

	ITM_ROLL_DICE,
	ITM_SWITCH_TO_DESIGN_MODE,
	ITM_NEW_GAME,
	ITM_INPUT_DICE_VALUE,
	ITM_PLAY_EXIT,
	

	///TODO: Add more items names here

	PLAY_ITM_COUNT		// no. of items ==> This should be the last line in this enum
};


__declspec(selectany) // This line to prevent "redefinition error"

struct UI_Info	// User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,			// Window width and height
		wx , wy,				// Window starting coordinates
		StatusBarHeight,		// Status Bar Height
		ToolBarHeight,			// Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;			// Width of each item in toolbar menu
	
	int CellHeight;				// Height of 1 CELL
	int CellWidth;				// Width of 1 CELL
	
	color MsgColor;				// Messages color (usually used in statusbar)
	color PlayerInfoColor;		// Players' Info color (used in the toolbar - right-indented)

	color CellColor_HasCard;	// Cell color if it has a card
	color CellColor_NoCard;		// Cell color if it does not have card

	color ToolBarColor;			// Toolbar color (toolbar background)
	color StatusBarColor;		// Statusbar color (statusbar background)

	color GridLineColor;		// Color of the Lines separating adjacent cells

	int CellNumFont;			// Font size of cell numbers
	color CellNumColor;			// Cell number color

	int CardNumFont;			// Font size of card numbers
	color CardNumColor;			// Card number color

	int LadderXOffset;			// Size of the horizontal space before drawing the ladder
	int LadderYOffset;			// Size of the vertical space before drawing the ladder
	int LadderlineWidth;		// Width of the lines of the ladder
	color LadderColor;			// Ladder color
	int SnakelineWidth;			// Width of the line and polygon of the snake
	color SnakeColor;			// Snake color

	color PlayerColors[MaxPlayerCount];		// Color of each player

	///TODO: Add more members if needed

} UI ;	// create a global object UI

#endif