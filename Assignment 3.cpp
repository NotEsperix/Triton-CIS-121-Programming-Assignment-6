/******************************************
* Edgardo Richard Ventura                 *
* Week 6                                  *
* Assignment 3                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/
#include <iostream>
#include <iomanip>
#include <limits> // Needed for numeric_limits
using namespace std;

int main() {
    int nt;
    char lc;
    float ppt, total;

    // Input phase with validation for the number of concert tickets
    while (true) {
        cout << "Enter the number of concert tickets: ";
        cin >> nt;

        if (cin.fail() || nt <= 0) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "Invalid input. Please enter a positive number for the number of tickets." << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the rest of the line
            break; // Valid number of tickets entered, exit the loop
        }
    }

    // Input phase with validation for location code
    while (true) {
        cout << "      Enter the location code (H/L): ";
        cin >> lc;
        lc = toupper(lc); // Convert to uppercase to simplify comparisons

        if (lc == 'H' || lc == 'L') {
            break; // Valid location code entered, exit the loop
        }
        else {
            cout << "Invalid location code. Please enter 'H' for high or 'L' for low." << endl;
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the rest of the line
        }
    }

    // Process phase
    // Determine the price per ticket based on volume and location
    if (nt > 25 || lc == 'H') ppt = 30.00;
    else if (nt > 10 || lc == 'L') ppt = 40.00;
    else ppt = 50.00; // For all other conditions

    total = nt * ppt; // Calculate total cost

    // Output phase
    cout << setprecision(2) << fixed;
    cout << "\nNumber of Tickets: " << nt << endl;
    cout << " Price per Ticket: $" << ppt << endl;
    cout << "       Total Cost: $" << total << endl;

    return 0;
}
