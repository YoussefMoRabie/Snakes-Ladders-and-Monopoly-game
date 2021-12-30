# Snakes-Ladders-and-Monopoly-game
A project by Cairo engineering students for programming for first graders, which is a project we are going to build a simple game application that is a mixture between the Snakes &amp; Ladders and Monopoly games. There are two modes in the game: Design mode is where The user is able to build the playing grid and Play mode is where he plays the game itself. The general idea of the game is four players moving in a grid having snakes, ladders, and Cards. The player goal is to get to the last cell before anyone else
Snakes-ladders-and-Monopoly-
A OOP class project were the rules of object oriented programming are used to implement the game's stucture.

# Game description
4 players will compete to reach the cell 99 on the grid with all of them starting from cell 1
snakes get you down ladders get you up and cards can be your friend or your worst enemy
players start the game with 100 coins in their wallets and every three dice rolls the player don't move on the grid but get his wallet charged by 10*dice_value
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

