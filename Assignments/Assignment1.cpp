/*
    * Darion Badillo
    * 09/03/2024
    * CS 3060
    * Assignment 1
    *
    * Description:
    * C++ Program to Calculate Kinetic Energy
    * C++ Program to Estimate Paint Job Costs
    * C++ Program to Calculate Stock Profit
*/

#include <iostream>
using namespace std;
#include <iomanip> 


// Function declarations (prototypes)
int kineticEnergy(int mass, int velocity);
void paintJobEstimator();
double stockProfit(int numShares, double pricePerShare, double purchaseCommission, double salePrice, double saleCommission);


int main() {

    // Variable declarations
    int mass, velocity, control = 0, numShares;
    double answer, pricePerShare, commissionPaid, salePrice, saleCommission;
    // Function Calls

    cout << "Select a program to run (1-3): " << endl;
    while (control < 1 || control > 3) {
        cout << "1. Kinetic Energy Calculator\n2. Paint Job Estimator \n3. Stock Profit" << endl;
        cin >> control;
        if (control < 1 || control > 3) {
            cout << "Invalid input" << endl;
        }
    }

    switch (control) {

        // KE Calculator
        case 1:
		    // Input: mass and velocity
            cout << "\nKinetic Energy Calculator" << endl;
            cout << "Enter an object's mass (in kg): ";
            cin >> mass;

            cout << "Enter an object's velocity (in m/s): ";
            cin >> velocity;

		    // Call the kineticEnergy function to calculate kinetic energy
            answer = kineticEnergy(mass, velocity);
            cout << "The object's kinetic energy is: " << answer << " Joules" << endl;
            break;
        

		// Paint Job Estimator
        case 2:
            cout << "\nPaint Job Estimator" << endl;
            paintJobEstimator();
            break;
        
		// Stock Profit
        case 3:
            // Input: number of shares
            cout << "Enter the number of shares: ";
            cin >> numShares;

            // Input: purchase price per share
            cout << "Enter the purchase price per share: ";
            cin >> pricePerShare;

            // Input: purchase commission paid
            cout << "Enter the purchase commission paid: ";
            cin >> commissionPaid;

            // Input: sale price per share
            cout << "Enter the sale price per share: ";
            cin >> salePrice;

            // Input: sale commission paid
            cout << "Enter the sale commission paid: ";
            cin >> saleCommission;

            // Call the stockProfit function to calculate profit/loss
            answer = stockProfit(numShares, pricePerShare, commissionPaid, salePrice, saleCommission);

            if (answer > 0) {
                cout << "The sale resulted in a profit of $" << fixed << setprecision(2) << answer << endl;
            }
            else if (answer < 0) {
                cout << "The sale resulted in a loss of $" << fixed << setprecision(2) << -answer << endl;
            }
            else {
                cout << "The sale resulted in no profit or loss." << endl;
            }
        
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
int kineticEnergy(int mass, int velocity) {
    // Function body
    return (mass * (velocity * velocity) / 2);
} // kineticEnergy

void paintJobEstimator() {
    // Function body
    bool valid = false;
    int laborCostPerHour = 25, sqFtPerHour = 110, numRooms = 0, totalWallSpace = 0;
    double paintPriceMin = 10.00, paintPrice = 0.00, totalPaintCost, totalLaborCost, totalCost, gallonsPaint, sqFtPerRoom = 0.00, hoursLabor = 0.00;

    // Get number of rooms and validate input
    while (!valid) {
        valid = false;
        cout << "Enter the number of rooms to be painted: ";
        cin >> numRooms;
        if (numRooms < 1) {
            cout << "Invalid input! Number of rooms must be 1+." << endl;
        } // if
        else {
            valid = true;
        } // else
    } // while
    
    valid = false;
    // Get square footage of each room and validate input
    while (!valid) {
        cout << "Enter the square footage of each room: ";
        cin >> sqFtPerRoom;
        if (sqFtPerRoom < 0) {
            cout << "Invalid Input! Square Footage cannot be a negative number." << endl;
        } // if
        else {
            valid = true;
        } // else
    } // while

    // Calculate total wall space
    totalWallSpace = numRooms * sqFtPerRoom;

    valid = false;
    // Get price of paint per gallon and validate input
    while (!valid) {
        cout << "Enter the price of paint per gallon: ";
        cin >> paintPrice;
        if (paintPrice < paintPriceMin) {
            cout << "Invalid Input! Price of paint per gallon cannot be lower than " << paintPriceMin << "." << endl;
        } // if
        else {
            valid = true;
        } // else
    } // while

    // Calculate total paint cost
    totalWallSpace = numRooms * sqFtPerRoom;
    gallonsPaint = static_cast<double>(totalWallSpace) / sqFtPerHour;
    hoursLabor = gallonsPaint * 8.00;
    totalPaintCost = gallonsPaint * paintPrice;
    totalLaborCost = hoursLabor * laborCostPerHour;
    totalCost = totalPaintCost + totalLaborCost;


    // Display results

    cout << fixed << setprecision(2);
    cout << "Number of gallons of paint required: " << gallonsPaint << endl;
    cout << "Hours of labor required: " << hoursLabor << endl;
    cout << "Cost of paint: $" << totalPaintCost << endl;
    cout << "Cost of labor: $" << totalLaborCost << endl;
    cout << "Total cost of paint job: $" << totalCost << endl;
} // paintJobEstimator

double stockProfit(int numShares, double pricePerShare, double purchaseCommission, double salePrice, double saleCommission) {
    // Function body
	double profit = ((static_cast<double>(numShares) * salePrice) - saleCommission) - ((static_cast<double>(numShares) * pricePerShare) + purchaseCommission);

	return profit;
} // stockProfit

// End of file
