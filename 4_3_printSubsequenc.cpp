// return  all the subsequence of a string.
// ex: abc
// output : 8 substring("", a,b,c,ab,bc,ac,abc)

#include <bits/stdc++.h>

using namespace std;

int subSequence(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    string smallString = input.substr(1);
    int smallOutputSize = subSequence(smallString, output);

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