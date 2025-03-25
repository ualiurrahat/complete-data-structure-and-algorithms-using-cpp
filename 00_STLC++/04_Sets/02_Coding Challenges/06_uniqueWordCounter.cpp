/*
    Question: Given N words, count the number of unique words.

    Input Format:
    - The first line contains an integer N, the number of words.
    - The second line contains N space-separated strings (the words).

    Output Format:
    - Output a single line with the number of unique words.

    Example:
    Input:
    5
    apple banana apple orange apple grape
    Output:
    4

*/

#include <iostream>
#include <unordered_set>
#include <cassert>

using namespace std;

int main()
{
    int n;
    cin >> n;                      // Input the number of words
    assert(1 <= n && n <= 100000); // Assert the valid range of N

    unordered_set<string> words; // Unordered set to store unique words

    // Input words and insert them into the set
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word; // Input each word
        int sz = word.size();
        assert(sz >= 1 && sz <= 10); // Assert that the word length is between 1 and 10
        words.insert(word);          // Insert word into the unordered set
    }

    cout << words.size(); // Output the number of unique words

    return 0;
}
