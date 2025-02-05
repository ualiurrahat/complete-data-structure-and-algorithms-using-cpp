/*You have been given an integer 'N'.
Your task is to return true if it is a power of two. Otherwise, return false.
An integer 'N' is a power of two, if it can be expressed as 2 ^ 'K' where 'K' is an integer.
NOTE: ***
for any power of two binary numbers, the no. of set bit will be 1
ex: 2 = 10, 4 = 100, 8=1000, 16 = 10000, see, power of 2 has only 1 set bit.

brute force solution:
1. convert the number into binary form.
2. check if total no. of set bit is 1. then it is power of 2. otherwise, not.

optimal solution:
already we saw in the previous problem.
that we do N & N-1 remove rightmost set bit.
so if we do N & N-1, and if N is power of two, the result will alway be zero.

ex1: 16 = 10000, 15 = 01111, n&(n-1) = 16 & 15 = 0 0 0 0 0. so 16 is a power of two.
ex2: 13 = 1 1 0 1, 12 = 1 1 0 0, 13&12 = 1 1 0 0, 13 not power of two.

*/
#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwoOptimal(int n)
{
    // Write your code here.
    if (n > 0 && (n & (n - 1)) == 0)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    while (1)
    {
        cout << "Enter a number (0 to exit): ";
        cin >> n;
        if (n == 0)
        {
            break;
        }
        bool isPower = isPowerOfTwoOptimal(n);
        if (isPower)
        {
            cout << n << " is a power of two." << endl;
        }
        else
        {
            cout << n << " not power of two" << endl;
        }
    }

    return 0;
}