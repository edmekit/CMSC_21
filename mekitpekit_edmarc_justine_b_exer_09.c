/*
Title: Exer 09 Files
Program Description    : 

Author: 	Mekitpekit, Edmarc Justine B.
Date: 		14 Apr 2026
Section: 	T-1L
Compilation and run cmd: gcc -Wall mekitpekit_edmarc_justine_b_exer_09.c 
-o mekitpekit_edmarc_justine_b_exer_09 && ./mekitpekit_edmarc_justine_b_exer_09

ERORR CHECK AND COMMENTS IM CLOSEEEE UGHHHHH
so fucking tired cuh

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
void inputData(citizen *citizen_num);
void writeCitizen(FILE* file, citizen person, int count);
int countCitizens(FILE* file);
void editData(FILE* file, int citizen_num, int count);
void outputAll(FILE* file);
void countMandF(FILE* file);



int main()
{	
	citizen person;
	int citizen_num;
	FILE* community = fopen("citizendb.txt", "a+");
	rewind(community);
	
	citizen_num = countCitizens(community);

	int choice, edit;
	char continue_entry = 'Y';
	do {
		printf("\n------------------------------------------\n");
		printf("[1] Input Data\n");
		printf("[2] Edit Data\n");
		printf("[3] Output All Data\n");
		printf("[4] Count All citizen\n");
		printf("[5] Count Males and Females\n");
		printf("[9] Exit\n");
		printf("\n------------------------------------------\n");
		printf("Please input entry: "); scanf("%d", &choice);

		if (choice == 1){
			continue_entry = 'Y';
			while (toupper(continue_entry) != 'N'){ // check if user hasnt entered 'N'
				citizen_num++;
				printf("\nThis entry is for citizen no. %d", citizen_num);
				inputData(&person); // input data
				writeCitizen(community, person, citizen_num);
				printf("Do you wish to continue for citizen no. %d? ", citizen_num + 1);
				scanf(" %c", &continue_entry);
			}
		}
		
		else if (choice == 2){
			while (1){
				printf("Please input the citizen no. to edit data or enter 0 to return: "); 
				scanf("%d", &edit);
				if (edit == 0 || edit > citizen_num){ // check if user wants to exit or if invalid
					printf("Exiting edit mode.\n");
					break;
				} 
				editData(community, edit, citizen_num);
			}
		}
		
		else if (choice == 3){
			outputAll(community); // output valid citizens datas
		}
		
		else if (choice == 4){
			 // count valid citizens
			printf("The community has a population of %d.", citizen_num);  
		}
		
		else if (choice == 5){
			countMandF(community); // count males and females from valid
		}
		else if (choice == 9){
			printf("Thanks.");
			fclose(community);
			return 0;
		}
		else {
			printf("Invalid entry. Choose from the menu.\n");
		}
	} while (choice != 9);
}


void writeCitizen(FILE* file, citizen person, int count){
	fprintf(file, "%d\n", count);
	fprintf(file, "%s", person.name);
	fprintf(file, "%c\n", person.sex);
	fprintf(file, "%.2f\n", person.age);
	fprintf(file, "%.2f\n", person.height);
	fprintf(file, "%.2f\n", person.weight);
}

int countCitizens(FILE* file){
	char ch;
	int lines = 0, count = 0;
	while((ch = fgetc(file)) != EOF){
		if (ch == '\n'){
			lines++;
		} 
	}
	count = lines / 6;
	return count;
}



void inputData(citizen *citizen_num){
	printf("\nName [Last Name, Given Name(s), MI]: ");
	getchar();
	fgets(citizen_num->name, 120, stdin); // get name

	while(1){
		printf("Sex [M/F]: "); 
		scanf(" %c", &(citizen_num->sex)); // get sex
		citizen_num->sex = toupper(citizen_num->sex);
		if (citizen_num->sex != 'M' && citizen_num->sex != 'F'){ // check if not M or F
			printf("Invalid entry. Please follow the format.");
		} else break;
	}

	while(1){
		printf("Age [Years]: "); 
		scanf("%f", &(citizen_num->age));
		if (citizen_num->age <= 0){ // check if age is negative or 0
			printf("Invalid entry. Age cannot be negative.\n");
			continue;
		} else break;			
	}

	while(1){
		printf("Height [cm]: "); 
		scanf("%f", &(citizen_num->height));
			if (citizen_num->height <= 0){ // check if height is negative or 0
			printf("Invalid entry. Height cannot be negative or 0.\n");
		} else break;		
	}

	while(1){
		printf("Weight [kg]: "); 
		scanf("%f", &(citizen_num->weight));
			if (citizen_num->weight <= 0){ // check if weight is negative or 0
			printf("Invalid entry. Weight cannot be negative or 0.\n");
		} else break;
	}
}


void editData(FILE* file, int citizen_num, int count){
	rewind(file);
	int choice, lineCount = 1, targetLine;
	char line[120];
	FILE* temp = fopen("temp.txt", "w");

	for (int i = 1; i <= count; i++) {
		if (i == citizen_num) {
			if (fgets(line, sizeof(line), file)) {
			printf("Citizen no. %s", line);  // Citizen number
			}
			if (fgets(line, sizeof(line), file)) {
				printf("[1] Name: %s", line);  // Name
			}
			if (fgets(line, sizeof(line), file)) {
				printf("[2] Sex: %s", line);  // Sex
			}
			if (fgets(line, sizeof(line), file)) {
				printf("[3] Age: %s", line);  // Age
			}
			if (fgets(line, sizeof(line), file)) {
				printf("[4] Height: %s", line);  // Height
			}
			if (fgets(line, sizeof(line), file)) {
				printf("[5] Weight: %s", line);  // Weight
			}
		} else {
			fgets(line, sizeof(line), file);
			fgets(line, sizeof(line), file);
			fgets(line, sizeof(line), file);
			fgets(line, sizeof(line), file);
			fgets(line, sizeof(line), file);
			fgets(line, sizeof(line), file);
		}
	}

	printf("Enter which field to edit or delete a citizen: ");
	scanf("%d", &choice);
	getchar();

	if (choice >= 1 && choice <= 5) {
		targetLine = (citizen_num - 1) * 6 + 1 + choice;
	}
	
	rewind(file);
	while (fgets(line, sizeof(line), file))
	{
		if (lineCount == targetLine)
		{
			if (choice == 1) {
				printf("Enter name: ");
				getchar();
				fgets(line, sizeof(line), stdin);
				fprintf(temp, "%s", line);
			} else if (choice == 2) {
				printf("Enter sex: ");
				fgets(line, sizeof(line), stdin);
				fprintf(temp, "%s", line);
			} else if (choice == 3) {
				printf("Enter age: ");
				fgets(line, sizeof(line), stdin);
				fprintf(temp, "%s", line);
			} else if (choice == 4) {
				printf("Enter height: ");
				fgets(line, sizeof(line), stdin);
				fprintf(temp, "%s", line);
			} else if (choice == 5) {
				printf("Enter weight: ");
				fgets(line, sizeof(line), stdin);
				fprintf(temp, "%s", line);
			} else if (choice == 6) {

			}
		}
		else
		{
			fprintf(temp, "%s", line);
		}
		lineCount++;
	}
	

	fclose(file);  // Close the original file first
	fclose(temp);
	remove("citizendb.txt");
	rename("temp.txt", "citizendb.txt");

	rewind(file);
}




void outputAll(FILE* file) {
    rewind(file);
    char line[120];
    int citizenCount = countCitizens(file);
    rewind(file);  // Rewind again after counting
    
    for (int i = 1; i <= citizenCount; i++) {
		printf("------------------------------------------\n");
        // Read and parse each line
        if (fgets(line, sizeof(line), file)) {
            printf("Citizen no. %s", line);  // Citizen number
        }
        if (fgets(line, sizeof(line), file)) {
            printf("Name: %s", line);  // Name
        }
        if (fgets(line, sizeof(line), file)) {
            printf("Sex: %s", line);  // Sex
        }
        if (fgets(line, sizeof(line), file)) {
            printf("Age: %s", line);  // Age
        }
        if (fgets(line, sizeof(line), file)) {
            printf("Height: %s", line);  // Height
        }
        if (fgets(line, sizeof(line), file)) {
            printf("Weight: %s", line);  // Weight
        } 
		printf("[6] Delete citizen\n");
		printf("------------------------------------------\n");
    }
}

void countMandF(FILE* file) {
    rewind(file);
    int male = 0, female = 0;
    char line[120];
    int citizenCount = countCitizens(file);
    rewind(file);
    
    for (int i = 1; i <= citizenCount; i++) {
        // Skip number line
        fgets(line, sizeof(line), file);
        
        // Skip name line
        fgets(line, sizeof(line), file);
        
        // Read sex line
        if (fgets(line, sizeof(line), file)) {
            char sex = line[0];  // First char is sex
            if (sex == 'M') male++;
            else if (sex == 'F') female++;
        }
        
        // Skip remaining lines
        fgets(line, sizeof(line), file);  // Age
        fgets(line, sizeof(line), file);  // Height
        fgets(line, sizeof(line), file);  // Weight
    }
    
    printf("Male: %d\t\tFemale: %d\n", male, female);
}




