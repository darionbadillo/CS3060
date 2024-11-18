/*
 * Darion Badillo
 * 11/11/2024
 * CS 3060
 * Assignment 8
 *
 * Description:
 * C++ program with three different components:
 *
 * 1. Ship, CruiseShip, and CargoShip Classes:
 *    - 
 *    - 
 *
 * 2. Pure Abstract Base Class Project:
 *    - 

*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Constants
const int MENU_WIDTH = 40;

/*
* Ship Class:
*   Variables: string shipName, string yearBuilt
*   Constructors: Ship(string name, string year)
*   Accessors: string getShipName(), string getYearBuilt()
*   Mutators: void setShipName(string name), void setYearBuilt(string year)
*/
class Ship {
    //Private Data Members
    private:
        string shipName;
        string yearBuilt;

    //Public Functions
    public:
        // Constructors
        Ship() : shipName(""), yearBuilt("") {}
        Ship(string name, string year) : shipName(name), yearBuilt(year) {}

        // Accessors
        string getShipName() const {
            return shipName;
        } // getShipName

        string getYearBuilt() const {
            return yearBuilt;
        } // getYearBuilt

        // Mutators
        void setShipName(string name) {
            shipName = name;
        } // setShipName

        void setYearBuilt(string year) {
            yearBuilt = year;
        } // setYearBuilt
        
        // Virtual Function
        virtual void print() const {
            cout << "Ship Name: " << shipName << endl;
            cout << "Year Built: " << yearBuilt << endl;
        } // print
}; // Ship Class

/*
* CruiseShip Class:
*   Variables: int maxPassengers
*   Constructors: CruiseShip(string name, string year, int maxPass)
*   Accessors: int getMaxPassengers()
*   Mutators: void setMaxPassengers(int maxPass)
*/
class CruiseShip : public Ship {
    //Private Data Members
    private:
        int maxPassengers;

    //Public Functions
    public:
        // Constructor
        CruiseShip(string name, string year, int maxPass) : Ship(name, year), maxPassengers(maxPass) {}

        // Accessors
        int getMaxPassengers() const {
            return maxPassengers;
        } // getMaxPassengers

        // Mutators
        void setMaxPassengers(int maxPass) {
            maxPassengers = maxPass;
        } // setMaxPassengers

        // Override Print Function
        void print() const {
            cout << "Ship Name: " << getShipName() << endl;
            cout << "Max Passengers: " << maxPassengers << endl;
        } // print

}; // CruiseShip Class

/*
* CargoShip Class:
*   Variables: int cargoCapacity
*   Constructors: CargoShip(string name, string year, int cargoCap)
*   Accessors: int getCargoCapacity()
*   Mutators: void setCargoCapacity(int cargoCap)
*/
class CargoShip : public Ship {
    //Private Data Members
    private:
        int cargoCapacity;

    //Public Functions
    public:
        // Constructor
        CargoShip(string name, string year, int cargoCap) : Ship(name, year), cargoCapacity(cargoCap) {}

        // Accessors
        int getCargoCapacity() const {
            return cargoCapacity;
        } // getCargoCapacity

        // Mutators
        void setCargoCapacity(int cargoCap) {
            cargoCapacity = cargoCap;
        } // setCargoCapacity

        // Override Print Function
        void print() const {
            cout << "Ship Name: " << getShipName() << endl;
            cout << "Cargo Capacity: " << cargoCapacity << endl;
        } // print
}; // CargoShip Class

/*
* BasicShape: Abstract Base Class
*   Variables: double area
*   Pure Virtual Functions: double calcArea()
*/
class BasicShape {
    //Private Data Members
    protected: 
        double area;
    
    //Public Virtual Functions
    public:
        // Pure Virtual Function
        virtual double calcArea() = 0;

        // Accessors
        double getArea() const {
            return area;
        } // getArea
}; // BasicShape Abstract Class

/*
* Circle: Derived from BasicShape
*   Variables: long centerx, long centery, double radius
*   Constructors: Circle(long x, long y, double r)
*   Accessors: long getCenterX(), long getCenterY(), 
*   Functions: double calcArea()
*/
class Circle : public BasicShape {
    //Private Data Members
    private:
        long centerx, centery;
        double radius;

    //Public Functions
    public:
        // Constructor
        Circle(long x, long y, double r) : centerx(x), centery(y), radius(r) {
            calcArea();
        } // Constructor

        // Accessors
        long getCenterX() const {
            return centerx;
        } // getCenterX

        long getCenterY() const {
            return centery;
        } // getCenterY

        // Functions
        double calcArea() {
            return 3.14159 * radius * radius;
         } // calcArea
}; // Circle Class

/*
* Rectangle: Derived from BasicShape
*   Variables: long width, long length
*   Constructors: Rectangle(long w, long l)
*   Accessors: long getWidth(), long getLength()
*   Functions: double calcArea()
*/
class Rectangle : public BasicShape {
    //Private Data Members
    private:
        long width, length;

    //Public Functions
    public:
        // Constructor
        Rectangle(long w, long l) : width(w), length(l) {
            calcArea();
        } // Constructor

        // Accessors
        long getWidth() const {
            return width;
        } // getWidth

        long getLength() const {
            return length;
        } // getLength

        // Functions
        double calcArea() {
            return width * length;
        } // calcArea
}; // Rectangle Class

