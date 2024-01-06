// You are given a string of '(',')','{','}', '[',']'.
// check and tell if these brackets are valid or invalid.
// example: input = ([{}])
// output: valid-->true
// example: input = ]([]){}
// output: invalid-->false.
#include <bits/stdc++.h>

using namespace std;
// function to check valid parenthesis.
bool isValid(string str)
{
    // creating stack
    stack<char> s;
    // traverse the given string.
    for (int i = 0; i < str.length(); i++)
    {
        // check if current character is opening brackets.
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            // push openeing bracket into the stack.
            s.push(str[i]);
        }
        //  the bracket is a closing one.
        else
        {
            // if stack is empty. then it is invalid.
            // since we encountered a closing bracket
            // and no opening bracket is there in the stack.
            if (s.empty())
            {
                // returning false as combination is invalid.
                return false;
            }
            // now, stack has element. take out the top one.
            char ch = s.top();
            // pop the top element.
            s.pop();
            // condtion to check if the top element and
            // the current char is corresponedent opening and closing brackets.
            if ((ch == '(' && str[i] == ')') || (ch == '{' && str[i] == '}') || (ch == '[' && str[i] == ']'))
            {
                // condition is true. so move forward to compare the remaining string.
                continue;
            }
            // condition fails. so given string is invalid.
            else
            {
                // returning false as string is invalid.
                return false;
            }
        }
    }

    // after traversing whole string,if stack is not empty.
    // then it is an imbalanced parenthesis.
    return s.empty();
}
int main()
{

    char str[100];
    cout << "enter your string: ";
    cin >> str;

    // using inbuilt stack

    cout << isValid(str) << endl;

    return 0;
}