/*
============================================================================
   FILE: 01_largentElementInArray.cpp
   TOPIC: Find the Largest Element in an Array
============================================================================

🧠 PROBLEM STATEMENT:
---------------------
Given an array of integers, find and return the largest element.

Example:
---------
Input:  a[] = {18, 1, 8, 5, 20, 13}
Output: 20

============================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm> // For sort()
using namespace std;

// ---------------------- Brute Force Solution ----------------------
/**
 * @brief Finds the largest element in an array using sorting.
 *
 * 🕒 Time Complexity: O(N log N)
 * 💾 Space Complexity: O(1)
 *
 * @param a Vector of integers representing the array.
 * @param n Size of the array.
 * @return int The largest element in the array.
 */
int findLargestElementBrute(vector<int> &a, int n)
{
    // sort the array first
    sort(a.begin(), a.end());

    // return the last element
    return a[a.size() - 1];
}

// ---------------------- Optimal Solution ----------------------
/**
 * @brief Finds the largest element in an array using a single traversal.
 *
 * 🕒 Time Complexity: O(N)
 * 💾 Space Complexity: O(1)
 *
 * @param a Vector of integers representing the array.
 * @param n Size of the array.
 * @return int The largest element in the array.
 */
int findLargestElementOptimal(vector<int> &a, int n)
{
    // take first element as the largest one
    int largest = a[0];

    // traverse the whole array
    for (int i = 1; i < n; i++)
    {
        // compare each element with largest
        // if current element is greater than largest,
        // update the largest
        if (a[i] > largest)
        {
            largest = a[i];
        }
    }
    return largest;
}

// ---------------------- Main Function ----------------------
int main()
{
    int n;
    cout << "Enter total no. of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Display results using both approaches
    cout << "Largest element (Brute Force): " << findLargestElementBrute(arr, n) << endl;
    cout << "Largest element (Optimal): " << findLargestElementOptimal(arr, n) << endl;

    return 0;
}

/*
============================================================================
✅ SAMPLE INPUT:
Enter total no. of elements: 6
Enter elements: 18 1 8 5 20 13

✅ EXPECTED OUTPUT:
Largest element (Brute Force): 20
Largest element (Optimal): 20
============================================================================
*/
