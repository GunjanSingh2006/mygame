#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char board[9] = {'1','2','3','4','5','6','7','8','9'};

void drawBoard() {
    system("cls");  // clear screen
    printf("\n\n   TIC - TAC - TOE\n");
    printf("   Player 1 (X)  -  Player 2 (O)\n\n");

    printf("        |       |      \n");
    printf("    %c   |   %c   |   %c \n", board[0], board[1], board[2]);
    printf("  _____||\n");
    printf("        |       |      \n");
    printf("    %c   |   %c   |   %c \n", board[3], board[4], board[5]);
    printf("  _____||\n");
    printf("        |       |      \n");
    printf("    %c   |   %c   |   %c \n", board[6], board[7], board[8]);
    printf("        |       |      \n\n");
}

int checkWin() {
    // rows
    if (board[0]==board[1] && board[1]==board[2]) return 1;
    if (board[3]==board[4] && board[4]==board[5]) return 1;
    if (board[6]==board[7] && board[7]==board[8]) return 1;

    // columns
    if (board[0]==board[3] && board[3]==board[6]) return 1;
    if (board[1]==board[4] && board[4]==board[7]) return 1;
    if (board[2]==board[5] && board[5]==board[8]) return 1;

    // diagonals
    if (board[0]==board[4] && board[4]==board[8]) return 1;
    if (board[2]==board[4] && board[4]==board[6]) return 1;

    return 0;
}

int checkDraw() {
    for (int i = 0; i < 9; i++)
        if (board[i] != 'X' && board[i] != 'O')
            return 0;
    return 1;
}

int main() {
    int player = 1, choice;
    char mark;

    while (1) {
        drawBoard();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number (1-9): ", player);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid move! Press any key...");
            getch();
            continue;
        }

        mark = (player == 1) ? 'X' : 'O';

        if (board[choice-1] != 'X' && board[choice-1] != 'O') {
            board[choice-1] = mark;
        } else {
            printf("Position already taken! Press any key...");
            getch();
            continue;
        }

        if (checkWin()) {
            drawBoard();
            printf("==> Player %d wins!\n", player);
            break;
        }

        if (checkDraw()) {
            drawBoard();
            printf("==> Game Draw!\n");
            break;
        }

        player++;
    }

    printf("\nPress any key to exit...");
    getch();
    return 0;
}
