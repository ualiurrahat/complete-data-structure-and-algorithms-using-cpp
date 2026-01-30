// -----------------------------------------------------------------------------
// File Name   : 03_bubbleSort.cpp
// Folder Path : 07_Sorting Algorithms/02 Bubble Sort
// -----------------------------------------------------------------------------
// Problem Statement:
//
// Implement the Bubble Sort algorithm to sort an array of integers in ascending
// order. Additionally, analyze and document its behavior in best, average, and
// worst case scenarios.
//
// The implementation should be:
// 1. Beginner-friendly.
// 2. Conceptually clear for intermediate learners.
// 3. Professionally documented for advanced learners and IT professionals.
//
// -----------------------------------------------------------------------------
// Theoretical Background:
//
// Bubble Sort is a simple, comparison-based sorting algorithm. The idea is to
// repeatedly step through the list, compare adjacent elements, and swap them if
// they are in the wrong order.
//
// In each iteration:
// - The largest unsorted element "bubbles up" to its correct position at the
//   end of the array.
// - Therefore, after the i-th iteration, the last i elements are guaranteed to
//   be sorted.
//
// This process continues until:
// - The entire array is sorted, or
// - No swaps occur in an iteration, indicating that the array is already sorted.
//
// Key Characteristics:
// - In-place algorithm: Requires no extra memory (O(1) auxiliary space).
// - Stable sorting algorithm: Preserves the relative order of equal elements.
// - Adaptive algorithm: Can terminate early if the array is already sorted.
//
// -----------------------------------------------------------------------------
// Time Complexity Discussion:
//
// Let N be the number of elements.
//
// 1. Best Case Scenario:
//    - Array is already sorted in ascending order.
//    - No swaps occur during the first iteration.
//    - Due to the swapped-flag optimization, the algorithm stops immediately.
//    - Time Complexity: O(N)
//
//    Example Array:
//        [1, 2, 3, 4, 5]
//
// 2. Worst Case Scenario:
//    - Array is sorted in descending order.
//    - Every comparison leads to a swap.
//    - Total comparisons:
//          (N-1) + (N-2) + ... + 1 = N(N-1)/2
//    - Time Complexity: O(N^2)
//
//    Example Array:
//        [5, 4, 3, 2, 1]
//
// 3. Average Case Scenario:
//    - Random arrangement of elements.
//    - Roughly half of the comparisons result in swaps.
//    - Time Complexity: O(N^2)
//
//    Example Array:
//        [25, 18, 1, 8, 5]
//
// Important Observation:
// - Bubble Sort is inefficient for large datasets.
// - However, due to its simplicity and adaptive nature, it is useful for
//   educational purposes and small datasets.
//
// -----------------------------------------------------------------------------
// Space Complexity:
//
// - O(1), because sorting is done in-place.
//
// -----------------------------------------------------------------------------

#include <iostream>  // For standard input/output
#include <algorithm> // For std::swap

using namespace std;

// -----------------------------------------------------------------------------
// Function: bubbleSort
//
// Purpose:
// Sorts the given integer array in ascending order using the Bubble Sort
// algorithm.
//
// Parameters:
// - arr[] : Integer array to be sorted.
// - n      : Number of elements in the array.
//
// Detailed Step-by-Step Logic:
// 1. Traverse the array multiple times.
// 2. Compare each pair of adjacent elements.
// 3. Swap them if they are in the wrong order.
// 4. After each iteration, the largest element of the unsorted part moves to
//    its correct position at the end.
// 5. Use a swapped flag to detect if no swaps occurred, allowing early
//    termination.
//
// -----------------------------------------------------------------------------
void bubbleSort(int arr[], int n)
{
    // Traverse through all elements except the last one,
    // because the last element will automatically be sorted.
    for (int i = 0; i < n - 1; i++)
    {
        // Flag to detect if any swapping happened in this iteration.
        bool swapped = false;

        // Compare adjacent elements and push the largest element to the end.
        for (int j = 0; j < n - i - 1; j++)
        {
            // If elements are in the wrong order, swap them.
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swaps occurred, the array is already sorted.
        if (swapped == false)
        {
            break;
        }
    }
}

// -----------------------------------------------------------------------------
// Main Function
//
// Demonstrates:
// - Input of array size.
// - Input of array elements.
// - Printing the original array.
// - Sorting using Bubble Sort.
// - Printing the final sorted array.
//
// -----------------------------------------------------------------------------
int main()
{
    int size;

    // Input array size.
    cout << "Enter array size: ";
    cin >> size;

    int arr[size];

    // Input array elements.
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Print the original array.
    cout << "Before sorting: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform bubble sort.
    bubbleSort(arr, size);

    // Print the sorted array.
    cout << "After sorting: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// -----------------------------------------------------------------------------
// Summary:
//
// Bubble Sort repeatedly compares adjacent elements and swaps them if they are
// in the wrong order. With each pass, the largest unsorted element moves to its
// correct position, hence the term "bubble". While simple and intuitive, its
// O(N^2) time complexity makes it unsuitable for large datasets. However, its
// adaptive nature allows it to perform efficiently for nearly sorted arrays.
//
// -----------------------------------------------------------------------------
