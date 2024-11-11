/*
 * Darion Badillo
 * 11/11/2024
 * CS 3060
 * Assignment 8
 *
 * Description:
 * C++ program with three different components:
 *
 * 1. Employee and ProductionWorker Classes:
 *    - 
 *    - 
 *
 * 2. PersonData and CustomerData Classes:
 *    - 
 *
 * 3. Course Grades:
 *    - 
 *    - 
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Constants
const int MENU_WIDTH = 40;

/*
* Employee:
*   This class holds the employee's name, number, and hire date. 
*   It has a constructor that accepts the following values as arguments:
*   - Employee's name
*   - Employee's number
*   - Hire date
*   The class also has the following member functions:
*   - getName: Returns the employee's name
*   - getNumber: Returns the employee's number
*   - getHireDate: Returns the employee's hire date
*   - setName: Sets the employee's name
*   - setNumber: Sets the employee's number
*   - setHireDate: Sets the employee's hire date
*/
class Employee {
    //Private Data Members
    private:
        string name;
        int number;
        string hireDate;

    //Public Functions
    public:
        // Constructor
        Employee(string nombre, int num, string dateHired) : name(nombre), number(num), hireDate(dateHired) {}

        // Accessors
        string getName() const {
            return name;
        } // getName
        
        int getNumber() const {
            return number;
        } // getNumber

        string getHireDate() const {
            return hireDate;
        } // getHireDate

        // Mutators
        void setName(string nombre) {
            name = nombre;
        } // setName

        void setNumber(int num) {
            number = num;
        } // setNumber

        void setHireDate(string dateHired) {
            hireDate = dateHired;
        } // setHireDate
}; // Employee Class

/*
* ProductionWorker:
*   This class is derived from the Employee class. It has an additional private member variable:
*   - shift (an integer)
*   - hourlyPayRate (a double)
*   The class has the following member functions:
*   - Constructor: Accepts the following values as arguments:
*     - Employee's name
*     - Employee's number
*     - Hire date
*     - Shift (an integer)
*     - Hourly pay rate (a double)
*   - Accessors and Mutators for the shift and hourlyPayRate member variables
*/
class ProductionWorker : public Employee {
    // Private Data Members
    private:
        int shift;
        double hourlyRate;

    // Public Functions
    public:
        // Constructor
        ProductionWorker(string nombre, int num, string dateHired, int shft, double rate) : Employee(nombre, num, dateHired), shift(shft), hourlyRate(rate) {}

        // Accessors
        int getShift() const {
            return shift;
        } // getShift

        double getHourlyRate() const {
            return hourlyRate;
        } // getHourlyRate

        // Mutators
        void setShift(int shft) {
            shift = shft;
        } // setShift

        void setHourlyRate(double rate) {
            hourlyRate = rate;
        } // setHourlyRate
}; // ProductionWorker Class

/*
* PersonData:
*   This class holds the following personal data for a person:
*   - Last name
*   - First name
*   - Address
*   - City
*   - State
*   - ZIP code
*   - Phone number
*   The class has the following member functions:
*   - Constructor: Accepts the following values as arguments:
*     - Last name
*     - First name
*     - Address
*     - City
*     - State
*     - ZIP code
*     - Phone number
*   - Accessors and Mutators for each member variable
*/
class PersonData {
    // Private Data Members
    private:
        string lastName;
        string firstName;
        string address;
        string city;
        string state;
        string zip;
        string phone;

    // Public Functions
    public:
        // Constructor
        PersonData(string last, string first, string addr, string cty, string st, string zp, string ph) : lastName(last), firstName(first), address(addr), city(cty), state(st), zip(zp), phone(ph) {}

        // Accessors
        string getLastName() const {
            return lastName;
        } // getLastName

        string getFirstName() const {
            return firstName;
        } // getFirstName

        string getAddress() const {
            return address;
        } // getAddress

        string getCity() const {
            return city;
        } // getCity

