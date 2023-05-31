#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[3][3];

// Function to initialize the board
void initializeBoard() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    printf("\n\n\t  ");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d %d",i+1,j+1);
            if (j < 2)
            {
                printf("  |  ");
            }
        }
        if (i < 2)
        printf("\n\t------------------------\n\t  ");
    }
    printf("\n\n\n");
}

//Function to print the board
void printBoard() {
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) {
                printf(" | ");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("----|-----|----\n");
        }
    }
    printf("\n");
}

// Function to check if the game has been won
bool checkWin(char player) {
    int i;
    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return true;
        }
    }
    // Check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] == player && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return true;
    }
    if (board[0][2] == player && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // Empty cell found, game is not a draw
            }
        }
    }
    return true; // No empty cell found, game is a draw
}

// Function to get the player's move
void get_player_move(char player) {
    int row, col;
    printf("Player %c\nenter your move (row column): ",player);
    scanf("%d %d", &row, &col);
    row--;
    col--; 

    // Check if the move is valid
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        printf("Invalid move. Please Enter a valid value.\n");
        get_player_move(player);
    } else 
     { board[row][col] = player;
    }
}

// Function to get the computer's move
void get_computer_move(char player) {
    int row, col;
    printf("Computer's turn:\n");

    // Generate random moves until a valid move is found
    while (true) {
        row = rand() % 3;
        col = rand() % 3;
        if (board[row][col] == ' ') {
            board[row][col] = player;
            break;
        }
    }
}

int main() {
    int mode;
    printf("\t**TIC TAC TOE** \n\n");
    printf("*MENU\n");
    printf("#Choose the mode:\n\n");
    printf("1. Player vs Player\n");
    printf("2. Player vs Computer\n\n");
    printf("Enter the mode number: ");
    scanf("%d", &mode);
    initializeBoard();
    printf("Game board\n");
    printBoard();

    char player1, player2;
    if (mode == 1) {
        printf("\n* Instructions \n\n");
    printf("\tPlayer 1 sign = X\n");
    printf("\tPlayer 2 sign = O\n");
        player1 = 'X';
        player2 = 'O';
    } else if (mode == 2) {
        printf("\n* Instructions \n\n");
    printf("\tPlayer 1 sign = X\n");
    printf("\tPlayer 2 sign = C\n");
        player1 = 'X';
        player2 = 'C';
    } else {
        printf("Invalid mode.\nPlease try again...\n");
        return 0;
    }

   

    while (true) {

        if (mode == 1 || mode == 2) {
            get_player_move(player1);
        }
        printBoard();
        if (checkWin(player1)) {
            printf("**PLAYER 1 WINS!**\n");
            break;
        } else if (checkDraw()) {
            printf("*DRAW...\n");
            break;
        }

        if (mode == 1) {
            get_player_move(player2);
        } else if (mode == 2) {
            get_computer_move(player2);
        }
        printBoard();
        if (checkWin(player2)) {
            if (mode == 1) {
                printf("**PLAYER 2 WINS!**\n");
            } else if (mode == 2) {
                printf("**COMPUTER WINS**\n");
            }
            break;
        } else if (checkDraw()) {
            printf("*DRAW...\n");
            break;
        }
    }
 printf("\n :: Thanks for playing Tic Tac Toe game! :: \n");
    return 0;
}