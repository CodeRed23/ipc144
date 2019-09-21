/* ---------------------------
 Name: Nicholas Defranco
 Student number: 106732183
 Email: ndefranco@myseneca.ca
 Section: P
 Date: Oct 31st 2018
 -----------------------------
 Assignment: 1
 Milestone: 2
 -----------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"	

// this function will avoid dangling new lines 
// (\n) that occur at the scanf
// used after every input
//
// I hope I can do this
// this function was used in the 
// notes given
void clearBuffer(void) {
	while(getchar() != '\n');
}

// simply created to make sure user inputs correct 
// either a y or n
void getConfirmation(char *c) {
	
	do {
		
		scanf("%c", c);
		if(*c != 'n' && *c != 'N' && *c != 'Y' && *c != 'y'){
			printf("please enter a 'y' or a 'n': ");
		}
	
	clearBuffer();

	}while(*c != 'n' && *c != 'N' && *c != 'Y' && *c != 'y');
	
}

int main(void) {

  	// Declare variables here:
  	
	struct Name contactName = {"", "", ""};
	struct Address contactAddr = {0, "", 0, "", ""};
	struct Numbers contactNums = {"", "", ""};

	// used to determine if the user has the information

	char confirm; 

	// Display the title:
	
	printf("Contact Management System\n");
	printf("-------------------------\n");
	
	// Contact Name Input:
	
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", contactName.firstName);
	clearBuffer();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	getConfirmation(&confirm);

	if(confirm == 'y' || confirm == 'Y'){
		printf("Please enter the contact's middle initial(s): ");	
		scanf("%6[^\n]", contactName.middleInitial);
		clearBuffer();
	}
	
	printf("Please enter the contact's last name: ");
	scanf("%30[^\n]", contactName.lastName);
	clearBuffer();

	// Contact Address Input:
	
	printf("Please enter the contact's street number: ");
	scanf("%d", &contactAddr.streetNum);
	clearBuffer();	

	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]", contactAddr.street);	
	clearBuffer();

	printf("Do you want to enter an apartment number? (y or n): ");
	getConfirmation(&confirm);

	if(confirm == 'y' || confirm == 'Y') {
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &contactAddr.apartmentNumber);
		clearBuffer();
	}
	
	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]", contactAddr.postalCode);
	clearBuffer();

	printf("Please enter the contact's city: ");
	scanf("%40[^\n]", contactAddr.city);
	clearBuffer();

	// Contact Numbers Input:
	
	printf("Do you want to enter a cell phone number? (y or n): ");
	getConfirmation(&confirm);	

	if(confirm == 'y' || confirm == 'Y'){
		printf("Please enter the contact's cell phone number: ");
		scanf("%10s", contactNums.cell);
		clearBuffer();
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	getConfirmation(&confirm);

	if(confirm == 'y' || confirm == 'Y') {
		printf("Please enter the contact's home phone number: ");
		// assumes no spaces
		scanf("%10s", contactNums.home);
		clearBuffer();
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	getConfirmation(&confirm);
	
	if(confirm == 'y' || confirm == 'Y') {
		printf("Please enter the contact's business phone number: ");
		scanf("%10s", contactNums.business);
		clearBuffer();
	}

	// Display Contact Summary Details:
	// The if statments are to avoid printing empty values	
	//
	// if the string starts with the null terminator it 
	// is empty and therfore not used
	//
	// if an integer is set to the value of zero it is not used

	printf("\n");
	printf("Contact Details\n");
	printf("---------------\n");

	printf("Name Details\n");
	printf("First name: %s\n", contactName.firstName);
	
	if(contactName.middleInitial[0] != '\0'){
		printf("Middle initial(s): %s\n", contactName.middleInitial);
	}

	printf("Last name: %s\n\n", contactName.lastName);
	
	printf("Address Details\n");
	printf("Street number: %d\n", contactAddr.streetNum);
	printf("Street name: %s\n", contactAddr.street);
	
	if(contactAddr.apartmentNumber != 0){
		printf("Apartment: %d\n", contactAddr.apartmentNumber);
	}

	printf("Postal code: %s\n", contactAddr.postalCode);
	printf("City: %s\n\n", contactAddr.city);

	if(contactNums.cell[0] != '\0' || contactNums.home[0] != '\0' ||
			contactNums.business[0] != '\0'){

		printf("Phone Numbers:\n");
	
		if(contactNums.cell[0] != '\0'){	
			printf("Cell phone number: %s\n", contactNums.cell);
		}

		if(contactNums.home[0] != '\0'){
			printf("Home phone number: %s\n", contactNums.home);
		}

		if(contactNums.business[0] != '\0'){
			printf("Business phone number: %s\n\n",
				 contactNums.business);
		}
	}

	// Display Completion Message: 
	
	printf("Structure test for Name, Address, and Numbers Done!\n");
	
	return 0;
}
	
