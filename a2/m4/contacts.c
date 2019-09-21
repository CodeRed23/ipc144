/* --------------------------------------------
Name: Nicholas Defranco
Student number: 106732183
Email: ndefranco@myseneca.ca
Section: P
Date: Nov 21st 2018
--------------------------------------------
Assignment: 2
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

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:

#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:



// clearKeyboard functions were placed after every string input
// as a safeguard in case the user exceeds the max amount
// of characters able to to stored in their corresponding arrays

// confirm variable was removed in favor of the yes function
// which returns a 1 (true) or 0 (false).
//
// yes() function is placed inside the condition for every yes
// or no question

void getName(struct Name *name){

	printf("Please enter the contact's first name: ");	
	scanf("%30[^\n]", name->firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	
	if(yes()){
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", name->middleInitial);
		clearKeyboard();
	}	

	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]", name->lastName);
	clearKeyboard();

}

// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function: 

void getAddress(struct Address *address){

	do {
		printf("Please enter the contact's street number: ");
	} while((address->streetNumber = getInt()) <= 0);

	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]", address->street);
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	if(yes()){
		do {
			printf("Please enter the contact's apartment number: ");
		} while((address->apartmentNumber = getInt()) <= 0);
	}

	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]", address->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf("%40[^\n]", address->city);
	clearKeyboard();

}

// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function: 
// cell numbers are no longer optional

void getNumbers(struct Numbers *numbers) {

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);	

	printf("Do you want to enter a home phone number? (y or n): ");
	if(yes()){
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	if(yes()) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}
	
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// calls all three functions above in the order that they
// appear in the file
// first getName()
// then getAddress()
// finally getNumbers()

void getContact(struct Contact *contact) {

	getName(&(contact->name));
	getAddress(&(contact->address));
	getNumbers(&(contact->numbers));	

}
