/******************************************
* Edgardo Richard Ventura                 *
* Week 6                                  *
* Assignment 5                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/
#include <iostream>
#include <iomanip>
#include <limits> // Needed for numeric_limits
using namespace std;

int main() {
    char jc;
    int hours;
    double rop, gross;

    // Input phase for job code
    while (true) {
        cout << "Enter the job code (L/J/A): ";
        cin >> jc;
        jc = toupper(jc); // Convert to uppercase to simplify comparisons

        if (jc == 'L' || jc == 'J' || jc == 'A') {
            break; // Valid job code entered, exit the loop
        }
        else {
            cout << "Invalid job code. Please enter 'L', 'J', or 'A'." << endl;
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the rest of the line
        }
    }

    // Input phase for hours
    while (true) {
        cout << "Enter the number of hours worked: ";
        cin >> hours;

        if (cin.fail() || hours < 0) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "Invalid input. Please enter a non-negative number for hours." << endl;
        }
        else {
            break; // Valid hours entered, exit the loop
        }
    }

    // Process phase
    // Determine the rate of pay based on job code and hours worked
    if (jc == 'L') {
        if (hours > 40) rop = 50.00;
        else rop = 40.00;
    }
    else if (jc == 'J') {
        if (hours > 60) rop = 100.00;
        else rop = 75.00;
    }
    else if (jc == 'A') {
        if (hours > 40) rop = 25.00;
        else rop = 20.00;
    }

    gross = hours * rop; // Compute gross pay (hrs * rate)

    // Output phase
    cout << setprecision(2) << fixed;
    cout << "Gross Salary: $" << gross << endl;

    return 0;
}
