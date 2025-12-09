// ------------------------------------------------------------
// File: 03_minNumberOfCoins.cpp
// ------------------------------------------------------------
// Problem Statement:
// Given an infinite supply of each denomination of Indian currency
// {1, 2, 5, 10} and a target value 'n', find the minimum number
// of coins and/or notes needed to make the change for Rs n.
//
// Example 1:
// Input: n = 39
// Output: 6
// Explanation:
// 39 can be formed using 3 coins of 10 rupees,
// 1 coin of 5 rupees and 2 coins of 2 rupees.
// So minimum coins required = 6.
//
// Example 2:
// Input: n = 121
// Output: 13
// Explanation:
// 121 = 12 coins of 10 rupees + 1 coin of 1 rupee.
//
// Constraints:
// 1 ≤ n ≤ 10^6
// ------------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Calculates the minimum number of coins/notes needed to make value n.
 *
 * This function uses a greedy approach because Indian currency denominations
 * {10, 5, 2, 1} are canonical, meaning the greedy method always produces an
 * optimal answer. We try to use the largest possible denomination first and
 * keep reducing the target amount.
 *
 * @param n The target amount for which minimum coins are needed.
 * @return int Minimum number of coins required.
 */
int findMin(int n)
{

    // Currency denominations arranged in descending order.
    // Greedy approach always tries to take the largest value first.
    int currency[] = {10, 5, 2, 1};

    // To store total number of coins we use.
    int count = 0;

    // Index to iterate over the currency array.
    int index = 0;

    // Continue until the entire amount is reduced to zero.
    while (n > 0)
    {

        // Determine how many times the current denomination fits in n.
        int usableCoins = n / currency[index];

        // If denomination can be used at least once.
        if (usableCoins > 0)
        {

            // Add required coins to count.
            count += usableCoins;

            // Reduce n after using usableCoins number of currency[index].
            n %= currency[index];
        }

        // Move to the next smaller denomination.
        index++;
    }

    return count;
    // ------------------------------------------------------------
    // Time Complexity  : O(1)
    //   - Because the number of denominations is fixed (4 values).
    // Space Complexity : O(1)
    //   - No extra space used except variables.
    // ------------------------------------------------------------
}

int main()
{

    // Example 1
    int n1 = 39;
    cout << "Minimum coins for 39: " << findMin(n1) << endl;
    // Expected Output: 6

    // Example 2
    int n2 = 121;
    cout << "Minimum coins for 121: " << findMin(n2) << endl;
    // Expected Output: 13

    return 0;
}
