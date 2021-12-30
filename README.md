# Snakes-Ladders-and-Monopoly-game
A project by Cairo engineering students for programming for first graders, which is a project we are going to build a simple game application that is a mixture between the Snakes &amp; Ladders and Monopoly games. There are two modes in the game: Design mode is where The user is able to build the playing grid and Play mode is where he plays the game itself. The general idea of the game is four players moving in a grid having snakes, ladders, and Cards. The player goal is to get to the last cell before anyone else
Snakes-ladders-and-Monopoly-
A OOP class project were the rules of object oriented programming are used to implement the game's stucture.

Game description
4 players will compete to reach the cell 99 on the grid with all of them starting from cell 1
snakes get you down ladders get you up and cards can be your friend or your worst enemy
players start the game with 100 coins in their wallets and every three dice rolls the player don't move on the grid but get his wallet charged by 10*dice_value
The Cards rules
1. Card1:
• Decrements the value of the passing player’s wallet by a value specified when creating
the grid.
• Input data in design mode:
i.Value to decrement
2. Card2:
• Moves the player forward to the start of the next ladder in the grid.
• If no ladders ahead, do nothing.
3. Card3 and Card4:
• Card3 gives the player an extra dice roll.
• Card4 prevents the player from rolling the next turn.
• Both the extra dice roll or the canceled dice roll count normally towards recharging the
wallet turn (both increment the count of player turns).
4. Card5:
• Moves the player backward with the same number of steps that he just rolled.
• If he reaches a ladder, a snake, or a card at the end of moving, take it.
5. Card6:
• Instructs the player to go to a specific cell.
• If the destination cell contains a ladder, snake, or card, take it.
• Input data in design mode:
i. Cell to move to
6. Card7:
• Restarts the game for the first player whose cell is after the current player in the grid.
• Restarting the game for a player makes him go to cell number 1.
