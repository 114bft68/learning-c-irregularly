#include <stdio.h>
#include <string.h>
#include <windows.h>

char board[] = "| 1 | 2 | 3 |\n-------------\n| 4 | 5 | 6 |\n-------------\n| 7 | 8 | 9 |",
input,
side,
player[2][5] = { {}, {} };

void handle(), s();

int c;

const char winPatterns[8][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'1', '4', '7'},
    {'2', '5', '8'},
    {'3', '6', '9'},
    {'1', '5', '9'},
    {'3', '5', '7'}
};

int main() {
    printf("- Tic Tac Toe -\n\n");
    s();
    printf("Alright, nice to meet you.\n\n");
    handle();
    return 0;
}

void s() {
    printf("Please pick your side (O or X): ");
    scanf(" %c", &side);
    while ((c = getchar()) != '\n' && c != EOF) {}
    if (side != 'O' && side != 'X') {
        s();
    }
}

void handle() {
    printf("%s\nIt's your turn, please enter the number of a slot: ", board);
    scanf(" %c", &input);
    printf("\n");
    while ((c = getchar()) != '\n' && c != EOF) {}
    if (input > '0' && input <= '9') {
        for (int i = 0; i < strlen(board); i++) {
            if (board[i] == input) {
                board[i] = side;
                player[sizeof(player[0]) / sizeof(player[0][0])] = i;
                printf("\n%s\nIt's now the bot's turn.\n\n", board);
                // bot part
                // soon
                break;
            }
        }
    } else {
        handle();
    }
}
