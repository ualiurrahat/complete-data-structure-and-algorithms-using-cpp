/**
 * @file 04_checkPanagramString.cpp
 * @brief Determine if a sentence is a pangram.
 *
 * Problem:
 * A pangram is a sentence where every letter of the English alphabet
 * appears at least once.
 *
 * Given a string `sentence` containing only lowercase English letters,
 * return true if `sentence` is a pangram, otherwise return false.
 *
 * Example:
 * Input:  sentence = "thequickbrownfoxjumpsoverthelazydog" → Output: true
 * Input:  sentence = "leetcode" → Output: false
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Check if the given sentence is a pangram.
 *
 * @param sentence A string consisting of only lowercase English letters.
 * @return true if the sentence contains all 26 letters at least once.
 * @return false otherwise.
 *
 * @note Time Complexity: O(n + 26) → O(n), where n = sentence length
 * @note Space Complexity: O(26) → O(1) since size of alphabet is constant
 */
bool checkIfPangram(string sentence)
{
    // Frequency array to mark presence of letters
    int alphabet[26] = {0};
    int n = sentence.size();

    // Count occurrences of each letter
    for (int i = 0; i < n; ++i)
    {
        alphabet[sentence[i] - 'a']++;
    }

    // Verify if every letter from 'a' to 'z' is present
    for (int i = 0; i < 26; ++i)
    {
        if (alphabet[i] == 0)
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Main function to test checkIfPangram utility.
 */
int main()
{
    string s1 = "thequickbrownfoxjumpsoverthelazydog";
    string s2 = "leetcode";

    cout << boolalpha << checkIfPangram(s1) << endl; // Output: true
    cout << boolalpha << checkIfPangram(s2) << endl; // Output: false

    return 0;
}
