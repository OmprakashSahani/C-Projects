#include <stdio.h>
#include <stdlib.h>

#define PLAYER 'X'
#define COMPUTER 'O'
#define EMPTY ' '

char board[3][3];

// Function prototypes
void print_board();
int check_winner();
int minimax(int depth, int isMax);
int find_best_move();
void make_move(int row, int col, char player);

int main() {
    int row, col;
    int game_over = 0;

    // Initialize the board
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = EMPTY;

    while (!game_over) {
        print_board();

        // Player move
        printf("Enter row (0-2) and column (0-2) for your move: ");
        scanf("%d %d", &row, &col);

        if (board[row][col] == EMPTY) {
            make_move(row, col, PLAYER);

            if (check_winner() == 1) {
                print_board();
                printf("Player wins!\n");
                break;
            }
            // Computer's move
            int best_move = find_best_move();
            row = best_move / 3;
            col = best_move % 3;
            make_move(row, col, COMPUTER);

            if (check_winner() == -1) {
                print_board();
                printf("Computer wins!\n");
                break;
            }
        } else {
            printf("Invalid move, try again.\n");
        }
    }

    return 0;
}

void print_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void make_move(int row, int col, char player) {
    board[row][col] = player;
}

int check_winner() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY)
            return (board[i][0] == PLAYER) ? 1 : -1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY)
            return (board[0][i] == PLAYER) ? 1 : -1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY)
        return (board[0][0] == PLAYER) ? 1 : -1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY)
        return (board[0][2] == PLAYER) ? 1 : -1;
    return 0;
}

int minimax(int depth, int isMax) {
    int score = check_winner();
    if (score == 1) return -10 + depth;
    if (score == -1) return 10 - depth;

    int moves_left = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY)
                moves_left++;
        }
    }

    if (moves_left == 0) return 0;

    if (isMax) {
        int best = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = COMPUTER;
                    best = (best > minimax(depth + 1, !isMax)) ? best : minimax(depth + 1, !isMax);
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER;
                    best = (best < minimax(depth + 1, !isMax)) ? best : minimax(depth + 1, !isMax);
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    }
}

int find_best_move() {
    int best_val = -1000;
    int best_move = -1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = COMPUTER;
                int move_val = minimax(0, 0);
                board[i][j] = EMPTY;
                if (move_val > best_val) {
                    best_move = i * 3 + j;
                    best_val = move_val;
                }
            }
        }
    }
    return best_move;
}
