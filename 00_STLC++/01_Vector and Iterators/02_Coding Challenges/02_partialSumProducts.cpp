/*
    Task:
    Given N positive integers, write a program to calculate the product of partial sums of the integers.
    Also, determine whether this product is divisible by both the minimum and maximum of the given integers.

    Input Format:
    - The first line contains an integer T, the number of test cases.
    - Each test case consists of:
        - An integer N, the number of integers.
        - N space-separated positive integers.

    Output Format:
    - For each test case, print two values:
        1. The product of partial sums.
        2. "YES" if the product is divisible by both the minimum and maximum integers, otherwise "NO".

    Constraints:
    - 1 ≤ N ≤ 1000
    - 1 ≤ Each integer ≤ 10^6

    Example:
    Input:
    2
    3
    2 3 4
    4
    5 10 15 20

    Output:
    120 YES
    930 YES
*/

#include <iostream>
#include <vector>
#include <numeric>   // For partial_sum and accumulate
#include <algorithm> // For min and max functions
#include <climits>   // For use of INT_MAX, INT_MIN

using namespace std;

// Function to multiply two numbers (used in accumulate)
long long multiply(long long x, long long y)
{
    return x * y;
}

int main()
{
    int tests, n, val;
    cin >> tests;

    vector<long long> nums; // Vector to store input numbers

    while (tests--)
    {
        cin >> n;
        nums.clear();

        int min_val = INT_MAX, max_val = INT_MIN; // Initialize min and max values

        // Read the input numbers and determine min and max values
        for (int i = 0; i < n; i++)
        {
            cin >> val;
            max_val = max(max_val, val);
            min_val = min(min_val, val);
            nums.push_back(val);
        }

        // Compute partial sums
        vector<long long> p_sum(n);
        partial_sum(nums.begin(), nums.end(), p_sum.begin());

        // Compute the product of partial sums
        long long p_sum_product = accumulate(p_sum.begin(), p_sum.end(), 1LL, multiply);

        // Print the product of partial sums
        cout << p_sum_product << " ";

        // Check divisibility by both min and max values
        if (p_sum_product % min_val == 0 && p_sum_product % max_val == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
