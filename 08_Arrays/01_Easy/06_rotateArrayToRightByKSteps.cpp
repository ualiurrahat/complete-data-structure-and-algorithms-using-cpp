/*
============================================================================
   FILE: 06_rotateArrayToRightByKSteps.cpp
   TOPIC: Rotate an Array to the Right by K Steps
============================================================================

🧠 PROBLEM STATEMENT:
----------------------
Rotate an array to the right by k steps.

Example:
---------
Input:  a[] = [1,2,3,4,5,6,7], k = 3
Output: a[] = [5,6,7,1,2,3,4]

Explanation:
-------------
rotate 1 step -> [7,1,2,3,4,5,6]
rotate 2 steps -> [6,7,1,2,3,4,5]
rotate 3 steps -> [5,6,7,1,2,3,4]

============================================================================
*/

#include <iostream>
using namespace std;

// ---------------------- Brute Force Approach ----------------------

/**
 * @brief Rotates the given array to the right by k positions.
 *
 * @param arr The input array.
 * @param n The size of the array.
 * @param k Number of times to rotate the array to the right.
 *
 * 🧩 Approach:
 * 1️⃣ Normalize k using k = k % n.
 * 2️⃣ Copy first (n - k) elements into a temporary array.
 * 3️⃣ Right shift remaining k elements to the front.
 * 4️⃣ Copy back the temporary array elements to the remaining positions.
 *
 * 🕒 Time Complexity: O(N)
 * 🧠 Space Complexity: O(N)
 */
void rotateArrayToRightKtimes(int arr[], int n, int k)
{
    // Recheck the value of k (normalize to array size)
    k = k % n;

    // Temporary array to store first (n - k) elements
    int temp[n - k];

    // Step 1: Store first n - k elements of arr in temp
    for (int i = 0; i < n - k; i++)
    {
        temp[i] = arr[i];
    }

    // Step 2: Right shift the last k elements to the front
    for (int i = 0; i < k; i++)
    {
        arr[i] = arr[n - k + i];
    }

    // Step 3: Copy elements from temp back into arr
    for (int i = k; i < n; i++)
    {
        arr[i] = temp[i - k];
    }
}

// ---------------------- Main Function ----------------------

int main()
{
    int n; // size of array

    cout << "Enter array size: ";
    cin >> n;

    int arr[n]; // constructing array with size n

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cout << "Enter how many elements to right shift: ";
    cin >> k;

    // Rotate the array
    rotateArrayToRightKtimes(arr, n, k);

    cout << "Array after rotation: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
