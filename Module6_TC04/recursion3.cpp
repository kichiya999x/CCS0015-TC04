#include<iostream>
using namespace std;

int simulateCallStack(int x){
    if(x > 0){
        cout << "Recursing... value of x: " << x << endl;
        simulateCallStack(x - 1);
    }

    cout << "Popping call stack, value popped: " << x << endl;
}

int main(){
    return simulateCallStack(5);
}