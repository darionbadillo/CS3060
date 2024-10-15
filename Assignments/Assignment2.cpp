/*
    * Darion Badillo
    * 09/12/2024
    * CS 3060
    * Assignment 2
    *
    * Description:
	* C++ program that contains three functions: chipsAndSalsa, monkeyBusiness, and gradeBook.
	* Main function will prompt the user to select a program to run (1-3).
	*   chipsAndSalsa: This function will prompt the user to enter the number of jars sold for each of the five types of salsa.
	*                  Then, a report will be generated showing the total sales, highest selling salsa, and the lowest selling salsa.
	*   monkeyBusiness: This function will prompt the user to enter the amount of food eaten by each monkey for each day.
	*                   Then, a report will be generated showing the average food eaten by all monkeys per day, the least amount of food eaten, and the most amount of food eaten.
	*   gradeBook: This function will prompt the user to enter the five student's names and their scores for the four tests.
    * 
*/

#include <iostream>
using namespace std;
#include <iomanip> 
#include <string>

// Constants
const int ARRAY_SIZE_1 = 5, ARRAY_SIZE_2 = 3, ARRAY_SIZE_3 = 4;

// Function declarations (prototypes)
void chipsAndSalsa();
void monkeyBusiness();
void gradeBook();


// Main function
int main() {

    // Variable
    int control = 0;

    // Function Calls

    cout << "Select a program to run (1-3): " << endl;
    while (control < 1 || control > 3) {
        cout << "1. Chips and Salsa\n2. Monkey Business \n3. Grade Book" << endl;

        // Input: user selection
        cin >> control;
        if (control < 1 || control > 3) {
            cout << "Invalid input" << endl;
		} // if
	} // while

    switch (control) {

        // Chips and Salsa
        case 1:
            cout << "Chips and Salsa" << endl;
            chipsAndSalsa();
            break;
        

		// Monkey Business
        case 2:
            cout << "Monkey Business" << endl;
            monkeyBusiness();
            break;
        
		// Grade Book
        case 3:
            cout << "Grade Book" << endl;
            gradeBook();
            break;

		// Default case
        default:
            cout << "Invalid input. Goodbye!" << endl;
            break;
        }

	// End of program
    return 0;
} // main

// Function definitions

/*
* Function: chipsAndSalsa
* Description: This function will prompt the user to enter the number of jars sold for each of the five types of salsa.
* Then, a report will be generated showing the total sales, highest selling salsa, and the lowest selling salsa.
*/
void chipsAndSalsa()
{
    // Variables
    int totalSales = 0, highestSales = 0, lowestSales = 0;
    string salsaNames[ARRAY_SIZE_1] = {"Mild", "Medium", "Sweet", "Hot", "Zesty"};
    int salsaSales[ARRAY_SIZE_1] = {0, 0, 0, 0, 0};

    // Input: number of jars sold for each salsa
    for (int i = 0; i < ARRAY_SIZE_1; i++) {
        cout << "Enter the number of jars sold for " << salsaNames[i] << " salsa: ";

        cin >> salsaSales[i];

		//input validation
		if (salsaSales[i] < 0) {
			cout << "Invalid input. Please enter a positive number." << endl;
			i--;
		}// if

		// Calculate total sales
        else
        {
            totalSales += salsaSales[i];
        }
        
    }// for

    // Find highest and lowest sales
    highestSales = salsaSales[0];
    lowestSales = salsaSales[0];
    
    for (int i = 1; i < ARRAY_SIZE_1; i++) {

        // find highest
        if (salsaSales[i] > highestSales) {
            highestSales = i;
        }// if

        // find lowest
        if (salsaSales[i] < lowestSales) {
            lowestSales = i;
        }// if
    }// for

    cout << "Salsa Sales Report" << endl;
    cout << "Salsa Name\t\tJars Sold" << endl;
    cout << "--------------------------------" << endl;
    for (int i = 0; i < ARRAY_SIZE_1; i++) {
        cout << salsaNames[i] << "\t\t" << salsaSales[i] << endl;
    } // for
    cout << "Total Sales: " << totalSales << endl;
    cout << "Highest Sales: " << salsaNames[highestSales] << endl;
    cout << "Lowest Sales: " << salsaNames[lowestSales] << endl;

} // chipsAndSalsa

