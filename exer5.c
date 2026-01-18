#include <stdio.h>
#include <string.h>

int words[10];

int main(){
    int menu;
    printf("Welcome to Terminal Wordle.\n");
    printf("[1] Play the game.\n");
    printf("[2] Manage words.\n");
    printf("[0] Exit.\n");

    printf("Choose an option: "); scanf("%i", &menu);

    if (menu == 2){
        manageWords();
    } else {
        return 0;
    }
}

int manageWords(){
    int menu;
    printf("Manage Words\n");
    printf("[1] Print Word Pool\n");
    printf("[2] Insert New Word\n");
    printf("[3] Delete Word\n");
    printf("[4] Reset Word Pool\n");
    printf("[0] Exit.\n");

    printf("Choose an option: "); scanf("%i", &menu);

    if (menu == 1){
        printWordPool();
    } else if (menu == 2){
        insertWord();
    } else if (menu == 3){
        deleteWord();
    } else if (menu == 4){
        resetWord();
    }
}

int printWordPool(){
    for (int i = 0; i < 10; i++){
        printf("%s\n", words[i]);
    }
}

int insertWord(){
    char word[5];
    printf("Enter Word to insert: "); scanf("%s", word);
    
}