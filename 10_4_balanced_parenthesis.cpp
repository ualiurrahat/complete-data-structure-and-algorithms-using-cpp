// check if parenthesis are in balanced or not
#include <bits/stdc++.h>

using namespace std;


bool isValid(string str)
{
    // creating stack
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s.push(str[i]);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }
            char ch = s.top();
            s.pop();
            if ((ch == '(' && str[i] == ')') || (ch == '{' && str[i] == '}') || (ch == '[' && str[i] == ']'))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }

    return s.empty();
}
int main()
{

    char str[100];
    cout << "enter your string: ";
    cin >> str;

    //using inbuilt stack

    cout << isValid(str) << endl;

    return 0;
}