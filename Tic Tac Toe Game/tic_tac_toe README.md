Tic Tac Toe Game in C

This is a simple implementation of the classic Tic Tac Toe game written in the C programming language. 
It features a Player vs AI mode, where Player 1 uses X and the AI (Player 2) uses O.

Features:

1. Player vs AI: Play against a basic AI that makes random valid moves.
2. Winner Detection: Automatically detects when a player wins or if the game ends in a draw.
3. Interactive Gameplay: Easy-to-understand input for marking cells.

How to Play:

1. The game board is displayed as a grid with numbered cells:

 1 | 2 | 3
---|---|---
 4 | 5 | 6
---|---|---
 7 | 8 | 9


2. Player 1 (human) starts the game and chooses a cell by entering its number.
3. Player 2 (AI) will automatically choose a random valid cell for its turn.
4. The game continues until:
    a. One player wins (three marks in a row, column, or diagonal).
    b. The game ends in a draw (all cells are filled with no winner).


How to Compile and Run

Prerequisites:

A C compiler such as GCC.

Steps:
1. Save the code to a file named tic_tac_toe.c.
2. Open a terminal/command prompt and navigate to the directory containing the file.
3. Compile the code using:

    gcc tic_tac_toe.c -o tic_tac_toe

4. Run the game:

    ./tic_tac_toe


Example Gameplay:

 1 | 2 | 3 
---|---|---
 4 | 5 | 6 
---|---|---
 7 | 8 | 9 

Player 1 (X) turn: 1

 X | 2 | 3 
---|---|---
 4 | 5 | 6 
---|---|---
 7 | 8 | 9 

Player 2 (O) plays: 5

 X | 2 | 3 
---|---|---
 4 | O | 6 
---|---|---
 7 | 8 | 9

Game Rules

1. Winning: Get three marks in a row, column, or diagonal to win.
2. Draw: If all cells are filled and no player has won, the game ends in a draw.
3. Invalid Moves: The game prevents selecting an already occupied cell.

Future Enhancements:

1. Improve AI logic to play strategically.
2. Add Player vs Player mode.
3. Create a GUI version using a graphics library.

License
This project is open-source and free to use, modify, and distribute for educational or personal use.
