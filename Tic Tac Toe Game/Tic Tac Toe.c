#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int currentPlayer = 1;  // Player 1 = 'X', Player 2 = 'O'

void draw_board();
int check_winner();
void player_move();
void ai_move();

int main() {
    int winner = 0;
    while (winner == 0) {
        draw_board();
        if (currentPlayer == 1) {
            player_move();
        } else {
            ai_move();
        }
        winner = check_winner();
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
    draw_board();
    if (winner == 1)
        printf("Player 1 (X) wins!\n");
    else if (winner == 2)
        printf("Player 2 (O) wins!\n");
    else
        printf("It's a draw!\n");

    return 0;
}

void draw_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int check_winner() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return (board[i][0] == 'X') ? 1 : 2;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return (board[0][i] == 'X') ? 1 : 2;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return (board[0][0] == 'X') ? 1 : 2;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return (board[0][2] == 'X') ? 1 : 2;

    // Check for draw
    int draw = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                draw = 0;
                break;
            }

    return (draw) ? 3 : 0; // Return 3 for draw
}

void player_move() {
    int move;
    printf("Player 1 (X) turn: ");
    scanf("%d", &move);
    if (move < 1 || move > 9) {
        printf("Invalid move. Try again.\n");
        player_move();
        return;
    }
    if (board[(move - 1) / 3][(move - 1) % 3] == 'X' || board[(move - 1) / 3][(move - 1) % 3] == 'O') {
        printf("Cell already occupied. Try again.\n");
        player_move();
    } else {
        board[(move - 1) / 3][(move - 1) % 3] = 'X';
    }
}

void ai_move() {
    int move = rand() % 9 + 1;
    while (board[(move - 1) / 3][(move - 1) % 3] == 'X' || board[(move - 1) / 3][(move - 1) % 3] == 'O')
        move = rand() % 9 + 1;
    printf("Player 2 (O) plays: %d\n", move);
    board[(move - 1) / 3][(move - 1) % 3] = 'O';
}

