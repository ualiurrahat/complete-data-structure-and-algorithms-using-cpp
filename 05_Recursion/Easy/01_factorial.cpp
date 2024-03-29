/*
Recursion: the method of calling a function by itself
untill a specified condition is met.
Use of Recursion:
When a problems acts as a same nature of problem with smaller input
we use recursion to solve the big problem.
*/

#include <bits/stdc++.h>

using namespace std;
// function to find nth factorial number using recursion.
int factorial(int n)
{
    cout << "calling for n = " << n << endl;
    // base case
    if (n == 0)
    {
        return 1;
    }
    // recursive call
    int smallOutput = factorial(n - 1);
    cout << "going back for n =" << n << endl;
    // small calculation
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