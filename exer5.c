#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototypes
int manageWords(char **words, int *size, int *capacity);
int printWordPool(char **words, int *size);
int insertWord(char ***words, int *size, int *capacity);
int deleteWord(char **words, int *size);
int resetWords(int *size);
int playGame(char **words, int *size);
void copylist(char **copy_list, char **orig_list, int size);
int checkIn(char words[5], char a, int size);

int main(){
    int menu;
    char **words;
    int size = 0;
    int capacity = 3;

    words = malloc(capacity * sizeof(char *)); // assign memory to the main list

    while (1) {
    printf("\nWelcome to Terminal Wordle.\n");
    printf("[1] Play the game.\n");
    printf("[2] Manage words.\n");
    printf("[0] Exit.\n");

    printf("Choose an option: "); scanf("%i", &menu);
    printf("\n");
    if (menu == 1){
        playGame(words, &size);
    }
    else if (menu == 2){
        manageWords(words, &size, &capacity);
    } else {
        for (int i = 0; i < size; i++){
            free(words[i]);
        }
        free(words);
        printf("Thank you.\n");
        return 0;
    }
}
}


int playGame(char **words, int *size){
    if (*size == 0) {
        printf("No words available to play the game.\n");
        return 0;
    }

    char guess[5];
    char word[5];
    char **copy_words;
    copy_words = malloc(*size * sizeof(char *));

    for (int i = 0; i < *size; i++){
        copy_words[i] = malloc(5 * sizeof(char));
    }

    copylist(copy_words, words, *size);

    int random_word = rand() % *size;
    strcpy(word, copy_words[random_word]);

    char guess_display[4] = {'_', '_', '_', '_'};
    while(1){
        for (int i = 0; i < 4; i++){
            printf("%c", guess_display[i]);
        }

        printf("\nGuess: "); scanf("%4s", guess);
        if (strcmp(word, guess) == 0){
            printf("You won!\n");
            break;
        } else {
            for (int i = 0; i < 4; i++){
                if (guess[i] == word[i]){
                    guess_display[i] = guess[i];
                } else if (checkIn(word, guess[i], 4)){
                    guess_display[i] = '*';
                } else {
                    guess_display[i] = '-';
                }
            }
        }
    }
    

    free(copy_words);
}

int manageWords(char **words, int *size, int *capacity){
    int menu;
    while (1){
    printf("\nManage Words\n");
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

int printWordPool(char **words, int *size){
    printf("Current size: %d\n", *size);
    for (int i = 0; i < *size; i++){
        printf("%s\n", words[i]);
    }
}

int insertWord(char ***words, int *size, int *capacity){
    if (*size == *capacity){
        *capacity *= 2;
        *words = realloc(*words, *capacity * sizeof(char *));
    }

    (*words)[*size] = malloc(5 * sizeof(char));
    printf("Enter Word to insert: "); scanf("%4s", (*words)[*size]);
    (*size)++;
}

int deleteWord(char **words, int *size){
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

void copylist(char **copy_list, char **orig_list, int size){
    for (int i = 0; i < size; i++){
        strcpy(copy_list[i], orig_list[i]);
    }
}

int checkIn(char words[5], char a, int size){
    for (int i = 0; i < size; i++){
        if (words[i] == a){
            return 1;
        }
    }
    return 0;
}