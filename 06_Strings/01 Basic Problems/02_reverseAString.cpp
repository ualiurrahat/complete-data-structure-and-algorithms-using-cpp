/*
Problem Statement:
You are given a string. You have to reverse it.

Example:
Input:  "Rahat"
Output: "tahaR"
*/

#include <iostream> // for cin and cout
using namespace std;

// brute force approach to reverse a string
void reverseBrute(string &str)
{
    string ans = "";    // To store reversed string
    int n = str.size(); // Length of the original string
    for (int i = n - 1; i >= 0; i--)
    {
        ans = ans + str[i]; // Append characters in reverse order
    }
    str = ans; // Assign reversed result to original
    return;
    // T:O(N), S:O(N)
}

/*
Function: reverseStringOptimal
Approach: Two-pointer Technique (Optimal)
*/
void reverseStringOptimal(string &str)
{
    int i = 0, j = str.size() - 1; // Initialize pointers
    while (i < j)
    {
        swap(str[i], str[j]); // Swap characters
        i++;                  // Move start forward
        j--;                  // Move end backward
    }
    return;
    // T:O(N/2), S:O(1)
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str; // Input the string

    // reverseBrute(str);        // Call this for brute-force approach

    reverseStringOptimal(str);                  // Call optimal in-place reversal
    cout << "Reversed string: " << str << endl; // Output the result
    return 0;
}
