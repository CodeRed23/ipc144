/*
		 Name:      Nicholas DeFranco
		 Student#:      106732183
		 Section:       P
*/

#include<stdio.h>

#define _CRT_SECURE_NO_WARNINGS

int main(void) {

	double amount;
	int loonies;
	const double GST = 1.13;

	printf("%s", "Please enter the amount to be paid: $");
	scanf("%lf", &amount);
	printf("%s", "GST: 1.13\n");
	printf("%s", "Balance owing: $");
	
	amount *= GST;
	amount += 0.005;

	printf("%.2lf", amount);
	printf("%s", "\n");

	loonies = (int)(amount);

	printf("%s", "Loonies required: ");
	printf("%d", loonies);
	printf("%s", ", balance owing $");

	amount = amount - loonies;

	printf("%.2lf", amount);
	//
	int quarters = (int)(amount / 0.25);

	printf("%s", "\nQuarters required: ");
	printf("%d", quarters);
	printf("%s", ", balance owing $");

	if(quarters != 0){
		amount = (int)(amount * 100) % (int)(quarters * 25);
		amount /= 100;
	}

	printf("%.2lf", amount);
	printf("%s", "\n");
	//

	int dimes = (int)(amount / 0.10);

	printf("%s", "Dimes required: ");
	printf("%d", dimes);
	printf("%s", ", balance owing $");

	if(dimes != 0){
		amount = (int)(amount * 100) % (int)(dimes * 10);
		amount /= 100;
	}

	printf("%.2lf", amount);
	printf("%s", "\n");
	//
	int nickels = (int)(amount / 0.05);

	printf("%s", "Nickels required: ");
	printf("%d", nickels);
	printf("%s", ", balance owing $");


	if(nickels != 0){
		amount = (int)(amount * 100) % (int)(nickels * 5);
		amount /= 100; 
	}

	printf("%.2lf", amount);
	printf("%s", "\n");
	//
	int pennies = (int)(amount / 0.01);

	printf("%s", "Pennies required: ");
	printf("%d", pennies);
	printf("%s", ", balance owing $");

	if(pennies != 0){
		amount = (int)(amount * 100) % (int)(pennies);
		amount /= 100;
	}

	printf("%.2lf", amount);
	printf("%s", "\n");
	//
	return 0;
}
