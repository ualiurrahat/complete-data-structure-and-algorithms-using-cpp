/**
 * @file 06_romanToInteger.cpp
 * @brief Convert a Roman numeral to an integer.
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 * This program reads a valid Roman numeral string and converts it into its integer form.
 *
 * Rules:
 * - If a smaller symbol appears before a larger symbol, it's subtracted.
 * - Otherwise, it's added.
 *
 * Valid subtraction cases:
 * - I can be before V (5) and X (10)
 * - X can be before L (50) and C (100)
 * - C can be before D (500) and M (1000)
 *
 * Constraints:
 * - 1 <= s.length <= 15
 * - Valid Roman numeral string in the range [1, 3999]
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Helper function to convert a Roman character to its integer value.
 *
 * @param ch Roman numeral character
 * @return int Integer value corresponding to the Roman symbol
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */
int charToNumber(char ch)
{
    if (ch == 'I')
        return 1;
    else if (ch == 'V')
        return 5;
    else if (ch == 'X')
        return 10;
    else if (ch == 'L')
        return 50;
    else if (ch == 'C')
        return 100;
    else if (ch == 'D')
        return 500;
    else
        return 1000; // ch == 'M'
}

/**
 * @brief Converts a Roman numeral string to an integer.
 *
 * @param s Roman numeral string
 * @return int Integer representation of the Roman numeral
 *
 * @note Time Complexity: O(n), where n is the length of the string
 * @note Space Complexity: O(1)
 */
int romanToInt(const string &s)
{
    int n = s.size();
    int ans = 0;

    // ---------------------- Core Logic ----------------------
    // Traverse until the second last character
    for (int i = 0; i < n - 1; ++i)
    {
        // If current value is less than next, subtract it
        if (charToNumber(s[i]) < charToNumber(s[i + 1]))
        {
            ans -= charToNumber(s[i]);
        }
        else
        {
            // Else, add it normally
            ans += charToNumber(s[i]);
        }
    }

    // Add the value of the last character
    ans += charToNumber(s[n - 1]);
    return ans;
}

// ---------------------- Driver Code ----------------------
int main()
{
    // Sample test cases
    string s1 = "III";
    string s2 = "LVIII";
    string s3 = "MCMXCIV";

    cout << "Input: " << s1 << "\nOutput: " << romanToInt(s1) << "\n\n";
    cout << "Input: " << s2 << "\nOutput: " << romanToInt(s2) << "\n\n";
    cout << "Input: " << s3 << "\nOutput: " << romanToInt(s3) << "\n";

    return 0;
}
