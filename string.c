#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // trying out string functions
    char name[] = "Hello, ";
    char *greet;
    printf("%s\n", name);
    
    greet = "Worlddd";
    strcpy(name, greet);
    printf("%s\n", name);
}