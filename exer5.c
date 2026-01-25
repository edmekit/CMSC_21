#include <stdio.h>
#include <string.h>

int manageWords(char words[][5], int *size);
int printWordPool(char words[][5], int *size);
int insertWord(char words[][5], int *size);

int main(){
    char words[][5] = {"feel", "teal", "reel"};
    int number = sizeof(words) / sizeof(words[0]);
    int* size = &number;
    int menu;
    printf("Welcome to Terminal Wordle.\n");
    printf("[1] Play the game.\n");
    printf("[2] Manage words.\n");
    printf("[0] Exit.\n");

    printf("Choose an option: "); scanf("%i", &menu);

    if (menu == 2){
        manageWords(words, size);
    } else {
        return 0;
    }
}

int manageWords(char words[][5], int *size){
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
        insertWord(words, size);
    } else if (menu == 3){
        deleteWord(words, size);
    }
}
}

int printWordPool(char words[][5], int *size){
    printf("Current size: %d\n", *size);
    for (int i = 0; i < *size; i++){
        printf("%s\n", words[i]);
    }
}

int insertWord(char words[][5], int *size){
    char word[5];
    printf("Enter Word to insert: "); scanf("%s", word);
    for (int i = 0; i < 5; i++){
        words[*size][i] = word[i];
    }
    (*size)++;
}

int deleteWord(char words[][5], int *size){
    
}