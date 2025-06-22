/*
Problem statement:
You are given a string denoting a valid Prefix expression containing '+', '-', '*', '/' and lowercase letters.

Convert the given Prefix expression into an Infix expression.

Note:
Infix notation is a method of writing mathematical expressions in which operators are placed between operands. For example, "a + b" represents the addition of a and b.
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
// Function: prefixToInfixConversion
// Description:
//      Converts a prefix expression to an infix expression using a stack.
// -------------------------------------------------------------------

/**
 * @brief Converts a prefix expression to an infix expression.
 *
 * This function processes the input string from right to left. Each operand
 * is pushed onto the stack. When an operator is encountered, the top two
 * operands are popped, combined into a new parenthesized infix expression,
 * and pushed back onto the stack.
 *
 * @param s The prefix expression string.
 * @return string The equivalent infix expression with full parentheses.
 *
 * @note Time Complexity: O(N) — where N is the length of the prefix string.
 *       Space Complexity: O(N) — for stack space and intermediate strings.
 */
string prefixToInfixConversion(string &s)
{
    stack<string> st; // Stack to store intermediate infix expressions
    int i = s.size() - 1;

    while (i >= 0)
    {
        if (isOperand(s[i]))
        {
            // Convert single character operand to string and push to stack
            st.push(string{s[i]});
        }
        else
        {
            // Operator encountered: pop top two elements from stack
            string first = st.top();
            st.pop();
            string second = st.top();
            st.pop();

            // Combine into infix format: (first op second)
            string exp = '(' + first + s[i] + second + ')';

            // Push the new expression back to the stack
            st.push(exp);
        }
        i--;
    }

    // The final element in the stack is the fully-formed infix expression
    return st.top();
}

// --------------------------------------------
// Driver Code: Demonstrates the conversion
// --------------------------------------------
int main()
{
    string prefix_one = "*-a/bc-/dkl";
    cout << "Prefix: " << prefix_one << endl;
    string infix_one = prefixToInfixConversion(prefix_one);
    cout << "Infix: " << infix_one << endl;
    cout << "-------------------------------" << endl;

    string prefix_two = "*-a/bc-/del";
    cout << "Prefix: " << prefix_two << endl;
    string infix_two = prefixToInfixConversion(prefix_two);
    cout << "Infix: " << infix_two << endl;

    return 0;
}
