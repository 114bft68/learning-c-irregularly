#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int number, input, lives = 10;

    srand(time(NULL));
    number = rand() % 100 + 1;
    
    printf("~ Guess the Number from 1 to 100 ~\n~ You have 10 lives in total ~\n\nMake your first guess: ");
    
    while (lives > 0) {
        printf(": ");
        scanf("%d", &input);
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        lives--;
        
        if (input == number) {
            
            puts("\nYou won!");
            return 0;
        
        } else {

            printf("The number is %s than your previous guess", number > input ? "higher" : "lower ");
        
        }
    }

    puts("\nYou lost");
    return 0;
}