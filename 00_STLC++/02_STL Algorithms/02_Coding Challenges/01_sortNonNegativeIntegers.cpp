// Question:
// Given N non-negative integers, sort them in non-decreasing order.
//
// Input Format:
// The first line of input contains a positive integer N - the number of integers.
// The second line contains N space-separated integers.
//
// Output Format:
// Print N space-separated integers on a single line - the input in non-decreasingly sorted order.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n; // Read the number of integers

    vector<int> nums(n); // Create a vector to store the integers
    for (int i = 0; i < n; i++)
        cin >> nums[i]; // Read the N integers into the vector

    sort(nums.begin(), nums.end()); // Sort the vector in non-decreasing order

    for (int i = 0; i < n; i++)
        cout << nums[i] << " "; // Print the sorted integers

    return 0; // Indicate successful execution
}