        string getState() const {
            return state;
        } // getState

        string getZip() const {
            return zip;
        } // getZip

        string getPhone() const {
            return phone;
        } // getPhone

        // Mutators
        void setLastName(string last) {
            lastName = last;
        } // setLastName

        void setFirstName(string first) {
            firstName = first;
        } // setFirstName

        void setAddress(string addr) {
            address = addr;
        } // setAddress

        void setCity(string cty) {
            city = cty;
        } // setCity

        void setState(string st) {
            state = st;
        } // setState

        void setZip(string zp) {
            zip = zp;
        } // setZip

        void setPhone(string ph) {
            phone = ph;
        } // setPhone
}; // PersonData Class

/*
* CustomerData:
*   This class is derived from the PersonData class. It has an additional private member variables:
*   - customerNumber (an integer)
*   - mailingList (a boolean)
*   The class has the following member functions:
*   - Constructor: Accepts the following values as arguments:
*     - Last name
*     - First name
*     - Address
*     - City
*     - State
*     - ZIP code
*     - Phone number
*     - Customer number (an integer)
*     - Mailing list (a boolean)
*   - Accessors and Mutators for the customerNumber and mailingList member variables
*/
class CustomerData : public PersonData {
    // Private Data Members
    private:
        int customerNumber;
        bool mailingList;

    // Public Functions
    public:
        // Constructor
        CustomerData(string last, string first, string addr, string cty, string st, string zp, string ph, int custNum, bool mailList) : PersonData(last, first, addr, cty, st, zp, ph), customerNumber(custNum), mailingList(mailList) {}

        // Accessors
        int getCustomerNumber() const {
            return customerNumber;
        } // getCustomerNumber

        bool getMailingList() const {
            return mailingList;
        } // getMailingList

        // Mutators
        void setCustomerNumber(int custNum) {
            customerNumber = custNum;
        } // setCustomerNumber

        void setMailingList(bool mailList) {
            mailingList = mailList;
        } // setMailingList
}; // CustomerData Class

/*
* GradedActivity:
*   This class holds a numeric score and determines whether the score is passing or failing.
*   The class has the following member functions:
*   - Constructor: Accepts a numeric score as an argument
*   - Accessors and Mutators for the score member variable
*/
class GradedActivity {
    // Private Data Members
    private:
        double score;

    // Public Functions
    public:
        // Constructor
        GradedActivity(double grade) : score(grade) {}

        // Accessors
        double getScore() const {
            return score;
        } // getScore

        // Mutators
        void setScore(double scr) {
            score = scr;
        } // setScore
}; // GradedActivity Class

/*
* CourseGrades:
*   This class holds four GradedActivity pointers, one for each of the following types of activities:
*   - Lab
*   - Pass/Fail Exam
*   - Essay
*   - Final Exam
*   The class has the following member functions:
*   - Constructor: Initializes all pointers to nullptr
*   - Destructor: Deletes all pointers
*   - setLab: Sets the lab activity grade
*   - setPassFailExam: Sets the pass/fail exam grade
*   - setEssay: Sets the essay grade
*   - setFinalExam: Sets the final exam grade
*   - print: Prints all grades
*/
class CourseGrades {

    // Private Data Members
    private:
        GradedActivity* grades[4]; // Array of pointers to GradedActivity objects

    // Public Functions
    public:
        // Default constructor (initializes all pointers to nullptr)
        CourseGrades() {
            for (int i = 0; i < 4; ++i) {
                grades[i] = nullptr;
            } // for
        } // Constructor

        // Destructor
        ~CourseGrades() {
            for (int i = 0; i < 4; ++i) {
                delete grades[i];
            } // for
        } // Destructor

        // Sets the lab activity grade
        void setLab(GradedActivity* lab) {
            grades[0] = lab;
        } // setLab

        // Sets the pass/fail exam grade
        void setPassFailExam(GradedActivity* exam) {
            grades[1] = exam;
        } // setPassFailExam

