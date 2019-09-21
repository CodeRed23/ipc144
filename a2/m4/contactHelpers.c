/* ---------------------------------
 * Name: Nicholas Defranco
 * Email: ndefranco@myseneca.ca
 * Section: P
 * Date: Nov 21st 2018
 * ---------------------------------
 *  Assignment: 2
 *  Miestone: 4
 *  --------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//This source file needs to "know about" the SYSTEM string library functions.
//HINT: The library name is string.h.
//	#include the string.h header file on the next line:

#include <string.h>
#include <ctype.h>

// -------------------------------------------------------------------------
// Include your contactHelpers header file on the next line:

#include "contactHelpers.h"

// -------------------------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):

#define MAXCONTACTS 5

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+
// clears the input buffer to avoid trailing chars
// to be automatically written to an address

void clearKeyboard(void){
	
	while(getchar() != '\n');

}

// the user must press enter if this function is 
// called to continue executing

void pause(void) {

	printf("(Press Enter to Continue)");
	clearKeyboard();

}

// validates int input
// returns the validated int

int getInt(void) {

	int Value = 0;
	char NL = 'x';

	while(NL != '\n') {
		scanf("%d%c", &Value, &NL);
		if(NL != '\n'){
			clearKeyboard();	
			printf("*** INVALID INTEGER *** "
				"<Please enter an integer>: ");
		}
	}

	return Value;

}

// validates int input within a range inclusive
// requires the min and max
// returns the validated int

int getIntInRange(int min, int max) {

	//int isValid = 0;
	int Value = 0;

	while((Value = getInt()) > max || Value < min){
		printf("*** OUT OF RANGE *** <Enter a number "
			"between %d and %d>: ", min, max);		
	}

/*	do {
		num = getInt();

		if(num < min || num > max){

				"between %d and %d>: ", min, max);
			isValid = 0;

		}else {

			isValid = 1;

		}
	
	} while(!isValid);
*/
	return Value;

}

// getConfirmation from the user
// returns either a 1 (yes) or 0 (no) 

int yes(void) {

	char NL = 'x', c = '\0'; // default values
	int isValid = 0;

	while(!isValid){
		scanf("%c%c", &c, &NL);
		if(NL != '\n'){ 		//buffer will only be cleared
			clearKeyboard();	//only if there are too many chars
			printf("*** INVALID ENTRY *** " 
				"<Only (Y)es or (N)o are acceptable>: ");
		}else if (c != 'n' && c != 'y' && c != 'Y' &&
				 c != 'N') {
			printf("*** INVALID ENTRY *** " 
				"<Only (Y)es or (N)o are acceptable>: ");
		} else {
			isValid = 1;
		}		
	}

	return (c == 'y' || c == 'Y') ? 1 : 0;

}

// simply prints the menu 
// returns int within a range (inclusive)

int menu(void) {

	puts("Contact Management System");
	puts("-------------------------");
	puts("1. Display contacts");
	puts("2. Add a contact");
	puts("3. Update a contact");
	puts("4. Delete a contact");
	puts("5. Search contacts by cell phone number");
	puts("6. Sort contacts by cell phone number");
	puts("0. Exit\n");
	printf("Select an option:> ");

	return getIntInRange(0, 6);
	
}

// connects the whole program together
// logic portion of the menu
void contactManagerSystem(void) {

	int isDone = 0;

	struct Contact contacts[MAXCONTACTS] = 
	{ { { "Rick", {'\0'}, "Grimes" },
 	    { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	    { "4161112222", "4162223333", "4163334444" } },
 	  {
 		{ "Maggie", "R.", "Greene" },
 		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
 		{ "9051112222", "9052223333", "9053334444" } },
 	  { 
 		{ "Morgan", "A.", "Jones" },
 		{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
 		{ "7051112222", "7052223333", "7053334444" } },
 	  {
		{ "Sasha", {'\0'}, "Williams" },
 		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
 		{ "9052223333", "9052223333", "9054445555" } },
  	  };

	do {	

		switch(menu()){			
	
			case 0: 
				printf("\nExit the program? (Y)es/(N)o: ");
				if((isDone = yes())){
					printf("\nContact Management "
						"System: terminated");
				}	
			break;
		
			case 1:
				displayContacts(contacts, MAXCONTACTS);
				pause();
			break;
		
			case 2:
				addContact(contacts, MAXCONTACTS);
				pause();
			break;
			
			case 3:
				updateContact(contacts, MAXCONTACTS);
				pause();
			break;

			case 4:
				deleteContact(contacts, MAXCONTACTS);
				pause();
			break;

			case 5:
				searchContacts(contacts, MAXCONTACTS);
				pause();
			break;

			case 6:
				sortContacts(contacts, MAXCONTACTS);
				pause();
			break;
		}

		putchar('\n');

	}while(!isDone);

}

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char telNum[]){
	int needInput = 1;
	int length = 0;
	int i = 0;
	char NL = 'x';
        while (needInput) {
        	scanf("%10s%c", telNum, &NL);

		length = strlen(telNum);

		// (String Length Function: validate entry of 10 characters)
		if(length == 10 && NL == '\n'){
			for(i = 0; isdigit(telNum[i]); i++);

			if(i != length){	
				printf("Enter a 10-digit phone number: ");
				needInput = 1;
			}else {
				needInput = 0;
			}
		}else {
			if(NL != '\n'){
				clearKeyboard();
			}
			needInput = 1;	
			printf("Enter a 10-digit phone number: ");
		}

		
		// this worls too, using a rule delimited set
		// to determine if all 10 chars are digits

		/*scanf("%10[0-9]%c", telNum, &NL);
		if(strlen(telNum) != 10 || NL != '\n'){
			printf("Enter a 10-digit phone number: ");
			clearKeyboard();
			needInput = 1;
		}else{

			needInput = 0;

		}
*/
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]){
	
	int i = 0;
	for(i = 0; i < size; i++){
		if(strcmp(contacts[i].numbers.cell, cellNum) == 0){
			return i;
		}
	}

	return -1;

}

// extra function I put in to help print
// meant to help print the headers and footers on the screen
void printRepeatingChar(char ch, int amount){
	
	int i;
	for(i = 0; i < amount; i++){
		putchar(ch);
	}

}

// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void) {

	//line 1
	printf("\n+");
	printRepeatingChar('-', 77);
	printf("+\n");

	// line 2
	putchar('|');
	printRepeatingChar(' ', 30);
	printf("Contacts Listing");
	printRepeatingChar(' ', 31);
	printf("|\n");

	//line 3
	putchar('+');
	printRepeatingChar('-', 77);
	printf("+\n");

}

// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int num){

	// line 2
	putchar('+');	
	printRepeatingChar('-', 77);
	printf("+\n");
	
	// line 2
	printf("Total contacts: %d\n\n", num);

}

// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact *contact) {

	if(strlen(contact->name.middleInitial) == 0){	
		printf(" %s %s\n", contact->name.firstName, 
			contact->name.lastName);	

	}else {

		printf(" %s %s %s\n", contact->name.firstName, 
			contact->name.middleInitial, contact->name.lastName);	
	}

	printf("    C: %-10s   H: %-10s   B: %-10s\n",contact->numbers.cell, 
		contact->numbers.home, contact->numbers.business);

	printf("       %d %s, ", contact->address.streetNumber, 
		contact->address.street);

	if(contact->address.apartmentNumber > 0){
		printf("Apt# %d, ", contact->address.apartmentNumber);
	}

	printf("%s, %s\n", contact->address.city, contact->address.postalCode);

}

// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size) {

	int i;
	int amount = 0;

	displayContactHeader();

	for(i = 0; i < size; i++){
		if(strlen(contacts[i].numbers.cell) > 0){
			displayContact(contacts + i);
			amount++;
		}
	}	

	displayContactFooter(amount);

}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size){

	int i = 0;
	char num[11];

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(num);

	i = findContactIndex(contacts, size, num);	

	if(i >= 0){
		putchar('\n');
		displayContact(contacts + i);
		putchar('\n');
	}else {
		printf("*** Contact NOT FOUND ***\n\n");
	}

}

// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size){

	int i = 0;
	for(i = 0; i < size; i++){
		if(strlen(contacts[i].numbers.cell) == 0){
			putchar('\n');
			getContact(contacts + i);
			printf("--- New contact added! ---\n\n");
			return;
		}
	}

	printf("\n*** ERROR: The contact list is full! ***\n\n");

}

// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size){

	int i = 0;
	char num[11];

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(num);

	i = findContactIndex(contacts, size, num);	

	if(i < 0){
		printf("*** Contact NOT FOUND ***\n\n");
		return;
	}

	printf("\nContact found:\n");
	displayContact(contacts + i);

	// optional values must be reset when the user wants
	// to update its corresponding structure

	printf("\nDo you want to update the name? (y or n): ");
	if(yes()){
		contacts[i].name.middleInitial[0] = '\0';
		getName(&contacts[i].name);
	}

	printf("Do you want to update the address? (y or n): ");
	if(yes()){
		contacts[i].address.apartmentNumber = 0;
		getAddress(&contacts[i].address);
	}

	printf("Do you want to update the numbers? (y or n): ");
	if(yes()){
		contacts[i].numbers.home[0] = '\0';
		contacts[i].numbers.business[0] = '\0';
		getNumbers(&contacts[i].numbers);
	}

	printf("--- Contact Updated! ---\n\n");
	
}

// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size){

	int i = 0;
	char num[11];

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(num);

	i = findContactIndex(contacts, size, num);	

	if(i < 0){
		printf("*** Contact NOT FOUND ***\n");
		return;
	}
	
	printf("\nContact found:\n");
	displayContact(contacts + i);

	printf("\nCONFIRM: Delete this contact? (y or n): ");
	if(!yes()) {
		putchar('\n');
		return;
	}

	// all optional values must be set to a default value
	// as this will prevent the next contact that takes
	// the same spot to possibly have info that doesn't
	// belong to them
	
	contacts[i].name.middleInitial[0] = '\0';
	contacts[i].address.apartmentNumber = 0;
	contacts[i].numbers.cell[0] = '\0';
	contacts[i].numbers.home[0] = '\0';
	contacts[i].numbers.business[0] = '\0';

	printf("--- Contact deleted! ---\n\n");

}

// sortContacts:
// Put function definition below:
// bubble sort algorithm
void sortContacts(struct Contact contacts[], int size){

	int i, j = size;
	int isDone = 0;
	struct Contact temp;

	while(!isDone){

		j--;
		isDone = 1;

		for(i = 0; i < j; i++){
			if(strcmp(contacts[i].numbers.cell,
				 contacts[i + 1].numbers.cell) > 0){
				temp = contacts[i];
				contacts[i] = contacts[i + 1];
				contacts[i + 1] = temp;	
				isDone = 0;
			}
		}
	
	}

	printf("\n--- Contacts sorted! ---\n\n");

}


