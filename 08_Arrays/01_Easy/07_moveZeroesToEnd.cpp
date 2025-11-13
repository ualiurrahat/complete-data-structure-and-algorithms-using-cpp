/*
============================================================================
   FILE: 07_moveZeroesToEnd.cpp
   TOPIC: Move All Zeroes of an Array to the End
============================================================================

🧠 PROBLEM STATEMENT:
----------------------
Move all zeroes of an array to the end while maintaining the relative order
of the non-zero elements.

Example:
---------
Input:  a[] = [1,2,0,0,3,17,0,0,9]
Output: a[] = [1,2,3,17,9,0,0,0,0]

============================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

// ---------------------- Brute Force Approach ----------------------

/**
 * @brief Moves all zeroes to the end of the array using extra space.
 *
 * @param arr Input array (vector reference).
 *
 * 🧩 Approach:
 * 1️⃣ Copy all non-zero elements into a temporary array.
 * 2️⃣ Insert those elements back into the original array from the start.
 * 3️⃣ Fill the remaining positions with zeroes.
 *
 * 🕒 Time Complexity: O(N)
 * 🧠 Space Complexity: O(N)
 */
void moveZeroesToEndBrute(vector<int> &arr)
{
    int n = arr.size();

    // Step 1: Copy non-zero elements into temp
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }

    // Step 2: Copy temp elements back to arr
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }

    // Step 3: Fill the rest of arr with zeroes
    for (int i = temp.size(); i < n; i++)
    {
        arr[i] = 0;
    }
}

// ---------------------- Optimal Approach ----------------------

/**
 * @brief Moves all zeroes to the end of the array in-place (O(1) extra space).
 *
 * @param arr Input array (vector reference).
 *
 * 🧩 Approach:
 * 1️⃣ Find the first zero index.
 * 2️⃣ Traverse the array; whenever a non-zero is found, swap it with the stored zero index.
 * 3️⃣ Increment the zero index each time after swapping.
 *
 * 🕒 Time Complexity: O(N)
 * 🧠 Space Complexity: O(1)
 */
void moveZerosToEndOptimal(vector<int> &arr)
{
    int n = arr.size();
    int index = -1; // To store the first index of zero

    // Step 1: Find the first zero index
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            index = i;
            break;
        }
    }

    // If no zero is found, array is already in correct form
    if (index == -1)
        return;

    // Step 2: Traverse and swap non-zero elements with the first available zero
    for (int i = index + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[index]);
            index++;
        }
    }
}

// ---------------------- Main Function ----------------------

int main()
{
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call either brute or optimal approach
    // moveZeroesToEndBrute(arr);
    moveZerosToEndOptimal(arr);

    cout << "Array after moving zeroes: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
