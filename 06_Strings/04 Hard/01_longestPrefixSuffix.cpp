/**
 * @file 01_longestPrefixSuffix.cpp
 * @brief Brute-force solution to find the longest prefix which is also a suffix (excluding the full string).
 *
 * @problem
 * You are given a string ‘str’. Find the longest prefix in the string which is also a suffix,
 * excluding the string itself.
 * If there's no such string return an empty string "".
 *
 * @constraints
 * 1 <= |str| <= 10^6
 * All characters are lowercase English alphabets.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * @brief Finds the longest prefix that is also a suffix using brute-force approach.
 *
 * @param str Reference to the input string.
 * @return The longest prefix which is also a suffix (excluding the full string), or empty string if none.
 *
 * @note
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 */
string longestPrefixSuffixBrute(string &str)
{
    vector<string> prefix;
    vector<string> suffix;
    int n = str.size();
    string ans = "";

    // ---------------------- Generating all valid prefixes ----------------------
    // A prefix is any substring that starts from index 0 and ends at i (0 <= i < n-1)
    for (int i = 0; i < n - 1; i++)
    {
        string pref = "";
        for (int j = 0; j <= i; j++)
        {
            pref += str[j];
        }
        prefix.push_back(pref);
    }

    // ---------------------- Generating all valid suffixes ----------------------
    // A suffix is any substring that ends at index n-1 and starts at i (n - i - 1) for i = 0 to n-2
    for (int i = 0; i < n - 1; i++)
    {
        string suff = "";
        for (int j = n - i - 1; j < n; j++)
        {
            suff += str[j];
        }
        suffix.push_back(suff);
    }

    // ---------------------- Comparing each prefix with corresponding suffix ----------------------
    for (int i = 0; i < n - 1; i++)
    {
        string s1 = prefix[i]; // prefix of length i+1
        string s2 = suffix[i]; // suffix of length i+1
        if (s1 == s2)
        {
            ans = s1; // update answer if prefix and suffix match
        }
    }

    return ans;
}
/**
 * @brief Helper function to compute length of longest prefix which is also a suffix using KMP algorithm.
 *
 * @param s Reference to the input string.
 * @return Length of the longest prefix which is also a suffix (excluding the full string).
 *
 * @note
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int longestPrefixSuffixLength(string &s)
{
    int n = s.size();
    vector<int> lps(n, 0); // lps[i] stores the length of the longest proper prefix-suffix for substring ending at i

    int pre = 0; // points to current prefix index
    int suf = 1; // points to current suffix index

    // ---------------------- Building the LPS (Longest Prefix Suffix) Array ----------------------
    while (suf < n)
    {
        if (s[pre] == s[suf])
        {
            // characters match, extend the current LPS length
            lps[suf] = pre + 1;
            pre++;
            suf++;
        }
        else
        {
            // mismatch after some matches
            if (pre == 0)
            {
                // no proper prefix matched, move forward
                lps[suf] = 0;
                suf++;
            }
            else
            {
                // try shorter prefix
                pre = lps[pre - 1];
            }
        }
    }

    return lps[n - 1]; // length of the longest prefix which is also a suffix
}

/**
 * @brief Optimal function to find the longest prefix which is also a suffix (excluding full string).
 *
 * @param str Reference to the input string.
 * @return The longest prefix-suffix string.
 *
 * @note
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
string longestPrefixSuffixOptimal(string &str)
{
    int len = longestPrefixSuffixLength(str);
    string ans = "";

    // ---------------------- Extracting the prefix from the original string ----------------------
    for (int i = 0; i < len; i++)
    {
        ans += str[i];
    }

    return ans;
}

// ---------------------- Main Function with Sample Inputs ----------------------
int main()
{
    string str1 = "ababcdabab";
    string str2 = "aaaaabaa";
    string str3 = "aab";

    cout << "Input: " << str1 << "\nOutput: " << longestPrefixSuffixBrute(str1) << "\n\n";
    cout << "Input: " << str2 << "\nOutput: " << longestPrefixSuffixOptimal(str2) << "\n\n";
    cout << "Input: " << str3 << "\nOutput: " << longestPrefixSuffixOptimal(str3) << "\n\n"; // Output = "", as no mathing suffix-prefix.

    return 0;
}
