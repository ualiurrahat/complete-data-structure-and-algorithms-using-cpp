// Question: Find the last occurrence of an element in an array using STL
// You are given an array and you need to find the index of the last occurrence of a specific element.
//
// Input Format:
// An array of integers is given. You need to find the last occurrence of a given element in the array.
//
// Output Format:
// The output should print the index of the last occurrence of the element or a message stating that the element does not exist.

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[] = {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12}; // Input array

    // Last occurrence of 10 -- expected result at index 7
    // Last occurrence of 6 -- expected result does not exist

    // Finding the last occurrence of 10
    int index = upper_bound(a, a + 11, 10) - a; // Find the position just past the last occurrence of 10
    index -= 1;                                 // Adjust the index to point to the last occurrence

    if (index >= 0 && a[index] == 10)
    { // Check if the element exists at the calculated index
        cout << "Last occurrence of 10 at index: " << index << endl;
    }
    else
    {
        cout << "Element does not exist" << endl; // Print this message if the element is not found
    }

    return 0;
}
