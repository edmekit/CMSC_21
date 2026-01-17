#include <stdio.h>

int buy_mats(gold);
int iron, wood, sword, spear, axe;

int main(void){
    int day, gold, menu;
    day = 1;
    gold = 20;

    while (1){
        printf("DAY %i\t", day);
        printf("Gold: %i\n", gold);
        printf("[1] Buy Materials\n");
        printf("[2] Craft Weapons\n");
        printf("[3] Sell All Weapons\n");
        printf("[4] Check inventory\n");
        printf("[0] Exit\n");
        printf("Choose an option: "); scanf("%i", &menu);

        if (menu == 0){
            break;
        } else if(menu == 1){
            buy_mats(gold);
        } else if (menu == 2){
            craft_weapons();
        } else if (menu == 3){
            sell_all_weapons(gold);
        } else if (menu == 4){
            check_inventory(gold);    
        }
    }
}

int buy_mats(gold){
    while(1){
        int menu,cost, bought;
        printf("BUY MATERIALS\n");
        printf("Gold: %i\t| Iron: %i\t| Wood: %i\n", gold, iron, wood);
        printf("(1) Iron [2 gold each]\n");
        printf("(2) Wood [1 gold each]\n");
        printf("(0) Back to main menu\n");

        printf("Which weapon to buy: "); scanf("%i", &menu);
        if (menu == 1){
            printf("How many: "); scanf("%i", &bought);
            cost = bought * 2;
        } else if (menu == 2){
            printf("How many: "); scanf("%i", &bought);
            cost = bought;
        } else if (menu == 0){
            return gold;
        }

        if (gold < cost) {
            int kulang = cost - gold;
            printf("Lacks %i gold to buy.\n", kulang);
        } else {
            gold -= cost;
            printf("Successfully bought for %i gold.\n",cost);
            iron += bought;
            wood = bought;
        }
    }
}