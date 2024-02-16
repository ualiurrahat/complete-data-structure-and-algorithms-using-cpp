/*print all the subsequences of a string
// ex: abc
// output : 8 sub-sequence("", a,b,c,ab,bc,ac,abc)
// A subsequence of a string is the one which is generated by deleting 0 or
// more characters from the string and keeping the other character at the same order.
// a sub-sequence is non-continuous but sub-string is continuous.
// ex: from string :"abc", ac is a subsequence but it is not substring.
// formula: is a string has 'n' characters, it will have exactly
// 2^n no. of total subsequence
 */
#include <bits/stdc++.h>

using namespace std;

void printSubsequences(string input, string output)
{
    // base case
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }
    // recursion call without adding first character with output
    printSubsequences(input.substr(1), output);
    // recursion call with adding first character in the output.
    printSubsequences(input.substr(1), output + input[0]);
}

int main()
{
    string input = "abc";
    string output = "";
    printSubsequences(input, output);

    return 0;
}