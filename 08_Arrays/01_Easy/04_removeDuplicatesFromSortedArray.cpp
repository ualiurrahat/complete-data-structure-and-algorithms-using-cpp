/*
Problem Statement:
------------------
Given an integer array `nums` sorted in non-decreasing order, remove the duplicates **in-place**
such that each unique element appears only once.

After removing duplicates:
- Let `k` be the number of unique elements.
- The first `k` positions of the array must contain those unique elements in sorted order.
- Elements beyond index `k - 1` can be ignored.

You must return `k`.

Custom Judge Behavior:
----------------------
The judge checks:
1. Returned value `k`
2. First `k` elements of the modified array

Examples:
---------
Input:  nums = [1,1,2]
Output: k = 2, nums = [1,2,_]

Input:  nums = [0,0,1,1,1,2,2,3,3,4]
Output: k = 5, nums = [0,1,2,3,4,_,_,_,_,_]

Constraints:
------------
1 <= nums.length <= 3 * 10^4
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

/**
 * @brief Brute force solution using a set.
 *
 * Approach:
 * ----------
 * 1. Insert all elements of the array into a set.
 *    - Set automatically removes duplicates and stores elements in sorted order.
 * 2. Copy the elements of the set back into the original array.
 * 3. Return the size of the set as the count of unique elements.
 *
 * Note:
 * -----
 * - This approach does NOT satisfy the O(1) extra space constraint.
 * - Used mainly for understanding and comparison.
 *
 * @param nums Reference to the input sorted array.
 * @return int Number of unique elements.
 *
 * Time Complexity:
 * ---------------
 * O(N log N) due to set insertions.
 *
 * Space Complexity:
 * ----------------
 * O(N) for the set.
 */
int removeDuplicatesBrute(vector<int> &nums)
{
    set<int> s;
    int n = nums.size();

    // Insert all elements into the set (duplicates are removed automatically)
    for (int i = 0; i < n; i++)
    {
        s.insert(nums[i]);
    }

    // Copy unique elements back into the array
    int index = 0;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        nums[index] = *it;
        index++;
    }

    // Remaining elements are irrelevant as per problem statement
    return s.size();
}

/**
 * @brief Optimal two-pointer approach (LeetCode standard).
 *
 * Approach:
 * ----------
 * 1. Maintain a pointer `nextIndex` to place the next unique element.
 * 2. Traverse the array from index 1.
 * 3. If the current element is different from the previous element,
 *    place it at `nextIndex` and increment `nextIndex`.
 *
 * @param nums Reference to the input sorted array.
 * @return int Number of unique elements.
 *
 * Time Complexity:
 * ---------------
 * O(N)
 *
 * Space Complexity:
 * ----------------
 * O(1) (in-place modification).
 */
int removeDuplicatesOptimal(vector<int> &nums)
{
    int n = nums.size();
    int nextIndex = 1;

    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[nextIndex] = nums[i];
            nextIndex++;
        }
    }
    return nextIndex;
}

/**
 * @brief Optimal two-pointer approach (i–j pointer variant).
 *
 * Explanation:
 * ------------
 * - Pointer `i` tracks the index of the last unique element.
 * - Pointer `j` scans the array.
 * - When a new unique element is found, it is placed at `i + 1`.
 *
 * Note:
 * -----
 * This logic is functionally identical to the previous optimal approach.
 * Differences in reported space usage on online judges are due to
 * internal implementation details, not actual algorithmic space usage.
 *
 * @param arr Input sorted array.
 * @param n Size of the array.
 * @return int Number of unique elements.
 *
 * Time Complexity:
 * ---------------
 * O(N)
 *
 * Space Complexity:
 * ----------------
 * O(1)
 */
int removeDuplicatesFromSortedArrayOptimal(int arr[], int n)
{
    int i = 0; // Pointer for last unique element

    // Start second pointer from index 1
    for (int j = 1; j < n; j++)
    {
        // If a new unique element is found
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j]; // Place next unique element
            i++;
        }
    }

    // Total unique elements = i + 1
    return i + 1;
}

/**
 * @brief Driver code to test duplicate removal.
 */
int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    // int k = removeDuplicatesBrute(nums);
    int k = removeDuplicatesOptimal(nums);
    // int k = removeDuplicatesFromSortedArrayOptimal(nums.data(), nums.size());

    cout << "Number of unique elements: " << k << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
