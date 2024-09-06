#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int number, input, lives = 10;

int main() {
    srand(time(NULL));
    number = rand() % 100 + 1;
    printf("~ Guess the Number from 1 to 100 ~\n~ You have 10 lives in total ~\n\n");
    printf("Make your first guess: ");
    while (lives > 0) {
        scanf("%d", &input);
        if (input == number) {
            printf("\nYou won!");
            lives = 0;
        } else {
            if (lives > 1) {
                lives--;
                printf("The number is %s than your previous guess: ", number > input ? "higher" : "lower");
            } else {
                printf("\nThe number was %d", number);
                lives = 0;
            }
        }
    }
    return 0;
}