        // Sets the essay grade
        void setEssay(GradedActivity* essay) {
            grades[2] = essay;
        } // setEssay

        // Sets the final exam grade
        void setFinalExam(GradedActivity* finalExam) {
            grades[3] = finalExam;
        } // setFinalExam

        // Prints all grades
        void print() const {
            const string labels[4] = { "Lab", "Pass/Fail Exam", "Essay", "Final Exam" };
            cout << "Course Grades:\n";
            for (int i = 0; i < 4; ++i) {
                if (grades[i]) {
                    cout << labels[i] << ": " << grades[i]->getScore() << endl;
                } 
                
                else {
                    cout << labels[i] << ": No grade assigned.\n";
                } // if
            } // for
        } // print
}; // CourseGrades Class

// Function Prototypes
void displayMenu();
void getValidInt(int& num);
void getValiddouble(double& num);
char getYesOrNo(const string& prompt);

// Employee and ProductionWorker Functions
void employeeProductionWorkerPresentation();
void demonstrateEmployee();
Employee initializeEmployee();
void demonstrateProductionWorker();
ProductionWorker initializeProductionWorker();

// PersonData and CustomerData Functions
void personDataCustomerDataPresentation();
void demonstratePersonData();
PersonData initializePersonData();
void demonstrateCustomerData();
CustomerData initializeCustomerData();

// Course Grades Functions
void courseGradesPresentation();
void demonstrateCourseGrades();
GradedActivity* initializeGradedActivity(const string& activityName);

