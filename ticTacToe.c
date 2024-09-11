#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char board[] = "| 1 | 2 | 3 |\n-------------\n| 4 | 5 | 6 |\n-------------\n| 7 | 8 | 9 |", input;

void boardStuff(), win(char first, char second, char third);

char players[2][5] = { {}, {} };

int indices[2] = {0, 0};

bool turn = false, end = false;

int main() {
    printf("~ Tic Tac Toe ~\n\n%s\n", board);
    boardStuff();
    return 0;
}

void boardStuff() {
    printf("\nPlayer%d, enter the number of a slot: ", turn);
    scanf(" %c", &input);
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {} // buffer clearing thing, I don't really know what it is but I'll learn about that later
    
    if (input > '0' && input <= '9') { // I want regex
        if (turn) {
            players[1][indices[1]++] = input;
        } else {
            players[0][indices[0]++] = input;
        }
        for (int i = 0; i < strlen(board); i++) {
            if (board[i] == input) {
                board[i] = turn ? 'O' : 'X';
            }
        }
        turn = !turn;
        printf("\n%s\n", board);
        win('1', '2', '3'); win('4', '5', '6'); win('7', '8', '9'); win('1', '4', '7'); win('2', '5', '8'); win('3', '6', '9'); win('1', '5', '9'); win('3', '5', '7');
        boardStuff();
    } else {
        boardStuff();
    }
}

void win(char first, char second, char third) {
    int count[2] = { 0, 0 };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < (sizeof(players[0]) / sizeof(players[0][0])); j++) {
            if (players[i][j] == first || players[i][j] == second || players[i][j] == third) {
                count[i]++;
            }
        }
        if (count[i] == 3) {
            printf("\nPlayer%d wins", i);
            exit(0);
        }
    }
}
