#include <stdio.h>

#define SIZE 3  // Size of the Tic-Tac-Toe board

// Function to print the Tic-Tac-Toe board
void print_board(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
}

// Function to check if a player has won
int check_winner(char board[SIZE][SIZE], char player) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }

    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return 1;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;

    return 0;
}

// Function to check if the board is full (draw)
int is_draw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ')  // Empty space found
                return 0;  // Not a draw yet
        }
    }
    return 1;  // The board is full
}

// Function to play the game
void play_game() {
    char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int row, col;
    int player_turn = 0;  // 0 for 'X', 1 for 'O'
    char player_symbol;
    int winner = 0;

    while (1) {
        // Print the board
        print_board(board);

        // Determine which player's turn it is
        player_symbol = (player_turn == 0) ? 'X' : 'O';
        printf("Player %c's turn. Enter row (1-3) and column (1-3): ", player_symbol);
        scanf("%d %d", &row, &col);

        // Adjust input for 0-indexed array
        row--;
        col--;

        // Check for valid input
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Place the player's mark
        board[row][col] = player_symbol;

        // Check for a winner
        if (check_winner(board, player_symbol)) {
            print_board(board);
            printf("Player %c wins!\n", player_symbol);
            break;
        }

        // Check for a draw
        if (is_draw(board)) {
            print_board(board);
            printf("It's a draw!\n");
            break;
        }

        // Switch player turn
        player_turn = 1 - player_turn;
    }
}

int main() {
    printf("Welcome to Tic-Tac-Toe!\n");
    play_game();
    return 0;
}
