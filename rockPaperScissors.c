#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void n() {
    int* random = malloc(sizeof(int));
    int* choice = malloc(sizeof(int));
    int* delta = malloc(sizeof(int));
    char text[12];
    char* toString[] = {"Rock", "Paper", "Scissors"};
    
    *random = rand() % 3;

    printf("0: Rock; 1: Paper; 2: Scissors; Enter your choice: ");
    scanf("%d", choice);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
        
    if (*choice > 2 || *choice < 0) {
        printf("Invalid choice!\n\n");
        free(random);
        free(choice);
        free(delta);
        random = choice = delta = NULL;
        n();
    }

    *delta = *choice - *random;

    if (*delta == 2 || *delta == -1) {
        strcpy(text, "- DEFEAT -");
    } else if (*delta == 1 || *delta == -2) {
        strcpy(text, "- VICTORY -");
    } else {
        strcpy(text, "- DRAW -");
    }

    printf("You: %s; Bot: %s;\n%s\n\n", toString[*choice], toString[*random], text);

    free(random);
    free(choice);
    free(delta);
    random = choice = delta = NULL;

    n();
}

int main() {
    srand(time(NULL));
    n();
    return 0;
}