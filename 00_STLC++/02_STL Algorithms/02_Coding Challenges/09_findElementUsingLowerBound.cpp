// Question: Find a number from an array using STL
// Note: lower_bound and upper_bound work only in sorted containers.
// You are given a sorted array, and you need to find if a specific number exists in the array using STL.

// Input Format:
// A sorted array is given. You need to find if a number exists in the array.

// Output Format:
// The output should print the index of the number if it exists or a message stating that it is not found.

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[] = {1, 5, 8, 18, 20}; // Sorted input array
    int n = 5;                   // Size of the array

    // Use lower_bound to find the position of the element 18 in the sorted array
    int index = lower_bound(a, a + n, 18) - a; // lower_bound gives the index of the first element >= 18

    // Check if the element at the found index is 18 and within the array bounds
    if (index != n && a[index] == 18)
    {
        cout << "Found 18 at index: " << index << endl;
    }
    else
    {
        cout << "Not found" << endl; // If the element is not found, print this message
    }

    return 0;
}
