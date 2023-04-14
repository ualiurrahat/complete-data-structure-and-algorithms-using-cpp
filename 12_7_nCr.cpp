/* 
Find nCr and nPr of numbers.

*/
#include <iostream>
#include <string>

using namespace std;

int factorial(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

int main()
{

    int n, r;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter r: ";
    cin >> r;

    while (r > n)
    {
        cout << "invalid values! r can not be greater than n." << endl;
        cout << "Enter n: ";
        cin >> n;
        cout << "Enter r: ";
        cin >> r;
    }

    int nCr, nPr;
    nCr = factorial(n) / (factorial(r) * factorial(n - r));
    nPr = factorial(n) / factorial(n - r);

    cout << n << "C" << r << " = " << nCr << endl;
    cout << n << "P" << r << " = " << nPr << endl;
    return 0;
}