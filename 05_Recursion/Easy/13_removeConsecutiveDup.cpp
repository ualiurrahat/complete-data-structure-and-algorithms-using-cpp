// remove all consecutive duplicates from a string.
// ex: aaabbcccddde
// out: abcde

#include <bits/stdc++.h>
using namespace std;

void removeDup(char str[])
{
    // base case
    if (strlen(str) == 1)
    {
        return;
    }
    // calculation: comparing first two characters
    if (str[0] != str[1])
    {
        // characters are diffirent
        // doing recursive call from the next character
        removeDup(str + 1);
    }
    else
    {
        // both characters are same.
        // to remove one character
        // means left shifting of all characters upto 1
        int i = 1;
        for (; str[i] != '\0'; i++)
        {
            str[i - 1] = str[i];
        }
        // now the last character will come twice.
        // so removing that one by null character
        str[i - 1] = '\0';
        removeDup(str);
    }
}

int main()
{
    char str[] = "aaabbcccdde";
    cout << "given string: " << str << endl;
    removeDup(str);
    cout << "output: " << str << endl;

    char str2[] = "aabbccddeea";
    cout << "given string :" << str2 << endl;
    removeDup(str2);
    cout << "output: " << str2 << endl;
    return 0;
}