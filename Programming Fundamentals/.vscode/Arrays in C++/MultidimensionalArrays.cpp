#include <iostream>
using namespace std;

int main(){
    int x[3][2]={
    
        {4,5},{8,10},{2,15}
    
    };//Mult-dimensional Array declaration

    for(int i=0;i<=size(x);i++){
        
        cout <<x[i]<<endl;
        for(int column=0;column<=size(x[i]);column++){
            cout <<x[i][column]<<endl;
        }
    }

    return 0;
}