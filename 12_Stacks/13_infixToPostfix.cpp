/*
Problem statement
You are given a string 'exp' which is a valid infix expression.
Convert the given infix expression to postfix expression.

Note:
Infix notation is a method of writing mathematical expressions in which operators are placed between operands.
For example, "3 + 4" represents the addition of 3 and 4.
Postfix notation is a method of writing mathematical expressions in which operators are placed after the operands.
For example, "3 4 +" represents the addition of 3 and 4.
Expression contains digits, lower case English letters, ‘(’, ‘)’, ‘+’, ‘-’, ‘*’, ‘/’, ‘^’.

Example:
Input: exp = ‘3+4*8’
Output: 348*+

Explanation:
Here multiplication is performed first and then the addition operation. Hence postfix expression is  3 4 8 * +.
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// function to return precedence i.e. priority of operator
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}
// The main function to convert infix expression
// to postfix expression
string infixToPostfix(string exp)
{
    // for stack operation, using c++ built in stack
    stack<char> st;
    string result; // stores to postfix expression == output of the function
    int n = exp.size();

    // iterate over the given string
    for (int i = 0; i < n; i++)
    {
        // case 1: if the current character is an operand,
        // then add it to the result
        if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= '0' && exp[i] <= '9'))
        {
            result += exp[i];
        }
        // case 2: if the current character is an opening bracket '(',
        // then push it to the stack
        else if (exp[i] == '(')
        {
            st.push(exp[i]);
        }
        // case 3: if the current character is a closing bracket ')'
        // pop out elements from the stack and
        // add them to the result string
        // untill a ')' is encounterd in the stack
        else if (exp[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result = result + st.top();
                st.pop();
            }
            // now the tope elment in stack is '('.
            // pop out the opening bracket '(' from the stack
            st.pop();
        }
        // case 4: if the current char is an operand
        // pop out operands whose priority is greater than or equal to current char operand
        // and add them to the result
        else
        {
            while (!st.empty() && precedence(exp[i]) <= precedence(st.top()))
            {
                result = result + st.top();
                st.pop();
            }
            // now no element in the stack has higher precedence than current one.
            // push it to the stack
            st.push(exp[i]);
        }
    }
    // pop all the remaining elements from the stack
    while (!st.empty())
    {
        result = result + st.top();
        st.pop();
    }
    return result;
    // Time Complexity: O(N)
    // - Each character in the input expression is processed exactly once in the for-loop → O(N)
    // - Each operator is pushed and popped from the stack at most once → O(N)
    // - Therefore, the total time complexity is O(N)

    // Space Complexity: O(N)
    // - Stack can store at most N characters in the worst case → O(N)
    // - Result string stores the postfix expression of length up to N → O(N)
    // - Therefore, total auxiliary space used is O(N) + O(N) = O(N)
}

/*
Dry Run Table for exp1 = (p+q)*(m-n)

| Step | Char | Stack (top right) | Result (Postfix) | Action                       |
| ---- | ---- | ----------------- | ---------------- | ---------------------------- |
| 1    | `(`  | (                 |                  | Push `(`                     |
| 2    | `p`  | (                 | p                | Append operand               |
| 3    | `+`  | ( +               | p                | Push operator `+`            |
| 4    | `q`  | ( +               | pq               | Append operand               |
| 5    | `)`  |                   | pq+              | Pop till `(` and discard `(` |
| 6    | `*`  | \*                | pq+              | Push `*`                     |
| 7    | `(`  | \* (              | pq+              | Push `(`                     |
| 8    | `m`  | \* (              | pq+m             | Append operand               |
| 9    | `-`  | \* ( -            | pq+m             | Push operator `-`            |
| 10   | `n`  | \* ( -            | pq+mn            | Append operand               |
| 11   | `)`  | \*                | pq+mn-           | Pop till `(` and discard `(` |
| 12   | END  |                   | pq+mn-\*         | Pop remaining `*` from stack |


*/
int main()
{
    string exp1 = "(p+q)*(m-n)";
    cout << "Infix expression 1: " << exp1 << endl;
    string output1 = infixToPostfix(exp1);
    cout << "Postfix expression 1: " << output1 << endl;

    string exp2 = "(a+b*(c^d)-e)";
    cout << "Infix expression 2: " << exp2 << endl;
    string output2 = infixToPostfix(exp2);
    cout << "Postfix expression 2: " << output2 << endl;
    return 0;
    /*
    Code Output:
    Infix expression 1: (p+q)*(m-n)
    Postfix expression 1: pq+mn-*
    Infix expression 2: (a+b*(c^d)-e)
    Postfix expression 2: abcd^*+e-
    */
}