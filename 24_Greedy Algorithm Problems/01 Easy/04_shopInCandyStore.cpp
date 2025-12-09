// ------------------------------------------------------------
// File: 04_shopInCandyStore.cpp
// ------------------------------------------------------------
// Problem Statement:
// In a candy store, prices[i] represents the price of the i-th candy.
// There is an offer: for every candy you buy, you can take up to 'k' other
// different candies for FREE.
//
// You must calculate:
//   1) Minimum amount of money required to buy all candies.
//   2) Maximum amount of money required to buy all candies.
//
// Important Note:
// In both minimum and maximum calculations, the buyer MUST take the maximum
// number of free candies possible.
//
// Example 1:
// Input: prices = [3, 2, 1, 4], k = 2
// Output: [3, 7]
//
// Explanation:
// Minimum Cost:
//   Buy candy worth 1 → take candies worth 3 and 4 for free.
//   Still need the candy worth 2 → buy it.
//   Total = 1 + 2 = 3.
//
// Maximum Cost:
//   Buy candy worth 4 → take candies worth 1 and 2 for free.
//   Still need candy worth 3 → buy it.
//   Total = 4 + 3 = 7.
//
// Example 2:
// Input: prices = [3, 2, 1, 4, 5], k = 4
// Output: [1, 5]
//
// Explanation:
// Minimum Cost:
//   Buy the cheapest candy (1) → get all others free.
// Maximum Cost:
//   Buy the most expensive candy (5) → get all others free.
//
// Constraints:
//   1 ≤ prices.size() ≤ 100000
//   0 ≤ k ≤ prices.size()
//   1 ≤ prices[i] ≤ 10000
// ------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief Computes minimum and maximum cost to buy all candies using the offer.
 *
 * The idea:
 * - To minimize cost: always buy the CHEAPEST candy first.
 *   After buying one candy, take 'k' costliest remaining candies for free.
 *   This is naturally achieved using two pointers on a sorted array.
 *
 * - To maximize cost: always buy the MOST EXPENSIVE candy first.
 *   After buying it, take 'k' cheapest remaining candies for free.
 *   Again accomplished using two pointers but in reverse direction.
 *
 * @param prices Vector of candy prices.
 * @param k The number of free candies allowed per purchase.
 * @return vector<int> A vector containing {minimumCost, maximumCost}.
 */
vector<int> minMaxCandy(vector<int> &prices, int k)
{

    // Vector to return minimum and maximum cost.
    vector<int> costs;

    // Total candies.
    int n = prices.size();

    // Variables to store computed minimum and maximum cost.
    int minAmount = 0;
    int maxAmount = 0;

    // Sort prices so that cheapest and costliest candies can be accessed easily.
    sort(prices.begin(), prices.end());

    // ------------------------------------------------------------
    // FINDING MINIMUM COST:
    // Buy the cheapest candy, and take the MOST expensive k candies for free.
    // ------------------------------------------------------------

    // Two-pointer technique:
    // 'i' → points to cheapest available candy.
    // 'j' → points to costliest available candy.
    int i = 0;
    int j = n - 1;

    // Continue until all candies are accounted for.
    while (i <= j)
    {

        // Buy candy at position i (cheapest).
        minAmount += prices[i];

        // Move to next cheapest candy.
        i++;

        // Since we must take maximum free candies:
        // Skip k candies from the right side.
        j -= k;
    }

    // ------------------------------------------------------------
    // FINDING MAXIMUM COST:
    // Buy the costliest candy, and take the k cheapest candies for free.
    // ------------------------------------------------------------

    // Reset pointers:
    // 'i' → points to costliest candy.
    // 'j' → points to cheapest leftover candy.
    i = n - 1;
    j = 0;

    while (i >= j)
    {

        // Buy candy at position i (costliest).
        maxAmount += prices[i];

        // Move left to next costliest candy.
        i--;

        // Skip k cheapest candies (those become free).
        j += k;
    }

    // Store results.
    costs.push_back(minAmount);
    costs.push_back(maxAmount);

    return costs;

    // ------------------------------------------------------------
    // Time Complexity  : O(n log n)
    //   Sorting dominates the complexity.
    //
    // Space Complexity : O(1)
    //   Sorting is in-place and no extra arrays stored.
    // ------------------------------------------------------------
}

int main()
{

    vector<int> prices1 = {3, 2, 1, 4};
    int k1 = 2;

    vector<int> result1 = minMaxCandy(prices1, k1);
    cout << "Min: " << result1[0] << ", Max: " << result1[1] << endl;
    // Expected Output: Min: 3, Max: 7

    vector<int> prices2 = {3, 2, 1, 4, 5};
    int k2 = 4;

    vector<int> result2 = minMaxCandy(prices2, k2);
    cout << "Min: " << result2[0] << ", Max: " << result2[1] << endl;
    // Expected Output: Min: 1, Max: 5

    return 0;
}
