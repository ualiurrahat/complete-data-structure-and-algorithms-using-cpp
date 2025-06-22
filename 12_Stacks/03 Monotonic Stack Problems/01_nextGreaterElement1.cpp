/**
 * @file 01_nextGreaterElement1.cpp
 * @brief Given two integer arrays nums1 and nums2 where nums1 is a subset of nums2,
 *        find the next greater element for each item in nums1 based on their position in nums2.
 *
 * Problem Statement:
 * ------------------
 * The next greater element of some element x in an array is the first greater element
 * that is to the right of x in the same array.
 *
 * You are given two distinct 0-indexed integer arrays nums1 and nums2,
 * where nums1 is a subset of nums2.
 *
 * For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j]
 * and determine the next greater element of nums2[j] in nums2.
 * If there is no next greater element, then the answer for this query is -1.
 *
 * Return an array ans of length nums1.length such that ans[i] is the next greater element.
 *
 * Constraints:
 * ------------
 * - 1 <= nums1.length <= nums2.length <= 1000
 * - 0 <= nums1[i], nums2[i] <= 10^4
 * - All integers in nums1 and nums2 are unique.
 * - All the integers of nums1 also appear in nums2.
 */

#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

/**
 * @brief Brute-force approach to find the next greater element for each value in nums1.
 *
 * For each element in nums1:
 * 1. Find its position in nums2 by linear search.
 * 2. From that position, scan to the right in nums2 to find the first greater element.
 *
 * If no greater element is found, -1 is stored.
 *
 * This is straightforward but inefficient for large inputs due to nested loops.
 *
 * @note
 * Time Complexity: O(M × N), where M = nums1.size(), N = nums2.size()
 * Space Complexity: O(1), aside from the result vector
 */
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        vector<int> ans;
        int number;
        int greaterElement;

        // ---------------------- Brute-force Checking ----------------------
        for (int i = 0; i < nums1.size(); i++)
        {
            number = nums1[i];

            // Find the matching index in nums2
            for (int j = 0; j < nums2.size(); j++)
            {

                if (number == nums2[j])
                {

                    greaterElement = -1;

                    // Search for the next greater element on the right
                    for (int k = j + 1; k < nums2.size(); k++)
                    {
                        if (nums2[k] > number)
                        {
                            greaterElement = nums2[k];
                            break; // Found the next greater, stop scanning
                        }
                    }

                    ans.push_back(greaterElement);
                }
            }
        }

        return ans;
    }
};

/**
 * @brief Optimized approach using monotonic stack and map to find next greater elements.
 *
 * Step 1: Traverse nums2 from right to left and maintain a stack to track potential next greater elements.
 *         - For each element, we pop from the stack until we find a greater one or the stack becomes empty.
 *         - Map each element in nums2 to its next greater value.
 *
 * Step 2: For each value in nums1, retrieve its next greater element directly from the map.
 *
 * This approach greatly reduces time complexity from quadratic to linear.
 *
 * @note
 * Time Complexity: O(N + M), where N = nums2.size(), M = nums1.size()
 * Space Complexity: O(N), for the hash map and the stack
 */
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        int n = nums2.size();

        // ---------------------- Preprocessing with Stack ----------------------
        unordered_map<int, int> mpp; // Maps each number to its next greater element
        mpp.reserve(n);              // Reserve space to improve performance

        stack<int> st; // Monotonic decreasing stack

        // Traverse nums2 from right to left
        for (int i = n - 1; i >= 0; i--)
        {

            // Remove all elements smaller than or equal to nums2[i]
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }

            // If stack is empty, no next greater element
            if (st.empty())
            {
                mpp[nums2[i]] = -1;
            }
            else
            {
                mpp[nums2[i]] = st.top();
            }

            // Push current number onto the stack
            st.push(nums2[i]);
        }

        // ---------------------- Constructing Result ----------------------
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++)
        {
            ans.emplace_back(mpp[nums1[i]]);
        }

        return ans;
    }
};
