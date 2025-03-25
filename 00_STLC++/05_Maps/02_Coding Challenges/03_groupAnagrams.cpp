// Question: Group Anagrams
// You are given N strings. Your task is to group the strings that are anagrams of each other.
// An anagram is a string formed by rearranging the letters of another string, using all the original letters exactly once.
// For example, "listen" and "silent" are anagrams of each other because they contain the same letters.
//
// Input Format:
// The first line of input contains an integer N — the number of strings.
// The next N lines contain strings.
//
// Output Format:
// Complete the function which returns a vector of string vectors. Each string vector is a group of anagram strings.
// You can return the groups of anagrams in any order. You will get a text "Nicely Grouped!" if grouping is done correctly, otherwise "WA".

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(const vector<string> &strings)
    {
        unordered_map<string, vector<string>> map; // Map to store sorted string as key and list of anagrams as value

        for (auto str : strings)
        {
            string key = str;
            sort(key.begin(), key.end()); // Sorting the string to create a key for anagram groups
            map[key].push_back(str);      // Grouping anagrams together
        }

        vector<vector<string>> result;

        for (const auto &pair : map)
        {
            result.push_back(pair.second); // Adding each anagram group to the result
        }

        return result; // Returning the final result containing all the anagram groups
    }
};
