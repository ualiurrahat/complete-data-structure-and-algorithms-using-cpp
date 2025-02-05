/*
Count the total number of set bits (1s) in a given number.
Example:
    Input: 13 (Binary: 1101)
    Output: 3 (since there are three 1s in 1101)
NOTE: in Cpp STL, there is a built in function to count set bits.
the function is: builtin_popcount(int n); return total no. of set bits in n.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute force solution: Check each bit by dividing the number by 2
int countSetBitsBrute(int n)
{
    int count = 0;
    while (n > 1) // Iterate until n reduces to 1
    {
        if (n % 2 == 1) // Check if the last bit is 1
        {
            count += 1; // Increment count if last bit is set
        }
        n = n / 2; // Divide n by 2 to move to the next bit
    }
    if (n == 1) // If n is 1, count its set bit
        count++;
    return count;
    // Time Complexity: O(log₂(n)), Space Complexity: O(1)
}

// Better solution: Use bitwise AND to check each bit efficiently
int countSetBitsBetter(int n)
{
    int count = 0;
    while (n > 1) // Iterate until n reduces to 1
    {
        count = count + (n & 1); // Add 1 if the last bit is set (n & 1)
        n = n >> 1;              // Right shift n to check the next bit
    }
    if (n == 1) // If n is 1, count its set bit
        count++;
    return count;
    // Time Complexity: O(log₂(n)), Space Complexity: O(1)
}
// optimal solution:
int countSetBitsOptimal(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
    // T:O(no. of set bits) usually, but if all the bits are 1, then O(log₂(n))
}
int main()
{
    int n;
    while (1) // Infinite loop to take multiple inputs
    {
        cout << "Enter a number (0 to exit): ";
        cin >> n;
        if (n == 0) // Exit condition
            break;

        // Choose the approach to count set bits
        // int ans = countSetBitsBrute(n); // Brute force approach
        // int ans = countSetBitsBetter(n); // Better approach
        int ans = countSetBitsOptimal(n); // optimal approach

        cout << n << " : " << "Set Bits == " << ans << endl;
    }
    return 0;
}
