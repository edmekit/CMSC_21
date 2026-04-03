#include <stdio.h>




int main(){
    FILE* fp;
    char str[100];
    int i;
    char cur_char;

    fp = fopen("testfile.txt", "r+");

    if (fgetc(fp) == EOF) {
        printf("Enter your name: "); fgets(str, 100, stdin);
        fputs(str, fp);
    } else {
        rewind(fp);
        printf("Hello, ");
        fgets(str, 100, fp);
        printf("%s", str);
    }


    fclose(fp);
}

