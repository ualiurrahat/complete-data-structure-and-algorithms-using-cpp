// remove 'x'(char that has more than one appearance) from a string
// ex: axbxcxxdxe
// output: abcde

// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void removeX(char str[])
{
    // base case
    if (str[0] == '\0')
    {
        return;
    }
    // small calculation: checking if str[0] is the characted
    if (str[0] != 'x')
    {
        // recursive call from the next character of the string
        removeX(str + 1);
    }
    else
    {
        // now str[0] == x
        // need to remove 'x'

        int i = 1;
        // left shifting the whole string by one character
        for (; str[i] != '\0'; i++)
        {
            str[i - 1] = str[i];
        }
        // now the last character will come twice
        // ex: if str= "xabc", now str has become = "abcc"
        // so need to assign null character in the place of last 'c'.
        str[i - 1] = '\0';

        // for str = 'xabcx', now str has become 'abcx'
        // so performing recursive call to the remaining string
        removeX(str);
    }
}

int main()
{
    char str[] = "axbxcxdxxex";
    cout << "Given string: " << str << endl;
    removeX(str);

    cout << "string after removing all x: " << str << endl;

    return 0;
}