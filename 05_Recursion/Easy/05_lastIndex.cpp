// Find the last index of an element inside an array.
// Example: a[] = {5, 6, 5, 4, 5}, x = 5; last index of 5 is 4.
// Example: x = 20, last index of 20 is -1 (not found).

#include <iostream>

using namespace std;

// Recursively find the last index of number x in array a of given size.
int lastIndex(int a[], int size, int x)
{
    // Base case: if the array is empty, return -1 (number not found).
    if (size == 0)
    {
        return -1;
    }

    // Recursive call: search for x in the remaining array starting from the next element.
    int index = lastIndex(a + 1, size - 1, x);

    // If the number was found in the rest of the array, adjust the index by adding 1.
    if (index != -1)
    {
        return index + 1;
    }
    // If not found in the rest, check the current element.
    else
    {
        // If the current element is x, return 0 (index relative to this recursive call).
        if (a[0] == x)
        {
            return 0;
        }
        // If neither found in rest nor current, return -1.
        else
        {
            return -1;
        }
    }
}

int main()
{
    // Define two arrays for testing.
    int a[] = {18, 1, 8, 1, 20};
    int b[] = {20, 1, 13, 1, 14, 14, 1};

    // Test case 1: search for number 1 in array a (size 5).
    int n = 5;
    int num = 1;
    // Print the last index of num in array a.
    cout << lastIndex(a, n, num) << endl;

    // Test case 2: search for number 18 in array a (size 5).
    num = 18;
    // Print the last index of num in array a.
    cout << lastIndex(a, n, num) << endl;

    // Test case 3: search for number 14 in array b (size 7).
    n = 7;
    num = 14;
    // Print the last index of num in array b.
    cout << lastIndex(b, n, num) << endl;

    // Indicate successful program termination.
    return 0;
}