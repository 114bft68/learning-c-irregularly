#include <stdio.h>

int rows, space, asterisks = 1, c;

int main() {
    printf("~ Asterisks Pyramid ~\n\nEnter the amount of rows: ");
    scanf("%d", &rows);
    while ((c = getchar()) != '\n' && c != EOF) {}
    space = rows - 1;
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < space; j++) {
            printf(" ");
        }
        for (int k = 0; k < asterisks; k++) {
            printf("*");
        }
        printf("\n");
        asterisks += 2;
        space--;
    }
    return 0;
}