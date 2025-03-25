// Question: Given N strings, print strings in lexicographical order with their frequency.
// The number of strings N can be as large as 10^5, and each string can have a size up to 100.
// You need to store and count the frequency of each string efficiently, then print them in lexicographical order.

// Input:
// N strings are given, where N ≤ 10^5 and each string size ≤ 100.

// Output:
// The output should print each string along with its frequency in lexicographical order.

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    int n;
    cout << "Enter how many strings you want to insert: ";
    cin >> n; // Input the number of strings

    // Map to store strings and their frequencies, automatically sorts by string in lexicographical order
    map<string, int> m;

    // Input each string and update its frequency
    for (int i = 0; i < n; i++)
    {
        string s;
        cout << "Enter string: ";
        cin >> s; // Input the string
        m[s]++;   // Insert string and update its frequency
    }

    // Printing strings in lexicographical order along with their frequency
    for (const auto &word : m)
    {
        cout << word.first << " : " << word.second << endl; // Output the string and its frequency
    }

    return 0;
}
