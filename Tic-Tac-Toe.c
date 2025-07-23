#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'O';
const char COMPUTER = 'X';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char winner);

int main() {
    char winner = ' ';

    resetBoard();
    printBoard();

    while (1) {
          playerMove();
         printBoard();
         winner = checkWinner();
         if (winner != ' ' || checkFreeSpaces() == 0)
            break;

        computerMove();
        printBoard();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0)
            break;
    }

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
    printf("%c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("--|---|--\n");
    printf("%c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("--|---|--\n");
    printf("%c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
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

void playerMove() {
    int x, y;
    do {
        printf("Enter row and column (1-3) for your move: ");
        scanf("%d%d", &x, &y);
        x--; y--;
        if (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != ' ')
            printf("Invalid move. Try again.\n");
        else
            break;
    } while (1);
    board[x][y] = PLAYER;
}

void computerMove() {
    int x, y;
    srand(time(0));
    if (checkFreeSpaces() > 0) {
        do {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
        printf("Computer played at %d, %d\n", x + 1, y + 1);
    }
}

char checkWinner() {
    // Rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];
    return ' ';
}

void printWinner(char winner) {
    if (winner == PLAYER)
        printf("You win!\n");
    else if (winner == COMPUTER)
        printf("You lose!\n");
    else
        printf("OMG!It's a tie\n");
}
