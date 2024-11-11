/*
 * Darion Badillo
 * 10/29/2024
 * CS 3060
 * Assignment 8
 *
 * Description:
 * C++ program with three different components:
 *
 * 1. Car Class:
 *    - Creates a Car object with user-defined yearModel and make.
 *    - Demonstrates accelerating and braking functions.
 *
 * 2. Personal Information Class:
 *    - Holds and displays user-defined personal info data for three individuals.
 *
 * 3. Number Array Class:
 *    - Manages a dynamic array of floating-point numbers with user-defined size and values.
 *    - Provides functions to find highest, lowest, and average values.
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Constants
const int MENU_WIDTH = 40;

// Car Class
class Car {
    // Private Data Members
    private:
        int yearModel;
        string make;
        int speed;

    // Public Functions
    public:
        // Constructor
        Car(int yModel, string carMake) : yearModel(yModel), make(carMake), speed(0) {}

        // Accessors
        int getYearModel() const { 
            return yearModel; 
        } // getYearModel

        string getMake() const { 
            return make; 
        } // getMake

        int getSpeed() const { 
            return speed; 
        } // getSpeed

        // Functions to modify speed
        void accelerate() { 
            speed += 5; 
        } // accelerate
        void brake() { 
            if (speed >= 5) speed -= 5; 
        } // brake

        // Display current speed
        void displaySpeed() const { 
            cout << "Current speed: " << speed << " mph" << endl; 
        } // displaySpeed 
}; // Car Class

// Personal Information Class
class PersonalInfo {

    // Private Data Members
    private:
        string name;
        string address;
        int age;
        string phone;

    // Public Functions
    public:
        // Constructor
        PersonalInfo(string n, string addr, int a, string ph) : name(n), address(addr), age(a), phone(ph) {}

        // Display information
        void displayInfo() const {
            cout << "Name: " << name << ", Address: " << address << ", Age: " << age << ", Phone: " << phone << endl;
        } // displayInfo
}; // PersonalInfo Class

// Number Array Class
class NumberArray {

    // Private Data Members
    private:
        float* array;
        int size;

    // Public Functions
    public:
        // Constructor
        NumberArray(int s) : size(s) { array = new float[size](); }

        // Destructor
        ~NumberArray() { 
            delete[] array;
        } // Destructor

        // Function to set value at index
        void setValue(int index, float value) { 
            if (index >= 0 && index < size) array[index] = value; 
        } // setValue

        // Retrieve highest value
        float getHighest() const {
            float highest = array[0];
            for (int i = 1; i < size; i++) { 
                if (array[i] > highest) highest = array[i]; 
            } // for
            return highest;
        } // getHighest

        // Retrieve lowest value
        float getLowest() const {
            float lowest = array[0];
            for (int i = 1; i < size; i++) { 
                if (array[i] < lowest) lowest = array[i]; 
            } // for
            return lowest;
        } // getLowest

        // Calculate average value
        float getAverage() const {
            float sum = 0;
            for (int i = 0; i < size; i++) { 
                sum += array[i]; 
            } // for

            return sum / size;
        } // getAverage

        // Display array values
        void displayArray() const {
            cout << "Array Values: " << endl;
            for (int i = 0; i < size; i++) { 
                cout << i + 1 << ". " << array[i] << endl; 
            } // for
        } // displayArray

        // Change value at index
        void changeValue(int index, float value) { 
            if (index >= 0 && index < size) {
                array[index] = value;
            } // if
            
            // Display error message if index is invalid
            else {
                cout << "Invalid index." << endl;
            } // else
        } // changeValue

        void retrieveValue(int index) const { 
            if (index >= 0 && index < size) cout << "Value at index " << index + 1 << ": " << array[index] << endl; 
        } // retrieveValue
}; // NumberArray Class

// Function Prototypes
void displayMenu();
void getValidInt(int& num);
void getValidFloat(float& num);

void demonstrateCar();
Car initializeCar();
void accelerateCar(Car& car);
void brakeCar(Car& car);

void demonstratePersonalInfo();
PersonalInfo initializePersonalInfo();

void demonstrateNumberArray();
NumberArray initializeNumberArray();
void displayNumberArrayResults(const NumberArray& numArray);
void changeIndexValue(NumberArray& numArray);
void retrieveValue(NumberArray& numArray);

int main() {
    char choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(1000, '\n');  // Clear input buffer

        switch (choice) {
        case '1':
            demonstrateCar();
            break;
        case '2':
            demonstratePersonalInfo();
            break;
        case '3':
            demonstrateNumberArray();
            break;
        case '4':
            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
            cout << "Exiting program. Have a nice day!" << endl;
            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
            break;
        default:
            cout << "Invalid input." << endl;
        }
    } while (choice != '4'); // Continue until the user chooses to exit

    return 0;
} // main

// Displays the main menu
void displayMenu() {
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    cout << "Select a program to run (1-3) or enter 4 to exit:\n";
    cout << "1. Car Class Demonstration\n";
    cout << "2. Personal Information Class Demonstration\n";
    cout << "3. Number Array Class Demonstration\n";
    cout << "4. Exit\n";
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
} // displayMenu

// Car Class Demonstration
void demonstrateCar() {
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    cout << "Car Class Demonstration" << endl;

    // Create a Car object with user input and demonstrate acceleration and braking
    Car myCar = initializeCar();
    accelerateCar(myCar);
    brakeCar(myCar);
} // demonstrateCar

// Initializes a Car object with user input
Car initializeCar() {
    int yearModel;
    string make;

    cout << "Enter the car's year model: ";
    getValidInt(yearModel);
    cin.ignore(); // Clear newline character for string input

    cout << "Enter the car's make: ";
    getline(cin, make);

    return Car(yearModel, make);
} // initializeCar

void accelerateCar(Car& car) {
    cout << "Accelerating..." << endl;
    for (int i = 0; i < 5; i++) {
        car.accelerate();
        car.displaySpeed();
    } // for
} // accelerateCar

void brakeCar(Car& car) {
    cout << "\nBraking..." << endl;
    for (int i = 0; i < 5; i++) {
        car.brake();
        car.displaySpeed();
    } // for
} // brakeCar

// PersonalInfo Class Demonstration
void demonstratePersonalInfo() {
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    cout << "Personal Information Class Demonstration" << endl;

    // Create and display three instances of PersonalInfo with user input
    cout << "Enter personal information for three individuals:" << endl;
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    cout << "Person 1:" << endl;
    PersonalInfo person1 = initializePersonalInfo();
    cout << "Person 2:" << endl;
    PersonalInfo person2 = initializePersonalInfo();
    cout << "Person 3:" << endl;
    PersonalInfo person3 = initializePersonalInfo();

    cout << "Personal Information:" << endl;
    person1.displayInfo();
    person2.displayInfo();
    person3.displayInfo();
} // demonstratePersonalInfo

// Initializes a PersonalInfo object with user input
PersonalInfo initializePersonalInfo() {
    string name, address, phone;
    int age;

    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter address: ";
    getline(cin, address);
    cout << "Enter age: ";
    getValidInt(age);
    cin.ignore();  // Clear newline character
    cout << "Enter phone number: ";
    getline(cin, phone);

    return PersonalInfo(name, address, age, phone);
} // initializePersonalInfo

// NumberArray Class Demonstration
void demonstrateNumberArray() {
    char choice;
    int index;
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    cout << "Number Array Class Demonstration" << endl;

    NumberArray numArray = initializeNumberArray();
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    numArray.displayArray();

    displayNumberArrayResults(numArray);


    // Menu for changing values in the array
    do {
        cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
        cout << "Number Array Menu: " << endl;
        cout << "Enter a choice (1-3): " << endl;
        cout << "1. Change a value in the array" << endl;
        cout << "2. Retrieve a specific element" << endl;
        cout << "3. Exit Number Array program" << endl;
        cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
        cin >> choice;
        
        switch (choice) {
            case '1':
                changeIndexValue(numArray);
                numArray.displayArray();
                displayNumberArrayResults(numArray);
                break;
            case '2':
                retrieveValue(numArray);
                break;
            case '3': 
                cout << "Exiting Number Array program." << endl;
                cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
                break;
            default:
                cout << "Invalid input." << endl;
        } // switch

    } while (choice != '3'); // Continue until the user chooses to exit

} // demonstrateNumberArray

// Initializes a NumberArray object with user input
NumberArray initializeNumberArray() {

    // Variables
    int arraySize;
    cout << "Enter the size of the array: ";
    cin >> arraySize;

    NumberArray numArray(arraySize);

    // Set values for each element in the array
    for (int i = 0; i < arraySize; i++) {
        float value;
        cout << "Enter value for element " << (i + 1) << ": ";
        cin >> value;
        numArray.setValue(i, value);
    } // for

    return numArray;
} // initializeNumberArray

// Controls changing a value in the NumberArray object
void changeIndexValue(NumberArray& numArray) {
    // variables
    int index;
    float value;

    // Get user input
    cout << "Enter the index of the value to change: ";
    getValidInt(index);
    cout << "Enter the new value: ";
    getValidFloat(value);

    // Change value at index
    numArray.changeValue(index - 1, value);
} // changeValue

// Controls retrieving a value from the NumberArray object
void retrieveValue(NumberArray& numArray) {
    // Variables
    int index;

    // Get user input
    cout << "Enter the index of the value to retrieve: ";
    getValidInt(index);
    numArray.retrieveValue(index - 1);
} // retrieveValue

// Displays the highest, lowest, and average values of a NumberArray object
void displayNumberArrayResults(const NumberArray& numArray) {
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;

    cout << fixed << setprecision(2);
    cout << "Highest Value: " << numArray.getHighest() << endl;
    cout << "Lowest Value: " << numArray.getLowest() << endl;
    cout << "Average Value: " << numArray.getAverage() << endl;

} // displayNumberArrayResults

// Ensures user input is a non-negative integer
void getValidInt(int& num) {
    // Loop until a valid integer is entered
    cin >> num;

    while (cin.fail() || num < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Please enter a valid number: ";
        cin >> num;
    } // while
} // getValidInt

// Ensures user input is a non-negative float
void getValidFloat(float& num) {
    // Loop until a valid integer is entered
    cin >> num;

    while (cin.fail() || num < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Please enter a valid number: ";
        cin >> num;
    } // while
} // getValidInt
