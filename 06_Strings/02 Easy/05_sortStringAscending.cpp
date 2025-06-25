/**
 * @file 05_sortStringAscending.cpp
 * @brief Sort the characters of a string in ascending order.
 *
 * Problem:
 * Given a string consisting of lowercase letters, arrange all its letters
 * in ascending order.
 *
 * Example:
 * Input:  "edcab" → Output: "abcde"
 * Input:  "xzy"   → Output: "xyz"
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Sorts characters of the input string in ascending order.
 *
 * @param s The input string consisting of lowercase English letters.
 * @return A new string with characters sorted in ascending order.
 *
 * @note Time Complexity: O(n + 26) → O(n), where n is the length of the string.
 * @note Space Complexity: O(26) → O(1), since the alphabet size is fixed.
 */
string sortString(string s)
{
    // Frequency array to count letters
    int alpha[26] = {0};
    int n = s.size();

    // Count each character occurrence
    for (int i = 0; i < n; ++i)
    {
        alpha[s[i] - 'a']++;
    }

    // Reconstruct the string in sorted order
    s.clear();
    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < alpha[i]; ++j)
        {
            s.push_back('a' + i);
        }
    }

    return s;
}

/**
 * @brief Main function to test sortString utility.
 */
int main()
{
    string input1 = "edcab";
    string input2 = "xzy";

    cout << sortString(input1) << endl; // Output: abcde
    cout << sortString(input2) << endl; // Output: xyz

    return 0;
}
