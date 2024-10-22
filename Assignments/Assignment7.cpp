/*
 * Darion Badillo
 * 10/22/2024
 * CS 3060
 * Assignment 7
 *
 * Description:
 * C++ program with three different components:
 *
 * 1. String Search in a File
 *       - User enters a file name and a string. The program searches the file for every occurrence of the string
 *         and displays the line that contains the string. It also reports the total number of occurrences.
 *
 * 2. Array to File and File to Array
 *       - User writes an integer array to a binary file, then reads the array back and displays its contents.
 *
 * 3. Corporate Sales Data
 *       - User enters sales data for four divisions over four quarters. The program stores the data and
 *         writes it to a file, ensuring no negative numbers are accepted.
 *      - The program then reads the data from the file and displays it.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Constants
const int DIVISIONS = 4;
const int QUARTERS = 4;

// Structs
struct SalesData
{
	string divisionName;
	double quarterlySales[QUARTERS] = {};
};

// Function Prototypes
void displayMenu();
void stringSearch();
void arrayFileProgram();
void arrayToFile(const string& filename, int array[], int size);
void fileToArray(const string& filename, int array[], int size);
void corporateSalesData();
void getDivisionSales(SalesData sales[]);
void writeSalesToFile(SalesData sales[], int size);
void getValidInt(int& input, const string& prompt);
void getValidDouble(double& input, const string& prompt);
char getYesOrNo(const string& prompt);

// Main Function
int main()
{
	// Variables
	char choice;

	do
	{
		// Display the menu
		displayMenu();
		cin >> choice;

		// Clear the input buffer
		cin.ignore(1000, '\n');

		// Switch between menu options
		switch (choice)
		{
		case '1':
			stringSearch();
			break;
		case '2':
			arrayFileProgram();
			break;
		case '3':
			corporateSalesData();
			break;
		case '4':
			cout << setfill('-') << setw(40) << "-" << endl;
			cout << "Exiting program." << endl;
			cout << setfill('-') << setw(40) << "-" << endl;

			break;
		default:
			cout << "Invalid input." << endl;
		} // switch

	} while (choice != '4'); // Continue until the user chooses to exit

	cout << "Have a nice day!" << endl;
	cout << setfill('-') << setw(40) << "-" << endl;

	return 0;
} // main

// Displays the main menu
void displayMenu()
{
	cout << setfill('-') << setw(40) << "-" << endl;
	cout << "Select a program to run (1-3) or enter 4 to exit:\n";
	cout << "1. String Search in a File\n";
	cout << "2. Array to File and File to Array\n";
	cout << "3. Corporate Sales Data\n";
	cout << "4. Exit\n";
	cout << setfill('-') << setw(40) << "-" << endl;

} // displayMenu

// Asks the user for a file name and a string to search. Displays matching lines and occurrence count.
void stringSearch()
{
	// Variables
	string filename, searchString, line;
	int count = 0;

	// Display the program title
	cout << setfill('-') << setw(40) << "-" << endl;
	cout << "String Search in a File" << endl;
	cout << setfill('-') << setw(40) << "-" << endl;

	// Get the file name and string to search for
	cout << "Enter the file name: ";
	getline(cin, filename);
	cout << "Enter the string to search for: ";
	getline(cin, searchString);

	// Open the file in input mode
	ifstream file(filename);
	if (!file)
	{
		cerr << "Error opening file!" << endl;
		return;
	} // if

	// Search for the string in each line of the file
	while (getline(file, line))
	{

		// Display the line if the string is found
		if (line.find(searchString) != string::npos)
		{
			cout << line << endl;
			count++;
		} // if
	} // while

	file.close();
	cout << "The string \"" << searchString << "\" appeared " << count << " times." << endl;
} // stringSearch

// Controls the array to file and file to array programs
void arrayFileProgram()
{
	// Variables
	char choice;
	int size;
	int* array;
	string filename = "arraydata.bin";

	// Display the program title
	cout << setfill('-') << setw(40) << "-" << endl;
	cout << "Array to File and File to Array" << endl;
	cout << setfill('-') << setw(40) << "-" << endl;

	// Ask the user if they want to enter a new file name
	choice = getYesOrNo("Would you like to enter a new file name? (Y/N): ");
	if (choice == 'Y')
	{
		cout << "Enter the file name: ";
		getline(cin, filename);
	} // if

	// Get the size of the array
	getValidInt(size, "Enter the size of the array: ");
	array = new int[size];

	// Fill out the array with user input
	for (int i = 0; i < size; i++)
	{
		getValidInt(array[i], ("Enter element " + to_string(i + 1) + ": "));
	} // for

	// Print the array to the file
	arrayToFile(filename, array, size);

	fileToArray(filename, array, size);

	// Deallocate the array
	delete[] array;

} // arrayFileProgram

// Writes an integer array to a binary file.
void arrayToFile(const string& filename, int array[], int size)
{
	// Open the file in binary mode
	ofstream file(filename, ios::binary);
	if (!file)
	{
		// Error message if the file cannot be opened
		cerr << "Error opening file for writing!" << endl;
		return;
	} // if

	// Write the array to the file and close it
	file.write(reinterpret_cast<char*>(array), sizeof(int) * size);
	file.close();

	// Success message
	cout << "Array contents successfully written to " << filename << endl;

} // arrayToFile

// Reads an integer array from a binary file and displays the contents.
void fileToArray(const string& filename, int array[], int size)
{
	// Open the file in binary mode
	ifstream file(filename, ios::binary);

	// Error message if the file cannot be opened
	if (!file)
	{
		cerr << "Error opening file for reading!" << endl;
		return;
	}

	// Read the array from the file and close it
	file.read(reinterpret_cast<char*>(array), sizeof(int) * size);
	file.close();

	// Display the array contents
	cout << "Array contents read from " << filename << ":" << endl;
	for (int i = 0; i < size; i++)
	{
		// Display each element of the array
		cout << array[i] << " ";
	}
	cout << endl;
} // fileToArray

// Controls the corporate sales data program
void corporateSalesData()
{
	// Variables
	SalesData sales[DIVISIONS] = {};
	const string& filename = "salesdata.txt";

	// Display the program title
	cout << setfill('-') << setw(40) << "-" << endl;
	cout << "Corporate Sales Data" << endl;
	cout << setfill('-') << setw(40) << "-" << endl;

	// Get sales data for each division
	getDivisionSales(sales);

	// Write sales data to a file
	writeSalesToFile(sales, DIVISIONS);
	cout << "Sales data has been written to " << filename << endl;

	cout << "Would you like to view the sales data file? (Y/N): ";
	if (getYesOrNo("") == 'Y')
	{
		// Open the file in input mode
		ifstream file(filename);
		if (!file)
		{
			cerr << "Error opening file!" << endl;
			return;
		} // if

		// Display the file contents
		string line;
		while (getline(file, line))
		{
			cout << line << endl;
		} // while

		file.close();
	} // if

} // corporateSalesData

// Prompts the user to enter sales data for one division
void getDivisionSales(SalesData sales[])
{
	// Get sales data for each division
	for (int i = 0; i < DIVISIONS; i++)
	{
		// Get the division name while ensuring it is not empty
		do {
			cout << "Enter the name of division " << (i + 1) << " of " << DIVISIONS << ": ";
			getline(cin, sales[i].divisionName);

			// Validate that the division name is not empty
			if (sales[i].divisionName.empty()) {
				cout << "Division name cannot be empty. Please re-enter." << endl;
			}// if

		} while (sales[i].divisionName.empty());

		cout << sales[i].divisionName << " division sales:" << endl;

		// Get sales data for each quarter of the division
		for (int j = 0; j < QUARTERS; j++)
		{
			do
			{
				getValidDouble(sales[i].quarterlySales[j], ("Enter sales for quarter " + to_string(j + 1) + ": $"));

				// Validate that sales are not negative
				if (sales[i].quarterlySales[j] < 0)
				{
					cout << "Sales cannot be negative. Please re-enter." << endl;
				} // if

			} while (sales[i].quarterlySales[j] < 0);

			// Clear the input buffer
			cin.ignore(1000, '\n');
			cin.clear();

		} // quarters for
	} // divisions for
} // getDivisionSales

// Writes the sales data to a text file
void writeSalesToFile(SalesData sales[], int size)
{
	// Open the file in output mode
	ofstream file("salesData.txt");

	// Error message if the file cannot be opened
	if (!file)
	{
		cerr << "Error opening file!" << endl;
		return;
	} // if

	// Write the sales data to the file
	for (int i = 0; i < size; i++)
	{
		// Write the division name
		file << "Division: " << sales[i].divisionName << endl;
		// Write sales data for each quarter
		for (int q = 0; q < QUARTERS; q++)
		{
			file << "  Quarter " << (q + 1) << ": $" << sales[i].quarterlySales[q] << endl;
		} // inner for
	}// outer for
	file.close();
} // writeSalesToFile

// Gets a valid integer input from the user
void getValidInt(int& input, const string& prompt)
{
	cout << prompt;
	cin >> input;

	while (cin.fail() || input < 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input! Please enter a non-negative value: ";
		cin >> input;
	}
} // getValidInt

void getValidDouble(double& input, const string& prompt)
{
	cout << prompt;
	cin >> input;

	while (cin.fail() || input < 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input! Please enter a non-negative value: ";
		cin >> input;
	}
} // getValidDouble

// Gets a 'Y' or 'N' response with validation
char getYesOrNo(const string& prompt)
{
	char choice;

	cout << prompt;
	cin >> choice;
	choice = toupper(choice);
	cin.ignore(1000, '\n');

	while (choice != 'Y' && choice != 'N')
	{
		cout << "Invalid input. Please enter Y or N: ";
		cin >> choice;
		choice = toupper(choice);
		cin.ignore(1000, '\n');
	}
	return choice;
} // getYesOrNo
