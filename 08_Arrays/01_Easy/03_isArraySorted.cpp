/*
============================================================================
   FILE: 03_isArraySorted.cpp
   TOPIC: Check if an Array is Sorted in Non-Decreasing Order
============================================================================

🧠 PROBLEM STATEMENT:
---------------------
Write a function to check if an array is sorted in non-decreasing order.
Return 1 if the array is sorted, else return 0.

Example:
---------
a[] = [18, 1, 8, 5, 20]  → Output = 0
b[] = [1, 5, 7, 9, 11]   → Output = 1

============================================================================
*/

#include <iostream>
using namespace std;

// ---------------------- Function Definition ----------------------
/**
 * @brief Checks whether the given array is sorted in non-decreasing order.
 *
 * @param arr Input array.
 * @param n   Size of the array.
 * @return int Returns 1 if the array is sorted, else returns 0.
 *
 * 🕒 Time Complexity: O(N)
 * 💾 Space Complexity: O(1)
 */
int isArraySorted(int arr[], int n)
{
    // traversing array from first element to before last element
    for (int i = 0; i < n - 1; i++)
    {
        // for non-decreasing order, (i+1)th element has to be
        // greater than or equal to ith element
        if (arr[i + 1] >= arr[i])
        {
            // sorting condition fulfilled
            // go to next element
            continue;
        }
        else
        {
            // condition not fulfilled. array not sorted.
            return 0;
        }
    }

    // all elements are in sorted order. return 1
    return 1;
}

// ---------------------- Main Function ----------------------
int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    // constructing array with size n
    int arr[n];

    // inserting elements
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // print result (1 for sorted, 0 for not sorted)
    cout << isArraySorted(arr, n) << endl;

    return 0;
}

/*
============================================================================
✅ SAMPLE INPUT 1:
Enter array size: 5
Enter array elements: 18 1 8 5 20

✅ EXPECTED OUTPUT 1:
0

✅ SAMPLE INPUT 2:
Enter array size: 5
Enter array elements: 1 5 7 9 11

✅ EXPECTED OUTPUT 2:
1
============================================================================
*/
