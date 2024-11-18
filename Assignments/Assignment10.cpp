/*
 * Darion Badillo
 * 11/18/2024
 * CS 3060
 * Assignment 10
 *
 * Description:
 * C++ program with two different components:
 *
 * 1. Ship, CruiseShip, and CargoShip Classes:
 *    - Ship Class: Base class with string shipName, string yearBuilt
 *    - CruiseShip Class: Derived from Ship with int maxPassengers
 *    - CargoShip Class: Derived from Ship with int cargoCapacity
 *
 * 2. Pure Abstract Base Class Project:
 *    - BasicShape: Abstract Base Class with double area
 *    - Circle: Derived from BasicShape with long centerx, long centery, double radius
 *    - Rectangle: Derived from BasicShape with long width, long length
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <type_traits>

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
            cout << "Cruise Ship Name: " << getShipName() << endl;
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
            cout << "Cargo Ship Name: " << getShipName() << endl;
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
        double area = 0;
    
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
            area = calcArea();
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
            area = calcArea();
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
void shipProgram();
void shapeProgram();
void createCircle(Circle*&);
void createRectangle(Rectangle*&);

template <class T>
void getValid(T& num) {
	// Validate input
	while (!(cin >> num)) { 
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input. Enter a valid number: ";
	} // while
	cin.ignore(1000, '\n'); // Clear the input buffer
} // getValid

// Ship Program Function Templates
template <typename ShipType>
void createShip(ShipType*& ship) {
    // Class Variables
    string name, year;
    int maxPassengers, cargoCapacity;

    cout << "Enter Ship Name: ";
    getline(cin, name);

    cout << "Enter Year Built: ";
    getline(cin, year);

    // Check if the ShipType is a CruiseShip or CargoShip
    // CPPReference: https://en.cppreference.com/w/cpp/types/is_same
    if constexpr (is_same<ShipType, CruiseShip>::value) {
        cout << "Enter Max Passengers: ";
        getValid(maxPassengers);
        ship = new ShipType(name, year, maxPassengers);
    } // if

    else if constexpr (is_same<ShipType, CargoShip>::value) {
        cout << "Enter Cargo Capacity: ";
        getValid(cargoCapacity);
        ship = new ShipType(name, year, cargoCapacity);
    } // else if

    else {
        ship = new ShipType(name, year);
    } // else
} // createShip

template <typename ShipType>
void printShip(Ship*& ship) {
    ship.print();
} // printShip

// Shape Program Function Templates
template <typename ShapeType>
void printShape(BasicShape*& shape) {
	cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
	cout << "Shape Area: " << shape->getArea() << endl;
	cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
} // printShape


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
    } while (choice != '3'); // Continue until the user chooses to exit

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

// Ship Program
// reinterpret_cast<Derived*&>(base) logic: https://en.cppreference.com/w/cpp/language/reinterpret_cast
void shipProgram() {
    Ship** shipArray = nullptr;
    char choice;
    int numShips;

    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    cout << "Welcome to the Ship, CruiseShip, and CargoShip demonstration!" << endl;
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;

    cout << "How many ships would you like to create?" << endl;
    getValid(numShips);
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;

    shipArray = new Ship*[numShips];

    for (int i = 0; i < numShips; i++) {  

        cout << "What type of ship would you like to create?" << endl;
        cout << "Enter '1' for Ship, '2' for CruiseShip, or '3' for CargoShip: ";
        cin >> choice;
        cin.ignore(1000, '\n');  // Clear input buffer
        
        switch (choice) {
        case '1':
            // Create Ship
            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
			cout << "Creating Ship..." << endl;

            createShip(shipArray[i]);

			cout << shipArray[i]->getShipName() << " created!" << endl;
            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
            break;

        case '2':
            // Create CruiseShip
			cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
			cout << "Creating CruiseShip..." << endl;

			createShip(reinterpret_cast<CruiseShip*&>(shipArray[i]));

            cout << shipArray[i]->getShipName() << " created!" << endl;
			cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
            break;

        case '3':
            // Create CargoShip
			cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
			cout << "Creating CargoShip..." << endl;

			createShip(reinterpret_cast<CargoShip*&>(shipArray[i]));

            cout << shipArray[i]->getShipName() << " created!" << endl;
            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;

            break;

        default:
            // Invalid input
            cout << "Invalid input." << endl;
			i--; // Decrement i to re-enter the ship type
		} // switch

    } // for

	// Print Ships 
    cout << "Printing Ships:" << endl;
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    
	// Print Ships
	for (int i = 0; i < numShips; i++) {
		shipArray[i]->print();
		cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
	} // for

    // Delete dynamic memory
    for (int i = 0; i < numShips; i++) {
        delete shipArray[i];
		shipArray[i] = nullptr;
    } // for

	delete[] shipArray;
	shipArray = nullptr;

    cout << "Exiting Ship Program." << endl;

} // shipProgram

// Shape Program
void shapeProgram() {
	Rectangle* rectangle = nullptr;
	Circle* circle = nullptr;
	char choice;
    double area = 0;

	cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
	cout << "Welcome to the Shape demonstration!" << endl;
	cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;

	do {
		cout << "What type of shape would you like to create?" << endl;
		cout << "Enter '1' for Circle, '2' for Rectangle, or '3' to exit: ";

		cin >> choice;
		cin.ignore(1000, '\n');  // Clear input buffer

		switch (choice) {
		case '1':
			// Create Circle
            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
			cout << "Creating Circle..." << endl;   
			createCircle(circle);
			cout << "The area of the circle is: " << circle->getArea() << endl;
			cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;

			break;

		case '2':
			// Create Rectangle
			cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
			cout << "Creating Rectangle..." << endl;
			createRectangle(rectangle);
            cout << "The area of the rectangle is: " << rectangle->getArea() << endl;
            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
			break;

		case '3':
			// Exit the program
			cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
			cout << "Exiting Shape Program." << endl;
			break;

		default:
			// Invalid input
			cout << "Invalid input." << endl;
		}

	} while (choice != '3'); // Continue until the user chooses to exit


} // shapeProgram   

// Create Circle
void createCircle(Circle*& circle) {
	long centerX, centerY;
	double radius;

	cout << "Enter the x-coordinate of the center: ";
	getValid(centerX);

	cout << "Enter the y-coordinate of the center: ";
	getValid(centerY);

	cout << "Enter the radius: ";
	getValid(radius);

	circle = new Circle(centerX, centerY, radius);
} // createCircle

// Create Rectangle
void createRectangle(Rectangle*& rectangle) {
	long width, length;

	cout << "Enter the width: ";
	getValid(width);

	cout << "Enter the length: ";
	getValid(length);

	rectangle = new Rectangle(width, length);
} // createRectangle
