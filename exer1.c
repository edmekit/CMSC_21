#include <stdio.h>

double exponent(double base, int expo);
int future_value(double pmt, double r, int t);
int main(void){
    int freq, cost, yearly, yearfive, year10, year20, year40;
    printf("How many times in a week do you buy milk tea? ");
    scanf("%i", &freq);

    printf("How much does you rmilk tea order typiccally cost? ");
    scanf("%i", &cost);

    yearly = freq * cost * 52;
    yearfive = yearly * 5;
    year10 = yearly * 10;
    year20 = yearly * 20;
    year40 = yearly * 40;

    printf("\nYour yearly milk tea spending is: %i\n", yearly);
    printf("\nIf you saved this money in a bank with interest, earning 4%% per year\n");
    printf("In 5 years, you would have saved %i, instead of spending %i \n", future_value(yearly, .04, 5), yearfive);
    printf("In 10 years, you would have saved %i, instead of spending %i \n", future_value(yearly, .04, 10), year10);
    printf("In 20 years, you would have saved %i, instead of spending %i \n", future_value(yearly, .04, 20), year20);
    printf("In 40 years, you would have saved %i, instead of spending %i \n", future_value(yearly, .04, 40),year40);
    return 0;
} 

int future_value(double pmt, double r, int t){
    double initial = ((exponent(1 + r, t) - 1)/r);
    double fv = pmt*initial;
    return fv;
}

double exponent(double base, int expo){
    if (expo == 0){
        return 1;
    }

    double result = 1;
    for (int i = 0;i < expo; i++){
        result *= base;
    }
    return result;
}