/*
*       Function Prototypes
*/
// Functions
void displayMenu();
void getValidInt(int& num);
void getValiddouble(double& num);
char getYesOrNo(const string& prompt);

// Ship Program Functions
void shipProgram();

// Ship Program Function Templates
template <typename ShipType>
void createShip(ShipType*& ship) {
    string name, year;
    int maxPassengers, cargoCapacity;

    cout << "Enter Ship Name: ";
    getline(cin, name);

    cout << "Enter Year Built: ";
    getline(cin, year);


    if (constexpr (is_same<ShipType, CruiseShip>::value)) {
        cout << "Enter Max Passengers: ";
        getValidInt(maxPassengers);
        ship = new ShipType(name, year, maxPassengers);
    } // if

    else if (constexpr (is_same<ShipType, CargoShip>::value)) {
        cout << "Enter Cargo Capacity: ";
        getValidInt(cargoCapacity);
        ship = new ShipType(name, year, cargoCapacity);
    } // else if

    else {
        ship = new ShipType(name, year);
    } // else
} // createShip

template <typename ShipType>
void printShip(Ship& ship) {
    ship.print();
} // printShip

void shapeProgram();
void createCircle(Circle*&);
void createRectangle(Rectangle*&);
void printShape(BasicShape*);


// Main 
int main() {
    char choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(1000, '\n');  // Clear input buffer

        switch (choice) {
        case '1':
            // Ship, CruiseShip, and CargoShip Classes
            shipProgram();
            break;

        case '2':
            // Pure Abstract Base Class Project
            shapeProgram();
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
    } while (choice != '4'); // Continue until the user chooses to exit

    // Exit the program
    return 0;
} // main

// Displays the main menu
void displayMenu() {
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    cout << "Select a program to run (1-2) or enter 3 to exit:\n";
    cout << "1. Ship, CruiseShip, and CargoShip\n";
    cout << "2. Pure Abstract Base Class Project\n";
    cout << "3. Exit\n";
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
} // displayMenu


// Function to get a valid integer input
void getValidInt(int& num) {
    while (!(cin >> num)) { // Ensure the input is an integer
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter an integer: ";
    }
    cin.ignore(1000, '\n'); // Clear the input buffer
} // getValidInt

// Function to get a valid double input
void getValiddouble(double& num) {
    while (!(cin >> num)) { // Ensure the input is a double
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a valid number: ";
    }
    cin.ignore(1000, '\n'); // Clear the input buffer
} // getValiddouble

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

// Ship Program
void shipProgram() {
    Ship* ship = nullptr;
    CruiseShip* cruiseShip = nullptr;
    CargoShip* cargoShip = nullptr;
    Ship* shipArray;
    char choice;
    int numShips;

    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    cout << "Welcome to the Ship, CruiseShip, and CargoShip demonstration!" << endl;
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;

    cout << "How many ships would you like to create?" << endl;
    getValidInt(numShips);
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;

    shipArray = new Ship[numShips];

    for (int i = 0; i < numShips; i++) {  

        cout << "What type of ship would you like to create?" << endl;
        cout << "Enter '1' for Ship, '2' for CruiseShip, or '3' for CargoShip,: ";
        cin >> choice;
        cin.ignore(1000, '\n');  // Clear input buffer

        switch (choice) {
        case '1':
            // Create Ship
            createShip(ship);
            shipArray[i] = *ship;
            break;

        case '2':
            // Create CruiseShip
            createCruiseShip(cruiseShip);
            shipArray[i] = *cruiseShip;
            cruiseShip->print();
            break;

        case '3':
            // Create CargoShip
            createCargoShip(cargoShip);
            shipArray[i] = *cargoShip;
            break;

        default:
            // Invalid input
            cout << "Invalid input." << endl;
        }

    } // for

    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    cout << "Printing Ships:" << endl;
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    for (int i = 0; i < numShips; i++) {
        shipArray[i].print();
    } // for

    // Delete dynamic memory
    for (int i = 0; i < numShips; i++) {
        delete &shipArray[i];
    } // for

    delete[] shipArray;

    ship = nullptr;
    cruiseShip = nullptr;
    cargoShip = nullptr;

    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    cout << "Exiting Ship Program." << endl;

} // shipProgram

void createShip(Ship*& ship) {
    string name, year;

    cout << "Enter Ship Name: ";
    getline(cin, name);

    cout << "Enter Year Built: ";
    getline(cin, year);

    ship = new Ship(name, year);
} // createShip

void createCruiseShip(CruiseShip*& cruiseShip) {
    string name, year;
    int maxPassengers;

    cout << "Enter Cruise Ship Name: ";
    getline(cin, name);

    cout << "Enter Year Built: ";
    getline(cin, year);

    cout << "Enter Max Passengers: ";
    getValidInt(maxPassengers);

    cruiseShip = new CruiseShip(name, year, maxPassengers);
} // createCruiseShip

void createCargoShip(CargoShip*& cargoShip) {
    string name, year;
    int cargoCapacity;

    cout << "Enter Cargo Ship Name: ";
    getline(cin, name);

    cout << "Enter Year Built: ";
    getline(cin, year);

    cout << "Enter Cargo Capacity: ";
    getValidInt(cargoCapacity);

    cargoShip = new CargoShip(name, year, cargoCapacity);
} // createCargoShip



