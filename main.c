
#include <stdio.h>

#define MAXEMPS 3
#define AMOUNTOFDAYS 7

struct Employee {

	char name[50];
	double hourlyRate;
	double hoursWorked[AMOUNTOFDAYS];

};

char days[7][5] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };


int main(void){

	struct Employee emps[MAXEMPS] = { {"Billy Bob", 17.5, {2, 3, 4, 5, 6, 0, 0} }, {"Betty Jean", 21.00, {3, 4, 5, 6, 7, 8, 9} }, {"Jean Ann", 18.00, {2, 0, 3, 0, 4, 0, 0} } };
	double dailyTotal[MAXEMPS][AMOUNTOFDAYS] = {  { 0.0 } };

	int i = 0;
	int j = 0;
	double sum = 0;

	printf("\n");

	for(i = 0; i < MAXEMPS; i++){
		printf("---%s---\n\n", emps[i].name);
		for(j = 0; j < AMOUNTOFDAYS; j++){
			dailyTotal[i][j] = emps[i].hoursWorked[j] * emps[i].hourlyRate;
			printf("Money owed for %s is $%.2lf\n", days[j], dailyTotal[i][j]);
			sum += dailyTotal[i][j];
		}
 
		printf("\nThe total money earned by: %s is $%.2lf\n\n", emps[i].name, sum);
		sum = 0;
	}

	return 0;

}
