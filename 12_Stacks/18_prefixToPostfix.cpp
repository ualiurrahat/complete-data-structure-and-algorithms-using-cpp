/*
Problem statement:
You are given a string 's' of size 'n', representing the prefix form of a valid mathematical expression.

Your task is to find out its corresponding postfix expression.

The expected time and space complexity is O(n) and O(n), where 'n' is the size of the string 's'.

Note:
The only operators used in the expressions are '+', '-', '*', '/'.

Example:
Input:  n = 5, s = "/A+BC"
Output:       "ABC+/"

Explanation:
For s = "/A+BC", the correct postfix expression is "ABC+/".
*/

#include <iostream>
#include <stack>
using namespace std;

// --------------------------------------------------
// Utility Function: Check if a character is operand
// --------------------------------------------------

/**
 * @brief Checks whether a character is an operand.
 *
 * Operands are either alphabetic characters (a-z, A-Z) or digits (0-9).
 *
 * @param ch The character to check.
 * @return true if the character is an operand, false otherwise.
 */
bool isOperand(char ch)
{
    return (isalpha(ch) || isdigit(ch));
}

// -------------------------------------------------------------------
// Function: prefixToPostfix
// Description:
//      Converts a prefix expression to a postfix expression using a stack.
// -------------------------------------------------------------------

/**
 * @brief Converts a prefix expression to a postfix expression.
 *
 * This function processes the input string from right to left. Each operand
 * is pushed onto a stack. When an operator is encountered, the top two
 * operands are popped, a new postfix expression is formed by appending
 * them followed by the operator, and then pushed back onto the stack.
 *
 * @param s The prefix expression string.
 * @return string The equivalent postfix expression.
 *
 * @note Time Complexity: O(N) — where N is the length of the prefix string.
 *       Space Complexity: O(N) — for stack space and intermediate strings.
 */
string prefixToPostfix(string s)
{
    int i = s.size() - 1;
    stack<string> st;

    while (i >= 0)
    {
        if (isOperand(s[i]))
        {
            // Push operand as a string to the stack
            st.push(string{s[i]});
        }
        else
        {
            // Operator encountered: pop top two elements from stack
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();

            // Construct postfix expression: operand1 + operand2 + operator
            string exp = top1 + top2 + s[i];

            // Push the new expression back to the stack
            st.push(exp);
        }
        i--;
    }

    // The final element in the stack is the fully-formed postfix expression
    return st.top();
}

// --------------------------------------------
// Driver Code: Demonstrates the conversion
// --------------------------------------------
int main()
{
    string prefix_one = "/-ab*+def";
    cout << "Prefix: " << prefix_one << endl;
    string postfix_one = prefixToPostfix(prefix_one);
    cout << "Postfix: " << postfix_one << endl;
    cout << "-------------------------------" << endl;

    string prefix_two = "-*+AB+CD/EF";
    cout << "Prefix: " << prefix_two << endl;
    string postfix_two = prefixToPostfix(prefix_two);
    cout << "Postfix: " << postfix_two << endl;

    return 0;
}
