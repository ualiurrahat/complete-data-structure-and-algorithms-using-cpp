#include <iostream>  // For input-output operations (cin, cout)
#include <vector>    // For using vector container
#include <algorithm> // For sort() function
#include <climits>   // For INT_MIN constant
using namespace std;

/*
============================================================================
PROBLEM:
Find the SECOND LARGEST DISTINCT element in an array.

IMPORTANT POINTS:
1. Duplicate values may exist.
2. Second largest must be STRICTLY smaller than the largest.
3. If no such element exists, return -1.
============================================================================
*/

// ---------------------- BRUTE FORCE APPROACH ----------------------
/*
APPROACH EXPLANATION:
1. Sort the array.
2. The last element will be the largest.
3. Traverse backwards to find the first element
   which is strictly smaller than the largest.

WHY IT WORKS:
- Sorting places elements in order.
- Reverse traversal avoids duplicates.

TIME COMPLEXITY: O(N log N)
SPACE COMPLEXITY: O(1)
*/
int secondLargestBrute(vector<int> &a, int n)
{
    // If array has fewer than 2 elements,
    // second largest cannot exist
    if (n < 2)
        return -1;

    // Sort the array in ascending order
    sort(a.begin(), a.end());

    // Store the largest element (last element after sorting)
    int largest = a[n - 1];

    // Traverse from second last index to the beginning
    for (int i = n - 2; i >= 0; i--)
    {
        // As soon as we find a value strictly smaller than largest,
        // that value is the second largest
        if (a[i] < largest)
        {
            return a[i];
        }
    }

    // If no smaller element is found,
    // second largest does not exist
    return -1;
}

// ---------------------- BETTER APPROACH (TWO PASSES) ----------------------
/*
APPROACH EXPLANATION:
1. First traversal finds the largest element.
2. Second traversal finds the largest element
   that is strictly smaller than the largest.

WHY TWO PASSES:
- Keeps logic simple and readable.
- Avoids sorting overhead.

TIME COMPLEXITY: O(2N) ≈ O(N)
SPACE COMPLEXITY: O(1)
*/
int secondLargestBetter(vector<int> &a, int n)
{
    // If array size is less than 2,
    // second largest cannot exist
    if (n < 2)
        return -1;

    // -------- FIRST PASS --------
    // Assume first element is the largest initially
    int largest = a[0];

    // Traverse array to find the largest element
    for (int i = 1; i < n; i++)
    {
        // If current element is greater than largest,
        // update largest
        if (a[i] > largest)
        {
            largest = a[i];
        }
    }

    // -------- SECOND PASS --------
    // Initialize secondLargest to INT_MIN
    int secondLargest = INT_MIN;

    // Boolean flag to check if second largest exists
    bool foundSecond = false;

    // Traverse again to find second largest
    for (int i = 0; i < n; i++)
    {
        // Check:
        // 1. Element must be smaller than largest
        // 2. Element must be greater than current secondLargest
        if (a[i] < largest && (!foundSecond || a[i] > secondLargest))
        {
            secondLargest = a[i]; // Update second largest
            foundSecond = true;   // Mark existence
        }
    }

    // If second largest was found, return it
    // Otherwise, return -1
    return foundSecond ? secondLargest : -1;
}

// ---------------------- OPTIMAL APPROACH (ONE PASS) ----------------------
/*
APPROACH EXPLANATION:
We maintain two variables while traversing once:
1. largest        → stores the largest value so far
2. secondLargest → stores the second largest distinct value

WHY THIS IS OPTIMAL:
- Only one traversal
- No sorting
- Constant extra space

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
*/
int secondLargestOptimal(vector<int> &a, int n)
{
    // If array has fewer than 2 elements,
    // second largest cannot exist
    if (n < 2)
        return -1;

    // Initialize largest and secondLargest
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    // Boolean flag to track if second largest exists
    bool foundSecond = false;

    // Traverse the array once
    for (int i = 0; i < n; i++)
    {
        // CASE 1:
        // If current element is greater than largest
        if (a[i] > largest)
        {
            // If largest was already assigned,
            // it becomes the second largest
            if (largest != INT_MIN)
            {
                secondLargest = largest;
                foundSecond = true;
            }

            // Update largest
            largest = a[i];
        }

        // CASE 2:
        // If element is smaller than largest
        // but greater than secondLargest
        else if (a[i] < largest)
        {
            // Update the second largest element:
            // - If no second largest has been found yet, accept this value
            // - Otherwise, update it only if the current value is larger
            //   than the existing second largest (but still < largest)
            if (!foundSecond || a[i] > secondLargest)
            {
                secondLargest = a[i];
                foundSecond = true;
            }
        }
        // CASE 3:
        // If a[i] == largest → ignore (duplicate)
    }

    // If second largest exists, return it
    // Otherwise return -1
    return foundSecond ? secondLargest : -1;
}

// ---------------------- MAIN FUNCTION ----------------------
int main()
{
    int n;

    // Input number of elements
    cout << "Enter total no. of elements: ";
    cin >> n;

    // Declare vector of size n
    vector<int> arr(n);

    // Input array elements
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call and display results from all approaches
    cout << "Second largest element (Brute): "
         << secondLargestBrute(arr, n) << endl;

    cout << "Second largest element (Better): "
         << secondLargestBetter(arr, n) << endl;

    cout << "Second largest element (Optimal): "
         << secondLargestOptimal(arr, n) << endl;

    return 0;
}
