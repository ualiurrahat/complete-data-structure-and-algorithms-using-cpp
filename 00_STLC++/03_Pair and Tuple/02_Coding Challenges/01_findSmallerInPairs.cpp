// Question:
// Task
// Given N pairs of integers, print the smaller one among them.
//
// Input Format
// The first line of input will contain a single integer N, denoting the number of pairs.
// Next N lines contain two space-separated integers x and y - the i-th pair on line i + 1.
//
// Output Format
// Print on N separate lines, the smaller integer in the i-th pair.

#include <iostream>  // For input and output operations
#include <utility>   // For using the pair container
#include <algorithm> // For using the min() function

using namespace std;

int main()
{
    int n;
    cin >> n; // Read the number of pairs

    pair<int, int> p[n]; // Declare an array of pairs to store N pairs of integers

    // Read N pairs of integers
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second; // Store input values in the pair array
    }

    // Process and output the smaller integer for each pair
    for (int i = 0; i < n; i++)
    {
        cout << min(p[i].first, p[i].second) << endl; // Find and print the smaller value
    }

    return 0; // Indicate successful program termination
}
