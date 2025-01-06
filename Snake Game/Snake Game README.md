# Games-Using-C-Language
Snake Game and Tic Tac Toe Game written in C.

Snake Game in C:

This is a simple implementation of the classic Snake game written in the C programming language. The game runs in the console and features basic functionality such as movement, score tracking, and growing the snake when it eats a fruit.

Features:
1. Console-based Gameplay: A minimalist approach using ASCII characters.
2. Dynamic Snake Growth: The snake grows as it eats the fruit.
3. Score Tracking: Tracks the player's score in real-time.
4. Wrap-around: Snake reappears on the opposite side when it crosses the boundary.
5. Game Over: The game ends if the snake collides with itself.

How to Play:

Use the following keys to control the snake:

1. W: Move Up

2. A: Move Left

3. S: Move Down

4. D: Move Right

5. X: Exit the game

Eat the fruit (F) to score points and grow the snake.
Avoid running into your own tail to prevent a game over.

Compilation and Execution

Prerequisites:

A C compiler like GCC.
A Windows operating system (uses <windows.h> for console manipulation).

Steps:
1. Save the code to a file named snake_game.c.
2. Open a terminal/command prompt and navigate to the directory containing the file.
3. Compile the code using the following command:
    gcc snake_game.c -o snake_game
   
5. Run the game:
    ./snake_game

Example Gameplay


######################
#                    #
#         O          #
#                    #
#         F          #
#                    #
#                    #
######################

Score: 10


Known Limitations:

1. The game currently supports only single-player mode.
2. The console interface is basic and may not be visually appealing.

Future Enhancements:

1. Adding walls or obstacles for increased difficulty.
2. Implementing levels with varying speeds.
3. Supporting cross-platform compatibility.

License

This project is for educational purposes and is open-source. Feel free to use, modify, and distribute it.
