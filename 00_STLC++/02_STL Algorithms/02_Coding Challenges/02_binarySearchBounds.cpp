// Question:
// Given a sorted vector of N integers, along with three other integers S, L, and U.
// Check if S exists in the vector. If it exists, print "YES", else print "NO".
// Find the lower bound of L and the upper bound of U.
//
// Input Format:
// The first line of input contains four space-separated positive integers:
// N - the number of integers, S, L, and U.
// The second line contains N space-separated sorted integers.
//
// Output Format:
// Print three space-separated values on the first line:
// 1. "YES" if S is present in the given array, else "NO".
// 2. The lower bound value of L.
// 3. The upper bound value of U.

#include <iostream>  // For input and output operations
#include <vector>    // For using the vector container
#include <algorithm> // For binary_search, lower_bound, and upper_bound
#include <cassert>   // For using assert to check precondition

using namespace std;

int main()
{
    int n, s, l, u;
    cin >> n >> s >> l >> u; // Read the number of integers, S, L, and U

    vector<int> nums(n); // Create a vector to store the integers
    for (int i = 0; i < n; i++)
        cin >> nums[i]; // Read the N sorted integers into the vector

    assert(is_sorted(nums.begin(), nums.end())); // Ensure the input array is sorted

    // Check if S exists in the vector using binary search
    bool check_s = binary_search(nums.begin(), nums.end(), s);

    if (check_s)
    {
        cout << "YES ";
    }
    else
    {
        cout << "NO ";
    }

    // Find the lower bound of L and upper bound of U
    auto lb = lower_bound(nums.begin(), nums.end(), l);
    auto ub = upper_bound(nums.begin(), nums.end(), u);

    cout << *lb << " " << *ub; // Print lower bound and upper bound values

    return 0; // Indicate successful execution
}
