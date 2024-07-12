//Determines if a number is PRIME or NOT
#include <iostream>
using namespace std;
int prime(int n, int i = 1);
int main()
{
    int num;
    cout << "Enter a positive number: ";
    cin >> num;

    if (prime(num) == 2)
        cout << "PRIME" << endl; //Answer must either PRIME/ NOT PRIME.

    else
        cout << "NOT PRIME" << endl; //Answer must be either PRIME / NOT PRIME.

    system("pause");
}

int prime(int n, int i)
{
    if (i == n)
        return 1; // n is prime if we reached n
    else if (n % i == 0)
        return 0; // not prime
    else
        return prime(n, i + 1); // check next divisor
}