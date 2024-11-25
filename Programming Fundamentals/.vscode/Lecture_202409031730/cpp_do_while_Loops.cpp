#include <iostream>
using namespace std;

int main(){
    int y=1;
    /*EVery loop has three things in common: 
    1. Initialize the variable
    2. Do something with it
    3. Increase/decrease the variable or modify the value of the variable
    FINALLY: Check whether the condition is still met else stop.*/
    
    do{cout <<"Hello, World 👉 "<<y <<endl;
      y=y+1;  }

    while(y<=5);

    return 0;
}