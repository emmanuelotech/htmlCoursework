#include <iostream>
using namespace std;

// Function to compute the greatest common divisor using the Euclidean algorithm
int greatestCommonDivisor(int n, int m) {
    while (m != 0) {
        int storedTempVariable = m;
        m = n % m;
        n = storedTempVariable;
    }
    return n;
}

// Function to reduce the fraction
// Returns 1 for successful reduction, and 0 for invalid input when the program is run
int reduce(int& num, int& denom) {
    // Check for invalid input
    if (denom == 0) {
        return 0; // Denominator cannot be zero
    }
    
    // Calculate the greatest common divisor
    int gcd = greatestCommonDivisor(num, denom); //FUnction will be called.
    
    // Reduce the fraction
    num /= gcd;
    denom /= gcd;
    
    return 1; // Successful reduction
}

int main() {
    int num, denom;
    
    cout << "Enter numerator: ";
    cin >> num;
    
    cout << "Enter denominator: ";
    cin >> denom;
    
    // Reduce the fraction
    int result = reduce(num, denom);
    
    if (result == 1) {
        cout << "Reduced fraction: " << num << "/" << denom << endl;
    } else {
        cout << "Failed to reduce the fraction. (Denominator cannot be zero)" << endl;
    }

    return 0;
}

//Emmanuel Okello