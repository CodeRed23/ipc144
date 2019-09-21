/*
Name: Nicholas Defranco
Student number: 106732183
Email: ndefranco@myseneca.ca
Workshop: 5
Section: P
Date: Oct 12th 2018
*/

//*****************************************************************
//*****					Please Read							*******
// There seems to be a conflict with the instructions given to us
// as well as the advice you gave in the email and announcement
//
// Email:
// 1) you said in the email that you do not want us to search for ID's
// that are positive to determine whether or not the employee actually 
// exists however, the instructions on github specifically say that 
// they wanted us to do exactly that which is why I did that.
//
// 2) you also said in the email that have to initalize the 
// struct array like this:
// struct Employee emp[SIZE] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
// and not like this:
// struct Employee emp[SIZE] = { { 0 } };
// however, the instructions and the pseudocode said that they want us to initialize
// the array using the latter option
// 
// Announcement:
// 1) You suggested that to delete an employee that it would be better 
// to shift all employees that have an index greater than the one deleted 
// down one index, which is what I originally planned to do when I first 
// saw the problem, however, the instructions specifally say that you are 
// not allowed to reorder elements in the array and if you do it 
// will attract a penalty. So are you letting us reorder elements?
//
// I sent an email in response to your email that gave feedback to the 
// in lab workshop but I am assuming you did not recieve it.
// 
// I am running low on time so I cannot wait much longer for a reply,
// so I created two versions of the for loop code for each case since 
// I am confused as to what is expected
//
// Version 1 - uses the emp_counter as the upper bound, this changes 
// the code for removing an employee as it is making me need 
// to shift the index of every employee that is greater than the 
// index of the deleted employee
//
// Version 2 - uses SIZE as upper bound, forcing me to use method of
// checking if the emp id > 0 to determine if the data stored in that
// index is a valid employee
//
// **if you want to change a version on one case change it for them all**
// 
// PLEASE MARK THE VERSION OF THE CODE THAT MEETS YOUR EXPECTATIONS
//*****************************************************************

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Define Number of Employees "SIZE" to be 4
#define SIZE 4

// Declare Struct Employee 
struct Employee {

	int id;
	int age;
	double salary;

};


