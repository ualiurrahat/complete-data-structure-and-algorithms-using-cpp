/**
 * @file 04_minCharsToMakePalindrome.cpp
 * @brief Optimal KMP-based solution to find the minimum characters to be added at front to make the string a palindrome.
 *
 * @problem
 * Given a string `s`, find the minimum number of characters to be added at the front of the string to make it a palindrome.
 *
 * A palindrome is a string that reads the same backward as forward.
 *
 * @example
 * Input: s = "abc"
 * Output: 2
 * Explanation: Add 'b' and 'c' in front: "cbabc"
 *
 * Input: s = "aacecaaaa"
 * Output: 2
 * Explanation: Add 2 'a's in front: "aaaacecaaaa"
 *
 * @constraints
 * 1 <= s.length() <= 10^6
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/**
 * @brief Builds the Longest Prefix Suffix (LPS) array using KMP preprocessing.
 *
 * @param s A reference to the input string (usually s + '$' + reversed(s))
 * @return The length of the longest prefix which is also a suffix
 *
 * @note
 * Time Complexity: O(4n)
 * Space Complexity: O(2n)
 */
int longestPrefixSuffix(const string &s)
{
    int n = s.size();
    vector<int> lps(n, 0);

    // 'first' points to prefix, 'second' scans the string
    int first = 0, second = 1;

    while (second < n)
    {
        if (s[first] == s[second])
        {
            lps[second] = first + 1;
            first++;
            second++;
        }
        else
        {
            if (first == 0)
            {
                second++;
            }
            else
            {
                first = lps[first - 1]; // fallback in the prefix
            }
        }
    }

    return lps[n - 1]; // longest prefix which is also suffix
}

/**
 * @brief Calculates the minimum number of characters to add at front to make string a palindrome.
 *
 * @param s Reference to the input string
 * @return Minimum characters to be added at front
 *
 * @note
 * Time Complexity: O(4n)
 * Space Complexity: O(2n)
 */
int minCharToMakePalindrome(const string &s)
{
    string reversed = s;
    reverse(reversed.begin(), reversed.end());

    // Combine original + special character + reversed
    string combined = s + '$' + reversed;

    // LPS will give the length of the longest prefix palindrome
    int longestPalindromicPrefix = longestPrefixSuffix(combined);

    // Remaining characters must be added at the front
    return s.size() - longestPalindromicPrefix;
}

/**
 * @brief Main function to test minCharToMakePalindrome.
 */
int main()
{
    vector<string> testCases = {
        "abc",       // Expected: 2
        "aacecaaaa", // Expected: 2
        "aa",        // Expected: 0
        "aabba",     // Expected: 2
        "abcd",      // Expected: 3
        "race"       // Expected: 3
    };

    for (const string &test : testCases)
    {
        cout << "Input: \"" << test << "\" => Minimum chars to add: "
             << minCharToMakePalindrome(test) << endl;
    }

    return 0;
}
