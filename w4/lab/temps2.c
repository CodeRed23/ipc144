//----------------------------------------------------
// Name: Nicholas DeFranco
// Student #106732183
// Email: ndefranco@myseneca.ca
// Section: P
// WorkShop: 4
// ---------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAXLENGTH 10

int main(void){

	int days, lows[MAXLENGTH], highs[MAXLENGTH];
	
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");

	do{
		scanf("%d", &days);
		printf("\n");

		if(days < 3 || days > 10){
			printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		}
        }while(days < 3 || days > 10);	

	int i;

	for(i = 0; i < days; i++){
		printf("Day %d - High: ", (i + 1));
		scanf("%d", &highs[i]);
		printf("Day %d - Low: ", (i + 1));
		scanf("%d", &lows[i]);
	}

	printf("\nDay  Hi  Low\n");

	int j;

	for(j = 0; j < days; j++){
		printf("%d    %d    %d\n", (j + 1), highs[j], lows[j]);
	}

	return 0;

}
