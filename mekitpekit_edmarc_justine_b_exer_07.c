/*
Title: Exer 07 Strings
Program Description    : 
C program where the user inputs a paragraph of text and a paragraph width 
then prints out a left-aligned text with the specified paragraph width. 

findloclastspace() - takes parameters of a string, start and end. It jumps to the
index[end] then decrements until it finds the last space. Returns the index.

printleftstr() - takes parameters of a string and the paragraph width. It prints
out the left-aligned text.

wordlen() - takes parameters of a string and start. It returns the length of
the word.

Author: Mekitpekit, Edmarc Justine B.
Date: 17 Mar 2026
Section: T-1L
Compilation and run cmd: gcc -Wall -lm mekitpekit_edmarc_justine_b_exer_07.c 
-o mekitpekit_edmarc_justine_b_exer_07 && ./mekitpekit_edmarc_justine_b_exer_07
*/

#include <stdio.h>
#include <string.h>

#define MAXNUM 1000

//prototype
int findloclastspace(char* strf, int start, int end);
void printleftstr(char* strf, int end);
int wordlen(char* strf,int start);

int main(){
	//declaring of variables
	char str[MAXNUM];
	int lenstr, parawidth;

	printf("---------------------------------------------------------------------------------\n");
	printf("Enter a paragraph:\n"); // get input paragraph
	if(fgets(str, MAXNUM, stdin) == NULL){
		printf("Input problem encountered. Terminating.");
		return 1;
	}
	lenstr = strlen(str);
	if (lenstr > 0 && str[lenstr - 1] == '\n'){
		str[lenstr - 1] = '\0';
		lenstr -= 1;
	}
	while (1)
	{
		printf("\nEnter textwidth for justification: \n");
		scanf("%d", &parawidth); // get input paragraph width
		if (parawidth < 2){ // input validation
			printf("Invalid input. Textwidth must be at least 2. Try again.\n");
		}
		else break;
	}
	

	printf("---------------------------------------------------------------------------------\n");
	printf("---------------------------------------------------------------------------------\n");
	printf("Here's the left-aligned paragraph:\n\n");

	printleftstr(str, parawidth); // function call

	printf("\n---------------------------------------------------------------------------------\n");
	return 0;
}

int findloclastspace(char* strf, int start, int end){
	//checks if the last character is not a space
	if (strf[end - 1] != ' '){ 
		for (int i = end; i > start; i--){ // decrements until it finds the last space
			if (strf[i] == ' '){
				return i; // return the index of the space
			}
		}
		return end; // if no space was found, return the end
	} else return end; // if the last character is a space, return the end
}

void printleftstr(char* strf, int end){
	int i = 0, j , last, lenstr; // declaring of variables
	lenstr = strlen(strf);

	while(i < lenstr) {
		// check if the i + end will overflow the string
		if (i + end == lenstr) {
			//the len of the str will be the final char
			last = findloclastspace(strf, i, lenstr); 
		} else last = findloclastspace(strf, i, i + end); // else, add to the end
		
		if (wordlen(strf, i) >= end) { // if the word is longer than the end
			for (j = i; j < i + end - 1; j++){
				putchar(strf[j]); // print the characters until end - 1 
			}
			putchar('-'); // "replace" the end - 1 character with a hyphen
			putchar('\n');
			i = i + end - 1; // set i to end - 1
			continue; // move to the next iteration
		}

		// print the characters until the last space
		for (j = i; j < last; j++){
			putchar(strf[j]);
		}
		putchar('\n'); // print a new line

		i = last; // move i to the found last space

		while (i < lenstr && strf[i] == ' '){//check if the first char of the line is a space
            i++; // ignore the space
		}
	}
}

int wordlen(char* strf,int start){
	int counter = 0;
	while (strf[start] != ' ' && strf[start] != '\0') { 
		// count the characters until a space is found or the terminating character
		start++;
		counter++;
	}
	return counter; // returns the counter 
}
