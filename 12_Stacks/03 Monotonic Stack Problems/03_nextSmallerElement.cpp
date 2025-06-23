/**
 * @file 04_nextSmallerElement.cpp
 * @brief Find the next smaller element for each element in the array.
 *
 * @problem
 * You are given an array 'arr' of integers of length N. Your task is to find the next smaller
 * element for each of the array elements.
 *
 * The Next Smaller Element for an array element is the first element to the right of that element
 * which has a value strictly smaller than that element.
 *
 * If for any array element the next smaller element does not exist, return -1 for that element.
 *
 * @example
 * Input: [2, 3, 1]
 * Output: [1, 1, -1]
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * @brief Brute force approach to find the next smaller element.
 *
 * @param arr Input array of integers.
 * @param n Length of the array.
 * @return vector<int> Vector containing next smaller elements for each index.
 *
 * @note Time Complexity: O(N^2)
 * @note Space Complexity: O(1) extra (excluding output array)
 */
vector<int> nextSmallerElementBruteForce(const vector<int> &arr, int n)
{
    vector<int> ans(n, -1); // Initialize all elements as -1

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // If a smaller element is found to the right and no answer has been assigned yet
            if (arr[j] < arr[i] && ans[i] == -1)
            {
                ans[i] = arr[j];
                break; // We need only the first smaller to the right
            }
        }
    }

    return ans;
}

/**
 * @brief Optimized approach using monotonic stack.
 *
 * @param arr Input array of integers.
 * @param n Length of the array.
 * @return vector<int> Vector containing next smaller elements for each index.
 *
 * @note Time Complexity: O(N)
 * @note Space Complexity: O(N) for stack and output
 */
vector<int> nextSmallerElementOptimized(const vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> s;

    // Initialize stack with a sentinel value
    s.push(-1);

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        // Remove elements from the stack that are not smaller than current
        while (!s.empty() && s.top() >= curr)
        {
            s.pop();
        }

        // Top of stack is the next smaller element
        ans[i] = s.top();

        // Push current element for future comparisons
        s.push(curr);
    }

    return ans;
}

/**
 * @brief Utility function to print the contents of a vector.
 *
 * @param vec The vector to be printed.
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
 * @brief Main function to run examples of next smaller element solutions.
 */
int main()
{
    vector<int> arr = {2, 3, 1};

    cout << "Input: ";
    printVector(arr);

    // Brute Force Approach
    vector<int> result1 = nextSmallerElementBruteForce(arr, arr.size());
    cout << "Brute Force Result: ";
    printVector(result1);

    // Optimized Stack-Based Approach
    vector<int> result2 = nextSmallerElementOptimized(arr, arr.size());
    cout << "Optimized Stack Result: ";
    printVector(result2);

    return 0;
}
