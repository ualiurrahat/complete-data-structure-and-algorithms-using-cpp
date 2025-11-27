/***************************************************************
 * File: 02_jumpGameOne.cpp
 *
 * Problem Statement:
 * You are given an integer array 'nums'. You start at index 0.
 * Each element at index 'i' represents your maximum jump length
 * from that position.
 *
 * You must determine whether it is possible to reach the last
 * index of the array.
 *
 * Example 1:
 * Input: nums = [2, 3, 1, 1, 4]
 * Output: true
 * Explanation:
 *   - From index 0, jump 1 step to index 1.
 *   - From index 1, jump 3 steps to reach the last index.
 *
 * Example 2:
 * Input: nums = [3, 2, 1, 0, 4]
 * Output: false
 * Explanation:
 *   - No matter what, you reach index 3.
 *   - nums[3] is 0, so you cannot move further.
 *
 * NOTE: The catch here is that, if array does not contain any 0, then
 * it will always reach the last stop. If it has 0, it might reach or not.
 ***************************************************************/

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Determines whether we can reach the last index of the array.
 *
 * This function uses a greedy approach:
 * - We track the farthest index ('maxIndex') we can reach so far.
 * - As we iterate, if the current index 'i' exceeds 'maxIndex',
 *   it means we are stuck and cannot move forward.
 * - Otherwise, we update 'maxIndex' using: max(maxIndex, i + nums[i]).
 *
 * @param nums A vector containing maximum jump lengths at each index.
 * @return true if the last index is reachable, false otherwise.
 *
 * Time Complexity: O(n)
 *   We traverse the array once.
 *
 * Space Complexity: O(1)
 *   Only constant extra variables used.
 */
bool canJump(vector<int> &nums)
{
    int maxIndex = 0;    // Tracks the farthest reachable index
    int n = nums.size(); // Total number of elements

    // Iterate until second last index
    for (int i = 0; i < n - 1; i++)
    {
        // If current index cannot be reached, we are stuck
        if (maxIndex < i)
        {
            return false;
        }

        // Update farthest reachable index
        maxIndex = max(maxIndex, i + nums[i]);

        // check if maxIndex already reach the last postion and return true
        if (maxIndex >= n)
        {
            return true;
        }
    }

    // Final check: if code has run till here, means maxIndex has reached last position
    return true;
}

/**
 * @brief Demonstrates example usage of the canJump() function.
 */
int main()
{
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Example 1 Output (Expected: 1): " << canJump(nums1) << endl;

    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Example 2 Output (Expected: 0): " << canJump(nums2) << endl;

    return 0;
}
