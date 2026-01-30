// -----------------------------------------------------------------------------
// File Name   : 02_selectionSortHWs.cpp
// -----------------------------------------------------------------------------
// Homework Problems:
//
// 1) Selection Sort Algorithm to sort the array of integers in **decreasing order**.
//
// 2) Selection Sort Algorithm to sort the array of integers in **increasing order
//    by taking the highest number to the last place**.
//
// 3) Selection Sort Algorithm to sort the array of **char in ascending order**.
//
// -----------------------------------------------------------------------------
// Purpose of This File:
//
// Instead of creating multiple separate files for very small variations of the
// same algorithm, this file documents and discusses the **key algorithmic
// modifications** required to solve each of the above problems.
//
// The goal is to:
// - Strengthen conceptual understanding.
// - Avoid unnecessary code repetition.
// - Clearly understand *how small logical changes lead to different behaviors*.
//
// -----------------------------------------------------------------------------
// Base Reference Algorithm:
//
// Standard Selection Sort (Ascending Order):
//
// - Outer loop moves from left → right.
// - In each iteration:
//     • Find the minimum element in the unsorted portion.
//     • Place it at the current index.
//
// Core Idea:
//     "Select the minimum and move it to the front."
//
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// HW-1: Selection Sort in Decreasing Order
// -----------------------------------------------------------------------------
// Problem:
// Sort an integer array in **decreasing order** using Selection Sort.
//
// Key Modification Compared to Normal Selection Sort:
//
// Instead of selecting the **minimum element**, we select the **maximum element**
// in each iteration and place it at the **current position**.
//
// Logical Changes:
//
// 1) Comparison condition:
//      Change:
//          if (arr[j] < arr[minIndex])
//      To:
//          if (arr[j] > arr[maxIndex])
//
// 2) Conceptual shift:
//      From:
//          "Pick the smallest and move it forward"
//      To:
//          "Pick the largest and move it forward"
//
// Result:
// - Largest elements get placed first.
// - Final array becomes sorted in decreasing order.
//
// Example:
//     Input : [5, 1, 4, 2, 3]
//     Output: [5, 4, 3, 2, 1]
//
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// HW-2: Selection Sort in Increasing Order
//       by taking the highest number to the last place
// -----------------------------------------------------------------------------
// Problem:
// Sort an integer array in **increasing order**, but by selecting the **maximum
// element and placing it at the end** instead of selecting the minimum and
// placing it at the beginning.
//
// Key Observation:
//
// Standard Selection Sort builds the sorted region from **left → right**.
// This variation builds the sorted region from **right → left**.
//
// Logical Changes:
//
// 1) Outer loop direction:
//      Instead of:
//          for (i = 0 → n-2)
//      We use:
//          for (i = n-1 → 1)
//
// 2) Selection logic:
//      We select the **maximum element** in the unsorted part.
//
// 3) Swap position:
//      Place the maximum element at index `i`, which starts from the last index.
//
// Conceptual Shift:
//
//      From:
//          "Select minimum → place at front"
//
//      To:
//          "Select maximum → place at back"
//
// Result:
// - Largest elements are fixed first at the end.
// - Sorted portion grows from right to left.
// - Final order is still increasing.
//
// Example:
//     Input : [25, 18, 1, 8, 5]
//     Output: [1, 5, 8, 18, 25]
//
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// HW-3: Selection Sort for Character Array in Ascending Order
// -----------------------------------------------------------------------------
// Problem:
// Sort an array of characters in **ascending order**.
//
// Key Observation:
//
// In C++, characters are internally represented using **ASCII values**.
// Therefore, normal relational operators (<, >) automatically compare ASCII
// codes.
//
// Logical Changes Compared to Integer Sorting:
//
// 1) Data type change:
//      int arr[]  →  char arr[]
//
// 2) No change required in comparison logic:
//      if (arr[j] < arr[minIndex])
//      works perfectly for characters due to ASCII comparison.
//
// Important Note:
//
// ASCII Order Example:
//      'A' = 65
//      'Z' = 90
//      'a' = 97
//      'z' = 122
//
// So:
//      'A' < 'a'
//
// Meaning:
//      Uppercase letters will appear before lowercase letters when sorted.
//
// Example:
//     Input : ['b', 'A', 'd', 'C', 'a']
//     Output: ['A', 'C', 'a', 'b', 'd']
//
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Summary of Key Differences Across All Variations
// -----------------------------------------------------------------------------
//
// | Problem | What to Select | Where to Place | Loop Direction | Final Order |
// |-----------|----------------|----------------|----------------|--------------|
// | Normal    | Minimum        | Front          | Left → Right   | Increasing  |
// | HW-1      | Maximum        | Front          | Left → Right   | Decreasing  |
// | HW-2      | Maximum        | End            | Right → Left   | Increasing  |
// | HW-3      | Minimum        | Front          | Left → Right   | ASCII Asc.  |
//
// Core Learning Outcome:
//
// Selection Sort is not just one fixed algorithm.
// By changing only:
//   • comparison condition
//   • loop direction
//   • swap position
//
// we can derive multiple powerful variations.
//
// -----------------------------------------------------------------------------

int main()
{
    // This file is intentionally kept as a conceptual and documentation-focused
    // reference.
    //
    // Individual implementations for each homework problem are written in their
    // respective practice files.
    //
    // Purpose of this file:
    // - Concept clarity
    // - Quick revision
    // - Algorithmic understanding
    //
    return 0;
}
