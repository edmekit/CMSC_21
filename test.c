#include <stdio.h>

int recur(int num, int sum);
void div7(int num, int* count);

int main(){
    int count = 0;
    int* k = &count;
    (*k) = 1;
    printf("%d\n", count);

    div7(25, &count);
    printf("%d\n", count);
    printf("%d\n", recur(9348, 0));
}

int recur(int num, int sum){
    if (num == 0){
        return sum;
    }
    else {
        int last = num % 10;
        return recur((num - last) / 10, sum + last);
    }
}

void div7(int num, int* count){
    for (int i = 1; i <= num; i++){
        if (i % 7 == 0){
            (*count)++;
        }
    }
}