/*
Title: Exer 08 Structures
Program Description    : 
C program that takes in the following pieces of information from citizens of a small community:
(a) Name (Last Name, Given Name(s), MI; maximum of 120 characters), (b) Sex (M/F), (c) Age(years)
(d) height(cm), (e) Weight(kg). In addition to this, every citizen has a citizen no. from 1 to a
maximum of 100; the database can only hold 100 citizens. The information should be stored in an
array of structures of maximum size 100.
Author: 	Mekitpekit, Edmarc Justine B.
Date: 		07 Apr 2026
Section: 	T-1L
Compilation and run cmd: gcc -Wall mekitpekit_edmarc_justine_b_exer_08.c 
-o mekitpekit_edmarc_justine_b_exer_08 && ./mekitpekit_edmarc_justine_b_exer_08
*/

// libraries
#include <stdio.h>
#include <ctype.h> // for checking and converting characters
#include <math.h> // for thhe dispersion and average values

// making of datatype structure citizen
typedef struct {
	char name[120]; 
	char sex;
	int status;
	float age;
	float height;
	float weight;
} citizen;

// prototypes
citizen inputData(citizen citizen_num);
citizen editData(citizen citizen_num);
void countAll(citizen community[], int size);
void outputAll(citizen community[], int size);
void countMandF(citizen community[], int size);
float average(citizen community[], int size, int stat);
float stddeviation(citizen community[], int size, int stat);


int main()
{	
	citizen community[100]; // array of 100 citizens
	for (int person = 0; person < 100; person++){
		community[person].status = 0; // initialize all citizens to have status of 0
	}
	// declaring and initializing variables
	int choice, citizen_num = 0, edit;
	float mean, deviation;
	char continue_entry = 'Y';
	do {
		printf("\n------------------------------------------\n");
		printf("[1] Input Data\n");
		printf("[2] Edit Data\n");
		printf("[3] Output All Data\n");
		printf("[4] Count All citizen\n");
		printf("[5] Count Males and Females\n");
		printf("[6] Compute Average Age and Dispersion\n");
		printf("[7] Compute Average Height and Dispersion\n");
		printf("[8] Compute Average Weight and Dispersion\n");
		printf("[9] Exit\n");
		printf("\n------------------------------------------\n");
		printf("Please input entry: "); scanf("%d", &choice);

		if (choice == 1){
			continue_entry = 'Y';
			while (toupper(continue_entry) != 'N'){ // check if user hasnt entered 'N'
				printf("\nThis entry is for citizen no. %d", citizen_num + 1);
				community[citizen_num] = inputData(community[citizen_num]); // input data
				printf("Do you wish to continue for citizen no. %d? ", citizen_num + 2);
				scanf(" %c", &continue_entry);
				citizen_num++;
				if (citizen_num == 100){ // check if the maximum number of citizens has been reached
					printf("The maximum number of citizens has been reached.\n");
					break;
				}
			}
		}
		else if (choice == 2){
			while (1){
				printf("Please input the citizen no. to edit data or enter 0 to return: "); 
				scanf("%d", &edit);
				if (edit == 0 || edit > citizen_num){ // check if user wants to exit or if invalid
					printf("Exiting edit mode.\n");
					break;
				} else if (community[edit - 1].status == 0){ // check if the citizen has been deleted
					printf("The citizen no. %d has not been entered or has been deleted.\n", edit);
					continue;
				}
				community[edit - 1] = editData(community[edit - 1]); // edit data
			}
		}
		else if (choice == 3){
			outputAll(community, citizen_num); // output valid citizens datas
		}
		else if (choice == 4){
			countAll(community, citizen_num); // count valid citizens
		}
		else if (choice == 5){
			countMandF(community, citizen_num); // count males and females from valid
		}
		else if (choice == 6){
			// 1 refers to age mode
			mean = average(community, citizen_num, 1); // get mean of age
			deviation = stddeviation(community, citizen_num, 1); // get standard deviation of age
			printf("Our citizens have an average age of %.2f ", mean);
			printf("and a standard deviation of %.2f\n", deviation);
		} else if (choice == 7){
			// 2 refers to height mode
			mean = average(community, citizen_num, 2); // get mean of height
			deviation = stddeviation(community, citizen_num, 2); // get standard deviation of height
			printf("Our citizens have an average height of %.2f ", mean);
			printf("and a standard deviation of %.2f\n", deviation);
		} else if (choice == 8){
			// 3 refers to weight mode
			mean = average(community, citizen_num, 3); // get mean of weight
			deviation = stddeviation(community, citizen_num, 3); // get standard deviation of weight
			printf("Our citizens have an average weight of %.2f ", mean);
			printf("and a standard deviation of %.2f\n", deviation);
		}
		else if (choice == 9){
			printf("Thanks.");
			return 0;
		}
		else {
			printf("Invalid entry. Choose from the menu.\n");
		}
	} while (choice != 9);
}



citizen inputData(citizen citizen_num){
	printf("\nName [Last Name, Given Name(s), MI]: ");
	getchar();
	fgets(citizen_num.name, 120, stdin); // get name

	while(1){
		printf("Sex [M/F]: "); 
		scanf(" %c", &(citizen_num.sex)); // get sex
		citizen_num.sex = toupper(citizen_num.sex);
		if (citizen_num.sex != 'M' && citizen_num.sex != 'F'){ // check if not M or F
			printf("Invalid entry. Please follow the format.");
		} else break;
	}

	while(1){
		printf("Age [Years]: "); 
		scanf("%f", &(citizen_num.age));
		if (citizen_num.age <= 0){ // check if age is negative or 0
			printf("Invalid entry. Age cannot be negative.\n");
			continue;
		} else break;			
	}

	while(1){
		printf("Height [cm]: "); 
		scanf("%f", &(citizen_num.height));
			if (citizen_num.height <= 0){ // check if height is negative or 0
			printf("Invalid entry. Height cannot be negative or 0.\n");
		} else break;		
	}

	while(1){
		printf("Weight [kg]: "); 
		scanf("%f", &(citizen_num.weight));
			if (citizen_num.weight <= 0){ // check if weight is negative or 0
			printf("Invalid entry. Weight cannot be negative or 0.\n");
		} else break;
	}
	citizen_num.status = 1; //set status to 1

	return citizen_num;
}

