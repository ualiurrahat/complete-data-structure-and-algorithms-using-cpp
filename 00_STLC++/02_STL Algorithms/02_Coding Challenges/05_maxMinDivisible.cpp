// Question:
// Given N positive integers, check if the maximum value is divisible by the minimum value.
//
// Input Format:
// The first line of input contains a positive integer N - the number of integers.
// The second line of input contains N space-separated integers.
//
// Output Format:
// Print "YES" if the maximum value is divisible by the minimum value, else print "NO".

#include <iostream>  // For input and output operations
#include <vector>    // For using the vector container
#include <algorithm> // For min and max functions

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

    // Find the minimum and maximum values in the vector
    int min_val = *min_element(nums.begin(), nums.end());
    int max_val = *max_element(nums.begin(), nums.end());

    // Check if maximum value is divisible by minimum value
    if (max_val % min_val == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0; // Indicate successful execution
}
