//Computes for the Summation f the series 1^1 + 2^2 + 3^3 + ... + n^n...
#include <iostream>
#include <______>
using namespace std;

long long series(int n);
int main()
{
    int ____;
    cout <<"Enter a positive number: ";
    cin >> ____;

    for (int i+______; i<=n; i++)
    if (i<_____)
    cout << i << "^" << i << " + ";
    else
    cout << i << "^" << i << " ____ ";

    cout << ___(n) << endl;
    system("pause");
    }
    if (n==0)
    return(____);
    else
    return pow(n,n) + series(_____);
}