//do we need this for this file?
//I used the same format as the other 
//one we were asked to put in
#ifndef CONTACTHELPERS_H_
#define CONTACTHELPERS_H_
/* ------------------------------------------------
 * Name: Nicholas Defranco
 * Student number: 106732183
 * Email: ndefranco@myseneca.ca
 * Section: P
 * Date: Nov 21st 2018
 * ------------------------------------------------
 *  Assignment: 2
 *  Milestone: 4
 *  -----------------------------------------------
 *  Description: This header file modularizes general helper functions to
 *  help reduce redundant coding for common repetitive tasks.
 *  ---------------------------------------------------------------------*/


//Hint:  This header file now has functions with parameters referring to 
//	 the struct Contact type so be sure to include the contacts.h header:

#include "contacts.h"

// HINT: 
// You will most likely want to include this header file
// in other files of the project since it provides general 
// helper functions that can be used throughout.
//
//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// Clear the standard input buffer
void clearKeyboard(void);

//pauses execution
void pause(void);

//validates int input
int getInt(void);

//validates int input within a range inclusive
int getIntInRange(int, int);

//gets confirmation from user
int yes(void);

//prints menu to STDOUT
int menu(void);

//heart of program
//connects all functionality of the 
//program together 
void contactManagerSystem(void);

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | NOTE:  Add new function prototypes as per the   |
// |        Milestone-3 specifications document      |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char[]);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact[], int, const char[]);

//printRepeatingChar
//helps print header and footer
//I hope I can do this
void printRepeatingChar(char, int);

// displayContactHeader
// put function prototype here:
void displayContactHeader(void);

// displayContactFooter:
// put function prototype here:
void displayContactFooter(int);

// displayContact:
// put function prototype here:
void displayContact(const struct Contact*);

// displayContacts:
// put function prototype here:
void displayContacts(const struct Contact[], int);

// searchContacts:
// put function prototype here:
void searchContacts(const struct Contact[], int);

// addContact:
// put function prototype here:
void addContact(struct Contact[], int);

// updateContact:
// put function prototype here:
void updateContact(struct Contact[], int);

// deleteContact:
// put function prototype here:
void deleteContact(struct Contact[], int);

// sortContacts:
// put function prototype here:
void sortContacts(struct Contact[], int);

#endif
