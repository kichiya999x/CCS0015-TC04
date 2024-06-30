#include<iostream>
using namespace std;

void showMessage(int i){
    // General case
    if(i <= 5){
        cout << i << ": I love repeating things....\n";
        showMessage(i + 1); // Recursive call
    }

    // Base case
    return;
}

int main(){
    showMessage(1);
}

// void showMessage(int i){
//     // Base case
//     if(i == 6){
//         return;
//     }

//     // General Case
//     cout << i << ": I love repeating things....\n";
//     showMessage(i + 1);
    
// }