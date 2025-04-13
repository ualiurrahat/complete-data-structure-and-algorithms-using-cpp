// Find the first index of a number in an array.
// Example: a = {18, 1, 8, 1, 20}, x = 1
// The first index of 1 is 1.

#include <iostream>

using namespace std;

// Recursively find the first index of number x in array a of given size.
int firstIndex(int a[], int size, int x)
{
    // Base case: if the array is empty, return -1 (number not found).
    if (size == 0)
    {
        return -1;
    }

    // Small calculation: check if the first element is the number x.
    if (a[0] == x)
    {
        return 0;
    }

    // Recursive call: search for x in the remaining array starting from the next element.
    int index = firstIndex(a + 1, size - 1, x);

    // If the number was not found in the rest of the array, return -1.
    if (index == -1)
    {
        return index;
    }
    // If found, adjust the index by adding 1 to account for the current position.
    else
    {
        return index + 1;
    }
}

int main()
{
    // Test case 1: array with size 5, search for number 1.
    int a[] = {18, 1, 8, 1, 20};
    int size = 5;
    int num = 1;
    // Print the first index of num in array a.
    cout << firstIndex(a, size, num) << endl;

    // Test case 2: array with size 7, search for number 14.
    int b[] = {20, 1, 13, 1, 14, 14, 1};
    size = 7;
    num = 14;
    // Print the first index of num in array b.
    cout << firstIndex(b, size, num) << endl;

    // Test case 3: search for number 25 in the same array b.
    num = 25;
    // Print the first index of num in array b.
    cout << firstIndex(b, size, num) << endl;

    // Indicate successful program termination.
    return 0;
}