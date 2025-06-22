/*
Problem statement:
You are given a string denoting a valid Postfix expression containing '+', '-', '*', '/' and lowercase letters.

Convert the given Postfix expression into a Prefix expression.

Note:
Postfix notation is a method of writing mathematical expressions in which operators are placed after the operands. For example, "a b +" represents the addition of a and b.
Prefix notation is a method of writing mathematical expressions in which operators are placed before the operands. For example, "+ a b" represents the addition of a and b.

Expression contains lowercase English letters, '+', '-', '*', and '/'.
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
 * Operands are either alphabetic characters (a-z) or digits (0-9).
 *
 * @param ch The character to check.
 * @return true if the character is an operand, false otherwise.
 */
bool isOperand(char ch)
{
    return (isalpha(ch) || isdigit(ch));
}

// -------------------------------------------------------------------
// Function: postfixToPrefix
// Description:
//      Converts a postfix expression to a prefix expression using a stack.
// -------------------------------------------------------------------

/**
 * @brief Converts a postfix expression to a prefix expression.
 *
 * This function iteratively scans each character from left to right.
 * Operands are pushed to the stack, and for every operator encountered,
 * the top two elements of the stack are popped, concatenated into a prefix
 * expression with the operator placed in front, and pushed back to the stack.
 *
 * @param s The postfix expression string.
 * @return string The equivalent prefix expression.
 *
 * @note Time Complexity: O(N) — where N is the length of the postfix string.
 *       Space Complexity: O(N) — for stack space and intermediate expressions.
 */
string postfixToPrefix(string &s)
{
    int i = 0, n = s.size();
    stack<string> st;

    while (i < n)
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

            // Construct prefix expression: operator + operand1 + operand2
            string exp = s[i] + top2 + top1;

            // Push the new expression back to the stack
            st.push(exp);
        }
        i++;
    }

    // The final element in the stack is the fully-formed prefix expression
    return st.top();
}

// --------------------------------------------
// Driver Code: Demonstrates the conversion
// --------------------------------------------
int main()
{
    string postfix_one = "ab+cd-*";
    cout << "Postfix: " << postfix_one << endl;
    string prefix_one = postfixToPrefix(postfix_one);
    cout << "Prefix: " << prefix_one << endl;
    cout << "-------------------------------" << endl;

    string postfix_two = "ABC/-AK/L-*";
    cout << "Postfix: " << postfix_two << endl;
    string prefix_two = postfixToPrefix(postfix_two);
    cout << "Prefix: " << prefix_two << endl;

    return 0;
}
