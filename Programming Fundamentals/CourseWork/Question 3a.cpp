#include <iostream>
using namespace std; 

// Function to calculate the sum of all integers from 'first' to 'last' inclusive
/*This functions return the sum of all integers from variable first to last entered number
called last. The sum will be returned in varible called sum.*/
int sum_from_to(int first, int last) {
    int sum = 0;
        
    if (first > last) {
        int staggingVariable = first;
        first = last;
        last = staggingVariable;}    

   //THis keeps on adding all integers from the first one to the last one.
    for (int i = first; i <= last; ++i) {sum += i;}
    
    return sum;}


int main() {
    int first, last;
       
    cout << "Enter the first integer: "; // I can enter like 2 for the first integer
    cin >> first;
    cout << "Enter the last integer: "; // Second integer or last one like 4
    cin >> last; // Prompts the user to enter the value.
    
    /*Display the results of the program to the user.*/
    int result = sum_from_to(first, last);
    cout << "The sum of integers from " << first << " to " << last << " is " << result << "." << endl;
    
    return 0;
}
