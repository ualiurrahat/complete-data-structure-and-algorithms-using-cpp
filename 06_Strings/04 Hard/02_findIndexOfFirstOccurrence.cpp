/**
 * Leetcode Problem: 28
 * @file 02_findIndexOfFirstOccurrence.cpp
 * @brief Implements brute-force and KMP-based solutions to find the first occurrence of a substring.
 *
 * @problem
 * Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`,
 * or -1 if `needle` is not part of `haystack`.
 *
 * @examples
 * Input: haystack = "sadbutsad", needle = "sad"
 * Output: 0
 * Explanation: "sad" occurs at index 0 and 6. The first occurrence is at index 0.
 *
 * Input: haystack = "leetcode", needle = "leeto"
 * Output: -1
 * Explanation: "leeto" is not a substring of "leetcode".
 *
 * @constraints
 * - 1 <= haystack.length, needle.length <= 10^4
 * - haystack and needle consist of only lowercase English letters.
 */

#include <iostream>
#include <vector>
using namespace std;

// ---------------------- Brute-force Approach ----------------------

/**
 * @brief Brute-force approach to find the first occurrence of needle in haystack.
 *
 * @param haystack The main string in which we search.
 * @param needle The substring to search for.
 * @return Index of the first occurrence, or -1 if not found.
 *
 * @note Time complexity: O((n - m + 1) * m)
 * @note Space complexity: O(1)
 */
int strStrBruteForce(string haystack, string needle)
{
    int n = haystack.size();
    int m = needle.size();

    // Try every possible starting position in haystack
    for (int i = 0; i <= n - m; i++)
    {
        int first = i;  // Pointer for haystack
        int second = 0; // Pointer for needle

        // Compare each character in needle with haystack
        while (second < m)
        {
            if (haystack[first] != needle[second])
            {
                break; // Mismatch found, break the comparison
            }
            first++;
            second++;
        }

        // If full needle matched, return the starting index
        if (second == m)
        {
            return first - second;
        }
    }

    // No match found
    return -1;
}

// ---------------------- KMP Helper Function ----------------------

/**
 * @brief Builds the LPS (Longest Prefix Suffix) array for KMP algorithm.
 *
 * @param lps Array to store the prefix-suffix lengths.
 * @param str The pattern (needle) string.
 *
 * @note Time complexity: O(2m)
 * @note Space complexity: O(m)
 */
void findLPS(vector<int> &lps, string &str)
{
    int pre = 0; // Length of previous longest prefix suffix
    int suf = 1; // Current character being processed
    int n = str.size();

    while (suf < n)
    {
        // Characters match → update LPS and move both pointers
        if (str[pre] == str[suf])
        {
            lps[suf] = pre + 1;
            pre++;
            suf++;
        }
        else
        {
            // If mismatch and pre is at the beginning → assign 0 and move suf
            if (pre == 0)
            {
                lps[suf] = 0;
                suf++;
            }
            else
            {
                // Otherwise, backtrack pre using LPS
                pre = lps[pre - 1];
            }
        }
    }
}

// ---------------------- Optimal KMP Approach ----------------------

/**
 * @brief Optimal solution using Knuth-Morris-Pratt (KMP) string matching algorithm.
 *
 * @param haystack The main string.
 * @param needle The pattern to search for.
 * @return Index of the first occurrence or -1 if not found.
 *
 * @note Time complexity: O(n + m)
 * @note Space complexity: O(m)
 */
int strStrKMP(string haystack, string needle)
{
    int n = haystack.size();
    int m = needle.size();

    if (m == 0)
        return 0; // Edge case: empty needle

    vector<int> lps(m, 0); // LPS array initialization
    findLPS(lps, needle);  // Build the prefix array for needle

    int first = 0;  // Pointer for haystack
    int second = 0; // Pointer for needle

    while (first < n && second < m)
    {
        // Characters match → move both pointers
        if (haystack[first] == needle[second])
        {
            first++;
            second++;
        }
        else
        {
            // If mismatch and second is at start → move first
            if (second == 0)
            {
                first++;
            }
            else
            {
                // Fall back in needle using LPS array
                second = lps[second - 1];
            }
        }
    }

    // Full match found → return starting index
    if (second == m)
    {
        return first - second;
    }

    // No match found
    return -1;
}

// ---------------------- Main Function ----------------------

int main()
{
    // Test case 1
    string h1 = "sadbutsad", n1 = "sad";
    cout << "Brute-force: " << strStrBruteForce(h1, n1) << endl; // Output: 0
    cout << "KMP:         " << strStrKMP(h1, n1) << endl;        // Output: 0

    // Test case 2
    string h2 = "leetcode", n2 = "leeto";
    cout << "Brute-force: " << strStrBruteForce(h2, n2) << endl; // Output: -1
    cout << "KMP:         " << strStrKMP(h2, n2) << endl;        // Output: -1

    // Test case 3
    string h3 = "aaaaa", n3 = "bba";
    cout << "Brute-force: " << strStrBruteForce(h3, n3) << endl; // Output: -1
    cout << "KMP:         " << strStrKMP(h3, n3) << endl;        // Output: -1

    // Test case 4
    string h4 = "mississippi", n4 = "issip";
    cout << "Brute-force: " << strStrBruteForce(h4, n4) << endl; // Output: 4
    cout << "KMP:         " << strStrKMP(h4, n4) << endl;        // Output: 4

    return 0;
}
