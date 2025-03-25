/*
Question:
You are given a string of size N. Count the number of distinct characters in it and also the frequency of each character.

Input Format:
- First line of the input contains a positive integer T - the number of test cases.
- The first line of each test case contains an integer N — the size of the string.
- The second line of each test case contains a string of size N.

Output Format:
For each test case:
- Output on a new line an integer K - the number of distinct characters in the string.
- On K next lines print two space-separated values - the character and its frequency.
  Characters should be printed in sorted order (i.e., from 'a' to 'z').
*/

#include <iostream> // For input and output operations
#include <map>      // For storing character frequency in sorted order
#include <cassert>  // For asserting string size

using namespace std;

int main()
{
    int t, n;
    cin >> t; // Read the number of test cases

    while (t--)
    { // Loop through each test case
        string s;
        cin >> n; // Read the size of the string
        cin >> s; // Read the string

        assert(s.size() == n); // Ensure the string size matches the given N

        map<char, int> freq; // Map to store character frequency (sorted by default)

        // Count the frequency of each character in the string
        for (char c : s)
        {
            freq[c]++;
        }

        cout << freq.size() << endl; // Output the number of distinct characters

        // Output each character and its frequency in sorted order
        for (auto it : freq)
        {
            cout << it.first << " " << it.second << endl;
        }
    }

    return 0;
}
