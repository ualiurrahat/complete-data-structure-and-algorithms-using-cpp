/* You are given a number n, a position k.
clear the kth bit (insert 0 in this position)

ex: n = 13 = 1 1 0 1,  k = 2
    output = 1 0 0 1 = 9

brute force solution:
1. convert the number into binary
2. traverse the kth bit from reverse
3. clear the bit

Optimal solution:
1. take not shift of 1 up to k times.
 x = ~(1 << k)
2. do bitwise and (&) with the value x.

ex: 13 = 1 1 0 1,    ~(1 << 2) = 1 0 1 1 = x
    x  = 1 0 1 1
------------------------
n & x  = 1 0 0 1 (ith bit clear)


*/

#include <bits/stdc++.h>
using namespace std;

// function to clear ith bit: optimal solution
int clearIthBitOptimal(int n, int k)
{
    return (n & (~(1 << k)));
    // T:O(1), S:O(1)
}
int main()
{
    int n, k;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Enter the bit position to clear the bit: ";
    cin >> k;
    int ans = clearIthBitOptimal(n, k);
    cout << "input number: " << n << endl;
    cout << "output after clearing " << k << "th bit : " << ans << endl;
    return 0;
}