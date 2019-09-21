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
			printf("Invalid entry, please enter a number between "
				"3 and 10, inclusive: ");
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

	int highest = highs[0], lowest = lows[0];
	int high_day, low_day;
	int j;

	for(j = 0; j < days; j++){
		printf("%d    %d    %d\n", (j + 1), highs[j], lows[j]);
		
		if(highs[j] > highest) {
			highest = highs[j];
			high_day = j + 1;
		}

		if(lows[j] < lowest) {
			lowest = lows[j];
			low_day = j + 1;
		}

	}

	printf("\n");
	printf("The highest temperature was %d, on day %d\n", highest, high_day);
	printf("The lowest temperature was %d, on day %d\n\n", lowest, low_day);

	printf("Enter a number between 1 and %d to see the average "
		"temperature for the entered number of days, "
		"enter a negative number to exit: ", days);

	int avg_day, negative = 0;
	int total_temp = 0;
	
	do {

		scanf("%d", &avg_day);
		printf("\n");

		if(avg_day == 0 || avg_day > days){
			printf("Invalid entry, please enter a number "
			"between 1 and %d, inclusive: ", days);
		} else if(avg_day < 0){
			negative = 1;
		}else {
			for(i = 0; i < avg_day; i++){
				total_temp += highs[i] + lows[i];	
			}
			
			printf("The average temperature up to day "
				"%d is: %.2f\n", avg_day, 
				((float)total_temp/(float)(avg_day * 2)));

			total_temp = 0;

			printf("\nEnter a number between 1 and %d to see "
				"the average temperature for the entered "
				"number of days, enter a negative "
				"number to exit: ", days);
		}

	} while(!negative);

	printf("Goodbye!\n");	

	return 0;

}
