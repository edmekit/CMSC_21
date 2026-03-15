/*
Title: Exer 03 Recursive Function, Compounded Growth
Program Description    : 
A C program that uses recursive function to calculate a the population (n) after (x) years 
with a growth rate (y). 
Author: Mekitpekit, Edmarc Justine B.
Date: 10 Feb 2026
Section: T-1L
Compilation and run cmd: gcc -Wall mekitpekit_edmarc_justine_b_exer_03.c -o 
mekitpekit_edmarc_justine_b_exer_03 && ./mekitpekit_edmarc_justine_b_exer_03
*/

#include <stdio.h>

typedef struct {
	double population;
	float rate;
	int years;
} growth;

double computeGrowth(growth g);

int main() {
	growth g;
	int choice;
	while(1){
		printf("\n=============================\n");
		printf("Population Growth Calculator\n");
		printf("[1] Calculate\n");
		printf("[2] Exit\n");
		printf("Enter choice: "); scanf("%d", &choice);

		if (choice == 1){ // choice for calculate
			double population;
			float rate;
			int years;

			while (1){ // loop for checking valid population
				printf("Enter population (n): "); scanf("%lf", &population);
				if (population <= 0){
					printf("\nPopulation cannot be 0 or negative.\n");
				} else {
					g.population = population;
					break;
				}
			}

			while (1) {
				printf("Growth rate (y%%): "); scanf("%f", &rate);
				if (rate < 0){
					printf("\nGrowth rate cannot be negative.\n");
			} else {
				g.rate = rate/100;
				break;
			}
			}
			
			
			while (1){ // loop for checking valid years
				printf("Years (x):  "); scanf("%d", &years);
				if (years < 0){
					printf("\nYear cannot be negative.\n");
				} else {
					g.years = years;
					break;
				};		
			}

			// printing of results
			printf("After %d year(s) at a %.0f%% growth rate, the population will be %.2lf\n", 
			 g.years, g.rate * 100, computeGrowth(g));
			}

		else if (choice == 2){
			printf("Program Terminated.\n");
			break;
		} else printf("\nPlease choose from the menu.\n"); // invalid menu choice
	}
}

double computeGrowth(growth g){
	if (g.years == 0) return g.population; // simply return original population if year is 0 
	else {
		g.years--;
		float added = g.population*g.rate; // get the added population
		g.population += added; // add to the original population
		return computeGrowth(g); // call the recursive function with 
		// the compounded population
	}
}
