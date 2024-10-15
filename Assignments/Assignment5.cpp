/*
	* Darion Badillo
	* 10/08/2024
	* CS 3060
	* Assignment 5
	*
	* Description:
	* C++ program with two main parts:
	* 1. Password Verifier:
	*    - Prompts the user to enter a password and validates it against defined criteria.
	*    - The password must be at least 6 characters long, have at least one uppercase letter, one lowercase letter, and one digit.
	*    - Provides detailed feedback on what is correct or missing and allows the user to check multiple passwords.
	*
	* 2. Customer Account Program:
	*    - Allows the user to input multiple customer records, storing information like name, address, city/state/ZIP, phone number,
	*      account balance, and last payment date.
	*    - The user is then able to search for a customer by name, view the account details, and edit existing customer accounts.
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

// Struct for Customer data
struct Customer {
	string name;
	string address;
	string cityStateZip;
	string telephoneNumber;
	double accountBalance;
	string lastPaymentDate;
};

// Function Prototypes
void displayMenu();
void validatePassword();
void customerAccountProgram();
bool isValidPassword(const string& password, bool& hasUpper, bool& hasLower, bool& hasDigit, bool& isLongEnough);
void displayPasswordFeedback(bool hasUpper, bool hasLower, bool& hasDigit, bool& isLongEnough);
void searchCustomer(Customer customers[], int size, const string& searchName);
void displayCustomer(const Customer& cust);
char getYesOrNoInput(const string& prompt);
void getCustomerData(Customer& customer);
void customerSearchLoop(Customer customers[], int size);
void editCustomerData(Customer customers[], int size);

const int MIN_SIZE = 10; // Minimum array size for Customer accounts

// Main function
int main() {
	char control = 0;

	do {
		displayMenu();
		cin >> control;

		// Clear the input buffer
		cin.ignore(1000, '\n');

		// Switch statement for menu options
		switch (control) {
		case '1':
			validatePassword();
			break;
		case '2':
			customerAccountProgram();
			break;
		case '3':
			cout << "Exiting program." << endl;
			break;
		default:
			cout << "Invalid input." << endl;
		} // switch

	} while (control != '3'); // do-while

	return 0;
} // main

// Function to display the main menu options
void displayMenu() {
	cout << "\nSelect a program to run (1-2) or enter 3 to exit: " << endl;
	cout << "1. Password Verifier\n2. Customer Account Program\n3. Exit" << endl;
} // displayMenu

// Checks if a given password meets specified criteria
void validatePassword() {

	// Variables 
	bool hasUpper, hasLower, hasDigit, isLongEnough;
	char choice = 'Y';
	string password;

	cout << "\nPassword Verifier Program." << endl;

	do {
		// Set/reset criteria variables
		hasUpper = false;
		hasLower = false;
		hasDigit = false;
		isLongEnough = false;

		// Get password from user
		cout << "Enter a password to verify: ";
		cin >> password;

		// Check if password meets all requirements
		if (isValidPassword(password, hasUpper, hasLower, hasDigit, isLongEnough)) {
			cout << "The password is valid." << endl;
		} // if

		else {
			cout << "The password is invalid. Details:" << endl;
			displayPasswordFeedback(hasUpper, hasLower, hasDigit, isLongEnough);
		} // else
		cout << endl;

		// Ask user if they want to check another password
		choice = getYesOrNoInput("Would you like to check another password? (Y/N): ");

	} while (choice == 'Y'); // do-while

} // validatePassword

// Check if the password meets all the criteria
bool isValidPassword(const string& password, bool& hasUpper, bool& hasLower, bool& hasDigit, bool& isLongEnough) {
	isLongEnough = password.length() >= 6;

	// Loop through each character to check for uppercase, lowercase, and digits
	for (char character : password) {
		if (isupper(character)) {
			hasUpper = true;
		}// if

		if (islower(character)) {
			hasLower = true;
		}// if

		if (isdigit(character)) {
			hasDigit = true;
		}// if
	} // for

	// Return true if all criteria are met, return false otherwise
	return hasUpper && hasLower && hasDigit && isLongEnough;
} // isValidPassword

// Provide detailed feedback on what criteria the password meets or fails
void displayPasswordFeedback(bool hasUpper, bool hasLower, bool& hasDigit, bool& isLongEnough) {
	cout << (isLongEnough ? "[PASS]" : "[FAIL]") << " Password must be at least 6 characters long." << endl;
	cout << (hasUpper ? "[PASS]" : "[FAIL]") << " Password must have at least one uppercase letter." << endl;
	cout << (hasLower ? "[PASS]" : "[FAIL]") << " Password must have at least one lowercase letter." << endl;
	cout << (hasDigit ? "[PASS]" : "[FAIL]") << " Password must have at least one digit." << endl;
} // displayPasswordFeedback

// Gets a 'Y' or 'N' input from the user with validation
char getYesOrNoInput(const string& prompt) {
	// Variables
	char choice;

	// Print prompt and get input
	cout << prompt;
	cin >> choice;
	choice = toupper(choice);
	cin.ignore(1000, '\n');

	while (choice != 'Y' && choice != 'N') {
		cout << "Invalid input. Please enter Y or N: ";
		cin >> choice;
		choice = toupper(choice);
		cin.ignore(1000, '\n');
	} // while
	return choice;
} // getYesOrNoInput

// Customer Account Program: Manages customer data and allows searching
void customerAccountProgram() {
	// Variables
	int size;
	char choice;

	cout << "\nCustomer Account Program." << endl;

	// Get the number of customer accounts to manage
	cout << "How many customer accounts would you like to create (minimum " << MIN_SIZE << ")? ";
	cin >> size;

	// Check for valid size input
	while (cin.fail() || size < MIN_SIZE) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid number! Please enter an integer of at least " << MIN_SIZE << ": ";
		cin >> size;
	} // while

	// Clear leftover newline
	cin.ignore(1000, '\n');

	// Dynamically allocate memory for Customer array
	Customer* customers = new Customer[size];

	// Input customer data
	for (int i = 0; i < size; ++i) {
		cout << "\nEntering data for customer #" << i + 1 << ":\n";
		getCustomerData(customers[i]);
	} // for

	// Customer Account Menu
	do {
		cout << "\nCustomer Account Menu:\n";
		cout << "1. Edit Existing Customer\n";
		cout << "2. Display All Customers\n";
		cout << "3. Search Customers\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore(1000, '\n');

		switch (choice) {
		case '1':
			editCustomerData(customers, size);
			break;
		case '2':
			if (size == 0) {
				cout << "No customers to display.\n";
			} // if
			else {
				for (int i = 0; i < size; ++i) {
					cout << "\nCustomer #" << (i + 1) << ":";
					displayCustomer(customers[i]);
				} // for
			} // else
			break;
		case '3':
			if (size == 0) {
				cout << "No customers to search.\n";
			} // if
			else {
				customerSearchLoop(customers, size);
			} // else
			break;
		case '4':
			cout << "Exiting Customer Account Program.\n";
			break;
		default:
			cout << "Invalid choice. Please select from the menu.\n";
		} // switch

	} while (choice != '4'); // do-while

	// Free dynamically allocated memory
	delete[] customers;

} // customerAccountProgram

// Function to input data for a single customer
void getCustomerData(Customer& customer) {

	// Get and validate name
	do {
		cout << "Name: ";
		getline(cin, customer.name);
		if (customer.name.empty()) {
			cout << "Name cannot be empty. Please enter a name.\n";
		} // if
	} while (customer.name.empty()); // do-while

	// Get and validate address
	do {
		cout << "Address: ";
		getline(cin, customer.address);
		if (customer.address.empty()) {
			cout << "Address cannot be empty. Please enter an address.\n";
		} // if
	} while (customer.address.empty()); // do-while

	// Get and validate city, state, ZIP
	do {
		cout << "City, State, ZIP: ";
		getline(cin, customer.cityStateZip);
		if (customer.cityStateZip.empty()) {
			cout << "City, State, ZIP cannot be empty. Please enter the details.\n";
		} // if
	} while (customer.cityStateZip.empty()); // do-while

	// Get and validate telephone number
	do {
		cout << "Telephone Number: ";
		getline(cin, customer.telephoneNumber);
		if (customer.telephoneNumber.empty()) {
			cout << "Telephone Number cannot be empty. Please enter a number.\n";
		} // if
	} while (customer.telephoneNumber.empty()); // do-while

	// Get and validate account balance
	cout << "Account Balance: ";
	cin >> customer.accountBalance;
	while (cin.fail() || customer.accountBalance < 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid balance! Enter a non-negative value: ";
		cin >> customer.accountBalance;
	} // while
	cin.ignore(1000, '\n');

	// Get and validate date of last payment
	do {
		cout << "Date of Last Payment: ";
		getline(cin, customer.lastPaymentDate);
		if (customer.lastPaymentDate.empty()) {
			cout << "Date cannot be empty. Please enter the date.\n";
		} // if
	} while (customer.lastPaymentDate.empty()); // do-while
} // getCustomerData

// Function to edit an existing customer's data
void editCustomerData(Customer customers[], int size) {
	if (size == 0) {
		cout << "No customers to edit.\n";
		return;
	} // if

	// Display all customer names with associated numbers
	cout << "\nList of Customers:\n";
	for (int i = 0; i < size; ++i) {
		cout << (i + 1) << ". " << customers[i].name << endl;
	} // for

	int index;
	cout << "Enter the customer number to edit (1 to " << size << "): ";
	cin >> index;
	cin.ignore(1000, '\n');

	while (cin.fail() || index < 1 || index > size) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid number! Please enter a number between 1 and " << size << ": ";
		cin >> index;
		cin.ignore(1000, '\n');
	} // while

	cout << "\nEditing Customer #" << index << ": " << customers[index - 1].name << "\n";
	getCustomerData(customers[index - 1]);
} // editCustomerData

// Function to handle customer search loop
void customerSearchLoop(Customer customers[], int size) {
	// Variables
	char choice;

	do {
		string searchName;
		cout << "\nEnter the name of the customer to search: ";
		getline(cin, searchName);
		searchCustomer(customers, size, searchName);

		choice = getYesOrNoInput("Would you like to search for another customer? (Y/N): ");

	} while (choice == 'Y'); // do-while
} // customerSearchLoop

// Search for a customer by name and display their details if found
void searchCustomer(Customer customers[], int size, const string& searchName) {
	// Variables
	bool found = false;

	// Convert searchName to lowercase for case-insensitive comparison
	string searchTerm = searchName;
	for (int i = 0; i < searchTerm.length(); ++i) {
		searchTerm[i] = tolower(searchTerm[i]);
	}

	// Search for customer by partial name match and display details if found
	for (int i = 0; i < size; ++i) {
		// Convert customer's name to lowercase
		string customerName = customers[i].name;
		for (int j = 0; j < customerName.length(); ++j) {
			customerName[j] = tolower(customerName[j]);
		}

		if (customerName.find(searchTerm) != string::npos) {
			displayCustomer(customers[i]);
			found = true;
		} // if
	} // for

	if (!found) {
		cout << "No account found matching: " << searchName << "\n";
	} // if
} // searchCustomer

// Display customer details
void displayCustomer(const Customer& customer) {
	cout << "\nCustomer Details:" << endl;
	cout << "-----------------" << endl;
	cout << "Name: " << customer.name << "\n"
		<< "Address: " << customer.address << "\n"
		<< "City, State, ZIP: " << customer.cityStateZip << "\n"
		<< "Telephone Number: " << customer.telephoneNumber << "\n"
		<< "Account Balance: $" << fixed << setprecision(2) << customer.accountBalance << "\n"
		<< "Last Payment Date: " << customer.lastPaymentDate << "\n";
} // displayCustomer
