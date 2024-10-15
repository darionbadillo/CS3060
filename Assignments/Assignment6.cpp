/*
	* Darion Badillo
	* 10/15/2024
	* CS 3060
	* Assignment 6
	*
	* Description:
	* C++ program with that runs three different programs
    * 1. Monthly Budget
    *       - User enters expenses for the month and the program displays the total expenses, budget, and over/under amount for each category.
    * 
    * 2. Drink Machine Simulator
    *       - User can select a drink from a menu and insert money to purchase the drink. The program displays the total earnings.
    * 
    * 3. Inventory Bins
    *       - User can add or remove parts from 10 different bins. The program displays the current part count for each bin.
    * 
    * The user can run each program multiple times before exiting the program.
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

// Constants
const int DRINKS_ARRAY_SIZE = 5;
const int MAX_PARTS = 30; 
const int BINS_ARRAY_SIZE = 10;  


// Budget struct that holds const values for monthly spending 
struct Budget {
	const double housing = 500;
    const double utilities = 150;
    const double householdExpenses = 65;
    const double transportation = 50;
    const double food = 250;
    const double medical = 30;
    const double insurance = 100;
    const double entertainment = 150;
    const double clothing = 75;
    const double miscellaneous = 50;
}; 

// Struct to hold all the user's spending expenses for the month
struct Expenses {
    double housing;
    double utilities;
    double householdExpenses;
    double transportation;
    double food;
    double medical;
    double insurance;
    double entertainment;
    double clothing;
    double miscellaneous;
};

// Drink struct
struct Drink {
    string name;
    double cost;
    int numDrinks;
};

// Bin struct
struct Bin {
    string partDescription;
    int partsInBin;
};

// Function Prototypes
void displayMenu();
void monthlyBudget();
void getExpenses(Expenses& expense);
void displayExpenses(Expenses expense, Budget budget);
void drinkMachineSimulator();
void drinkMenu(Drink drinks[], int size);
void processPurchase(Drink& selectedDrink, double& totalEarnings);
void inventoryBinSimulator();
void displayBins(Bin bins[], int size);
void addParts(Bin& bin);
void removeParts(Bin& bin);
char getYesOrNo(const string& prompt);
double getMoney(double drinkCost);


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
			monthlyBudget();
			break;
		case '2':
			drinkMachineSimulator();
			break;
        case '3':
            inventoryBinSimulator();
        break;
		case '4':
			cout << "Exiting program." << endl;
			break;
		default:
			cout << "Invalid input." << endl;
		} // switch

	} while (control != '4'); // do-while

	return 0;
} // main

// Function to display the main menu options
void displayMenu() {
	cout << "\nSelect a program to run (1-3) or enter 4 to exit: " << endl;
	cout << "1. Monthly Budget\n2. Drink Machine Simulator\n3. Inventory Bins\n4. Exit" << endl;
} // displayMenu

// Gets a 'Y' or 'N' input from the user with validation
char getYesOrNo(const string& prompt) {
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
} // getYesOrNo

// monthlyBudget controls the flow of the monthly budget program. It prompts the user to enter expenses for the month and displays the total expenses, 
// budget, and over/under amount for each category. The user can enter multiple sets of expenses and view the results before exiting the program.
void monthlyBudget(){
    // Variables and Stuctures
    Expenses expense;
    Budget budget;

    do {
        // Get and display expenses
        getExpenses(expense);
        displayExpenses(expense, budget);

    } while (getYesOrNo("Would you like to enter another set of expenses? (Y/N): ") == 'Y'); 
} // monthlyBudget

void getExpenses(Expenses& expense) {
    // Get and validate housing expense
    cout << "Housing: ";
    cin >> expense.housing;
    while (cin.fail() || expense.housing < 0) {
        cin.clear();  // clear the error flag
        cin.ignore(1000, '\n');  // discard invalid input
        cout << "Invalid input! Enter a non-negative value for Housing: ";
        cin >> expense.housing;
    } // while

    // Get and validate utilities expense
    cout << "Utilities: ";
    cin >> expense.utilities;
    while (cin.fail() || expense.utilities < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Enter a non-negative value for Utilities: ";
        cin >> expense.utilities;
    } // while

    // Get and validate household expenses
    cout << "Household Expenses: ";
    cin >> expense.householdExpenses;
    while (cin.fail() || expense.householdExpenses < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Enter a non-negative value for Household Expenses: ";
        cin >> expense.householdExpenses;
    } // while

    // Get and validate transportation expense
    cout << "Transportation: ";
    cin >> expense.transportation;
    while (cin.fail() || expense.transportation < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Enter a non-negative value for Transportation: ";
        cin >> expense.transportation;
    } // while

    // Get and validate food expense
    cout << "Food: ";
    cin >> expense.food;
    while (cin.fail() || expense.food < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Enter a non-negative value for Food: ";
        cin >> expense.food;
    } // while

    // Get and validate medical expense
    cout << "Medical: ";
    cin >> expense.medical;
    while (cin.fail() || expense.medical < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Enter a non-negative value for Medical: ";
        cin >> expense.medical;
    } // while

    // Get and validate insurance expense
    cout << "Insurance: ";
    cin >> expense.insurance;
    while (cin.fail() || expense.insurance < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Enter a non-negative value for Insurance: ";
        cin >> expense.insurance;
    } // while

    // Get and validate entertainment expense
    cout << "Entertainment: ";
    cin >> expense.entertainment;
    while (cin.fail() || expense.entertainment < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Enter a non-negative value for Entertainment: ";
        cin >> expense.entertainment;
    } // while

    // Get and validate clothing expense
    cout << "Clothing: ";
    cin >> expense.clothing;
    while (cin.fail() || expense.clothing < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Enter a non-negative value for Clothing: ";
        cin >> expense.clothing;
    } // while

    // Get and validate miscellaneous expense
    cout << "Miscellaneous: ";
    cin >> expense.miscellaneous;
    while (cin.fail() || expense.miscellaneous < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Enter a non-negative value for Miscellaneous: ";
        cin >> expense.miscellaneous;
    } // while
} // getExpenses

// Displays the user's expenses against the budget and calculates the over/under while displaying the results
void displayExpenses(Expenses expense, Budget budget){
    cout << fixed << setprecision(2);
    cout << "\nMonthly Expenses:\t\tSpent\t\tOver(-)/Under(+)" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "Housing:\t\t\t$" << expense.housing << "\t\t$" << (budget.housing - expense.housing) << endl;
    cout << "Utilities:\t\t\t$" << expense.utilities << "\t\t$" << (budget.utilities - expense.utilities) << endl;
    cout << "Household Expenses:\t\t$" << expense.householdExpenses << "\t\t$" << (budget.householdExpenses - expense.householdExpenses) << endl;
    cout << "Transportation:\t\t\t$" << expense.transportation << "\t\t$" << (budget.transportation - expense.transportation) << endl;
    cout << "Food:\t\t\t\t$" << expense.food << "\t\t$" << (budget.food - expense.food) << endl;
    cout << "Medical:\t\t\t$" << expense.medical << "\t\t$" << (budget.medical - expense.medical) << endl;
    cout << "Insurance:\t\t\t$" << expense.insurance << "\t\t$" << (budget.insurance - expense.insurance) << endl;
    cout << "Entertainment:\t\t\t$" << expense.entertainment << "\t\t$" << (budget.entertainment - expense.entertainment) << endl;
    cout << "Clothing:\t\t\t$" << expense.clothing << "\t\t$" << (budget.clothing - expense.clothing) << endl;
    cout << "Miscellaneous:\t\t\t$" << expense.miscellaneous << "\t\t$" << (budget.miscellaneous - expense.miscellaneous) << endl;
    cout << "Total Expenses:\t\t\t$" << (expense.housing + expense.utilities + expense.householdExpenses + expense.transportation + expense.food + expense.medical + expense.insurance + expense.entertainment 
        + expense.clothing + expense.miscellaneous) << endl;
    cout << "Total Budget:\t\t\t$" << (budget.housing + budget.utilities + budget.householdExpenses + budget.transportation + budget.food + budget.medical + budget.insurance + budget.entertainment 
        + budget.clothing + budget.miscellaneous) << endl;    
    cout << "Total Over/Under:\t\t$" << ((budget.housing + budget.utilities + budget.householdExpenses + budget.transportation + budget.food + budget.medical + budget.insurance 
        + budget.entertainment + budget.clothing + budget.miscellaneous) - (expense.housing + expense.utilities + expense.householdExpenses + expense.transportation + expense.food + expense.medical + expense.insurance 
        + expense.entertainment + expense.clothing + expense.miscellaneous)) << endl;
    cout << "----------------------------------------------------------------" << endl;
} // displayExpenses

void drinkMachineSimulator() {
    // Variables
    double totalEarnings = 0.0;  
    int choice;  

    // Array of Drink structures with initial data
    Drink drinks[DRINKS_ARRAY_SIZE] = {
        {"Cola", 0.75, 20},
        {"Root Beer", 0.75, 20},
        {"Lemon-Lime", 0.75, 20},
        {"Grape Soda", 0.80, 20},
        {"Cream Soda", 0.80, 20}
    };

    // Drink selection loop
    do {
        // Display drink menu for user to make selection
        drinkMenu(drinks, DRINKS_ARRAY_SIZE);  

        cout << "\nEnter a drink number (1-5) or 0 to exit: ";
        cin >> choice;

        // Validate input: choice must be between 0 and 5
        while (cin.fail() || choice < 0 || choice > 5) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number between 0 and 5: ";
            cin >> choice;
        } // while

        // Process drink selection if the user did not choose to exit
        if (choice != 0) {
            processPurchase(drinks[choice - 1], totalEarnings);  
        } // if

    } while (choice != 0);  

    // Display total earnings
    cout << "---------------------------------------\n";
    cout << "\nTotal earnings: $" << fixed << setprecision(2) << totalEarnings << endl;
    cout << "---------------------------------------\n";

} // drinkMachineSimulator

// Drink menu display
void drinkMenu(Drink drinks[], int size) {
    cout << "\nDrink Menu\n";
    cout << "---------------------------------------\n";
    for (int i = 0; i < size; i++) {
        // Display drink name, cost, and availability
        cout << i + 1 << ". " << drinks[i].name << " - $" << fixed << setprecision(2) << drinks[i].cost;
        if (drinks[i].numDrinks == 0) {
            cout << " (SOLD OUT)";
        } // if
        cout << endl;
    } // for
    // Exit option
    cout << "0. Exit\n";
    cout << "---------------------------------------\n";

} // drinkMenu

// Handles drink selection and purchase process
void processPurchase(Drink& selectedDrink, double& totalEarnings) {
    // Variables
    double moneyInserted, change;

    // If drink is sold out, exit function
    if (selectedDrink.numDrinks == 0) {
        cout << "---------------------------------------\n";
        cout << "Sorry, " << selectedDrink.name << " is sold out.\n";
        cout << "---------------------------------------\n";
        return;
    } // if

    // Get money input from the user
    moneyInserted = getMoney(selectedDrink.cost);

    // Process the transaction
    if (moneyInserted >= selectedDrink.cost) {
        change = moneyInserted - selectedDrink.cost;
        cout << "---------------------------------------\n";
        cout << "Dispensing " << selectedDrink.name << ". Change: $"
             << fixed << setprecision(2) << change << endl;
        cout << "---------------------------------------\n";

        // Update the number of drinks and total earnings
        selectedDrink.numDrinks--;
        totalEarnings += selectedDrink.cost;
    } // if
    
    else {
        cout << "Insufficient funds. Returning $" << fixed << setprecision(2)
             << moneyInserted << endl;
    } // else
} // processPurchase

// Function to get and validate money input from the user
double getMoney(double drinkCost) {

    // Variables
    double money;

    // Get money input
    cout << "Please insert money ($0.00 to $1.00): ";
    cin >> money;

    // Validate money input
    while (cin.fail() || money < 0 || money > 1) {
        cin.clear();  // Clear the error flag
        cin.ignore(1000, '\n');  // Discard invalid input
        cout << "Invalid input! Please insert a valid amount ($0.00 to $1.00): ";
        cin >> money;
    } // while

    return money;
} // getMoney

// Inventory Bin Program
void inventoryBinSimulator() {
    // Initialized array of 10 part bins
    Bin bins[BINS_ARRAY_SIZE] = {
        {"Valve", 10}, {"Bearing", 5}, {"Bushing", 15}, {"Coupling", 21}, {"Flange", 7}, 
        {"Gear", 5}, {"Gear Housing", 5}, {"Vacuum Gripper", 25}, {"Cable", 18}, {"Rod", 12}
    };
 
    // Variables
    char action;
    int choice, binIndex;

    // Main loop to keep the program running
    do {
        displayBins(bins, BINS_ARRAY_SIZE);  // Display bin contents

        cout << "\nEnter a bin number (1-10) to modify, or 0 to exit: ";
        cin >> choice;

        // Validate input
        while (cin.fail() || choice < 0 || choice > 10) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number between 0 and 10: ";
            cin >> choice;
        } // while

        // Process bin selection if user didn't choose to exit
        if (choice != 0) {
            binIndex = choice - 1;
            cout << "Do you want to (A)dd or (R)emove parts? ";
            cin >> action;
            action = toupper(action);

            // Add or remove parts
            if (action == 'A') {
                addParts(bins[binIndex]);
            } // inner if

            else if (action == 'R') {
                removeParts(bins[binIndex]);
            }  // else if
            
            else {
                cout << "Invalid action. Please enter A to add or R to remove parts.\n";
            } // else
        } // outer if

    } while (choice != 0);
} // inventoryBinSimulator

// Displays all bins and their part counts
void displayBins(Bin bins[], int size) {
    cout << "\nInventory Bins\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < size; i++) {

        if (i >= 9)
        {
            cout << i + 1 <<  ". " << setw(14) << left << bins[i].partDescription 
             << " : " << bins[i].partsInBin << " parts\n";
        } // if

        else 
        {
            cout << i + 1 <<  ". " << setw(15) << left << bins[i].partDescription 
             << " : " << bins[i].partsInBin << " parts\n";
        } // else
    } // for
    cout << "----------------------------------------\n";
} // displayBins

// Adds parts to a selected bin
void addParts(Bin& bin) {
    // Variables
    int partsToAdd;

    cout << "How many parts would you like to add to the " << bin.partDescription << " bin? ";
    cin >> partsToAdd;

    // Validate input
    while (cin.fail() || partsToAdd < 0 || bin.partsInBin + partsToAdd > MAX_PARTS) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Please enter a number between 0 and " << MAX_PARTS - bin.partsInBin << ": ";
        cin >> partsToAdd;
    } // while

    // Add the parts to the bin
    bin.partsInBin += partsToAdd;  
    cout << "Successfully added " << partsToAdd << " parts to the " << bin.partDescription << " bin.\n";
} // addParts

// Removes parts from a bin
void removeParts(Bin& bin) {
    int partsToRemove;
    cout << "How many parts would you like to remove from the " << bin.partDescription << " bin? ";
    cin >> partsToRemove;

    // Validate input
    while (cin.fail() || partsToRemove < 0 || partsToRemove > bin.partsInBin) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Please enter a number between 0 and " << bin.partsInBin << ": ";
        cin >> partsToRemove;
    } // while

    bin.partsInBin -= partsToRemove;  // Remove the parts from the bin
    cout << "Successfully removed " << partsToRemove << " parts from the " << bin.partDescription << " bin.\n";
} // removeParts
