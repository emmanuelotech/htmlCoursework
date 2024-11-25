#include <iostream>
using namespace std;

// Function to find the greatest common divisor (GCD) of two numbers
int greatest_common_divisor(int x, int y) {
    // Keep finding the remainder until y becomes 0
    while (y != 0) {
        int holdingVariable = y; // Store y temporarily
        y = x % y;              // Find the remainder when x is divided by y
        x = holdingVariable;    // Set x to the old value of y
    }
    return x; // Return the greatest common divisor
}

// Function to reduce the fraction
// num is the numerator and denom is the denominator
// We use references so changes will affect the original variables
int reduce(int &num, int &denom) {
    // Check if either number is less than or equal to 0
    if (num <= 0 || denom <= 0) {
        return 0; // Return 0 to indicate there was a problem
    }

    // Find the greatest common divisor of num and denom
    int divisor = greatest_common_divisor(num, denom);

    // Divide both num and denom by the divisor to reduce the fraction
    num /= divisor;
    denom /= divisor;

    return 1; // Return 1 to indicate success
}

int main() {
    int numerator, denominator;

    // Ask the user to enter the numerator
    cout << "Enter the numerator: ";
    cin >> numerator;
    // Ask the user to enter the denominator
    cout << "Enter the denominator: ";
    cin >> denominator;

    // Call the reduce function and check if it was successful
    if (reduce(numerator, denominator)) {
        // If successful, print the reduced fraction
        cout << "The reduced fraction is: " << numerator << "/" << denominator << endl;
    } else {
        // If there was a problem (e.g., non-positive numbers), print an error message
        cout << "Both values you are entering must be positive only!" << endl;
    }

    return 0;
}
