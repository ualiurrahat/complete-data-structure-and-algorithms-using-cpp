/**
 * @file 16_allIndicesRecursion.cpp
 * @brief Find all indices of a given number in an array using recursion.
 *
 * @problem_statement
 * You are given an integer array `a[]` of size `n`, and a target number `k`.
 * You need to find all indices where `k` occurs in the array using recursion.
 *
 * The function should also return the count of occurrences.
 *
 * Example:
 * ----------
 * Input:
 *     a[] = {5, 6, 5, 5, 6}, n = 5, k = 5
 * Output:
 *     Indices = {0, 2, 3}
 *     Count = 3
 *
 * @approach
 * - Use recursion to process one element at a time.
 * - Base case: if array size becomes 0, return 0.
 * - Recursive case:
 *     1. Recursively find indices in the subarray (a + 1, size - 1).
 *     2. Increment each index in the output array by 1 (since we shifted the array).
 *     3. If the first element (a[0]) equals k, insert 0 at the beginning.
 * - Return the total count of found indices.
 *
 */

#include <iostream>
using namespace std;

/**
 * @brief Recursively finds all indices of 'k' in the array 'a'.
 *
 * @param a Pointer to the array.
 * @param size Current size of the array.
 * @param k The target value to find.
 * @param output Array to store the found indices.
 * @return int The count of occurrences of 'k'.
 *
 * @note
 * Time Complexity: O(3n) → recursion + index shifting + updates
 * Space Complexity: O(n) → recursion stack + output array
 */
int allIndices(int a[], int size, int k, int output[])
{
    // ---------------------- Base Case ----------------------
    // If array becomes empty, there are no occurrences
    if (size == 0)
        return 0;

    // ---------------------- Recursive Call ----------------------
    // Process the rest of the array excluding the first element
    int smallOutputSize = allIndices(a + 1, size - 1, k, output);

    // ---------------------- Small Calculation ----------------------
    // Increment each stored index by 1 because of array shifting
    for (int i = 0; i < smallOutputSize; i++)
    {
        output[i] = output[i] + 1;
    }

    // If the current element matches 'k', insert 0 at the start of output[]
    if (a[0] == k)
    {
        // Shift all elements to the right
        for (int i = smallOutputSize - 1; i >= 0; i--)
        {
            output[i + 1] = output[i];
        }
        // Insert current index (0)
        output[0] = 0;

        // Return incremented size
        return smallOutputSize + 1;
    }

    // If no match, return size from recursive call
    return smallOutputSize;
}

/**
 * @brief Driver function to demonstrate the recursion.
 */
int main()
{
    int a[] = {5, 6, 5, 5, 6};
    int size = 5;
    int k = 5;

    // Output array to store indices
    int output[100]; // large enough buffer for demo

    // Function call
    int count = allIndices(a, size, k, output);

    // Display results
    cout << "Indices of " << k << " are: ";
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;

    cout << "Total occurrences: " << count << endl;

    /**
     * Expected Output:
     * -----------------
     * Indices of 5 are: 0 2 3
     * Total occurrences: 3
     */
    return 0;
}