/*
* Function: monkeyBusiness
* Description: This function will prompt the user to enter the amount of food eaten by each monkey for each day.
* Then, a report will be generated showing the average food eaten by all monkeys per day, the least amount of food eaten, and the most amount of food eaten.
*/
void monkeyBusiness()
{
	// Variables
    int monkey, day;
	double food[ARRAY_SIZE_2][ARRAY_SIZE_1], totalFood = 0, highestFood = 0, lowestFood = 0, avgFood, sum;

	// Input: food eaten by each monkey
	//row = monkey, column = day
	for (monkey = 0; monkey < ARRAY_SIZE_2; monkey++) {
        cout << "Enter the amount of food eaten by Monkey " << monkey + 1 << " for each day" << endl;
		for (day = 0; day < ARRAY_SIZE_1; day++) {
			cout << "Day " << day + 1 << ": ";
			cin >> food[monkey][day];
			//input validation
			if (food[monkey][day] < 0) {
				cout << "Invalid input. Please enter a positive number." << endl;
				day--;
			}// if
			// Calculate total food
			else
			{
				totalFood += food[monkey][day];
			}
		}// inner for
	}// outer for

	// Find highest and lowest food
	highestFood = food[0][0];
	lowestFood = food[0][0];
	for (monkey = 0; monkey < ARRAY_SIZE_2; monkey++) {
		for (day = 0; day < ARRAY_SIZE_1; day++) {
			// find highest
			if (food[monkey][day] > highestFood) {
				highestFood = food[monkey][day];
			}// if
			// find lowest
			if (food[monkey][day] < lowestFood) {
				lowestFood = food[monkey][day];
			}// if
		}// inner for
	}// outer for

	// Output: food eaten by each monkey
    cout << "Average Food Eaten by All Monkeys per Day: " << endl;
    for (day = 0; day < ARRAY_SIZE_1; day++) {
        sum = 0;
        for (monkey = 0; monkey < ARRAY_SIZE_2; monkey++) {
            sum += food[monkey][day];
        }// inner for
        avgFood = sum / ARRAY_SIZE_1;
        cout << "Day " << day + 1 << ": " << avgFood << endl;
    }// outer for
    
    cout << "Least amount of food eaten: " << lowestFood << endl;
    cout << "Most amount of food eaten: " << highestFood << endl;


}// monkeyBusiness

/*
* Function: gradeBook
* Description: This function will prompt the user to enter the five student's names and their scores for the four tests.
*/ 
void gradeBook()
{
    // Variables
    string studentNames[ARRAY_SIZE_1];
    double studentGrades[ARRAY_SIZE_1][ARRAY_SIZE_3], totalGrades[ARRAY_SIZE_1] = {0}, avgGrade[ARRAY_SIZE_1] = {0};
    char letterGrades[ARRAY_SIZE_1];
    double totalAvg = 0;
    int student, assignment;

    // Input: student names and grades
    for (student = 0; student < ARRAY_SIZE_1; student++) {
        cout << "Enter the student's name: ";
        cin >> studentNames[student];

        for (assignment = 0; assignment < ARRAY_SIZE_3; assignment++) {
            cout << "Enter " << studentNames[student] << "'s grade for assignment " << assignment + 1 << ": ";
            cin >> studentGrades[student][assignment];

            // Input validation for grades between 0 and 100
            while (studentGrades[student][assignment] < 0 || studentGrades[student][assignment] > 100) {
                cout << "Invalid input. Please enter a grade between 0 and 100 for Assignment " << assignment + 1 << ": ";
                cin >> studentGrades[student][assignment];
			}// while

            // Add to total grades for this student
            totalGrades[student] += studentGrades[student][assignment];
		} // inner for

        // Calculate average for the student
        avgGrade[student] = totalGrades[student] / ARRAY_SIZE_3;

        // Assign letter grade based on average
        if (avgGrade[student] >= 90) {
            letterGrades[student] = 'A';
        } else if (avgGrade[student] >= 80) {
            letterGrades[student] = 'B';
        } else if (avgGrade[student] >= 70) {
            letterGrades[student] = 'C';
        } else if (avgGrade[student] >= 60) {
            letterGrades[student] = 'D';
        } else {
            letterGrades[student] = 'F';
        } // if chain

        // Add to total average for all students
        totalAvg += avgGrade[student];
	} // outer for

    // Output student names, averages, and letter grades
    cout << "\nStudent Grade Report" << endl;
    cout << "-------------------------" << endl;
    cout << "Student Name\tAverage\tGrade" << endl;
    cout << "-------------------------" << endl;
  
    for (student = 0; student < ARRAY_SIZE_1; student++) {
        cout << studentNames[student] << "\t\t" << fixed << setprecision(2) << avgGrade[student] 
             << "\t" << letterGrades[student] << endl;
    } // for

    // Output the overall average for the class
    totalAvg /= ARRAY_SIZE_1;
    cout << "\nClass Average: " << fixed << setprecision(2) << totalAvg << endl;
    
} // gradeBook