/* main program */
int main(void) {

	int option = 0;
	int emp_counter = 0;
	int i = 0;
	//j vsriable is needed in version 1
	//int j = 0;
	int temp_id = 0;
	int doesExist = 0;
	int isDone = 0;

	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero
	struct Employee emp[SIZE] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
	// like this instead of this:
	// struct Employee emp[SIZE] = { { 0 } };
	

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program

			printf("Exiting Employee Data Program. Good Bye!!!\n");

			break;
		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 

			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0
			
			// version 1
			// uses emp_counter as a upper bound to know it displayed all valid 
			// employees
			//*****************************************************************
			/*for (i = 0; i < emp_counter; i++) {
				printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
			}*/
			//*****************************************************************

		
			// Version 2
			// uses SIZE as a upper bound and then check if the id > 0 to determine 
			// if the employee data is valid 
			//*****************************************************************
			for (i = 0; i < SIZE; i++) {
				if (emp[i].id > 0) {
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
				}
			}
			//*****************************************************************
			

			printf("\n");

			break;
		case 2:	// Adding Employee
				// @IN-LAB

			printf("Adding Employee\n");
			printf("===============\n");

			// Check for limits on the array and add employee 
			// data accordingly. 
			
			//version 1
			// uses emp_counter as the way to find the next index that must be 
			// filled in 
			//*****************************************************************
			/*if (emp_counter == SIZE) {
				printf("ERROR!!! Maximum Number of Employees Reached\n");
			} else {

				printf("Enter Employee ID: ");
				scanf("%d", &emp[emp_counter].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[emp_counter].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[emp_counter].salary);
				emp_counter++;
									
			}*/
			//*****************************************************************


			
			// version 2
			// runs through the entire array using SIZE as a upper bound and 
			// then checking if the id is equal to zero
			// if so, prompt user for employee info
			//*****************************************************************
			if (emp_counter == SIZE) {
				printf("ERROR!!! Maximum Number of Employees Reached\n");
			}
			else {
				//uses flag isDone to exit loop early
				for (i = 0; i < SIZE && !isDone; i++) {
					if (emp[i].id == 0) {
						printf("Enter Employee ID: ");
						scanf("%d", &emp[i].id);
						printf("Enter Employee Age: ");
						scanf("%d", &emp[i].age);
						printf("Enter Employee Salary: ");
						scanf("%lf", &emp[i].salary);
						emp_counter++;
						isDone = 1; 
					}
				}

			}
			//*****************************************************************
			
			isDone = 0;//reset flag

			printf("\n");

			break;

		case 3: //Update employee salary

			printf("Update Employee Salary\n");
			printf("======================\n");

			do {
				//1. prompt user for an employee's id number
				printf("Enter Employee ID: ");
				scanf("%d", &temp_id);

				//version 1
				// uses emp_counter as a upper bound and then nested if determines
				// whether or not the employee's id is equal to the id the user
				// has inputted
				//*****************************************************************
				/*for (i = 0; i < emp_counter; i++) {
					//2. check if employee exists
					if (emp[i].id == temp_id) {
						//3. if so prompt for a new salary for that employee
						printf("The current salary is %.2lf\n", emp[i].salary);
						printf("Enter Employee New Salary: ");
						scanf("%lf", &emp[i].salary);
						printf("\n");
						doesExist = 1;
					}
				}*/
				//*****************************************************************
				
				
				// Version 2
				// uses SIZE as a upper bound as other than that it is the same
				//*****************************************************************
				for (i = 0; i < SIZE; i++) {
					//2. check if employee exists
					if (emp[i].id == temp_id) {
						//3. if so prompt for a new salary for that employee
						printf("The current salary is %.2lf\n", emp[i].salary);
						printf("Enter Employee New Salary: ");
						scanf("%lf", &emp[i].salary);
						printf("\n");
						doesExist = 1;
					}
				}
				//*****************************************************************
				


				//4. if not repeat from step one
				if(!doesExist){
					printf("*** ERROR: Employee ID not found! ***\n");
				}

			} while (!doesExist);

			doesExist = 0; // reset flag

			break;

		case 4: //Remove employee

			printf("Remove Employee\n");
			printf("===============\n");
			
			do {
				//1. prompt user for an employee's id number
				printf("Enter Employee ID: ");
				scanf("%d", &temp_id);
				//2. check if employee exists


				// version 1
				// uses emp_counter as a upper bound
				//*****************************************************************
				/*for (i = 0; i < emp_counter; i++) {
					//3. if so, more all employees past 
					//   that index down one index
					if (emp[i].id == temp_id) {
						printf("Employee %d will be removed\n\n", emp[i].id);
						// SIZE - 1, so that the computer will not go out of
						// bounds
						for (j = i; j < SIZE - 1; j++) {
							*****************************************************
							// individually moving all info down one index
							// starting from the deleted employee index
							****************************************************
							emp[j].id = emp[j + 1].id;
							emp[j].age = emp[j + 1].age;
							emp[j].salary = emp[j + 1].salary;
							*****************************************************
							// OR
							// assign the previous index with the employee 
							// in the position that is one index higher 
							// starting from the deleted employee index
							*****************************************************
							//emp[j] = emp[j + 1];
							*****************************************************
						}
						doesExist = 1;
						emp_counter--;
					}
				}*/
				//*****************************************************************

				
				// version 2
				// once found it sets the id equal to zero, an invalid value
				//*****************************************************************
				for (i = 0; i < SIZE; i++) {
					//3. if so, set that employee's 
					// id equal to zero
					if (emp[i].id == temp_id) {
						printf("Employee %d will be removed\n\n", emp[i].id);
						doesExist = 1;
						emp[i].id = 0;
						emp_counter--;
					}
				}
				//*****************************************************************
				

				if(!doesExist){
					printf("*** ERROR: Employee ID not found! ***\n");
				} 

				//4. if not repeat from step one
			} while (!doesExist);

			doesExist = 0; // reset flag

			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);


	return 0;
}
