/*Given a number, unset/ remove the rightmost set bit
and return the number
ex: n = 12 = 1 1 0 0
output = 1 0 0 0 = 8

brute force solution:
1. convert the number into its binary form
2. traverse the number in reverse order
3. find the rightmost bit and unset the bit

optimal solution:

let's take a look at those numbers
16 = 1 0 0 0 0
15 = 0 1 1 1 1 (after rightmost bit in 16, all other are 1s in 15)
then
40 = 1 0 1 0 0 0
39 = 1 0 0 1 1 1 ( same goes for 40 and 39)
again
84 = 1 0 1 0 1 0 0
83 = 1 0 1 0 0 1 1
what are we seeing here?
between N and N-1,
the rightmost bit is N is unset in N-1.
and after the rightmost bit, all other bits are 0 in N. but they all are 1 in N-1

16 = 2 ^ 4;
15 = 2^3 + 4 + 2 + 1

and in 40 = 2^5 + 2^3
in 39 = 2^5 + 7 = 2^5 + 4 + 2 + 1
because of this pattern(4+2+1), in 39, all the bits are 1 after the rightmost bit in 40.

solution: just do N & (N-1)
    16 = 1 0 0 0 0
    15 = 0 1 1 1 1
----------------------
(&)    = 0 0 0 0 0(all other bits are 0, which is same for 16, rightmost bit is also unset)


*/

#include <bits/stdc++.h>
using namespace std;

// optimal solution
int removeRightMostSetBit(int n)
{
    return n & (n - 1);
    // T:O(1), S:O(1)
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "input number: " << n << endl;
    cout << "After removing rightmost set bit : " << removeRightMostSetBit(n) << endl;
    return 0;
}