#include <stdio.h>
#include <string.h>

int main(void) {
    char fuel[10];
    int liters, paid;
    double change, gasoline, total;

    printf("What type of fuel? "); scanf("%s", fuel);
    printf("\nHow many liters bought? "); scanf("%i", &liters); 
    printf("\nHow much paid? "); scanf("%i", &paid);

    if (liters == 0 || liters < 0) {
        printf("Cannot buy 0 or negative liters of fuel.\n");
    } else if (strcmp(fuel, "DIESEL") == 0) {
        gasoline = 66.5;
    } else if (strcmp(fuel, "PREMIUM") == 0) {
        gasoline = 71.45;
    } else if (strcmp(fuel, "UNLEADED") == 0) {
        gasoline = 69.36;
    } else if (strcmp(fuel, "KEROSENE") == 0) {
        gasoline = 67.56;
    } else {
        printf("Invalid fuel type.\n");
        return 1;
    }

    total = liters * gasoline;
    
    if (paid < total) {
        double kulang = total - paid;
        printf("Customer needs to add %f pesos to buy the item.", kulang);
    } else {
        change = paid - total;
        printf("Customer change is %f pesos.", change);
    }
    return 0;
}