/**
 * @file 03_nextGreaterElements.cpp
 * @brief Find the next greater element for each element in a circular array.
 *
 * @problem
 * Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]),
 * return the next greater number for every element in nums.
 * The next greater number of a number x is the first greater number to its traversing-order next in the array.
 * If it doesn't exist, return -1 for this number.
 *
 * @examples
 * Input: nums = [1,2,1]
 * Output: [2,-1,2]
 *
 * Input: nums = [1,2,3,4,3]
 * Output: [2,3,4,-1,4]
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * @brief Brute force approach using nested loops and direct comparison.
 *
 * @param nums The input circular array.
 * @return vector<int> Next greater elements for each index in nums.
 *
 * @note Time Complexity: O(N^2)
 * @note Space Complexity: O(1) extra (excluding output array)
 */
vector<int> nextGreaterElementsBruteForce(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int greaterElement = -1;
        bool found = false;

        // Search in the remaining right side of the array
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i])
            {
                greaterElement = nums[j];
                found = true;
                break;
            }
        }

        // If not found, check circularly from beginning to index i-1
        if (!found)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] > nums[i])
                {
                    greaterElement = nums[j];
                    break;
                }
            }
        }

        ans.push_back(greaterElement);
    }

    return ans;
}

/**
 * @brief Brute force with single circular loop using modulo operator.
 *
 * @param nums The input circular array.
 * @return vector<int> Next greater elements for each index in nums.
 *
 * @note Time Complexity: O(N^2)
 * @note Space Complexity: O(1) extra (excluding output array)
 */
vector<int> nextGreaterElementsCircularLoop(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        bool found = false;

        // Check the next N-1 elements circularly using modulo
        for (int j = i + 1; j < i + n; j++)
        {
            int index = j % n;
            if (nums[index] > nums[i])
            {
                ans.push_back(nums[index]);
                found = true;
                break;
            }
        }

        if (!found)
        {
            ans.push_back(-1);
        }
    }

    return ans;
}

/**
 * @brief Optimized approach using monotonic stack.
 *
 * @param nums The input circular array.
 * @return vector<int> Next greater elements for each index in nums.
 *
 * @note Time Complexity: O(N)
 * @note Space Complexity: O(N) for stack and output
 */
vector<int> nextGreaterElementsOptimized(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    stack<int> st; // Monotonic stack to keep track of next greater elements

    // Traverse the array twice (simulate circular array)
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int current = nums[i % n];

        // Maintain stack in decreasing order
        while (!st.empty() && st.top() <= current)
        {
            st.pop();
        }

        // Push result only for the first pass
        if (i < n)
        {
            int nextGreater = st.empty() ? -1 : st.top();
            ans.push_back(nextGreater);
        }

        // Push current element onto the stack
        st.push(current);
    }

    // Reverse the result as we filled it in reverse order
    reverse(ans.begin(), ans.end());
    return ans;
}

/**
 * @brief Utility function to print vector content.
 *
 * @param vec A vector of integers.
 */
void printVector(const vector<int> &vec)
{
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;
}

/**
 * @brief Main function to run examples.
 */
int main()
{
    vector<int> example1 = {1, 2, 1};
    vector<int> example2 = {1, 2, 3, 4, 3};

    cout << "Input: [1, 2, 1]" << endl;
    cout << "Brute Force: ";
    printVector(nextGreaterElementsBruteForce(example1));

    cout << "Circular Loop: ";
    printVector(nextGreaterElementsCircularLoop(example1));

    cout << "Optimized Stack: ";
    printVector(nextGreaterElementsOptimized(example1));

    cout << "\nInput: [1, 2, 3, 4, 3]" << endl;
    cout << "Brute Force: ";
    printVector(nextGreaterElementsBruteForce(example2));

    cout << "Circular Loop: ";
    printVector(nextGreaterElementsCircularLoop(example2));

    cout << "Optimized Stack: ";
    printVector(nextGreaterElementsOptimized(example2));

    return 0;
}
