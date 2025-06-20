/*
Problem statement:
A sentence is a list of words separated by a single space with no leading or trailing spaces.
Each word consists of lowercase and uppercase English letters.

A sentence can be shuffled by appending the 1-indexed word position to each word and then rearranging the words.
Given a shuffled sentence containing no more than 9 words, reconstruct and return the original sentence.

Example:
Input:  s = "sentence4 a3 is2 This1"
Output: "This is a sentence"
*/

#include <iostream>
#include <vector>
using namespace std;

// -------------------------------------------------------------------
// Function: sortSentence
// Description:
//      Reconstructs the original sentence from a shuffled one by
//      decoding the appended numeric indices and rearranging the words.
// -------------------------------------------------------------------

/**
 * @brief Reconstructs the original sentence from a shuffled string.
 *
 * Parses the input sentence word-by-word, extracts each word's position
 * from the trailing digit, and stores it in a vector. Finally joins them
 * in the correct order to form the original sentence.
 *
 * @param s Shuffled sentence with position-appended words.
 * @return string Original sentence.
 *
 * @note Time Complexity: O(N) — N is the length of the string.
 *       Space Complexity: O(1) — maximum of 10 words.
 */
string sortSentence(string s)
{
    int n = s.size();       // Length of the input string
    int index = 0;          // Index to traverse characters
    vector<string> ans(10); // To store words at their position (1-indexed)
    string temp = "";       // Temporary string to hold current word
    int count = 0;          // Counter to track number of words

    // Traverse each character in the string
    while (index < n)
    {
        if (s[index] == ' ')
        {
            // Extract position from last character of the word
            int pos = temp.back() - '0';
            temp.pop_back(); // Remove digit
            ans[pos] = temp; // Store word at correct index
            temp.clear();    // Reset temp
            count++;         // Increment word count
        }
        else
        {
            // Accumulate characters to form a word
            temp += s[index];
        }
        index++;
    }

    // Process the last word (not followed by space)
    int pos = temp.back() - '0';
    temp.pop_back();
    ans[pos] = temp;
    count++;

    // Reconstruct the sentence from words
    temp.clear();
    for (int i = 1; i <= count; i++)
    {
        temp += ans[i];
        temp += ' ';
    }

    temp.pop_back(); // Remove trailing space
    return temp;

    // T: O(N), S: O(1) since word count <= 9
}

// --------------------------------------------
// Driver Code: Demonstrates sentence sorting
// --------------------------------------------
int main()
{
    string s = "sentence4 a3 is2 This1";
    cout << "Shuffled: " << s << endl;
    string result = sortSentence(s);
    cout << "Original: " << result << endl;
    return 0;
}
