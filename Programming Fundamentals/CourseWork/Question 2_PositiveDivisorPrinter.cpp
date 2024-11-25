#include <iostream>
using namespace std;

void DispalyUsageInstructions(){
    std::cout  << "This program prints the positive divisors of positive integers."<<endl;
    std::cout  << "Enter a positive integer to see its divisors." <<endl;
    std::cout  << "Enter a non-positive integer to terminate the program.\n"<<endl;}

void DisplayDivisors(int num) {
    // Displaying divisors in decreasing order
    for (int i = num; i >= 1; --i) {
        if (num % i == 0) {
            std::cout << i << std::endl; }}}

int main() {
    DispalyUsageInstructions();//Display the usage instructions.

    while (true) {
        int num;
        std::cout << "Please enter a positive integer: ";
        std::cin >> num;

        if (num > 0){
            DisplayDivisors(num);

            char user_choice;
            std::cout << "Would you like to see the divisors of another integer (Y/N)? ";
            std::cin >> user_choice;

            if (user_choice != 'Y' && user_choice != 'y') {
                break;
            }
        } else {
            std::cout << "Input is not a positive integer. Program terminated.\n";
            break;
        }
    }
    return 0;}
