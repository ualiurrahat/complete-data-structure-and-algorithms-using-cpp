/**
 * @file 01_sortVowelInString.cpp
 * @brief Sorts vowels in a string in ASCII order while keeping consonants in their original positions.
 *
 * Problem Statement:
 * Given a 0-indexed string `s`, permute `s` to get a new string `t` such that:
 * - All consonants remain in their original places.
 * - All vowels are sorted in non-decreasing order of their ASCII values.
 * Return the resulting string.
 *
 * Vowels: {'a', 'e', 'i', 'o', 'u'} and their uppercase variants.
 * Consonants: All other English letters.
 *
 * Example 1:
 * Input:  s = "lEetcOde"
 * Output: "lEOtcede"
 *
 * Example 2:
 * Input:  s = "lYmpH"
 * Output: "lYmpH"
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * @brief Returns the string after sorting vowels in ASCII order, keeping consonants in their original positions.
 *
 * @param s The input string.
 * @return string The transformed string with vowels sorted and consonants untouched.
 *
 * @note
 * Time Complexity:  O(4n),  where n = length of string
 * Space Complexity: O(52) = O(1) since 26 lowercase + 26 uppercase are constant space arrays
 */
string sortVowels(string s)
{
    // ---------------------- Section: Count Vowels ----------------------
    vector<int> lower(26, 0); // Frequency for lowercase vowels
    vector<int> upper(26, 0); // Frequency for uppercase vowels
    int n = s.size();         // Length of input string

    // Traverse string and collect vowel frequencies, mark vowels as '#' temporarily
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            lower[ch - 'a']++;
            s[i] = '#';
        }
        else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            upper[ch - 'A']++;
            s[i] = '#';
        }
    }

    // ---------------------- Section: Create Sorted Vowel String ----------------------
    string sortedVowels;

    // Add all uppercase vowels in ASCII order
    for (int i = 0; i < 26; i++)
    {
        while (upper[i]--)
        {
            sortedVowels += (char)('A' + i);
        }
    }

    // Add all lowercase vowels in ASCII order
    for (int i = 0; i < 26; i++)
    {
        while (lower[i]--)
        {
            sortedVowels += (char)('a' + i);
        }
    }

    // ---------------------- Section: Replace '#' with Sorted Vowels ----------------------
    int vowelIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '#')
        {
            s[i] = sortedVowels[vowelIndex++];
        }
    }

    return s;
}

// ---------------------- Section: Main Function with Test ----------------------
int main()
{
    string s1 = "lEetcOde";
    string s2 = "lYmpH";

    cout << "Input:  " << s1 << "\n";
    cout << "Output: " << sortVowels(s1) << "\n\n";

    cout << "Input:  " << s2 << "\n";
    cout << "Output: " << sortVowels(s2) << "\n";

    return 0;
}
