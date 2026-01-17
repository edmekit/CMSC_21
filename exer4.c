#include <stdio.h>

int buy_mats(int gold);
void craft_weapons();
int sell_all_weapons(int gold);
void check_inventory(int gold);
int iron, wood, sword, spear, axe;

int main(void){
    int day, gold, menu;
    day = 1;
    gold = 20;

    while (1){
        printf("\nDAY %i\t", day);
        printf("Gold: %i\n", gold);
        printf("[1] Buy Materials\n");
        printf("[2] Craft Weapons\n");
        printf("[3] Sell All Weapons\n");
        printf("[4] Check inventory\n");
        printf("[0] Exit\n");
        printf("Choose an option: "); scanf("%i", &menu);

        if (menu == 0){
            printf("For %i days, you collected %i golds.", day, gold);
            break;
        } else if(menu == 1){
            gold = buy_mats(gold);
            day += 1;
        } else if (menu == 2){
            craft_weapons();
            day += 1;
        } else if (menu == 3){
            gold = sell_all_weapons(gold);
            day += 1;
        } else if (menu == 4){
            check_inventory(gold);    
        } else {
            printf("Invalid option.\n");
        }
    }
}

int buy_mats(int gold){
    while(1){
        int menu,cost, bought;
        printf("\nBUY MATERIALS\n");
        printf("Gold: %i\t| Iron: %i\t| Wood: %i\n", gold, iron, wood);
        printf("(1) Iron [2 gold each]\n");
        printf("(2) Wood [1 gold each]\n");
        printf("(0) Back to main menu\n");

        printf("Which weapon to buy: "); scanf("%i", &menu);
        if (menu == 1){
            printf("How many: "); scanf("%i", &bought);
            cost = bought * 2;
            if (gold < cost) {
                int kulang = cost - gold;
                printf("Lacks %i gold to buy.\n", kulang);
            } else {
                gold -= cost;
                printf("Successfully bought %i iron(s) for %i gold.\n",bought, cost);
                iron += bought;
        }
        } else if (menu == 2){
            printf("How many: "); scanf("%i", &bought);
            cost = bought;
            if (gold < cost) {
                int kulang = cost - gold;
                printf("Lacks %i gold to buy.\n", kulang);
            } else {
                gold -= cost;
                printf("Successfully bought %i wood(s) for %i gold.\n",bought, cost);
                wood += bought;
        }
        } else if (menu == 0){
            return gold;
        } else {
            printf("Invalid option.\n");
            continue;
        }
    }
}

void craft_weapons(){
    while(1){
        int menu, crafted;
        printf("\nCRAFT WEAPONS\n");
        printf("Iron: %i\t| Wood: %i\n", iron, wood);

        printf("(1) Craft Sword [2 iron & 1 wood]\n");
        printf("(2) Craft Spear [1 iron & 2 wood]\n");
        printf("(3) Craft Axe [3 iron & 2 wood]\n");
        printf("(0) Back to main menu\n");

        printf("Choose from the option: "); scanf("%i", &menu);
        
        if (menu == 1){
            while (iron > 1 && wood > 0){
                crafted += 1;  
                iron -= 2;
                wood -= 1;
            }
            sword += crafted;
            printf("Successfully crafted %i swords.\n", crafted);
        } else if (menu == 2){
            while (iron > 0 && wood > 1){
                crafted += 1;
                iron -= 1;
                wood -= 2;
            }
            spear += crafted;
            printf("Successfully crafted %i spears.\n", crafted);
        } else if (menu == 3){
            while (iron > 2 && wood > 1){
                crafted += 1;
                iron -= 3;
                wood -= 2;
            }
            axe += crafted;
            printf("Successfully crafted %i axes.\n", crafted);
        } else if (menu == 0){
            return;
        } else {
            printf("Invalid option.\n");
        }
    }
}

int sell_all_weapons(int gold){
    int menu;
    printf("\nSELL ALL WEAPONS\n");
    printf("Gold : %i\n| Sword: %i [9G each]\n| Spear: %i[8G each]\n| Axe: %i[15G each]\n", gold, sword, spear, axe);
    int profit = (sword * 9) + (spear * 8) + (axe * 15);
    printf("Total profit: %i\n", profit);
    printf("Do you want to sell all? [1] Yes [2] No\n"); scanf("%i", &menu);
    if (menu == 1){
        gold += profit;
        printf("Successfully sold all weapons.\n");
        return gold;
    } else if (menu == 2){
        return gold;
    } else {
            printf("Invalid option.\n");
        }
}

void check_inventory(int gold){
    printf("\nINVENTORY\n");
    printf("Gold: %i\n", gold);
    printf("Iron: %i\n", iron);
    printf("Wood: %i\n", wood);
    printf("Sword: %i\n", sword);
    printf("Spear: %i\n", spear);
    printf("Axe: %i\n", axe);
}