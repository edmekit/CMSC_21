#include <stdio.h>

int main(){
    char name[50];
    int num1, num2, num3, sum, product;

    printf("Project Description:\nThis program determines whether the product and sum of two integers are correspondingly divisible by the third integer.\n\n");

    printf("What is your name? "); fgets(name, sizeof(name), stdin);
    printf("\nHello %s\n", name);

    printf("Please input the first integer: "); scanf("%d", &num1);
    printf("Please input the second integer: "); scanf("%d", &num2);

    sum = num1 + num2;
    product = num1 * num2;

    printf("\nThe sum and product of the two integers are %d and %d, respectively.\n\n", sum, product);

    printf("Please input the third integer. We will then determine if the sum and product are correspondingly divisible by this number: ");
    scanf("%d", &num3);

    if (sum % num3 == 0){
        if (product % num3 == 0){
            printf("\nThe sum, %d, and product, %d, are both divisible by %d.\n",sum, product, num3);
        } else if(product % num3 != 0){
            printf("\nThe sum, %d, is divisble by %d. On the other hand, the product, %d, is NOT divisible by %d.\n",sum, num3, product, num3);
        }
    } else if (sum % num3 != 0){
        if (product % num3 == 0){
            printf("\nThe sum, %d, is NOT divisible by %d. On the other hand, the product, %d, is divisible by %d.\n",sum, num3, product, num3);
        } else if(product % num3 != 0){
            printf("\nNeither the sum, %d, nor the product, %d, are divisible by %d.\n",sum, product, num3);
        }
    }
}