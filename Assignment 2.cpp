/******************************************
* Edgardo Richard Ventura                 *
* Week 6                                  *
* Assignment 2                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/
#include <iostream>
#include <iomanip>
#include <limits> // Needed for numeric_limits
using namespace std;

int main() {
    int pn, quantity;
    double cpu, total;

    // Input phase with validation for part number
    while (true) {
        cout << "Enter the part number (10, 99, 55, 70, 50): ";
        cin >> pn;

        if (cin.fail() || (pn != 10 && pn != 99 && pn != 55 && pn != 70 && pn != 50)) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "Invalid input. Please enter one of the specified part numbers." << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the rest of the line
            break; // Valid part number entered, exit the loop
        }
    }

    // Input phase with validation for quantity
    while (true) {
        cout << "                       Enter the quantity : ";
        cin >> quantity;

        if (cin.fail() || quantity <= 0) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "Invalid input. Please enter a positive number for quantity." << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the rest of the line
            break; // Valid quantity entered, exit the loop
        }
    }

    // Process phase
    // Determine the cost per unit based on part number and quantity
    if (pn == 10 && quantity > 1000)
        cpu = 1.00;
    else if (pn == 99 && quantity > 500)
        cpu = 2.00;
    else
        cpu = 5.00; // For all other conditions

    total = quantity * cpu; // Calculate total cost

    // Output phase
    cout << setprecision(2) << fixed;
    cout << "\n  Part Number: " << pn << endl;
    cout << "Cost per Unit: $" << cpu << endl;
    cout << "   Total Cost: $" << total << endl;

    return 0;
}
