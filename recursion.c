#include <stdio.h>

int make_triangle(int size, int curr);
int main() {
    int size;

    printf("How many rows: "); scanf("%d", &size);

    make_triangle(size, 0);
}

int make_triangle(int size, int curr) {
    if (curr == size){
        return 0;
    } else {
        for (int i = 0; i < size - curr; i++){ // loop for spaces, decreasing
            printf(" ");
        }
        for (int i = 0; i < curr + 1; i++){ // loop for *, increasing
            printf(" *");
        } printf("\n");
        curr++;
        make_triangle(size, curr);
    }
}
