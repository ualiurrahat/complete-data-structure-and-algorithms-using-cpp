// Fibonacci series: 0 1 1 2 3 5 8 13 ..........
// write a recursive function to find nth fibonacci number(here, n starts from 0)
#include <bits/stdc++.h>

using namespace std;

int fibonacci(int n)
{

    if (n == 0 || n == 1)
    {
        return n;
    }
    // if (n == 1)
    // {
    //     return 1;
    // }

    int smallOutput1 = fibonacci(n - 1);
    int smallOutput2 = fibonacci(n - 2);

    return smallOutput1 + smallOutput2;
}

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    cout << n << "th fibonacci number is : " << fibonacci(n) << endl;

    return 0;
}