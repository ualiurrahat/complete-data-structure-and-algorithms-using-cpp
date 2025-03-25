// Question: Count the number of times an element appears in an array using STL
// You are given an array and you need to count how many times a particular element appears in the array.
//
// Input Format:
// An array of integers is given. You need to check how many times specific elements appear in the array.
//
// Output Format:
// The output should print the count of the element in the array.

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[] = {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12}; // Input array

    // For x = 10 -- expected result = 3
    // For x = 6 -- expected result = 0;

    // Count the occurrences of 10
    int upper = upper_bound(a, a + 11, 10) - a; // Find the position just past the last occurrence of 10
    int lower = lower_bound(a, a + 11, 10) - a; // Find the position of the first occurrence of 10

    cout << "Number of 10: " << upper - lower << endl; // The difference gives the count of 10 in the array

    // Count the occurrences of 6
    upper = upper_bound(a, a + 11, 6) - a;
    lower = lower_bound(a, a + 11, 6) - a;

    cout << "Number of 6: " << upper - lower << endl; // The difference gives the count of 6 in the array

    return 0;
}
