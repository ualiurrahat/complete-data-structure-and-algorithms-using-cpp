/**
 * Leetcode Problem: 796
 * @file 06_rotateString.cpp
 * @brief Checks if string `s` can be rotated to match string `goal`.
 *
 * @problem
 * Given two strings `s` and `goal`, return true if and only if `s` can become `goal`
 * after some number of shifts on `s`.
 *
 * A shift on `s` consists of moving the leftmost character of `s` to the rightmost position.
 *
 * @example
 * Input: s = "abcde", goal = "cdeab"
 * Output: true
 *
 * Input: s = "abcde", goal = "abced"
 * Output: false
 *
 * @constraints
 * 1 <= s.length, goal.length <= 100
 * Only lowercase English letters are used.
 */

#include <iostream>
#include <string>

using namespace std;

// -----------------------------------------------------
// 🔁 Manual Left Rotation Helper
// -----------------------------------------------------

/**
 * @brief Performs one left rotation on the input string.
 *        Moves the first character to the end.
 *
 * @param str Reference to the string to rotate
 *
 * @note
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void leftRotation(string &str)
{
    char ch = str[0];
    int n = str.size();

    // Shift each character one position to the left
    for (int i = 1; i < n; i++)
    {
        str[i - 1] = str[i];
    }

    // Place the first character at the end
    str[n - 1] = ch;
}

// -----------------------------------------------------
// 🧪 Brute-force Solution Using Manual Rotation
// -----------------------------------------------------

/**
 * @brief Checks if string `s` can be rotated to become string `goal` using manual shifting.
 *
 * @param s The original string
 * @param goal The target string to match after rotation
 * @return true if `s` can be rotated into `goal`, false otherwise
 *
 * @note
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
bool rotateStringBrute(string s, string goal)
{
    int len1 = s.size();
    int len2 = goal.size();

    // Edge case: length mismatch
    if (len1 != len2)
    {
        return false;
    }

    // Already equal without any rotation
    if (s == goal)
    {
        return true;
    }

    // Try rotating s up to len1 times
    for (int i = 0; i < len1; i++)
    {
        leftRotation(s);
        if (s == goal)
        {
            return true;
        }
    }

    // No match found after all rotations
    return false;
}

// -----------------------------------------------------
// ⚡ Optimal Solution Using Concatenation & Substring
// -----------------------------------------------------

/**
 * @brief Optimally checks if `goal` is a rotation of `s` using string doubling technique.
 *
 * @param s The original string
 * @param goal The target string
 * @return true if some left rotation of `s` matches `goal`, false otherwise
 *
 * @note
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
bool rotateStringOptimal(string s, string goal)
{
    // Check if the lengths are different
    if (s.length() != goal.length())
        return false;

    // Create a new string by concatenating 's' with itself
    string doubledString = s + s;

    // Use find to search for 'goal' in 'doubledString'
    // If 'goal' is a substring of 'doubledString', return true
    return doubledString.find(goal) < doubledString.length();
}

// -----------------------------------------------------
// 🚀 Driver Code (main)
// -----------------------------------------------------

int main()
{
    // Sample test cases
    string s1 = "abcde";
    string goal1 = "cdeab";

    string s2 = "abcde";
    string goal2 = "abced";

    string s3 = "aaaa";
    string goal3 = "aaaa";

    cout << "Brute-force Results:\n";
    cout << "Input: \"" << s1 << "\", Goal: \"" << goal1 << "\" => "
         << (rotateStringBrute(s1, goal1) ? "true" : "false") << endl;

    cout << "Input: \"" << s2 << "\", Goal: \"" << goal2 << "\" => "
         << (rotateStringBrute(s2, goal2) ? "true" : "false") << endl;

    cout << "Input: \"" << s3 << "\", Goal: \"" << goal3 << "\" => "
         << (rotateStringBrute(s3, goal3) ? "true" : "false") << endl;

    cout << "\nOptimal Results:\n";
    cout << "Input: \"" << s1 << "\", Goal: \"" << goal1 << "\" => "
         << (rotateStringOptimal(s1, goal1) ? "true" : "false") << endl;

    cout << "Input: \"" << s2 << "\", Goal: \"" << goal2 << "\" => "
         << (rotateStringOptimal(s2, goal2) ? "true" : "false") << endl;

    cout << "Input: \"" << s3 << "\", Goal: \"" << goal3 << "\" => "
         << (rotateStringOptimal(s3, goal3) ? "true" : "false") << endl;

    return 0;
}
