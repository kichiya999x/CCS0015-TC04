#include<iostream>
using namespace std;

void fx1(int x);
void fx2(int y);

int main(){
    fx1(3);
}

void fx1(int x){
    if (x == 0){
        return;
    }
    cout << "fx1 executing...\n";
    cout << "Calling fx2...\n";
    fx2(x);
}

void fx2(int y){
    cout << "fx2 executing...\n";
    cout << "Calling fx1...\n";
    fx1(y - 1);
}