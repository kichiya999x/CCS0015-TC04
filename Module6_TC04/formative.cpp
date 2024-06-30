//Determines if a number is PRIME or NOT
#include <iostream>
using namespace std;
int prime (int n, int i=2); // Start i at 2, since 1 is not useful for checking prime
int main()
{
    int num;
    cout <<"Enter a positive number: ";
    cin >> num; // Fill with variable to store input

    if (prime(num)==1) // If function returns 1, it's prime
        cout << "PRIME" << endl;

    else
        cout << "NOT PRIME" << endl;
    
    system ("pause");
}


int prime(int n, int i=2)
{
    if (i == n)
        return(1);
    else if (n % i == 0)
    return(0);
    else
    return prime(n, i + 1);
}
