#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 20

int gameOver, score;
int x, y, fruitX, fruitY, tailX[100], tailY[100];
int nTail;
int dir; // 0: left, 1: right, 2: up, 3: down

void Setup();
void Draw();
void Input();
void Logic();
void gotoxy(int x, int y);
void GenerateFruit();

int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(100);  // Sleep to control game speed (based on difficulty)
    }
    return 0;
}

void Setup() {
    gameOver = 0;
    dir = 1;  // Start moving right
    x = WIDTH / 2;
    y = HEIGHT / 2;
    GenerateFruit();
    score = 0;
}

void Draw() {
    system("cls");
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                printf("#");
            else if (j == x && i == y)
                printf("O");
            else if (j == fruitX && i == fruitY)
                printf("F");
            else {
                int isPrint = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        isPrint = 1;
                        break;
                    }
                }
                if (!isPrint)
                    printf(" ");
            }
            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    printf("Score: %d\n", score);
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': dir = 0; break;
            case 'd': dir = 1; break;
            case 'w': dir = 2; break;
            case 's': dir = 3; break;
            case 'x': gameOver = 1; break;
        }
    }
}

void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case 0: x--; break;
        case 1: x++; break;
        case 2: y--; break;
        case 3: y++; break;
    }

    if (x >= WIDTH) x = 0; else if (x < 0) x = WIDTH - 1;
    if (y >= HEIGHT) y = 0; else if (y < 0) y = HEIGHT - 1;

    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = 1;
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        GenerateFruit();
        nTail++;
    }
}

void GenerateFruit() {
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

