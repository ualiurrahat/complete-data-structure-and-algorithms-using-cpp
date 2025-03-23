/*
    Task: Replace occurrences of a specific value in a vector

    Given N positive integers and a value x, replace all occurrences of x with x + 1.

    Input Format:
    - The first line contains two space-separated integers:
      N (number of integers) and x (the specific value to be replaced).
    - The second line contains N space-separated integers.

    Output Format:
    - The modified sequence where all occurrences of x are replaced with x + 1.
*/

#include <iostream>
#include <vector>
#include <algorithm> // For replace() function

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x; // Read the number of elements and the value to replace

    vector<int> v(n); // Declare a vector of size n

    // Read the input values into the vector
    for (int i = 0; i < n; i++)
        cin >> v[i];

    // Replace all occurrences of x with x + 1
    replace(v.begin(), v.end(), x, x + 1);

    // Print the modified vector
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";

    return 0;
}
