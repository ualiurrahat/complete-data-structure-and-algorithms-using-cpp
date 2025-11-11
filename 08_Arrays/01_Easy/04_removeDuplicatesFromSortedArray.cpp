/*
============================================================================
   FILE: 04_removeDuplicatesFromSortedArray.cpp
   TOPIC: Remove Duplicates from Sorted Array
============================================================================

🧠 PROBLEM STATEMENT:
----------------------
Remove the duplicates from a sorted array such that each element appears once.
Return the size of the new array.

Example:
---------
Input:  arr[] = [1, 2, 2, 2, 3]
Output: new array = [1, 2, 3]
Answer = 3

============================================================================
*/

#include <iostream>
#include <set>
using namespace std;

// ------------------------------------------------------------
// 🧩 Brute Force Technique
// ------------------------------------------------------------
// Idea:
// 1️⃣ Use a set container (since it stores only unique elements).
// 2️⃣ Insert all elements of the array into the set (duplicates auto-removed).
// 3️⃣ Return the size of the set (this equals the number of unique elements).
//
// 🔹 Time Complexity:  O(n * log n)
//    → O(n) for traversing + O(log n) for each insertion in set
// 🔹 Space Complexity: O(n), for storing elements in the set
// ------------------------------------------------------------
int removeDuplicatesFromSortedArrayBrute(int arr[], int n)
{
    set<int> s; // Set to store unique elements

    // Traverse the array and insert elements into the set
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]); // Each insertion takes O(log n)
    }

    // Return the number of unique elements
    return s.size();
}

// ------------------------------------------------------------
// ⚙️ Optimal Technique — Two Pointer Approach
// ------------------------------------------------------------
// Idea:
// 1️⃣ Use two pointers (i and j).
// 2️⃣ Compare element at second pointer (j) with the first pointer (i).
// 3️⃣ If they are different → place arr[j] at arr[i + 1] (next unique position).
// 4️⃣ Move the first pointer (i) one step ahead.
// 5️⃣ Continue until end of array, then return (i + 1) as new array size.
//
// 🔹 Time Complexity:  O(n) — single traversal
// 🔹 Space Complexity: O(1) — in-place modification
// ------------------------------------------------------------
int removeDuplicatesFromSortedArrayOptimal(int arr[], int n)
{
    int i = 0; // Pointer for last unique element found

    // Start second pointer from index 1
    for (int j = 1; j < n; j++)
    {
        // If a new unique element is found
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j]; // Place it next to the last unique element
            i++;                 // Move the unique pointer
        }
    }

    // The total count of unique elements is (i + 1)
    return i + 1;
}

// ------------------------------------------------------------
// 🧪 Main Function — Driver Code
// ------------------------------------------------------------
int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    // Constructing array with size n
    int arr[n];

    // Input array elements
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Uncomment below line to test brute force method
    // cout << removeDuplicatesFromSortedArrayBrute(arr, n) << endl;

    // Testing optimal method
    cout << "Unique element count: " << removeDuplicatesFromSortedArrayOptimal(arr, n) << endl;

    return 0;
}
