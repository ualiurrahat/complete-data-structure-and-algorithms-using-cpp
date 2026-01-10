/*
============================================================================
   FILE: 03_leetCode1752SortedAndRotated.cpp
   TOPIC: Check if Array is Sorted and Rotated
============================================================================

🧠 PROBLEM STATEMENT:
----------------------
Given an array 'nums', return true if the array was originally sorted in
non-decreasing order, then rotated some number of positions (including zero).
Otherwise, return false.

There may be duplicates in the original array.

📘 Note:
---------
An array A rotated by x positions results in an array B such that:
    B[i] == A[(i + x) % A.length]
for every valid index i.

📥 Example 1:
-------------
Input:  nums = [3, 4, 5, 1, 2]
Output: true
Explanation: The original sorted array was [1, 2, 3, 4, 5].
If we rotate it by 2 positions → [3, 4, 5, 1, 2].

📥 Example 2:
-------------
Input:  nums = [2, 1, 3, 4]
Output: false
Explanation: There is no sorted array rotation that produces this.

📥 Example 3:
-------------
Input:  nums = [1, 2, 3]
Output: true
Explanation: Already sorted (rotation = 0).

📊 Constraints:
----------------
1 <= nums.length <= 100
1 <= nums[i] <= 100
============================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Checks whether the given array was originally sorted and then rotated.
 *
 * @param nums The input vector of integers.
 * @return true  if the array is sorted and rotated or just sorted.
 * @return false otherwise.
 *
 * 🧩 Intuition:
 * ---------------
 * - If an array is sorted and then rotated, there will be **at most one place**
 *   where the order is violated (nums[i-1] > nums[i]).
 * - This point marks where the rotation occurred.
 * - We also check the circular order (last → first) because the array is treated
 *   as circular after rotation.
 */
bool check(vector<int> &nums)
{
    int count = 0; // To count how many times order breaks
    int n = nums.size();

    // ---------------------- Step 1: Count order breaks ----------------------
    for (int i = 1; i < n; i++)
    {
        // If current element is smaller than the previous, order is broken
        if (nums[i - 1] > nums[i])
        {
            count++;
        }
    }

    // ---------------------- Step 2: Check circular order -------------------
    // Compare last element with first to check rotation wrap-around
    if (nums[n - 1] > nums[0])
    {
        count++;
    }

    // ---------------------- Step 3: Decision -------------------------------
    // If order breaks more than once, it cannot be sorted-then-rotated
    return count <= 1;
}

/*
============================================================================
   🔍 TESTING THE FUNCTION
============================================================================
*/
int main()
{
    vector<int> nums1 = {3, 4, 5, 1, 2};
    vector<int> nums2 = {2, 1, 3, 4};
    vector<int> nums3 = {1, 2, 3};

    cout << boolalpha; // print true/false instead of 1/0

    cout << "Example 1: " << check(nums1) << endl; // Expected: true
    cout << "Example 2: " << check(nums2) << endl; // Expected: false
    cout << "Example 3: " << check(nums3) << endl; // Expected: true

    return 0;
}

/*
============================================================================
🕒 Time Complexity: O(n)
   → We traverse the array once.

💾 Space Complexity: O(1)
   → Only constant extra space used.

💡 Summary:
------------
✔ 0 breaks → Sorted (no rotation)
✔ 1 break  → Sorted and Rotated
✖ >1 breaks → Not possible by rotation of sorted array
============================================================================
*/
