/*
	 Name:      Nicholas DeFranco
	 Student#:	106732183
	 Section:	P
*/

#include<stdio.h>

#define _CRT_SECURE_NO_WARNINGS

int main(void) {

	double amount;
	int loonies;

	printf("%s", "Please enter the amount to be paid: $");
	scanf("%lf", &amount);

	loonies = (int)(amount);

	printf("%s", "Loonies required: ");
	printf("%d", loonies);
	printf("%s", ", balance owing $");

	amount = amount - loonies;

	printf("%.2lf", amount);

	int quarters = (int)(amount / 0.25);

	printf("%s", "\nQuarters required: ");
	printf("%d", quarters);
	printf("%s", ", balance owing $");

	printf("%.2lf", (amount - (quarters * 0.25)));
	printf("%s", "\n");
	return 0;
}
