/*
Problem:
Given an array arr[] containing only 0s, 1s, and 2s.
Sort the array in ascending order without using any built-in sort function.

Approach:
We use the Dutch National Flag algorithm, which processes the array in a single pass.
We maintain three pointers:
- low: boundary between 0s and 1s
- mid: current element under consideration
- high: boundary between 2s and unknowns

The algorithm works by:
1. Swapping 0 to the front and incrementing both low and mid
2. Leaving 1s in place and incrementing mid
3. Swapping 2 to the end and decrementing high
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to sort the array containing only 0s, 1s, and 2s
void sort012(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, mid = 0, high = n - 1;

    // Traverse the array until all elements are processed
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            // Swap 0 to the front (position of 'low'), then move both pointers forward
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            // 1 is already in the correct region, just move mid forward
            mid++;
        }
        else if (arr[mid] == 2)
        {
            // Swap 2 to the end (position of 'high'), move high pointer backward
            swap(arr[mid], arr[high]);
            high--;
            // mid is not incremented here because the swapped element needs to be checked
        }
    }

    // T:O(N), S:O(1)
}

// Driver code to test the function
int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};

    sort012(arr);

    // Print the sorted array
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
