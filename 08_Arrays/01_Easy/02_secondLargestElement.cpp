/*
============================================================================
   FILE: 02_secondLargestElement.cpp
   TOPIC: Find the Second Largest Element in an Array
============================================================================

🧠 PROBLEM STATEMENT:
---------------------
Given an array of integers, find and return the second largest element.

Example:
---------
Input:  a[] = {12, 35, 1, 10, 34, 1}
Output: 34

============================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm> // For sort()
#include <climits>   // For INT_MIN
using namespace std;

// ---------------------- Brute Force Approach ----------------------
/**
 * @brief Finds the second largest element using sorting.
 *
 * 🕒 Time Complexity: O(N log N)
 * 💾 Space Complexity: O(1)
 *
 * @param a Vector of integers representing the array.
 * @param n Size of the array.
 * @return int The second largest element (or -1 if not found).
 */
int secondLargestBrute(vector<int> &a, int n)
{
    // to store the second largest element
    // initial value -1, in case second largest does not exist in the array
    int ans = -1;

    // sort the array: O(nlogn)
    sort(a.begin(), a.end());

    // now traverse the sorted array in reverse order
    // return the second largest element
    int largest = a[n - 1];

    // O(n)
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < largest)
        {
            ans = a[i];
            break;
        }
    }
    return ans;
}

// ---------------------- Better Approach ----------------------
/**
 * @brief Finds the second largest element using two passes (two traversals).
 *
 * 🕒 Time Complexity: O(2N)
 * 💾 Space Complexity: O(1)
 *
 * @param a Vector of integers representing the array.
 * @param n Size of the array.
 * @return int The second largest element.
 */
int secondLargestBetter(vector<int> &a, int n)
{
    // take -1 as initial answer if all given inputs are +ve,
    // or INT_MIN for +ve,-ve numbers as input
    int secondLargest = INT_MIN;

    // first parse: find the largest element: O(n)
    int largest = a[0];
    for (int i = 1; i < n; i++)
    {
        if (largest < a[i])
        {
            largest = a[i];
        }
    }

    // second parse: find second largest now.
    // O(n)
    for (int i = 0; i < n; i++)
    {
        if (a[i] > secondLargest && a[i] < largest)
        {
            secondLargest = a[i];
        }
    }
    return secondLargest;
}

// ---------------------- Optimal Approach ----------------------
/**
 * @brief Finds the second largest element using a single traversal.
 *
 * 🕒 Time Complexity: O(N)
 * 💾 Space Complexity: O(1)
 *
 * @param a Vector of integers representing the array.
 * @param n Size of the array.
 * @return int The second largest element.
 */
int secondLargestBest(vector<int> &a, int n)
{
    int largest = a[0];

    // take -1 as initial answer if all given inputs are +ve,
    // or INT_MIN for +ve,-ve numbers as input
    int secondLargest = INT_MIN;

    // traverse the array
    for (int i = 1; i < n; i++)
    {
        // if a[i] > largest, set secondLargest to largest
        // update largest to a[i]
        if (a[i] > largest)
        {
            secondLargest = largest;
            largest = a[i];
        }
        // a[i] > secondLargest but not than largest,
        // update the secondLargest
        else if (a[i] < largest && a[i] > secondLargest)
        {
            secondLargest = a[i];
        }
    }
    return secondLargest;
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

    // You can test all three methods as shown below:
    // cout << "Second largest element (Brute): " << secondLargestBrute(arr, n) << endl;
    // cout << "Second largest element (Better): " << secondLargestBetter(arr, n) << endl;
    cout << "Second largest element (Optimal): " << secondLargestBest(arr, n) << endl;

    return 0;
}

/*
============================================================================
✅ SAMPLE INPUT:
Enter total no. of elements: 6
Enter elements: 12 35 1 10 34 1

✅ EXPECTED OUTPUT:
Second largest element (Optimal): 34
============================================================================
*/
