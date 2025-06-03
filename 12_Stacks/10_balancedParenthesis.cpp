// Given a string consisting of brackets: '(', ')', '{', '}', '[', ']',
// this program checks whether the sequence of brackets is valid or not.
// Example 1: input = "([{}])"  → output: valid → true
// Example 2: input = "]([]){}" → output: invalid → false

#include <iostream>
#include <stack>
using namespace std;

// Function to check whether the given string has valid parentheses
bool isValid(string str)
{
    // Create a stack to store opening brackets
    stack<char> s;

    // Traverse each character in the input string
    for (int i = 0; i < str.length(); i++)
    {
        // If the current character is an opening bracket
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            // Push the opening bracket onto the stack
            s.push(str[i]);
        }
        // If the current character is a closing bracket
        else
        {
            // If the stack is empty, it means there's no matching opening bracket
            if (s.empty())
            {
                // Return false as the bracket sequence is invalid
                return false;
            }

            // Retrieve the top element from the stack
            char ch = s.top();
            // Remove the top element from the stack
            s.pop();

            // Check if the current closing bracket matches the top opening bracket
            if ((ch == '(' && str[i] == ')') ||
                (ch == '{' && str[i] == '}') ||
                (ch == '[' && str[i] == ']'))
            {
                // Bracket pair is valid, continue checking remaining characters
                continue;
            }
            else
            {
                // Bracket pair mismatch, hence the sequence is invalid
                return false;
            }
        }
    }

    // After processing the entire string, the stack should be empty
    // If not, it indicates unmatched opening brackets
    return s.empty();

    // T:O(N), N == size of string
    // S:O(N), at max all can be opening brackets and stack can have N elements
    // NOTE: This is the most optimized solution
    // we can not solve it in better way since we need store the opening parenthesis
    // to check and verify the balancing thing.
}

int main()
{
    char str[100];
    cout << "Enter your string: ";
    cin >> str; // ((({{}})))

    // Check if the entered string contains a valid sequence of brackets
    cout
        << isValid(str) << endl; // 1

    return 0;
}
