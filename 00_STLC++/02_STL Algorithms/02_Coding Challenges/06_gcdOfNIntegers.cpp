// Question:
// Given N integers, find their GCD (Greatest Common Divisor).
//
// Input Format:
// The first line of input contains a positive integer N - the number of integers.
// The second line contains N space-separated integers.
//
// Output Format:
// Print on a single line: The GCD of the given N integers.

/*
#include <iostream>  // For input and output operations
#include <vector>    // For using the vector container
#include <algorithm> // For using the gcd function from C++ standard library

using namespace std;

int main()
{
    int n;
    cin >> n;         // Read the number of integers
    vector<int> v(n); // Create a vector to store the integers

    for (int i = 0; i < n; i++)
    {
        cin >> v[i]; // Read the N integers into the vector
    }

    int gcd_val = v[0]; // Initialize GCD with the first number

    // Compute the GCD of all numbers in the vector
    for (int i = 1; i < n; i++)
    {
        gcd_val = gcd(gcd_val, v[i]); // Update GCD with the next number
    }

    cout << gcd_val; // Output the final GCD

    return 0; // Indicate successful execution
}
*/