// Question:
// You are given a string of size N. Count the number of distinct characters in it.
//
// Input Format:
// The first line of each test case contains an integer N — the size of the string.
// The next line contains a string of size N.
//
// Output Format:
// Output on a new line the number of distinct characters in the string.

#include <iostream> // For input and output operations
#include <set>      // For using the set container to store unique characters
#include <cassert>  // For assertions

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;              // Read the size of the string
    cin >> s;              // Read the string
    assert(s.size() == n); // Ensure the input string size matches N

    set<char> unique_chars; // Set to store unique characters

    // Insert each character into the set (duplicates are automatically ignored)
    for (char c : s)
    {
        unique_chars.insert(c);
    }

    // Output the number of distinct characters
    cout << unique_chars.size();

    return 0; // Indicate successful program termination
}
