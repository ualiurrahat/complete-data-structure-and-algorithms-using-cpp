/*
Problem Statement:
You are given a string 'infix' which is a valid infix expression.
Convert it to prefix notation.

Note:
- Infix: Operators appear between operands, e.g., A + B
- Prefix: Operators appear before operands, e.g., +AB

Allowed characters: digits, lowercase/uppercase letters, ‘(’, ‘)’, ‘+’, ‘-’, ‘*’, ‘/’, ‘^’

Example:
Input: (a+b)*c-d+f
Output: +-*+abcdf
*/

#include <bits/stdc++.h>
using namespace std;

// function to check if a character is an operator
bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

// function to get precedence of operators
int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

/*
Step 1: Convert Infix to Postfix
- Input: valid infix string
- Output: postfix string
- Uses precedence rules and a stack for operators
*/
string infixToPostfix(string infix)
{
    // add '(' at beginning and ')' at end for simpler parsing
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> char_stack;
    string output; // postfix result

    for (int i = 0; i < l; i++)
    {
        // case 1: current char is operand → append to output
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];

        // case 2: current char is '(' → push to stack
        else if (infix[i] == '(')
            char_stack.push('(');

        // case 3: current char is ')' → pop till '('
        else if (infix[i] == ')')
        {
            while (char_stack.top() != '(')
            {
                output += char_stack.top();
                char_stack.pop();
            }
            char_stack.pop(); // remove '('
        }

        // case 4: current char is operator
        else
        {
            if (isOperator(char_stack.top()))
            {
                // case 4a: right-associative (^) → pop only if priority is strictly greater
                if (infix[i] == '^')
                {
                    while (getPriority(infix[i]) <= getPriority(char_stack.top()))
                    {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
                // case 4b: left-associative (+, -, *, /) → pop while greater precedence exists
                else
                {
                    while (getPriority(infix[i]) < getPriority(char_stack.top()))
                    {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
                // now push current operator
                char_stack.push(infix[i]);
            }
        }
    }

    // append remaining stack content (should be empty in this approach)
    while (!char_stack.empty())
    {
        output += char_stack.top();
        char_stack.pop();
    }

    return output;

    // T:O(N), S:O(N)
}

/*
Step 2: Convert Infix to Prefix
Logic:
- Reverse the infix string
- Replace '(' with ')' and vice versa
- Get postfix of modified expression
- Reverse the result to get prefix
*/
string infixToPrefix(string infix)
{
    int l = infix.size();

    // reverse the original infix
    reverse(infix.begin(), infix.end());

    // flip the brackets
    for (int i = 0; i < l; i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
            i++;
        }
    }

    // step 3: convert to postfix
    string prefix = infixToPostfix(infix);

    // step 4: reverse postfix to get prefix
    reverse(prefix.begin(), prefix.end());

    return prefix;
    // T:O(N), S:O(N)
}

int main()
{
    string s = "(a+b)*c-d+f";
    cout << "Infix expression: " << s << endl;
    string result = infixToPrefix(s);
    cout << "Prefix Expression: " << result << endl;

    return 0;
}
