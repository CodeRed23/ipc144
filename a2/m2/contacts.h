/*----------------------
Name: Nicholas Defranco
Student number: 106732183
Email: ndefranco@myseneca.ca
Section: P
Date: Nov 14th 2018
------------------------
Assignment: 2
Milestone: 2
------------------------*/
#pragma once

// Structure type Name declaration (Milestone 1)

struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

// Structure type Address declaration (Milstone 1)
struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration (Milestone 1)
struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};

// Structure type Contact declaration (Milestone 3)
struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};

//------------------------------------
// Function Prototypes
//------------------------------------

// ======= Milestone 4 ======

// Get and store from standard input the values for Name

void getName(struct Name *);

// Get and store from standard input the values for address

void getAddress(struct Address *);

// Get and store from standard input the values for Numbers

void getNumbers(struct Numbers *);

// Get and store from standard input the values for a Contact

void getContact(struct Contact *);

