/**
 * @file 04_longestSubstringWithoutRepeatingCharacter.cpp
 * @brief Find the length of the longest substring without repeating characters.
 */

/**
 * Problem Statement:
 * Given a string s, find the length of the longest substring without duplicate characters.
 *
 * Example 1:
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 * Example 2:
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 * Example 3:
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 *
 * Constraints:
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/**
 * @brief Brute force solution to find the longest substring without repeating characters.
 *
 * This method checks all possible substrings and uses a frequency array to detect duplicates.
 *
 * @param s The input string.
 * @return int Length of the longest substring with all unique characters.
 *
 * @note Time Complexity: O(n^2)
 * @note Space Complexity: O(256) per starting index → O(256)
 */
int lengthOfLongestSubstringBruteForce(string s)
{
    int n = s.size();
    int len = 0;

    // Traverse the string character by character
    for (int first = 0; first < n; first++)
    {
        // Initialize a frequency array of size 256 (ASCII character range)
        // All characters have initial frequency 0
        vector<int> count(256, 0);

        // Try to expand the substring from index 'first'
        for (int second = first; second < n; second++)
        {
            // If the current character is already present in substring, break
            if (count[s[second]])
            {
                break;
            }

            // Mark the character as seen
            count[s[second]] = 1;

            // Update maximum length if this window is longer
            len = max(len, second - first + 1);
        }
    }

    return len;
}

/**
 * @brief Optimized sliding window approach to find the longest substring without repeating characters.
 *
 * Uses two pointers to maintain a window of unique characters and a frequency array to track duplicates.
 *
 * @param s The input string.
 * @return int Length of the longest substring with all unique characters.
 *
 * @note Time Complexity: O(n)
 * @note Space Complexity: O(256)
 */
int lengthOfLongestSubstringOptimal(string s)
{
    vector<bool> count(256, 0); // Frequency array for all ASCII characters
    int first = 0, second = 0;  // Pointers defining the sliding window
    int len = 0;                // To store the maximum length found

    int n = s.size();
    while (second < n)
    {
        // If current character already exists in the window,
        // shrink the window from the left until it is removed
        while (count[s[second]])
        {
            count[s[first]] = 0;
            first++;
        }

        // Include the current character into the window
        count[s[second]] = 1;

        // Update maximum length of current window
        len = max(len, second - first + 1);

        // Move right pointer to expand the window
        second++;
    }

    return len;
}

/**
 * @brief Main function to demonstrate both approaches.
 */
int main()
{
    vector<string> testCases = {"abcabcbb", "bbbbb", "pwwkew", "", "au", "dvdf"};

    for (const string &s : testCases)
    {
        cout << "Input string: \"" << s << "\"" << endl;

        int bruteLen = lengthOfLongestSubstringBruteForce(s);
        int optimalLen = lengthOfLongestSubstringOptimal(s);

        cout << "Brute Force Length: " << bruteLen << endl;
        cout << "Optimal Length:     " << optimalLen << endl;
        cout << "-------------------------------" << endl;
    }

    return 0;
}
