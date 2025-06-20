/*
Problem statement: Leetcode 409
Given a string `s` which consists of lowercase or uppercase letters,
return the length of the longest palindrome that can be built with those letters.

Letters are case-sensitive, meaning 'A' and 'a' are considered different.

Example 1:
Input:  s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:
Input:  s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// -------------------------------------------------------------------
// Function: longestPalindromeBrute
// Description:
//      Calculates the longest possible palindrome length from the given string
//      using two frequency arrays for lowercase and uppercase characters.
// -------------------------------------------------------------------

/**
 * @brief Returns the length of the longest palindrome that can be formed.
 *
 * This brute-force approach uses two frequency vectors (for lowercase and uppercase)
 * to count character occurrences, and builds the maximum palindrome possible.
 *
 * @param s Input string with upper/lowercase letters.
 * @return int Length of the longest palindrome that can be built.
 *
 * @note Time Complexity: O(N) — for traversing the string.
 *       Space Complexity: O(1) — uses 52-element fixed vectors.
 */
int longestPalindromeBrute(string s)
{
    int n = s.size();

    vector<int> lower(26, 0); // Frequency for lowercase letters
    vector<int> upper(26, 0); // Frequency for uppercase letters

    // Count character frequencies
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a')
            lower[s[i] - 'a']++;
        else
            upper[s[i] - 'A']++;
    }

    int length = 0;   // Store the max palindrome length
    bool odd = false; // Flag to track if any odd frequency exists

    for (int i = 0; i < 26; i++)
    {
        // Add all even frequencies directly, and (count - 1) for odd ones
        if (lower[i] % 2 == 0)
            length += lower[i];
        else
        {
            length += lower[i] - 1;
            odd = true;
        }

        if (upper[i] % 2 == 0)
            length += upper[i];
        else
        {
            length += upper[i] - 1;
            odd = true;
        }
    }

    // We can place one odd-frequency character in the middle if exists
    if (odd)
        length++;

    return length;
}

// -------------------------------------------------------------------
// Function: longestPalindromeOptimal
// Description:
//      Calculates the longest palindrome length using hash map and
//      a simple odd-frequency counter.
// -------------------------------------------------------------------

/**
 * @brief Optimal solution to find the longest palindrome length.
 *
 * Uses an unordered_map to count character frequencies and simultaneously tracks
 * the number of characters with odd frequency.
 *
 * @param s Input string with upper/lowercase letters.
 * @return int Length of the longest palindrome that can be built.
 *
 * @note Time Complexity: O(N)
 *       Space Complexity: O(K) where K is the number of unique characters
 */
int longestPalindromeOptimal(string s)
{
    unordered_map<char, int> mpp;
    int oddCount = 0;

    for (char ch : s)
    {
        mpp[ch]++;
        // Track number of characters with odd frequency
        if (mpp[ch] % 2 == 1)
            oddCount++;
        else
            oddCount--;
    }

    // If any odd frequency character exists, we can place one in the center
    if (oddCount > 0)
        return s.length() - oddCount + 1;
    else
        return s.length();
}

// --------------------------------------------
// Driver Code: Demonstrates both approaches
// --------------------------------------------
int main()
{
    string s = "abccccdd";
    cout << "Input string: " << s << endl;

    int bruteAns = longestPalindromeBrute(s);
    cout << "Brute-force result: " << bruteAns << endl;

    int optimalAns = longestPalindromeOptimal(s);
    cout << "Optimal result: " << optimalAns << endl;

    return 0;
}
