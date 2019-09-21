/* ---------------------------------
 * Name: Nicholas Defranco
 * Email: ndefranco@myseneca.ca
 * Section: P
 * Date: Nov 14th 2018
 * ---------------------------------
 *  Assignment: 2
 *  Miestone: 2
 *  --------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:

#include "contactHelpers.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
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

			printf("*** OUT OF RANGE *** <Enter a number "
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

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");

	return getIntInRange(0, 6);
	
}

// connects the whole program together
// logic portion of the menu

void contactManagerSystem(void) {

	int isDone = 0;

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
				printf("\n<<< Feature 1 is unavailable >>>\n\n");
				pause();
			break;
		
			case 2:
				printf("\n<<< Feature 2 is unavailable >>>\n\n");
				pause();
			break;
			
			case 3:
				printf("\n<<< Feature 3 is unavailable >>>\n\n");
				pause();
			break;

			case 4:
				printf("\n<<< Feature 4 is unavailable >>>\n\n");
				pause();
			break;

			case 5:
				printf("\n<<< Feature 5 is unavailable >>>\n\n");
				pause();
			break;

			case 6:
				printf("\n<<< Feature 6 is unavailable >>>\n\n");
				pause();
			break;
		}

		printf("\n");

	}while(!isDone);

}
