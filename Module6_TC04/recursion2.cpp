#include<iostream>
using namespace std;

int fx(int x, int i){
    if(x == 0 || i == 0){
        return 0;
    }else if(i == 1){
        return x;
    }else if(i > 1){
        return (x + fx(x, i - 1));
    }
}

int main(){
    cout << fx(5, 5);

    for(int i = 1; i <= 5; i++);
}