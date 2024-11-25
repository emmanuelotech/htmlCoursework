#include <iostream>
using namespace std;

/*DECLARING ARRAYS
- Name
- Type of Array - one dimension/ mult-dimensional
- Number of elements*/

int main(){

    //int numbers[] --> declares an array . A collection of items of same type.
    int numbers[] = {10,15,20,25,30,35,40,50,60,45};

    cout <<numbers[6] <<endl;
    cout <<numbers[0] <<endl;


    for(int x=0;x<size(numbers);x++){
        cout<<numbers[x]<<endl;
    }


    return 0;
}