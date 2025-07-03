/**
 * @file 08_reverseWordsInString.cpp
 * @brief Reverse the order of words in a given input string
 *
 * @problem
 * Given an input string s, reverse the order of the words.
 * A word is defined as a sequence of non-space characters.
 * The words in s will be separated by at least one space.
 *
 * Return a string of the words in reverse order concatenated by a single space.
 * Note that s may contain leading or trailing spaces or multiple spaces between words.
 * The returned string should only have a single space separating the words.
 * Do not include any extra spaces.
 *
 * @example
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 *
 * Input: s = "  hello world  "
 * Output: "world hello"
 *
 * Input: s = "a good   example"
 * Output: "example good a"
 *
 * @constraints
 * 1 <= s.length <= 10^4
 * s contains English letters (upper-case and lower-case), digits, and spaces.
 * There is at least one word in s.
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/**
 * @brief Reverses the words in a given string while cleaning up extra spaces.
 *
 * @param s The original input string
 * @return string The string with words reversed and properly spaced
 *
 * @note
 * Time Complexity: O(4n) — Single pass through string with some reversals and concatenations
 * Space Complexity: O(n) — Temporary string storage for answer and word construction
 */
string reverseWordsBrute(string s)
{
    string ans = "";  // Final answer string
    int n = s.size(); // Length of input
    string word = ""; // Temporary string to store each word

    int i = n - 1;
    while (i >= 0)
    {
        if (s[i] == ' ')
        {
            // Reverse the word if not empty
            if (word.size() > 0)
                reverse(word.begin(), word.end());

            // Append to answer with space management
            if (ans.size() > 0)
            {
                ans = ans + ' ' + word;
            }
            else
            {
                ans = ans + word;
            }

            // Clear for next word
            word.clear();

            // Skip multiple spaces
            while (i >= 0 && s[i] == ' ')
            {
                i--;
            }
        }

        // Add characters in reverse order to word
        if (i >= 0)
        {
            word = word + s[i];
        }

        i--;
    }

    // Handle the last word if exists
    if (word.size() > 0)
    {
        reverse(word.begin(), word.end());
        if (ans.size() > 0)
        {
            ans = ans + ' ' + word;
        }
        else
        {
            ans = ans + word;
        }
    }

    return ans;
}
// -- -- -- -- -- -- -- -- -- -- --Optimal Approach-- -- -- -- -- -- -- -- -- -- --

/**
 * @brief Appends a reversed word to the result string with space management.
 *
 * @param result The final string being built
 * @param word The word to reverse and append
 */
void appendReversedWord(string &result, string &word)
{
    if (word.empty())
        return;

    reverse(word.begin(), word.end());

    if (!result.empty())
        result += ' ';

    result += word;
    word.clear();
}

/**
 * @brief Brute-force reversal of word order by traversing from right to left.
 *
 * @param s Input string
 * @return string Words in reversed order, trimmed and space-normalized
 *
 * @note
 * Time: O(4n)
 * Space: O(n)
 */
string reverseWordsOptimal(string s)
{
    string result, word;
    int i = s.size() - 1;

    while (i >= 0)
    {
        if (s[i] == ' ')
        {
            appendReversedWord(result, word);
            while (i >= 0 && s[i] == ' ')
                i--; // Skip spaces
        }

        if (i >= 0)
        {
            word += s[i];
            i--;
        }
    }

    // Append last collected word
    appendReversedWord(result, word);

    return result;
}

// ---------------------- Main Function for Demonstration ----------------------
int main()
{
    string input1 = "the sky is blue";
    string input2 = "  hello world  ";
    string input3 = "a good   example";

    cout << "Brute Force:\n";
    cout << "\"" << reverseWordsBrute(input1) << "\"\n";
    cout << "\"" << reverseWordsBrute(input2) << "\"\n";
    cout << "\"" << reverseWordsBrute(input3) << "\"\n\n";

    cout << "Optimal:\n";
    cout << "\"" << reverseWordsOptimal(input1) << "\"\n";
    cout << "\"" << reverseWordsOptimal(input2) << "\"\n";
    cout << "\"" << reverseWordsOptimal(input3) << "\"\n";

    return 0;
}
