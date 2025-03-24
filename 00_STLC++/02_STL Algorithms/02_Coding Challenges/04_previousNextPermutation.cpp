// Question:
// Given N non-negative integers, print its previous and next permutations.
//
// Input Format:
// The first line of input contains a positive integer N - the number of integers.
// The second line of input contains N space-separated integers.
//
// Output Format:
// 1. Print the next permutation of the given N integers on the first line (space-separated).
// 2. Print the previous permutation of the given N integers on the second line (space-separated).

#include <iostream>  // For input and output operations
#include <vector>    // For using the vector container
#include <algorithm> // For next_permutation and prev_permutation

using namespace std;

int main()
{
    int n;
    cin >> n; // Read the number of integers

    vector<int> nums(n); // Create a vector to store the integers
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // Read the N integers into the vector
    }

    vector<int> nums_copy = nums; // Make a copy of the original vector

    // Compute the next permutation of the sequence
    next_permutation(nums.begin(), nums.end());
    for (int val : nums)
        cout << val << " ";
    cout << endl;

    // Compute the previous permutation of the sequence
    prev_permutation(nums_copy.begin(), nums_copy.end());
    for (int val : nums_copy)
        cout << val << " ";

    return 0; // Indicate successful execution
}
