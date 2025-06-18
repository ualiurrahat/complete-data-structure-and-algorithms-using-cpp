/*
Problem Statement:
Check whether a given string is a palindrome or not.
A palindrome is a string that reads the same forward and backward.

Examples:
Input:  "madam" → Output: true
Input:  "rahat" → Output: false
*/

#include <iostream>
using namespace std;

/*
Brute force approach to check if a string is a palindrome
- Reverse the string
- Compare with the original
*/
bool isPalindromeBrute(string &str)
{
    // Step 1: Initialize an empty string to store reversed string
    string reversed = "";

    // Step 2: Traverse from end and build the reversed string
    for (int i = str.size() - 1; i >= 0; i--)
    {
        reversed += str[i];
    }

    // Step 3: Compare reversed and original
    return str == reversed;

    // T:O(N), S:O(N)
}

/*
Optimal approach using two-pointer technique
- Compare characters from start and end moving toward center
*/
bool isPalindromeOptimal(string &str)
{
    // Step 1: Initialize two pointers at both ends
    int left = 0;
    int right = str.size() - 1;

    // Step 2: Loop while left pointer is before right
    while (left < right)
    {
        // Step 3: If characters don't match, it's not a palindrome
        if (str[left] != str[right])
        {
            return false;
        }

        // Step 4: Move both pointers toward center
        left++;
        right--;
    }

    // Step 5: If all characters matched, it's a palindrome
    return true;

    // T:O(N/2), S:O(1)
}

int main()
{
    string input;

    // Ask for user input
    cout << "Enter a string: ";
    cin >> input;

    // Call the optimal function
    if (isPalindromeOptimal(input))
    {
        cout << input << " is a palindrome!" << endl;
    }
    else
    {
        cout << input << " is not a palindrome!" << endl;
    }

    return 0;
}