citizen editData(citizen citizen_num){
	int choice;
	printf("[1] Name [Last Name, Given Name(a), MI]: ");
	printf("%s", citizen_num.name);
	printf("[2] Sex[M/F]: %c \n", citizen_num.sex);
	printf("[3] Age[Years]: %.2f \n", citizen_num.age); 
	printf("[4] Height [cm]: %.2f \n", citizen_num.height); 
	printf("[5] Weight [kg]: %.2f \n", citizen_num.weight); 
	printf("[6] Delete citizen\n");

	printf("\nChoose the entry to edit or delete a citizen: ");
	scanf("%d", &choice);

	if (choice == 1){
		printf("Name [Last Name, Given Name(a), MI]: ");
		getchar();
		fgets(citizen_num.name, 120, stdin); // get name
	} else if (choice == 2){
		while(1){
			printf("Sex [M/F]: "); // get sex
			scanf(" %c", &(citizen_num.sex));
			citizen_num.sex = toupper(citizen_num.sex);
			if (citizen_num.sex != 'M' && citizen_num.sex != 'F'){ // check if not M or F
				printf("\nInvalid entry. Please follow the format.\n");
			} else break;
		}
	} else if (choice == 3){
		while(1){
			printf("Age [Years]: "); 
			scanf("%f", &(citizen_num.age));
			if (citizen_num.age <= 0){ //check if age is negative or 0
				printf("Invalid entry. Age cannot be negative.\n");
			} else break;
		}
	} else if (choice == 4){
		while(1){
			printf("Height [cm]: "); 
			scanf("%f", &(citizen_num.height));
			if (citizen_num.height <= 0){ //check if height is negative or 0
				printf("Invalid entry. Height cannot be negative or 0.\n");
			} else break;
		}
	} else if (choice == 5){
		while(1){
			printf("Weight [kg]: "); 
			scanf("%f", &(citizen_num.weight));
			if (citizen_num.weight <= 0){ //check if weight is negative or 0
				printf("Invalid entry. Weight cannot be negative or 0.\n");
			} else break;
		}
	} else if (choice == 6){
		citizen_num.status = 0; // set status to 0
	}
	else {
		printf("Invalid entry. Choose from the menu.\n");
	}

	return citizen_num;
}

void countAll(citizen community[], int size){
	int count = 0;
	for (int i = 0; i < size; i++){
		if (community[i].status == 0) continue; // check if status is 0, invalid if so
		count++;
	}
	printf("Total number of citizens: %d", count);
}

void outputAll(citizen community[], int size){
	for (int i = 0; i < size; i++){
		if (community[i].status == 0) continue; // check if status is 0, skip if so
		printf("\n\nCitizen no. %d", i + 1);
		printf("\nName: %s", community[i].name);
		printf("Sex: %c", community[i].sex);
		printf("\nAge: %.2f", community[i].age);
		printf("\nHeight: %.2f", community[i].height);
		printf("\nWeight: %.2f", community[i].weight);
	}
}

void countMandF(citizen community[], int size){
	int male = 0, female = 0;
	for (int i = 0; i < size; i++){
		if (community[i].status == 0) continue; // check if invalid citizen
		if (community[i].sex == 'F') female++; // add to female
		else if (community[i].sex == 'M') male++; // add to male
	}
	printf("Male: %d\t\tFemale: %d", male, female);
}

float average(citizen community[], int size, int stat){
	// init locals
	float mean;
	float total_age = 0, total_height = 0, total_weight = 0, total_people = 0;
	for (int i = 0; i < size; i++){
		if (community[i].status == 0) continue; // skip if invalid citizen
		total_age += community[i].age;
		total_height += community[i].height;
		total_weight += community[i].weight;
		total_people++; // get the current number of people
	}
	if (total_people == 0) return 0; // check if there are no people

	if (stat == 1){ // check if mode is age
		mean = total_age / total_people;
		return mean;
	}else if(stat == 2){ // check if mode is height
		mean = total_height / total_people;
		return mean;
	}else if(stat == 3){ // check if mode is weight
		mean = total_weight / total_people;
		return mean;
	}
}

float stddeviation(citizen community[], int size, int stat){
	float deviation_age, deviation_height, deviation_weight;
	float total_age = 0, total_height = 0, total_weight = 0, total_people = 0;
	float mean = average(community, size, stat);

	for (int i = 0; i < size; i++){
		if (community[i].status == 0) continue; // skip if invalid citizen
		total_age += pow(community[i].age - mean, 2);
		total_height += pow(community[i].height - mean, 2);
		total_weight += pow(community[i].weight - mean, 2);
		total_people++;
	}
	if (total_people == 0) return 0; // check if there are no people
	
	if (stat == 1){ // check if mode is age
		deviation_age = sqrt(total_age / total_people); 
		return deviation_age;
	} else if(stat == 2){ // check if mode is height
		deviation_height = sqrt(total_height / total_people); 
		return deviation_height;
	} else if(stat == 3){ // check if mode is weight
		deviation_weight = sqrt(total_weight / total_people);
		return deviation_weight;
	}
}
