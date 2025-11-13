/*
============================================================================
   FILE: 08_linearSearch.cpp
   TOPIC: Linear Search in an Array
============================================================================

🧠 PROBLEM STATEMENT:
----------------------
Find if a given number exists in an array or not.
If it exists, return its index; otherwise, return -1.

Example 1:
-----------
Input:  a[] = [18, 1, 8, 5, 20], num = 5
Output: 3   (index of 5)

Example 2:
-----------
Input:  b[] = [20, 1, 13, 1, 14, 14, 1], num = 18
Output: -1  (18 does not exist)

============================================================================
*/

#include <iostream>
using namespace std;

// ---------------------- Function Definition ----------------------

/**
 * @brief Performs a linear search on the given array to find a specific number.
 *
 * @param arr The array in which to search.
 * @param n The size of the array.
 * @param num The number to search for.
 * @return int Index of the number if found, otherwise -1.
 *
 * 🧩 Approach:
 * 1️⃣ Traverse the array from start to end.
 * 2️⃣ Compare each element with the target number.
 * 3️⃣ If a match is found, return the index immediately.
 * 4️⃣ If the loop ends without a match, return -1.
 *
 * 🕒 Time Complexity: O(N)
 * 🧠 Space Complexity: O(1)
 */
int linearSearch(int arr[], int n, int num)
{
    // Traverse the array linearly
    for (int i = 0; i < n; i++)
    {
        // Check if the current element matches the target
        if (arr[i] == num)
        {
            // Return the index of the matched element
            return i;
        }
    }

    // If number is not found, return -1
    return -1;
}

// ---------------------- Main Function ----------------------

int main()
{
    int n; // size of array

    // Taking array size from user
    cout << "Enter array size: ";
    cin >> n;

    int arr[n]; // Constructing array with size n

    // Taking array elements as input
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int num; // Number to search
    cout << "Enter the number you want to search: ";
    cin >> num;

    // Call linear search function and display result
    int result = linearSearch(arr, n, num);
    cout << result << endl;

    return 0;
}
