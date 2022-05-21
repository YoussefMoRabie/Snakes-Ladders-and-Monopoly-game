# Snakes-Ladders-and-Monopoly-game
A project by Cairo engineering students for programming for first graders, which is a project we are going to build a simple game application that is a mixture between the Snakes &amp; Ladders and Monopoly games. There are two modes in the game: Design mode is where The user is able to build the playing grid and Play mode is where he plays the game itself. The general idea of the game is four players moving in a grid having snakes, ladders, and Cards. The player goal is to get to the last cell before anyone else
Snakes-ladders-and-Monopoly-
A OOP class project were the rules of object oriented programming are used to implement the game's stucture.

# Game description
In the Design mode, the player can add, copy, cut, paste, and delete any game object. He
can also save a grid and load a previously saved grid.
In the Play mode, the player is moving in a grid of 99 cells divided into rows and columns.
Each cell has a number from 1 to 99. They are divided to 9 rows and 11 columns.

**Grid cells may contain:**
1. Ladder
2. Snake
3. Card making the cell a special cell

**Players:**
1. The Game has four players.
2. Each player has:

	  o Steps’ count (initially step 0). This holds the value of the current cell the player is in.
			
 	 o Wallet (initially contains 100 coins).
			
3. The player can only move if there is at least 1 coin in his wallet. If he has zero
or less coins, he must wait till his wallet is recharged with coins.
4. Players take turn rolling the dice, one after another.
5. After a player rolls the dice, he moves from his n cell to n + t, where t is the result of rolling
the dice. For example, if the player gets 4 after rolling the dice and he is in cell 25, he
moves to cell 29.
6. Every 3 turns, a player dice roll is used to add money to his wallet instead of moving. A
player gets 10*t coins (where t is the result of rolling the dice). For example:

	  o The game starts and player 0 has 100 coins. He rolls the dice to get 5. He moves
to cell 5.

	  o In his next turn he gets 2 and moves to cell 7.

	  o In his third turn, he rolls the dice and gets 4. Then, 40 coins are added to his wallet,
and he will not move to cell 11. This happens every three turns, i.e., turn 3, 6, 9,
… etc.
7. The player’s target in the game is to reach the last cell before any opponent reaches it.
8. Winning Player → Is the first player to reach cell #100.
A Game cell contains players’ objects and game objects. It can hold multiple player objects, and at
most one game object.

A Game object is the fixed objects placed in the grid’s cells.
You cannot place game objects in the first or last cell.

# The Cards rules
**• Card1:**
Decrements the value of the passing player’s wallet by a value specified when creating
the grid.

**• Card2:**
 Moves the player forward to the start of the next ladder in the grid.If no ladders ahead, do nothing.
 
**• Card3 and Card4:**
Card3 gives the player an extra dice roll.
Card4 prevents the player from rolling the next turn. Both the extra dice roll or the canceled dice roll count normally towards recharging the
wallet turn (both increment the count of player turns).

**• Card5:**
Moves the player backward with the same number of steps that he just rolled.
If he reaches a ladder, a snake, or a card at the end of moving, take it.

**• Card6:**
 Instructs the player to go to a specific cell.
 If the destination cell contains a ladder, snake, or card, take it.
 Input data in design mode:
i. Cell to move to

**• Card7:**
Restarts the game for the first player whose cell is after the current player in the grid.
 Restarting the game for a player makes him go to cell number 1.
 
**• Card8:**
This card is a prison. When a player stops at a Card8 cell, the player should choose either to pay specific
amount of coins to go out of the prison, or stay in prison and not playing for 3 turns.
Input data in design mode:
i. The amount of coins needed to go out of the prison

**• Cards [from 9 to 11]:**
Gives the player the option to buy this cell and all cells containing a card with the same
number. For example, if a player chooses to buy a cell with Card10, he will own all cells
having a Card10.
This cell is considered a station for a specific price.
This specific price is deducted from the player’s wallet in case he chooses to buy the cell.
Whenever another player stops at a cell owned by another player, he has to pay fees to
the player who owns the cell.
 The price of the cell and the fees are taken as input during grid design.
 Input data in design mode is only taken if it is the first time to insert a card with the same
number. For example, user will insert price and fees of Card10 only once.
 Input data in design mode:
i. Card price
ii. Fees to pay by passing players

**• Card12:**
This card moves the ownership of the most expensive station that the current user owns
from the current user to the player that has the least amount of coins in his wallet.


**Important Note:** all the above cards are executed only if the current player stops at it (not passing
on it on his way).


# Team Members:
 - Yousef Mohamed El-Said Rabia
 - Mahmoud Sobhy Rashid
 - Yousef Mohamed Hajjaj

## Teacher Assistants Supervisor:
 - Eng. Eman Hossam
 - Eng. Marwa
