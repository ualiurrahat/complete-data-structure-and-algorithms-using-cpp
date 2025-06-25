/**
 * @file 03_rotateStringBy2Places.cpp
 * @brief Check if one string is a rotation of another by exactly 2 places.
 *
 * Problem:
 * Given two strings `s1` and `s2`, return true if `s2` can be obtained by rotating `s1`
 * by exactly 2 places in one direction (either clockwise or anti-clockwise), else return false.
 *
 * Example:
 * Input:  s1 = "amazon", s2 = "azonam" → Output: true
 * Input:  s1 = "geeksforgeeks", s2 = "geeksgeeksfor" → Output: false
 * Input:  s1 = "ab", s2 = "ab" → Output: true
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Rotate the string clockwise by 1 place.
 *
 * @param s The input string (modified in-place).
 */
void rotateClockWise(string &s)
{
    // Save the last character
    char lastChar = s[s.size() - 1];

    // Shift all characters one step to the right
    for (int i = s.size() - 2; i >= 0; --i)
    {
        s[i + 1] = s[i];
    }

    // Place the last character at the front
    s[0] = lastChar;
}

/**
 * @brief Rotate the string anti-clockwise by 1 place.
 *
 * @param s The input string (modified in-place).
 */
void rotateAntiClockWise(string &s)
{
    // Save the first character
    char firstChar = s[0];

    // Shift all characters one step to the left
    for (int i = 1; i < s.size(); ++i)
    {
        s[i - 1] = s[i];
    }

    // Place the first character at the end
    s[s.size() - 1] = firstChar;
}

/**
 * @brief Check if one string can be rotated by exactly 2 places to get the other.
 *
 * @param s1 The original string.
 * @param s2 The target string to compare after rotation.
 * @return true if s2 can be obtained by rotating s1 by 2 places; false otherwise.
 *
 * @note Time Complexity: O(4n)
 * @note Space Complexity: O(n) for temporary strings
 */
bool isRotated(string &s1, string &s2)
{
    // If sizes differ, they cannot be rotations
    if (s1.size() != s2.size())
    {
        return false;
    }

    // Make temporary copies to apply rotations
    string clockWise = s1;
    string antiClockWise = s1;

    // Apply 2 clockwise rotations
    rotateClockWise(clockWise);
    rotateClockWise(clockWise);

    // Check if clockwise rotation matches s2
    if (clockWise == s2)
    {
        return true;
    }

    // Apply 2 anti-clockwise rotations
    rotateAntiClockWise(antiClockWise);
    rotateAntiClockWise(antiClockWise);

    // Check if anti-clockwise rotation matches s2
    if (antiClockWise == s2)
    {
        return true;
    }

    // Neither rotation resulted in s2
    return false;
}

/**
 * @brief Main function to test isRotated utility.
 */
int main()
{
    string s1 = "amazon";
    string s2 = "azonam";

    cout << boolalpha << isRotated(s1, s2) << endl; // Output: true

    s1 = "geeksforgeeks";
    s2 = "geeksgeeksfor";
    cout << boolalpha << isRotated(s1, s2) << endl; // Output: false

    s1 = "ab";
    s2 = "ab";
    cout << boolalpha << isRotated(s1, s2) << endl; // Output: true

    return 0;
}
