#include <stdio.h>

int main(void){
    float interest_rate, tax_rate, principal, term;

    printf("Enter principal: "); scanf("%f", &principal);
    printf("Enter term: "); scanf("%f", &term);
    printf("Enter interest: "); scanf("%f", &interest_rate); 
    printf("Enter tax: "); scanf("%f", &tax_rate);

    float interest = (principal * (interest_rate / 100)) / 12;
    float tax = interest * (tax_rate / 100);
    float net_income = interest - tax;
    float balance = principal + net_income;

    float total_interest = 0;
    float total_tax = 0;
    float total_net_income = 0; 

    printf("Month\tPrincipal\tInterest\tTax\tNet Income\tBalance\n");
    
    for (int i = 1; i < (term * 12) + 1; i++){
        printf("%i\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", i, principal, interest, tax, net_income, balance);

        total_interest += interest;
        total_tax += tax;
        total_net_income += net_income;
        
        principal = balance;
        interest = (principal * (interest_rate / 100)) / 12;
        tax = interest * (tax_rate / 100);
        net_income = interest - tax;
        balance = principal + net_income;        
    }
    
    printf("Totals %.2f\t%.2f\t%.2f\n", total_interest, total_tax, total_net_income);
}