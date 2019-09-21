// Name: Nicholas DeFranco
// Student #: 106732183
// Email: ndefranco@myseneca.ca
// Section: P
// WorShop: 3 - Logic - temps.c

#define _CRT_SECURE_NO_WARNINGS
#define NUMS 3

#include<stdio.h>

int main(void){
	
	printf("---=== IPC Temperature Analyzer ===---\n");
	
	int total_high = 0;
	int total_low = 0;
	int temp_high;
	int temp_low;
	
	int i;

	for(i = 1; i <= NUMS; i++){

		do {
			printf("Enter the high value for day %d: ", i);
			scanf("%d", &temp_high);
			printf("\nEnter the low value for day %d: ", i);
			scanf("%d", &temp_low);
			if((temp_low > temp_high) || (temp_high > 40) || (temp_low < -40)){
				printf("\nIncorrect values, temperatures must be in the range -40 to 40, "
				"high must be greater than low.\n");
			}
			printf("\n");
		}while((temp_low > temp_high) || (temp_high > 40) || (temp_low < -40));
		
		total_high += temp_high;
		total_low += temp_low;
		
	}

	float average_temp = ((float)(total_high + total_low)) / ((float)(NUMS * 2));

	printf("The average (mean) temperature was: %.2f\n", average_temp);
	
	return 0;
}
