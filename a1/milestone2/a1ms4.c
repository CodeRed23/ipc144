/* ---------------------------
 Name: Nicholas Defranco
 Student number: 106732183
 Email: ndefranco@myseneca.ca
 Section: P
 Date: Nov 7th 2018
 -----------------------------
 Assignment: 1
 Milestone: 4
 -----------------------------*/

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// Hint: put the header file name in double quotes so the compiler knows
// 	 to look for it in the same directory/folder as this source file
// #inlude your contacts header file on the next line:

#include "contacts.h"	

int main(void) {

  	// Declare variables here:
  	
  	// Create a variable of type Contact and call it something
  	// self-describing like "contact"
  	// - Hint: Be sure to initialize the values to 0 and empty
  	// C strings
  	// IMPORTANT: Do Not declare variables of type Name, 
  	// Address, or Numbers
	struct Contact contact = {
		 {"", "", ""},
		 {0, "", 0, "", ""},
		 {"", "", ""}
	 };

	// Display the title:
	
	printf("Contact Management System\n");
	printf("=========================\n");
	
	// Call the Contact function getName to store the values
	// for the Name member

	getName(&contact.name);

	// Call the contact function getAddress to store the values 
	// for the Address member
	
	getAddress(&contact.address);

	// Call the contact function getNumbers to store the values
	// for the Numbers member
	
	getNumbers(&contact.numbers);

	// Display Contact Summary Details:
	// The if statments are to avoid printing empty values	
	//
	// if the string starts with the null terminator it 
	// is empty and therfore not used
	//
	// if an integer is set to the value of zero it is not used

	printf("\n");
	printf("Contact Details\n");
	printf("===============\n");

	printf("Name Details\n");
	printf("------------\n");
	printf("First name: %s\n", contact.name.firstName);
	
	if(contact.name.middleInitial[0] != '\0'){
		printf("Middle initial(s): %s\n", contact.name.middleInitial);
	}

	printf("Last name: %s\n\n", contact.name.lastName);
	
	printf("Address Details\n");
	printf("---------------\n");
	printf("Street number: %d\n", contact.address.streetNum);
	printf("Street name: %s\n", contact.address.street);
	
	if(contact.address.apartmentNumber > 0){
		printf("Apartment: %d\n", contact.address.apartmentNumber);
	}

	printf("Postal code: %s\n", contact.address.postalCode);
	printf("City: %s\n\n", contact.address.city);

	if(contact.numbers.cell[0] != '\0' || contact.numbers.home[0] != '\0' ||
			contact.numbers.business[0] != '\0'){

		printf("Phone Numbers\n");
		printf("-------------\n");
	
		if(contact.numbers.cell[0] != '\0'){	
			printf("Cell phone number: %s\n", contact.numbers.cell);
		}

		if(contact.numbers.home[0] != '\0'){
			printf("Home phone number: %s\n", contact.numbers.home);
		}

		if(contact.numbers.business[0] != '\0'){
			printf("Business phone number: %s\n\n",
				 contact.numbers.business);
		}
	}

	// Display Completion Message: 
	
	printf("Structure test for Contact using functions done!\n");
	
	return 0;
}
	
