#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int manageWords(char (*words)[5], int *size, int *capacity);
int printWordPool(char (*words)[5], int *size);
int insertWord(char (**words)[5], int *size, int *capacity);
int deleteWord(char (*words)[5], int *size);
int resetWords(int *size);
int playGame();

int main(){
    int menu;
    char (*words)[5] = NULL;
    int size = 0;
    int capacity = 3;

    words = malloc(capacity * sizeof(*words));

    printf("Welcome to Terminal Wordle.\n");
    printf("[1] Play the game.\n");
    printf("[2] Manage words.\n");
    printf("[0] Exit.\n");

    printf("Choose an option: "); scanf("%i", &menu);
    if (menu == 1){
        playGame();
    }
    if (menu == 2){
        manageWords(words, &size, &capacity);
    } else {
        free(words);
        return 0;
    }
}

int playGame(){
    //making onli
}

int manageWords(char (*words)[5], int *size, int *capacity){
    while (1){
    int menu;
    printf("Manage Words\n");
    printf("[1] Print Word Pool\n");
    printf("[2] Insert New Word\n");
    printf("[3] Delete Word\n");
    printf("[4] Reset Word Pool\n");
    printf("[0] Exit.\n");

    printf("Choose an option: "); scanf("%i", &menu);

    if (menu == 1){
        printWordPool(words, size);
    } else if (menu == 2){
        insertWord(&words, size, capacity);
    } else if (menu == 3){
        deleteWord(words, size);
    } else if (menu == 4){
        resetWords(size);
    } else if (menu == 0){
        return 0;
    } else {
        printf("Invalid option.\n");
    }
}
}

int printWordPool(char (*words)[5], int *size){
    printf("Current size: %d\n", *size);
    for (int i = 0; i < *size; i++){
        printf("%s\n", words[i]);
    }
}

int insertWord(char (**words)[5], int *size, int *capacity){
    if (*size == *capacity){
        *capacity *= 2;
        *words = realloc(*words, *capacity * sizeof(*(*words)));
    }

    char word[5];
    printf("Enter Word to insert: "); scanf("%4s", word);
    for (int i = 0; i < 5; i++){
        *words[*size][i] = word[i];
    }
    (*size)++;
}

int deleteWord(char (*words)[5], int *size){
    char word[5];
    printWordPool(words, size);
    printf("Enter word to delete: ") ; scanf("%4s", word);

    int position = -1; 

    for (int i = 0; i < *size; i++){
        if (strcmp(words[i], word) == 0){
            position = i;
            break;
        }
    }

    if (position == -1){
        printf("Word is not on the list.\n");
        return 0;
    }

    for (int i = position + 1; i < *size; i++){
        for (int j = 0; j < 5; j++){
            words[i - 1][j] = words[i][j];
        }
    }

    (*size)--;
}

int resetWords(int *size){
    *size = 0;
}