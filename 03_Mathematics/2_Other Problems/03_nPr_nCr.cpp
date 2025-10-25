/**
 * @file 03_nPr_nCr.cpp
 * @brief Program to calculate both Permutation (nPr) and Combination (nCr).
 *
 * ---------------------- Problem Statement ----------------------
 * You are given two integers 'n' and 'r'.
 * Your task is to calculate:
 *   1. nPr = n! / (n - r)!   → number of ways to arrange r items from n.
 *   2. nCr = n! / [(n - r)! * r!]  → number of ways to choose r items from n.
 *
 * Example:
 * Input:
 * n = 5, r = 2
 *
 * Output:
 * 5P2 = 20
 * 5C2 = 10
 * ---------------------------------------------------------------
 */

#include <iostream>
using namespace std;

/**
 * @brief Function to compute Permutation (nPr).
 *
 * @param n Total number of items.
 * @param r Number of items to arrange.
 * @return The permutation value (nPr).
 *
 * @note
 * Formula used:
 *      nPr = n × (n - 1) × (n - 2) × ... × (n - r + 1)
 * Example:
 *      5P2 = 5 × 4 = 20
 *
 * @note
 * Edge Cases:
 * - If r > n → 0 (invalid case)
 * - If r < 0 → 0 (invalid case)
 *
 * @note
 * Time Complexity: O(r)
 * Space Complexity: O(1)
 */
int nPr(int n, int r)
{
    // Handle invalid inputs
    if (r > n || r < 0)
    {
        return 0;
    }

    int ans = 1;

    // Multiply n × (n-1) × ... for r terms
    for (int i = 1; i <= r; i++)
    {
        ans = ans * n;
        n--; // Decrease n each time
    }

    return ans;
}

/**
 * @brief Function to compute Combination (nCr).
 *
 * @param n Total number of items.
 * @param r Number of items to choose.
 * @return The combination value (nCr).
 *
 * @note
 * Formula used:
 *      nCr = nPr / r!
 * Example:
 *      6C3 = (6 × 5 × 4) / (3 × 2 × 1) = 20
 *
 * @note
 * Edge Cases:
 * - If r > n → 0 (invalid)
 * - If r = 0 or r = n → 1 (only one way)
 *
 * @note
 * Time Complexity: O(r)
 * Space Complexity: O(1)
 */
int nCr(int n, int r)
{
    if (r > n)
        return 0;

    // By definition, nC0 = nCn = 1
    if (r == 0 || r == n)
        return 1;

    int ans = 1;

    // Compute numerator: n × (n-1) × ... × (n-r+1)
    for (int i = 1; i <= r; i++)
    {
        ans = ans * n;
        n--;
    }

    // Divide by r! (denominator)
    for (int i = 2; i <= r; i++)
    {
        ans = ans / i;
    }

    return ans;
}

/**
 * @brief Demonstrates both nPr and nCr calculations.
 */
int main()
{
    int n, r;
    cout << "Enter n and r: ";
    cin >> n >> r;

    int permutation = nPr(n, r);
    int combination = nCr(n, r);

    cout << n << "P" << r << " = " << permutation << endl;
    cout << n << "C" << r << " = " << combination << endl;

    /**
     * ---------------- Example ----------------
     * Input:
     * 5 2
     *
     * Output:
     * 5P2 = 20
     * 5C2 = 10
     * ------------------------------------------
     */

    return 0;
}
