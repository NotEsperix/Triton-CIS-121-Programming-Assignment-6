/******************************************
* Edgardo Richard Ventura                 *
* Week 6                                  *
* Assignment 1                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int quantity;
    char stat;
    double price, exprice, tax, total;

    // Input phase for quantity
    while (true) {
        cout << "Enter the quantity of widgets: ";
        cin >> quantity;
        if (cin.fail() || quantity <= 0) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "Invalid input. Please enter a positive number for quantity." << endl;
        }
        else {
            break; // Valid quantity entered, exit the loop
        }
    }

    // Input phase for customer status
    while (true) {
        if (quantity > 10000) {
            cout << "Enter customer status (A/B): ";
        }
        else if (quantity >= 5000) {
            cout << "Enter customer status (C/D): ";
        }
        else {
            cout << "Enter customer status (A/B/C/D): ";
        }
        cin >> stat;

        stat = toupper(stat); // Convert to uppercase to simplify comparisons
        if (quantity > 10000 && (stat == 'A' || stat == 'B')) {
            break; // Valid status for this quantity range
        }
        else if (quantity >= 5000 && (stat == 'C' || stat == 'D')) {
            break; // Valid status for this quantity range
        }
        else if (quantity < 5000 && (stat == 'A' || stat == 'B' || stat == 'C' || stat == 'D')) {
            break; // Valid status for this quantity range
        }
        else {
            cout << "Invalid customer status. Please try again." << endl;
            cin.clear(); // Clear error flag
            // No need to ignore remaining input here as we're expecting a single character
        }
    }

    // Process phase
    // Determine the price based on quantity and customer status
    if (quantity > 10000) {
        if (stat == 'A') price = 10;
        else if (stat == 'B') price = 12;
    }
    else if (quantity >= 5000 && quantity <= 10000) {
        if (stat == 'C') price = 20;
        else if (stat == 'D') price = 22;
    }
    else if (quantity < 5000)
        price = 30; // For quantities below 5000, price is $30 regardless of status

    exprice = quantity * price; // Calculate extended price
    tax = exprice * 0.07; // Calculate tax at 7%
    total = exprice + tax; // Calculate total

    // Output phase
    cout << setprecision(2) << fixed;
    cout << "\nExtended Price: $" << exprice << endl;
    cout << "    Tax Amount: $" << tax << endl;
    cout << "         Total: $" << total << endl;

    return 0;
}
