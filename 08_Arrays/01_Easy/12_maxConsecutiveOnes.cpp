/**
 * @file 12_maxConsecutiveOnes.cpp
 *
 * @brief Problem Statement:
 * Given a binary array 'nums', return the maximum number of consecutive 1's.
 *
 * Example 1:
 * Input:  [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits OR the last three digits are consecutive 1s.
 *
 * Example 2:
 * Input:  [1,0,1,1,0,1]
 * Output: 2
 *
 * Constraints:
 * 1 <= nums.length <= 100000
 * nums[i] ∈ {0, 1}
 *
 * Additional Example (from my notes):
 * a[] = {1,1,0,1,1,1,0,1,1}
 * Output = 3
 */

#include <iostream>
using namespace std;

/**
 * @brief Function to compute the maximum number of consecutive 1's.
 *
 * Explanation:
 * - We maintain two counters:
 *      1. current  → counts the current streak of consecutive 1s
 *      2. maxi     → stores the maximum streak found so far
 *
 * - Traverse the array:
 *      - If arr[i] == 1 → increment current, update maxi
 *      - If arr[i] == 0 → streak breaks → reset current = 0
 *
 * @param arr Input binary array
 * @param n Size of the array
 * @return Longest streak of consecutive 1's
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int maxConsecutiveOnes(int arr[], int n)
{
    int maxi = 0;    // Stores the final answer
    int current = 0; // Tracks consecutive 1's in the current streak

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            current++;                 // Increment streak
            maxi = max(maxi, current); // Update max streak
        }
        else
        {
            current = 0; // Reset streak when encountering a 0
        }
    }

    return maxi;
}

int main()
{
    int n;

    cout << "Enter array size: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Maximum consecutive 1's: "
         << maxConsecutiveOnes(arr, n) << endl;

    /*
        Example Input:
        9
        1 1 0 1 1 1 0 1 1

        Expected Output:
        Maximum consecutive 1's: 3
    */

    return 0;
}
