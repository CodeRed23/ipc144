/* --------------------------------------------
Name: Nicholas Defranco
Student number: 106732183
Email: ndefranco@myseneca.ca
Section: P
Date: Nov 7th 2018
--------------------------------------------
Assignment: 1
Milestone: 4
-------------------------------------------*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double qoutes so the compiler konws
// 	 to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line: 

#include "contacts.h"

// I have these functions here as helpers
// they are not as cohesive as the other 
// functions so I left them out of the header file
// I also left them out because they are only
// used in this source file unlike the other three
// I hope I can do this

// Avoid trailing chars to be read written to other addresses
// after inputting to a scanf
// taken from the notes - Section: Input Functions
//
// doesn't require a new line character as a plain character 
// in the format (scanf's first parameter) if used the fuction
// is used

void clearBuffer(void){
	while(getchar() != '\n');
}

// validates char input
// same function as last milestone
// except it returns a char rather 
// than pass an address to points to
// the char
// I thought this would be better 
// because there are multiple
// confirm variables in this file
// one for each function.

char getConfirmation(void) {

	char c;

	do {

		scanf("%c", &c);
		if (c != 'n' && c != 'y' && c != 'Y' && c != 'N') {
			printf("Invalid, please only enter 'y' or an 'n': ");
		} 
		clearBuffer();

	} while(c != 'n' && c != 'y' && c != 'Y' && c != 'N');
		
	return c;

}

// validates positive integer input
// requires an address to the numer
// to be written to

void getIntInput(int *num) {

	do {

		scanf("%d", num);
		if(*num <= 0){
			printf("please enter a positive integer");
		}
		clearBuffer();

	} while(*num <= 0);

}

// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:

void getName(struct Name *name){

	char confirm;

	printf("Please enter the contact's first name: ");	
	scanf("%30[^\n]", name->firstName);
	clearBuffer();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	confirm = getConfirmation();
	
	if(confirm == 'y' || confirm == 'Y'){
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", name->middleInitial);
		clearBuffer();
	}	

	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]", name->lastName);
	clearBuffer();

}

// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function: 

void getAddress(struct Address *address){

	char confirm;

	printf("Please enter the contact's street number: ");
	getIntInput(&address->streetNum);

	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]", address->street);
	clearBuffer();

	printf("Do you want to enter an apartment number? (y or n): ");
	confirm = getConfirmation();
	
	if(confirm == 'y' || confirm == 'Y'){
		printf("Please enter the contact's apartment number: ");
		getIntInput(&address->apartmentNumber);
	}

	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]", address->postalCode);
	clearBuffer();

	printf("Please enter the contact's city: ");
	scanf("%40[^\n]", address->city);
	clearBuffer();

}

// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function: 

void getNumbers(struct Numbers *numbers) {

	char confirm;

	printf("Do you want to enter a cell phone number? (y or n): ");
	confirm = getConfirmation();
	
	if(confirm == 'y' || confirm == 'Y'){
		printf("Please enter the contact's cell phone number: ");
		scanf("%10s", numbers->cell);
		clearBuffer();
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	confirm = getConfirmation();
	
	if(confirm == 'y' || confirm == 'Y'){
		printf("Please enter the contact's home phone number: ");
		scanf("%10s", numbers->home);
		clearBuffer();
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	confirm = getConfirmation();
	
	if(confirm == 'y' || confirm == 'Y'){
		printf("Please enter the contact's business phone number: ");
		scanf("%10s", numbers->business);
		clearBuffer();
	}

}
