/*
    Problem Statement:
    You are climbing a staircase. It takes n steps to reach the top.
    Each time you can either climb 1 or 2 steps. You must compute how many
    distinct ways exist to reach the top.

    Examples:
    Input: n = 2
    Output: 2
    Explanation:
        1. 1 step + 1 step
        2. 2 steps

    Input: n = 3
    Output: 3
    Explanation:
        1. 1 step + 1 step + 1 step
        2. 1 step + 2 steps
        3. 2 steps + 1 step

    Requirements:
    - Include both the DP solution (successfully executed on LeetCode)
      and the recursive solution (which causes TLE).
    - Follow the user's C++ coding style:
        * Only necessary headers
        * Doxygen-style documentation
        * Keep original comments but rewrite in clean form
        * Include brute/better/optimal when relevant
        * Include main() with sample test cases and expected outputs
*/

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Computes the number of ways to climb n stairs using a recursive approach.
 *
 * Line-by-line intuition:
 * - Base Case:
 *      - If n = 1 → only 1 way.
 *      - If n = 2 → two ways.
 * - Recursive Case:
 *      - To reach step n, you must come from step n-1 or n-2.
 *      - Therefore:
 *          climbStairsRecursive(n) = climbStairsRecursive(n-1) + climbStairsRecursive(n-2)
 * - This leads to exponential time complexity, hence TLE on LeetCode.
 *
 * @param n Number of steps.
 * @return int Total distinct ways.
 *
 * Time Complexity: O(2^n)
 * - Because each call branches into two further calls.
 *
 * Space Complexity: O(n)
 * - Due to recursion stack depth.
 */
int climbStairsRecursive(int n)
{
    // base case
    if (n == 1 || n == 2)
    {
        return n;
    }
    return climbStairsRecursive(n - 1) + climbStairsRecursive(n - 2);
}

/**
 * @brief Computes the number of ways to climb n stairs using Dynamic Programming.
 *
 * Line-by-line intuition:
 * - If n <= 1 → only 1 way.
 * - Create a DP array `steps` of size n+1.
 * - Initialize:
 *      steps[0] = 1 (1 way to stand at the starting point)
 *      steps[1] = 1
 * - Relation:
 *      steps[i] = steps[i-1] + steps[i-2]
 * - This is identical to Fibonacci style DP.
 *
 * This solution runs efficiently on LeetCode.
 *
 * @param n Number of steps.
 * @return int Number of distinct ways.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int climbStairsDP(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    vector<int> steps(n + 1, 0);
    steps[0] = 1;
    steps[1] = 1;

    for (int index = 2; index <= n; index++)
    {
        steps[index] = steps[index - 1] + steps[index - 2];
    }

    return steps[n];
}

int main()
{
    // Test Cases with Expected Output
    cout << climbStairsDP(2) << endl; // Expected: 2
    cout << climbStairsDP(3) << endl; // Expected: 3
    cout << climbStairsDP(5) << endl; // Expected: 8

    // Recursive version demonstration (slow)
    cout << climbStairsRecursive(4) << endl; // Expected: 5
    cout << climbStairsRecursive(3) << endl; // Expected: 3

    return 0;
}
