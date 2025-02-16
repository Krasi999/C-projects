#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char board[3][3];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove(char player);
char checkWinner();
void printWinner(char winner);

int main() {
    char winner = ' ';
    resetBoard();

    while (winner == ' ' && checkFreeSpaces() > 0) {
        printBoard();
        playerMove(PLAYER1);
        winner = checkWinner();

        if (winner != ' ')
            break;

        printBoard();
        playerMove(PLAYER2);
        winner = checkWinner();
    }

    printBoard();
    printWinner(winner);

    return 0;
}

void resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int checkFreeSpaces() {
    int freeSpaces = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                freeSpaces++;
        }
    }
    return freeSpaces;
}

void playerMove(char player) {
    int x, y;
    do {
        printf("Player %c's turn:\n", player);
        printf("Enter row (1-3): ");
        scanf("%d", &x);
        printf("Enter column (1-3): ");
        scanf("%d", &y);
        x--;
        y--;
        if (x < 0 || x >= 3 || y < 0 || y >= 3 || board[x][y] != ' ') {
            printf("Invalid move. Try again.\n");
        } else {
            board[x][y] = player;
            break;
        }
    } while (1);
}

char checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' '))
        return board[1][1];

    // Check for tie
    if (checkFreeSpaces() == 0)
        return 'T';

    return ' ';
}

void printWinner(char winner) {
    if (winner == PLAYER1)
        printf("Player 1 wins!\n");
    else if (winner == PLAYER2)
        printf("Player 2 wins!\n");
    else
        printf("It's a tie!\n");
}
