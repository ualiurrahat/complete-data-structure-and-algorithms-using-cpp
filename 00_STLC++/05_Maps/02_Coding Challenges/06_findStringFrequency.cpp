/*
    Question: Given N strings and Q queries. In each query, you are given a string.
    Print the frequency of that string.

    Constraints:
    - N = 10^6 (up to one million strings)
    - String size ≤ 100
    - Q ≤ 10^6 (up to one million queries)

    Example:
    Input:
    Strings: abc, def, abc, ghj, jkl, ghj, ghj, abc
    Queries: 2
    Query strings: abc, ghj

    Output:
    Frequency of abc = 3
    Frequency of ghj = 3
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> m; // Using unordered_map for average O(1) time complexity on insert and lookup
    int n;
    cout << "Enter total number of strings you want to insert: ";
    cin >> n; // Input number of strings

    // Input strings and count their frequencies using unordered_map
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s; // Input each string
        m[s]++;   // Increment frequency count for the string
    }

    int q;
    cout << "Enter total number of queries: ";
    cin >> q; // Input number of queries

    // Process each query
    while (q--)
    {
        string s;
        cin >> s;                                              // Input string to check frequency
        cout << "Frequency of " << s << " : " << m[s] << endl; // Output frequency of queried string
    }

    return 0;
}
