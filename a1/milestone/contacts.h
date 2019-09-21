/*----------------------
Name: Nicholas Defranco
Student number: 106732183
Email: ndefranco@myseneca.ca
Section: P
Date: Oct 31st 2018
------------------------
Assignment: 1
Milestone: 1
------------------------*/
#pragma once

// Structure type Name declaration

struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

// Structure type Address declaration
struct Address {
	int streetNum;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration
struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};
