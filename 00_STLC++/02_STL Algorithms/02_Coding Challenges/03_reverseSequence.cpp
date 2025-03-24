// Question:
// Given two integers N and x, generate a sequence of N integers starting from x,
// where each successive integer is 1 greater than the previous one.
// Then, reverse the generated sequence and print it.
//
// Input Format:
// The first and only line of input contains two space-separated positive integers:
// N - the number of integers in the sequence.
// x - the starting integer of the sequence.
//
// Output Format:
// Print N space-separated integers on a single line in reversed order.

#include <iostream>  // For input and output operations
#include <vector>    // For using the vector container
#include <algorithm> // For reverse function
#include <numeric>   // For iota function to generate sequence

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x; // Read the number of integers and the starting integer

    vector<int> nums(n);               // Create a vector of size N
    iota(nums.begin(), nums.end(), x); // Generate the sequence starting from x

    reverse(nums.begin(), nums.end()); // Reverse the sequence

    // Print the reversed sequence
    for (int val : nums)
    {
        cout << val << " ";
    }

    return 0; // Indicate successful execution
}
