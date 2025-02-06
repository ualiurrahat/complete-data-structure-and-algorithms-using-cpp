/*
A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

optimal solution:
step 1: xor between start and goal. If we do it, then
the resultant contains 1 in all the postions where bit flipped is required.
stpe 2: count the total set bits in the resultant. that's the answer.

ex:     10 = 1 0 1 0(start)
         7 = 0 1 1 1 (goal)
-------------------------------------
start^goal = 1 1 0 1 (need to flip bits in the position where there is 1 in this value)
so total setb bits = 3. that's the answer.

*/

#include <bits/stdc++.h>
using namespace std;

// function to get total set bits in a number.
int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
    // T:O(no. of set bits) avg, worst case when all bits are 1: O(log₂ n)
}
// optimal solution to find minimum bit flips
int minBitFlips(int start, int goal)
{
    int xorValue = start ^ goal;
    int ans = countSetBits(xorValue);
    return ans;
    // T: O(log₂ n)
    // S:O(1)
}
int main()
{
    int start, goal;
    while (1)
    {
        cout << "Enter the starting and goal numbers (-1 -1 to exit): ";
        cin >> start >> goal;
        if ((start == -1) && (goal == -1))
        {
            break;
        }
        int ans = minBitFlips(start, goal);
        cout << "Min. number of bits flipped to convert " << start << " to " << goal << " is : " << ans << endl;
    }

    return 0;
}