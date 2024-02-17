/*
Given a digit string 's', return all possible letter combinations that the number could represent.
Example:
Input: s = “92”
Output: [“wa”, “wb”, “wc”, “xa”, “xb”, “xc”, “ya”, “yb”, “yc”, “za”, “zb”, “zc”]
Explanation:
9 is mapped with "wxyz", and 2 is mapped with "abc".
Recursion tree:

             /             |           \                \
           /               |            \                \
        w                  x              y                z
     /  |  \            /  |  \         /  |  \          /  |  \
    /   |    \         /   |    \      /   |    \       /   |   \
   wa   wb    wc      xa   xb    xc   ya   yb    yc   za   zb   zc
*/

#include <bits/stdc++.h>
using namespace std;

// recursive solve function to generate all possible combinations.
void solve(string digits, string output, int index, vector<string> &ans, string mapping[])
{
    // base case
    if (index >= digits.size())
    {
        ans.push_back(output);
        return;
    }
    // correspondent number for the index in mapping
    int number = digits[index] - '0';
    // correspendent string value
    string value = mapping[number];

    // loop to generate all possible combination
    for (int i = 0; i < value.size(); i++)
    {
        // insert first charactrer in the output
        output.push_back(value[i]);
        // recursive function call
        // to generate combintations from the next index characters
        solve(digits, output, index + 1, ans, mapping);
        // backtracking: pop back the last characters from the string
        output.pop_back();
    }
}

// function to generate all letter combinations in a mobile keypad.
// takes the digits pressed as function input
// returns all combinations in a string array.
vector<string> letterCombinations(string digits)
{
    // to store all combinations
    vector<string> ans;
    // edge case
    if (digits.size() == 0)
    {
        return ans;
    }
    // starting index
    int index = 0;
    // map digit and strings
    string mapping[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    // to store a single combination
    string output = "";

    // function call to get all possible combination
    solve(digits, output, index, ans, mapping);
    return ans;
}
int main()
{
    string input;
    cout << "insert your digit combination : ";
    cin >> input;

    vector<string> output = letterCombinations(input);
    cout << "Generating all possible combinations: " << endl;
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}