#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* filePath1 = malloc(100 * sizeof(char));
    char* filePath2 = malloc(100 * sizeof(char));

    if (filePath1 == NULL) {
        perror("Couldn't allocate memory");
        exit(1);
    } else if (filePath2 == NULL) {
        perror("Couldn't allocate memory");
        free(filePath1);
        filePath1 = NULL;
        exit(1);
    }

    printf("Please input the first valid file path: ");
    fgets(filePath1, 100, stdin);
    printf("Please input the second valid file path: ");
    fgets(filePath2, 100, stdin);
    
    filePath1[strcspn(filePath1, "\n")] = '\0';
    filePath2[strcspn(filePath2, "\n")] = '\0';
    
    FILE* file1 = fopen(filePath1, "r");
    FILE* file2 = fopen(filePath2, "r"); // r+ mode doesn't allow file truncating

    if (file1 == NULL || file2 == NULL) {
        free(filePath1);
        free(filePath2);
        filePath1 = NULL;
        filePath2 = NULL;

        if (file1 == NULL) {
            perror("Couldn't open File1");
        } else if (file2 == NULL) {
            perror("Couldn't open File2");
        }

        exit(1);
    }

    long int* fileSize1 = malloc(sizeof(long int));
    long int* fileSize2 = malloc(sizeof(long int));

    fseek(file1, 0, SEEK_END);
    *fileSize1 = ftell(file1);
    fseek(file1, 0, SEEK_SET);

    fseek(file2, 0, SEEK_END);
    *fileSize2 = ftell(file2);
    fseek(file2, 0, SEEK_SET);

    char* fileContent1 = malloc(*fileSize1 * sizeof(char));
    char* fileContent2 = malloc(*fileSize2 * sizeof(char));

    void freeFileContent() {
        free(fileContent1);
        free(fileContent2);
        fileContent1 = NULL;
        fileContent2 = NULL;
    }

    fread(fileContent1, sizeof(char), *fileSize1, file1);
    fread(fileContent2, sizeof(char), *fileSize2, file2);

    free(fileSize1);
    free(fileSize2);
    fileSize1 = NULL;
    fileSize2 = NULL;

    file1 = freopen(filePath1, "w", file1);
    file2 = freopen(filePath2, "w", file2);

    free(filePath1);
    free(filePath2);
    filePath1 = NULL;
    filePath2 = NULL;

    if (fputs(fileContent2, file1) == EOF) {
        perror("Operation stopped due to failure to swap file contents");
        freeFileContent();
        exit(1);
    } else if (fputs(fileContent1, file2) == EOF) {
        fputs(fileContent1, file1); // so that the files remain unchanged
        perror("Operation stopped due to failure to swap file contents");
        freeFileContent();
        exit(1);
    }

    freeFileContent();

    fclose(file1);
    fclose(file2);

    return 0;
}
