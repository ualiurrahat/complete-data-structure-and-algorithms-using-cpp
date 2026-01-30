// -----------------------------------------------------------------------------
// File Name   : 01_selectionSort.cpp
// -----------------------------------------------------------------------------
// Problem Statement:
// Implement the Selection Sort algorithm to sort an array of integers in
// ascending order. Additionally, print the state of the array after each
// iteration (i.e., after each selection and possible swap) to clearly visualize
// how the algorithm gradually sorts the array.
//
// The implementation should be:
// 1. Easy to understand for beginners.
// 2. Detailed enough for intermediate learners.
// 3. Professionally documented for advanced learners and IT professionals.
//
// -----------------------------------------------------------------------------
// Theoretical Background:
//
// Selection Sort is a simple, comparison-based sorting algorithm. The idea is
// to divide the array into two conceptual parts:
//
//   1. A sorted subarray at the beginning.
//   2. An unsorted subarray containing the remaining elements.
//
// At each iteration:
//   - We select the minimum element from the unsorted subarray.
//   - Swap it with the first element of the unsorted subarray.
//   - This effectively grows the sorted subarray by one element.
//
// The process continues until the entire array becomes sorted.
//
// Key Characteristics:
// - In-place algorithm: Requires no extra memory (O(1) auxiliary space).
// - Not stable by default: Relative order of equal elements may change.
// - Always performs O(N^2) comparisons regardless of input order.
//
// -----------------------------------------------------------------------------
// Time Complexity Discussion:
//
// Let N be the number of elements.
//
// 1. Best Case Scenario:
//    - Array is already sorted in ascending order.
//    - Even in this case, the algorithm still scans the remaining unsorted
//      part to find the minimum element.
//    - Comparisons:
//          (N-1) + (N-2) + ... + 1 = N(N-1)/2
//    - Time Complexity: O(N^2)
//
//    Example Array:
//        [1, 2, 3, 4, 5]
//
// 2. Worst Case Scenario:
//    - Array is sorted in descending order.
//    - In every iteration, the minimum element is at the far end of the
//      unsorted portion, causing a swap each time.
//    - Comparisons remain the same as best case.
//    - Time Complexity: O(N^2)
//
//    Example Array:
//        [5, 4, 3, 2, 1]
//
// 3. Average Case Scenario:
//    - Random arrangement of elements.
//    - Still performs the same number of comparisons.
//    - Time Complexity: O(N^2)
//
//    Example Array:
//        [25, 18, 1, 8, 5]
//
// Important Observation:
// - Unlike algorithms like Bubble Sort, Selection Sort does NOT optimize for
//   already sorted data.
// - The number of comparisons remains fixed regardless of input order.
//
// -----------------------------------------------------------------------------
// Space Complexity:
//
// - O(1), because sorting is performed in-place using only a few extra
//   variables.
//
// -----------------------------------------------------------------------------

#include <iostream>  // For standard input/output
#include <algorithm> // For std::swap

using namespace std;

// -----------------------------------------------------------------------------
// Function: selectionSort
//
// Purpose:
// Sorts the given integer array in ascending order using the Selection Sort
// algorithm. Also prints the array after each iteration to demonstrate the
// intermediate steps.
//
// Parameters:
// - arr[] : Integer array to be sorted.
// - n      : Number of elements in the array.
//
// Detailed Step-by-Step Logic:
// 1. Iterate from index 0 to n-2.
// 2. Assume the current index contains the minimum element.
// 3. Traverse the remaining unsorted portion of the array to find the actual
//    minimum.
// 4. If a smaller element is found, update the minimum index.
// 5. After the inner loop, swap the current index element with the found
//    minimum element (if required).
// 6. Print the array state after each iteration.
//
// -----------------------------------------------------------------------------
void selectionSort(int arr[], int n)
{
    // Traverse through all elements except the last one,
    // because the last element will automatically be sorted.
    for (int i = 0; i < n - 1; i++)
    {
        // Assume the first element of the unsorted part is the minimum.
        int minIndex = i;

        // Find the index of the minimum element in the remaining unsorted part.
        for (int j = i + 1; j < n; j++)
        {
            // If a smaller element is found, update minIndex.
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap only if a smaller element was actually found.
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }

        // Print the state of the array after each iteration.
        cout << i << "th iteration: ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

// -----------------------------------------------------------------------------
// Main Function
//
// Demonstrates:
// - Input of array size.
// - Input of array elements.
// - Printing the original array.
// - Sorting using Selection Sort.
// - Printing intermediate states.
// - Printing the final sorted array.
//
// -----------------------------------------------------------------------------
int main()
{
    int size;

    // Input array size.
    cout << "Enter array size: ";
    cin >> size;

    // Dynamic array declaration (stack-based for simplicity).
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

    // Perform selection sort.
    selectionSort(arr, size);

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
// Selection Sort repeatedly selects the smallest element from the unsorted
// portion and moves it to its correct position. Although it is easy to
// understand and implement, its O(N^2) time complexity makes it inefficient
// for large datasets. However, due to its simplicity and deterministic behavior,
// it is widely used for educational purposes and for small data sizes.
//
// -----------------------------------------------------------------------------
