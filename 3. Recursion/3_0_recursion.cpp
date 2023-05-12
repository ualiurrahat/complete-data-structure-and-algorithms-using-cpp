/*
Use of Recursion:
When a problems acts as a same nature of problem with smaller input
we use recursion to solve the big problem.
*/

#include <bits/stdc++.h>

using namespace std;

int factorial(int n)
{
    cout << "calling for n = " << n << endl;
    if (n == 0)
    {
        return 1;
    }
    int smallOutput = factorial(n - 1);
    cout << "going back for n =" << n << endl;
    return n * smallOutput;
}

int main()
{
    int n;
    cout << "Enter a number to find its factorial: ";
    cin >> n;
    int output = factorial(n);
    cout << output << endl;

    return 0;
}