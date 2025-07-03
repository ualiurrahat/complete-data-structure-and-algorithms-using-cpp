/**
 * @file 05_smallestDistinctWindow.cpp
 * @brief Find length of smallest substring containing all characters of given string at least once
 *
 * @problem
 * Given a string str, find the length of the smallest window that contains all the characters
 * of the given string at least once.
 *
 * @example
 * Input: str = "aabcbcdbca"
 * Output: 4  // Substring "dbca"
 *
 * Input: str = "aaab"
 * Output: 2  // Substring "ab"
 *
 * Input: str = "geeksforgeeks"
 * Output: 7  // Substrings like "eksforg", "ksforge"
 *
 * @constraints
 * 1 ≤ str.size() ≤ 10^5
 * str contains only lowercase English alphabets
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * @brief Finds length of the smallest window containing all unique characters of input string.
 *
 * @param str Reference to the input string
 * @return int Length of the smallest distinct-character window
 *
 * @note
 * Time Complexity: O(4n) — two-pointer traversal + unique character counting
 * Space Complexity: O(256) — constant space for ASCII frequency array
 */
int findSubString(string &str)
{
    vector<int> count(256, 0); // to store frequency of characters
    int n = str.size();        // size of input string

    int first = 0, second = 0; // two pointers to traverse the string
    int len = n;               // initial length is equal to string size assumed
    int diff = 0;              // stores total no. of unique characters in the string

    // ---------------------- Count Total Unique Characters ----------------------
    for (int i = 0; i < n; i++)
    {
        if (count[str[i]] == 0)
        {
            diff++; // unique character found
        }
        count[str[i]]++;
    }

    // reset the count vector i.e. the frequency of all characters
    for (int i = 0; i < 256; i++)
    {
        count[i] = 0;
    }

    // ---------------------- Find Smallest Distinct Window ----------------------
    while (second < n)
    {
        // expand window until all unique characters are included
        while (diff && second < n)
        {
            if (count[str[second]] == 0)
            {
                diff--; // unique character found
            }
            count[str[second]]++; // increase frequency of current character
            second++;             // move second to the next character
        }

        // update length of minimum distinct window
        len = min(len, second - first);

        // shrink window while it still contains all unique characters
        while (diff != 1)
        {
            len = min(len, second - first); // update window length
            count[str[first]]--;            // remove character at `first` from window
            if (count[str[first]] == 0)
            {
                diff++; // one unique character removed
            }
            first++; // move start of window forward
        }
    }

    return len;
}

// ---------------------- Main Function for Demonstration ----------------------
int main()
{
    string s1 = "aabcbcdbca";
    string s2 = "aaab";
    string s3 = "geeksforgeeks";

    cout << "Input: " << s1 << "\nOutput: " << findSubString(s1) << "\n\n";
    cout << "Input: " << s2 << "\nOutput: " << findSubString(s2) << "\n\n";
    cout << "Input: " << s3 << "\nOutput: " << findSubString(s3) << "\n";

    return 0;
}
