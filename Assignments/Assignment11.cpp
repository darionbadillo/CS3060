/*
 * Darion Badillo
 * 11/26/2024
 * CS 3060
 * Assignment 10
 *
 * Description:
 * C++ program with two different components:
 *
 * 1. Minimum/Maximum Template Functions:
 *    - Minimum Template Function: Returns the minimum of two values of any data type
 *    - Maximum Template Function: Returns the maximum of two values of any data type
 *    - Both functions use a ternary operator to compare the values returning the desired result
 *
 * 2. Test Scores Class:
 *    - Constructor that takes an array of test scores as its argument
 *    - Accessor that returns the average of the test scores
 *    - If any test score is negative, the class throws an exception
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <type_traits>

using namespace std;

// Constants
const int MENU_WIDTH = 40;

// Classes
class TestScores {
    private:
        double* scores;
        int numScores;
        double average = 0;

    public:
        // Constructors
        TestScores() : scores(nullptr), numScores(0) {
        } // default constructor

        TestScores(double* array, int total) : scores(array), numScores(total) {            
            calculateAverage();
        } // constructor

        // Calculate the average of the test scores
        void calculateAverage() {
            for (int i = 0; i < numScores; i++) {
                if (scores[i] < 0 || scores[i] > 100) {
                    throw "Invalid test score. Test Scores must be greater than 0 and less than 100.";
                } // if

                // Sum the test scores
                average += scores[i];
            } // for

            // Calculate the average
            average /= numScores;
        } // calculateAverage

        // Accessor
        double getAverage() const {
            return average;
        } // getAverage

        // Print the test scores
        void printScores() {
            for (int i = 0; i < numScores; i++) {
                cout << "Test Score " << i + 1 << ": " << scores[i] << endl;
            } // for
        } // printScores

}; // TestScores

// Function Prototypes and Templates
void displayMenu();

// Function template to get valid input for any data type
template <class T>
void getValid(T& num, string prompt) {
    cout << prompt;
	// Validate input
	while (!(cin >> num)) { 
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input. Enter a valid number: ";
        cout << prompt;
	} // while
	cin.ignore(1000, '\n'); // Clear the input buffer
} // getValid

void minimumMaximumProgram();
template <class T>
T minimum(T num1, T num2) {return (num1 < num2) ? num1 : num2;} // minimum
template <class T>
T maximum(T num1, T num2) {return (num1 > num2) ? num1 : num2;} // maximum

void testScoresProgram();
void getTestScores(double*& scores, int& numScores);

// Main Function
int main() {

    // Variables
    char choice;

    // Set the output formatting for the program
    std::cout << std::fixed << std::setprecision(2);


    // Loop until the user chooses to exit
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(1000, '\n');  // Clear input buffer

        switch (choice) {
        case '1':
            // Minimum/Maximum Template Functions
            minimumMaximumProgram();
            break;

        case '2':
            // Test Scores Class
            testScoresProgram();
            break;

        case '3':
            // Exit the program
            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
            cout << "Exiting program. Have a nice day!" << endl;
            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
            break;
        default:
            // Invalid input
            cout << "Invalid input." << endl;
        }
    } while (choice != '3'); // Continue until the user chooses to exit

    // Exit the program
    return 0;
} // main

// Displays the main menu
void displayMenu() {
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    cout << "Select a program to run (1-2) or enter 3 to exit:\n";
    cout << "1. Minimum/Maximum\n";
    cout << "2. Test Scores\n";
    cout << "3. Exit\n";
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
} // displayMenu

// Driver function for the Minimum/Maximum Template Program
void minimumMaximumProgram() {
    char choice, char1, char2;
    int int1, int2;
    long long1, long2;
    double double1, double2;
    
        cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
        cout << "Minimum/Maximum Template Program" << endl;
        cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;

    do {
        cout << "What data type would you like to compare?" << endl;
        // What data type would you like to compare?
        cout << "Enter '1' for char, '2' for int, '3' for long, '4' for double, or '5' to exit: ";
        cin >> choice;
        cin.ignore(1000, '\n');  // Clear input buffer

        cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;

        switch (choice) {
        case '1':
            // Char
            cout << "Enter two characters to compare: " << endl;
            cout << "Char 1: ";  
            cin >> char1;        
            cin.ignore(1000, '\n');  // Clear input buffer

            cout << "Char 2: ";  
            cin >> char2;        
            cin.ignore(1000, '\n');  // Clear input buffer

            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;

            cout << "Minimum: " << minimum(char1, char2) << endl;
            cout << "Maximum: " << maximum(char1, char2) << endl;
            break;
        
        case '2':
            // Int
            cout << "Enter two integers to compare: " << endl;
            getValid(int1, "Integer 1: ");
            getValid(int2, "Integer 2: ");

            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
            
            cout << "Minimum: " << minimum(int1, int2) << endl;
            cout << "Maximum: " << maximum(int1, int2) << endl;
            break;

        case '3':
            // Long
            cout << "Enter two long integers to compare: " << endl;
            getValid(long1, "Long 1: ");
            getValid(long2, "Long 2: ");

            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
            
            cout << "Minimum: " << minimum(long1, long2) << endl;
            cout << "Maximum: " << maximum(long1, long2) << endl;
            break;

        case '4':
            // Double
            cout << "Enter two double values to compare: "<< endl;
            getValid(double1, "Double 1: ");
            getValid(double2, "Double 2: ");

            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
            
            cout << "Minimum: " << minimum(double1, double2) << endl;
            cout << "Maximum: " << maximum(double1, double2) << endl;
            break;

        case '5':
            // Exit the program
            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
            cout << "Exiting Minimum/Maximum Template Program." << endl;
            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
            break;

        default:
            // Invalid input
            cout << "Invalid input." << endl;
        }

    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;


    } while (choice != '5'); // Continue until the user chooses to exit
} // minimumMaximumProgram

// Driver function for the Test Scores Class Program
void testScoresProgram() {

    // Variables
    int numScores = 0;
    double* scores = nullptr;
    TestScores testScores;

    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    cout << "Test Scores Class Program" << endl;
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;

    getTestScores(scores, numScores);
    
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;

    // Try to create a TestScores object with the test scores. 
    try { 
        // Create a TestScores object
        TestScores testScores(scores, numScores);

        // Display the test scores
        testScores.printScores();

        cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;

        // Display the average of the test scores
        cout << "The average of the test scores is: " << testScores.getAverage() << endl;

        cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;

        delete[] scores;

    } // try
    
    // Catch exception thrown by the TestScores class
    catch (const char* msg) {
            cerr << "ERROR: " << msg << endl;
            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
 
        } // catch

    cout << "Exiting Test Scores Class Program." << endl;

} // testScoresProgram

// Get the test scores from the user
void getTestScores(double*& scores, int& numScores) {
    int num;

    getValid(num, "Enter the number of test scores: ");

    // Allocate memory for the test scores
    scores = new double[num];

    // Get the test scores
    for (int i = 0; i < num; i++) {
        getValid(scores[i], ("Enter test score " + to_string(i + 1) + ": "));
    } // for

    numScores = num;
} // getTestScores