// Main 
int main() {
    char choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(1000, '\n');  // Clear input buffer

        switch (choice) {
        case '1':
            // Demonstrate Employee and ProductionWorker Classes
            employeeProductionWorkerPresentation();
            break;

        case '2':
            // Demonstrate PersonData and CustomerData Classes
            personDataCustomerDataPresentation();
            break;
            
        case '3':
            // Demonstrate Course Grades
            courseGradesPresentation();
            break;

        case '4':
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
    cout << "Select a program to run (1-3) or enter 4 to exit:\n";
    cout << "1. Employee and ProductionWorker Classes\n";
    cout << "2. PersonData and CustomerData Classes\n";
    cout << "3. Course Grades\n";
    cout << "4. Exit\n";
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

// Demonstrate Employee Class
void employeeProductionWorkerPresentation() {
    char choice;

    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    cout << "Welcome to the Employee Class demonstration!" << endl;
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;


    // Loop to demonstrate different classes based on user input until the user chooses to exit
    do {
        cout << "What type of employee would you like to create?" << endl;
        cout << "Enter '1' for normal employee, '2' for production worker, or '3' to exit : ";
        cin >> choice;
        cin.ignore(1000, '\n');  // Clear input buffer

        // Switch statement to determine which class to demonstrate
        switch (choice) {
        case '1':
            // Demonstrate Employee Class
            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
            demonstrateEmployee();
            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
            break;

        case '2':
            // Demonstrate ProductionWorker Class
            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
            demonstrateProductionWorker();
            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
            break;
        
        case '3':
            // Exit the program
            cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
            cout << "Exiting program. Have a nice day!" << endl;
            break;

        default:
            // Invalid input
            cout << "Invalid input." << endl;
        }
            
    } while (choice != '3'); // Continue until the user chooses to exit
} // demonstrateEmployee

// Demonstrate Employee
void demonstrateEmployee() {
    cout << "Create an employee" << endl;

    Employee emp = initializeEmployee();

    // Display Employee details
    cout << "\nEmployee Details:" << endl;
    cout << "Name: " << emp.getName() << endl;
    cout << "Employee Number: " << emp.getNumber() << endl;
    cout << "Hire Date: " << emp.getHireDate() << endl;
} // demonstrateEmployee

// Initialize an Employee object
Employee initializeEmployee() {
    // Variables
    string name, hireDate;
    int empNumber;

    // Get all necessary information for an Employee object
    cout << "Enter Employee Name: ";
    getline(cin, name);

    cout << "Enter Employee Number: ";
    getValidInt(empNumber);

    cout << "Enter Hire Date: ";
    getline(cin, hireDate);

    return Employee(name, empNumber, hireDate);
} // initializeEmployee

// Demonstrate ProductionWorker Class
void demonstrateProductionWorker() {
    cout << "Demonstrating Production Worker Class" << endl;

    ProductionWorker worker = initializeProductionWorker();

    // Display ProductionWorker details
    cout << "\nProductionWorker Details:" << endl;
    cout << "Name: " << worker.getName() << endl;
    cout << "Employee Number: " << worker.getNumber() << endl;
    cout << "Hire Date: " << worker.getHireDate() << endl;
    cout << "Shift: " << (worker.getShift() == 1 ? "Day" : "Night") << endl;
    cout << "Hourly Rate: $" << fixed << setprecision(2) << worker.getHourlyRate() << endl;
} // demonstrateProductionWorker

// Initialize a ProductionWorker object
ProductionWorker initializeProductionWorker() {
    // Variables
    string name, hireDate;
    int empNumber, shift;
    double hourlyRate;

    // Get all necessary information for a ProductionWorker object
    cout << "Enter Worker Name: ";
    getline(cin, name);

    cout << "Enter Employee Number: ";
    getValidInt(empNumber);

    cout << "Enter Hire Date: ";
    getline(cin, hireDate);

    cout << "Enter Shift (1 for Day, 2 for Night): ";
    getValidInt(shift);

    cout << "Enter Hourly Rate: ";
    getValiddouble(hourlyRate);

    return ProductionWorker(name, empNumber, hireDate, shift, hourlyRate);
} // initializeProductionWorker

// Demonstrate PersonData Class
void personDataCustomerDataPresentation() {
    // Variables
    char choice;

    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    cout << "Welcome to the PersonData and CustomerData Class demonstration!" << endl;
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    
    // Loop to demonstrate different classes based on user input until the user chooses to exit
    do {
        cout << "What type of object would you like to create?" << endl;
        cout << "Enter '1' for normal person, '2' for customer, or '3' to exit : ";
        cin >> choice;
        cin.ignore(1000, '\n');  // Clear input buffer

        // Switch statement to determine which class to demonstrate
        switch (choice) {
            case '1':
                // Demonstrate PersonData Class
                cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
                demonstratePersonData();
                cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
                break;

            case '2':
                // Demonstrate CustomerData Class
                cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
                demonstrateCustomerData();
                cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
                break;

            case '3':
                // Exit the program
                cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
                cout << "Exiting program. Have a nice day!" << endl;
                break;

            default:
                // Invalid input
                cout << "Invalid input." << endl;
        } // switch
    } while (choice != '3'); // Continue until the user chooses to exit
} // personDataCustomerDataPresentation

void demonstratePersonData() {
    // Variables
    PersonData person = initializePersonData();

    // Display PersonData details
    cout << "\nPerson Data:" << endl;
    cout << "First Name: " << person.getFirstName() << endl;
    cout << "Last Name: " << person.getLastName() << endl;
    cout << "Address: " << person.getAddress() << endl;
    cout << "City: " << person.getCity() << endl;
    cout << "State: " << person.getState() << endl;
    cout << "ZIP: " << person.getZip() << endl;
    cout << "Phone: " << person.getPhone() << endl;
} // demonstratePersonData

// Initialize a PersonData object
PersonData initializePersonData() {
    // Variables
    string firstName, lastName, address, city, state, zip, phone;

    cout << "Please enter all necessary person data" << endl;

    // Get all necessary information for a PersonData object
    cout << "Enter First Name: ";
    getline(cin, firstName);

    cout << "Enter Last Name: ";
    getline(cin, lastName);

    cout << "Enter Address: ";
    getline(cin, address);

    cout << "Enter City: ";
    getline(cin, city);

    cout << "Enter State: ";
    getline(cin, state);

    cout << "Enter ZIP: ";
    getline(cin, zip);

    cout << "Enter Phone: ";
    getline(cin, phone);

    // Return a new PersonData object
    return PersonData(lastName, firstName, address, city, state, zip, phone);
} // initializePersonData

// Demonstrate CustomerData Class
void demonstrateCustomerData() {
    // Variables
    CustomerData customer = initializeCustomerData();

    // Display CustomerData details
    cout << "\nCustomer Data:" << endl;
    cout << "First Name: " << customer.getFirstName() << endl;
    cout << "Last Name: " << customer.getLastName() << endl;
    cout << "Address: " << customer.getAddress() << endl;
    cout << "City: " << customer.getCity() << endl;
    cout << "State: " << customer.getState() << endl;
    cout << "ZIP: " << customer.getZip() << endl;
    cout << "Phone: " << customer.getPhone() << endl;
    cout << "Customer Number: " << customer.getCustomerNumber() << endl;
    cout << "Mailing List: " << (customer.getMailingList() ? "Yes" : "No") << endl;
} // demonstrateCustomerData

// Initialize a CustomerData object
CustomerData initializeCustomerData() {
    // Variables
    string firstName, lastName, address, city, state, zip, phone;
    int customerNumber;
    char mailingListChoice;
    bool mailingList;

    // Get all necessary information for a CustomerData object
    cout << "Please enter all necessary customer data" << endl;

    cout << "Enter First Name: ";
    getline(cin, firstName);

    cout << "Enter Last Name: ";
    getline(cin, lastName);

    cout << "Enter Address: ";
    getline(cin, address);

    cout << "Enter City: ";
    getline(cin, city);

    cout << "Enter State: ";
    getline(cin, state);

    cout << "Enter ZIP: ";
    getline(cin, zip);

    cout << "Enter Phone: ";
    getline(cin, phone);

    cout << "Enter Customer Number: ";
    getValidInt(customerNumber);

    cout << "Is the customer on the mailing list? (Y/N): ";
    cin >> mailingListChoice;
    cin.ignore(1000, '\n'); // Clear input buffer

    if (toupper(mailingListChoice) == 'Y') {
        mailingList = true;
    } // if

    else {
        mailingList = false;
    } // else

    return CustomerData(lastName, firstName, address, city, state, zip, phone, customerNumber, mailingList);
} // initializeCustomerData

// Demonstrate CourseGrades Class
void courseGradesPresentation() {
    // Variables
    char choice;

    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    cout << "Welcome to the Course Grades demonstration!" << endl;
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;

    do {

        // Demonstrate Course Grades
        demonstrateCourseGrades();
        cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;

    } while (getYesOrNo("Would you like to enter another set of grades? (Y/N): ") == 'Y');
} // demonstrateCourseGrades

void demonstrateCourseGrades() {
    // Variables
    CourseGrades course;
    
    cout << "Please enter the correct grades for the following activities:" << endl;
    cout << "Lab, Pass/Fail Exam, Essay, and Final Exam" << endl;
    cout << setfill('-') << setw(MENU_WIDTH) << "-" << endl;
    // Initialize grades
    course.setLab(initializeGradedActivity("Lab"));
    course.setPassFailExam(initializeGradedActivity("Pass/Fail Exam"));
    course.setEssay(initializeGradedActivity("Essay"));
    course.setFinalExam(initializeGradedActivity("Final Exam"));

    // Print the grades
    cout << endl;
    course.print();
} // demonstrateCourseGrades

// Initialize a GradedActivity object
GradedActivity* initializeGradedActivity(const string& activityName) {
    double score;

    cout << "Enter the score for " << activityName << ": ";
    getValiddouble(score);

    return new GradedActivity(score);
} // initializeGradedActivity
