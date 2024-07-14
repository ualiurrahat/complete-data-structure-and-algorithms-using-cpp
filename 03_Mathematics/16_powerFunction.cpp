/*Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25*/
#include <iostream>
using namespace std;

// brute force solution
// calculate x^n
double powerBrute(double x, int n)
{
    double val = 1.0;
    // when n is positive value
    if (n > 0)
    {
        for (int i = n; i >= 1; i--)
        {
            val = val * x;
        }
    }
    else
    // when n is nagative.
    {
        val = val * x;
        for (int i = n; i < 0; i++)
        {
            val = val / x;
        }
        val = val / x;
    }
    return val;
    // T:O(n)
    // S:O(1)
}
// optimal solution
double powerOptimal(double x, int n)
{
    long long N = n;
    // when n is -ve power
    if (N < 0)
    {
        N = -N;
        x = 1 / x;
    }
    double ans = 1;
    while (N)
    {
        if ((N & 1) != 0) // equivalent to if(n % 2 != 0) i.e. multiply only when the number is odd
        {
            ans = ans * x;
        }
        x *= x;
        N >>= 1; // equivalent to n = n /2; i.e. keep dividing the number by 2.
    }
    return ans;
}
int main()
{
    double baseNum;
    int powerNum;
    cout << "Enter base and power number: ";
    cin >> baseNum >> powerNum;

    cout << baseNum << " to the power of " << powerNum << " is = " << powerBrute(baseNum, powerNum);
    return 0;
}