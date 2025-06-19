/*
Problem statement:
You are given a mathematical expression in postfix notation. The expression consists of alphabets (both lowercase and uppercase) and operators.

Convert this expression to infix notation.

Note:
Surround every expression with a pair of parentheses "()".

Example:
Input:  postfix = "ab+c+"
Output: infix  = "((a+b)+c)"

Explanation:
The expression "((a+b)+c)" in infix is equivalent to "ab+c+" in postfix.
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
 * Operands are either alphabetic characters (A-Z, a-z) or digits (0-9).
 *
 * @param ch The character to check.
 * @return true if the character is an operand, false otherwise.
 */
bool isOperand(char ch)
{
    return (isalpha(ch) || isdigit(ch));
}

// -------------------------------------------------------------------
// Function: postToInfix
// Description:
//      Converts a postfix expression to an infix expression by using a stack.
// -------------------------------------------------------------------

/**
 * @brief Converts a postfix expression to an infix expression.
 *
 * This function uses a stack to iteratively convert each character in the postfix
 * expression into a valid infix expression. Each operand is pushed to the stack,
 * and each operator pops the top two operands, combines them into an infix
 * expression with parentheses, and pushes the result back.
 *
 * @param postfix The postfix expression string.
 * @return string The equivalent infix expression with full parentheses.
 *
 * @note Time Complexity: O(N) + O(N1 + N2) where N is length of postfix,
 *       and N1, N2 are lengths of intermediate expressions.
 *       => Effectively O(N)
 *       Space Complexity: O(N) for stack space
 */
string postToInfix(string postfix)
{
    stack<string> st; // Stack to store intermediate infix expressions
    int n = postfix.size();
    int i = 0;

    while (i < n)
    {
        if (isOperand(postfix[i]))
        {
            // Convert single character operand to string and push to stack
            st.push(string{postfix[i]});
        }
        else
        {
            // Operator encountered: pop two top elements from stack
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            // Combine into a valid infix expression with parentheses
            // for postfix to infix converstion, structure = second top(t2) + operator + first top(t1)
            string exp = '(' + t2 + postfix[i] + t1 + ')';

            // Push the new expression back to the stack
            st.push(exp);
        }
        i++;
    }

    // The final element of the stack is the fully-formed infix expression
    return st.top();
}

// --------------------------------------------
// Driver Code: Demonstrates the conversion
// --------------------------------------------
int main()
{
    string postfix_one = "ab+c+";
    cout << "Postfix: " << postfix_one << endl;
    string infix_one = postToInfix(postfix_one);
    cout << "Infix: " << infix_one << endl;
    cout << "-------------------------------" << endl;

    string postfix_two = "ABC/DA-*+";
    cout << "Postfix: " << postfix_two << endl;
    string infix_two = postToInfix(postfix_two);
    cout << "Infix: " << infix_two << endl;

    return 0;
}
