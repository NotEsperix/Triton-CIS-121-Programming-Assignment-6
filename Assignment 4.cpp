/******************************************
* Edgardo Richard Ventura                 *
* Week 6                                  *
* Assignment 4                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/
#include <iostream>
#include <iomanip>
#include <limits> // Needed for numeric_limits
using namespace std;

int main() {
    // Define variables
    char ec, dc; // For storing equipment and day codes
    float rc; // For storing the rental cost

    // Input phase for equipment code with validation
    cout << "       ~ Welcome to Lick My Sprockets Unlimited ~" << endl; 
    cout << "Where you can get all your equiptment in a lick of a split!\n" << endl; 
    cout << "   Equipment codes:                          Day codes:" << endl; 
    cout << "(A - Aspearagus Pealer)                  (F - for Full day)" << endl; 
    cout << "(B - Banana Cannon)                      (H - for Half day)" << endl; 
    cout << "(C - Florida Man Repelant)\n" << endl; 
    while (true) {
        cout << "Enter the Equipment code: ";
        cin >> ec;
        ec = toupper(ec); // Convert to uppercase to simplify comparisons

        if (ec == 'A' || ec == 'B' || ec == 'C') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the rest of the line
            break; // Valid equipment code entered, exit the loop
        }
        else {
            cout << "Invalid equipment code. Please enter 'A', 'B', or 'C'." << endl;
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the rest of the line
        }
    }

    // Input phase for day code with validation
    while (true) {
        cout << "      Enter the day code: ";
        cin >> dc;
        dc = toupper(dc); // Convert to uppercase to simplify comparisons

        if (dc == 'F' || dc == 'H')
            break; // Valid day code entered, exit the loop
        else {
            cout << "Invalid day code. Please enter 'F' for Full day or 'H' for Half day." << endl;
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the rest of the line
        }
    }

    // Process phase using if-else statements
    if (ec == 'A') {
        if (dc == 'F')
            rc = 10.00;
        else
            rc = 15.00;
    }
    else if (ec == 'B') {
        if (dc == 'F')
            rc = 20.00;
        else
            rc = 35.00;
    }
    else if (ec == 'C') {
        if (dc == 'F')
            rc = 45.00;
        else
            rc = 40.00;
        }
    else
        rc = 50.00; // Default cost for any other conditions (should not occur due to validation)

        // Output phase
        cout << setprecision(2) << fixed;
        cout << "             Rental Cost: $" << rc << endl;

        return 0;
    } // End of main
