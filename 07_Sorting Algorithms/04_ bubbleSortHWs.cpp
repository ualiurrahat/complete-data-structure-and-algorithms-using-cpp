// -----------------------------------------------------------------------------
// File Name   : 04_bubbleSortHWs.cpp
// Folder Path : 07_Sorting Algorithms/02 Bubble Sort
// -----------------------------------------------------------------------------
// Homework Problems:
//
// 1) Use Bubble Sort Algorithm to sort the array of integers in **decreasing order**.
//
// 2) Bubble Sort Algorithm to sort the array of integers in **increasing order
//    by taking the smallest number to the first place by starting from the last**.
//    (Question was explained in the class)
//
// 3) Bubble Sort Algorithm to sort the array of **char in ascending order**.
//
// -----------------------------------------------------------------------------
// Purpose of This File:
//
// Instead of creating multiple small files for very similar variations of
// Bubble Sort, this file contains all homework variations in a single place
// with clear documentation. The focus here is:
//   - Understanding how small logical changes affect the algorithm behavior.
//   - Strengthening conceptual clarity.
//   - Avoiding unnecessary repetition of similar code.
//
// -----------------------------------------------------------------------------
// Base Reference Algorithm:
//
// Standard Bubble Sort (Ascending Order):
//
// - In each iteration, adjacent elements are compared.
// - Larger elements gradually move toward the end.
// - After the i-th iteration, the i-th largest element is placed at the correct
//   position from the right.
//
// Core Idea:
//     "Repeatedly swap adjacent elements if they are in the wrong order,
//      so that the largest element bubbles up to the end."
//
// -----------------------------------------------------------------------------

#include <iostream>  // For standard input/output
#include <algorithm> // For std::swap

using namespace std;

// -----------------------------------------------------------------------------
// HW-1: Bubble Sort in Decreasing Order
// -----------------------------------------------------------------------------
// Problem:
// Sort an array of integers in **decreasing order** using Bubble Sort.
//
// Key Observation:
//
// In standard Bubble Sort, we swap when:
//      arr[j] > arr[j + 1]
//
// That moves larger elements toward the right (ascending order).
//
// To sort in **decreasing order**, we simply reverse the comparison condition:
//
//      arr[j] < arr[j + 1]
//
// This causes smaller elements to move toward the right and larger elements
// to move toward the left, resulting in a decreasing order.
//
// -----------------------------------------------------------------------------
void bubbleSortDecreasingOrder(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            // Reverse comparison for decreasing order
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Print iteration state
        cout << i + 1 << "th iteration: ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;

        if (swapped == false)
        {
            break;
        }
    }
}

// -----------------------------------------------------------------------------
// HW-2: Bubble Sort in Increasing Order
//       by taking the smallest number to the first place
//       by starting from the last
// -----------------------------------------------------------------------------
// Problem:
// Sort an array of integers in **increasing order**, but instead of pushing the
// largest element to the end, we push the **smallest element to the beginning**
// in each iteration.
//
// Key Conceptual Shift:
//
// Standard Bubble Sort:
//      Largest element → moves to the right (end)
//
// This Variation:
//      Smallest element → moves to the left (beginning)
//
// Core Logic:
// - Traverse the array from **right to left**.
// - Compare adjacent elements backward.
// - If arr[j] < arr[j - 1], swap them.
// - This causes the smallest element to bubble toward index 0.
//
// Sorted portion grows from **left to right**.
//
// -----------------------------------------------------------------------------
void bubbleSortMinToFront(int arr[], int n)
{
    // Traverse from right to left
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        // Move smallest element toward the front
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                swapped = true;
            }
        }

        // Print iteration state
        cout << i + 1 << "th iteration: ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;

        if (swapped == false)
        {
            break;
        }
    }
}

// -----------------------------------------------------------------------------
// HW-3: Bubble Sort for Character Array in Ascending Order
// -----------------------------------------------------------------------------
// Problem:
// Sort an array of characters in **ascending order**.
//
// Key Observation:
//
// Characters in C++ are internally represented using ASCII values.
// Therefore, direct comparison using relational operators (<, >) automatically
// compares ASCII codes.
//
// Hence, no special logic is required — standard bubble sort works directly.
//
// -----------------------------------------------------------------------------
void bubbleSortCharAscending(char arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Print iteration state
        cout << i + 1 << "th iteration: ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;

        if (swapped == false)
        {
            break;
        }
    }
}

// -----------------------------------------------------------------------------
// Main Function
//
// Demonstrates all three homework variations separately using example inputs.
//
// -----------------------------------------------------------------------------
int main()
{
    // ------------------- HW-1 Demo -------------------
    cout << "HW-1: Bubble Sort in Decreasing Order\n";
    int arr1[] = {25, 18, 1, 8, 5};
    int n1 = 5;

    cout << "Before sorting: ";
    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    bubbleSortDecreasingOrder(arr1, n1);

    cout << "After sorting:  ";
    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl
         << endl;

    // ------------------- HW-2 Demo -------------------
    cout << "HW-2: Bubble Sort (Min to Front, Increasing Order)\n";
    int arr2[] = {25, 18, 1, 8, 5};
    int n2 = 5;

    cout << "Before sorting: ";
    for (int i = 0; i < n2; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    bubbleSortMinToFront(arr2, n2);

    cout << "After sorting:  ";
    for (int i = 0; i < n2; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl
         << endl;

    // ------------------- HW-3 Demo -------------------
    cout << "HW-3: Bubble Sort for Character Array (Ascending Order)\n";
    char arr3[] = {'b', 'A', 'd', 'C', 'a'};
    int n3 = 5;

    cout << "Before sorting: ";
    for (int i = 0; i < n3; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;

    bubbleSortCharAscending(arr3, n3);

    cout << "After sorting:  ";
    for (int i = 0; i < n3; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}

// -----------------------------------------------------------------------------
// Time Complexity (All Variants):
//
// Best Case:
//   O(N) → When the array is already sorted (due to swapped flag optimization)
//
// Average Case:
//   O(N^2)
//
// Worst Case:
//   O(N^2)
//
// Space Complexity:
//   O(1) → In-place sorting
//
// -----------------------------------------------------------------------------
// Final Note:
//
// Bubble Sort is conceptually simple but inefficient for large datasets.
// However, its variations provide excellent insight into how algorithm
// behavior changes with small logical modifications.
//
// -----------------------------------------------------------------------------
