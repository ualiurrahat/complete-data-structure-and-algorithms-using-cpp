// return  all the subsequence of a string.
// ex: abc
// output : 8 sub-sequence("", a,b,c,ab,bc,ac,abc)
// A subsequence of a string is the one which is generated by deleting 0 or
// more characters from the string and keeping the other character at the same order.
// a sub-sequence is non-continuous but sub-string is continuous.
// ex: from string :"abc", ac is a subsequence but it is not substring.
// formula: is a string has 'n' characters, it will have exactly
// 2^n no. of total subsequence

#include <bits/stdc++.h>

using namespace std;

// function to to get subsequence of a string
// it takes the input string and an output string array
// output string array stores all the subsequence and
// function returns size of output array.
int subSequence(string input, string output[])
{
    // base case
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    // trim the first  character of the input string
    string smallString = input.substr(1);
    // recursion call with the trimmed input string
    // this will create all subsequences for smallString
    int smallOutputSize = subSequence(smallString, output);
    // small calculation
    // first copy the found subsequences from recursion call
    // and create new substring combinining from
    // already existed string in output array and attaching first character
    // in frot of them.
    for (int i = 0; i < smallOutputSize; i++)
    {
        output[i + smallOutputSize] = input[0] + output[i];
    }
    return 2 * smallOutputSize;
}

int main()
{

    string input;

    cout << "enter input string: ";
    cin >> input;
    int size = pow(2, input.size());
    string output[size];
    int count = subSequence(input, output);

    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}