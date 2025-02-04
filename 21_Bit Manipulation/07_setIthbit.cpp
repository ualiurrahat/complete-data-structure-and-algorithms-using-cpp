/* You are given a number and a position k. set the kth bit to 1
ex: n = 1001 = 9, i = 2(0 based)
output = 1101 = 13

brute force:
1. convert the given number n into its binary form.
2. the traverse the number to ith bit in reverse order
3. then set the bit.

Optimal solution:
1. x = left shift 1 upto kth times
2. do or with this value x (n | x). kth bit is set.
ex: n = 1 0 0 1,  i = 2
i<<2  = 0 1 0 0
-----------------------
n | x = 1 1 0 1(kth bit is set)
*/

#include <bits/stdc++.h>
using namespace std;

// funciton to set the ith bit
// takes the number n and the bit position k(0-based)
int setIthBitOptimal(int n, int k)
{
    return (n | (1 << k));
    // T:O(1), S:O(1)
}

int main()
{
    int n, k;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Enter the bit position to set the bit: ";
    cin >> k;
    int ans = setIthBitOptimal(n, k);
    cout << "input number: " << n << endl;
    cout << "output after bit set: " << ans << endl;
    return 0;
}