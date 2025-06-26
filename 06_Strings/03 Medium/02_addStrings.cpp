/**
 * @file addStrings.cpp
 * @brief Add two non-negative integers represented as strings.
 */

/**
 * Problem Statement:
 * Given two non-negative integers `num1` and `num2` represented as strings,
 * return their sum as a string. You must not use any built-in library
 * for handling large integers or directly convert the strings to integers.
 *
 * Example:
 * Input: num1 = "11", num2 = "123" → Output: "134"
 * Input: num1 = "456", num2 = "77" → Output: "533"
 * Input: num1 = "0", num2 = "0" → Output: "0"
 */

#include <iostream>
#include <string>
#include <algorithm> // for reverse

using namespace std;

/**
 * @brief Helper function to add two strings where num1 >= num2
 *
 * @param num1 String representing a large number (guaranteed longer or equal length)
 * @param num2 String representing a smaller or equal-length number
 * @return string Sum of num1 and num2 as string
 *
 * @note Time Complexity: O(n1) + O(n2) + O(n1+n2)(for reversing) = O(n1+n2)
 * @note Space Complexity: O(n1+n2), for storing the answer string
 */
string add(string &num1, string &num2)
{
    int index1 = num1.size() - 1;
    int index2 = num2.size() - 1;
    int carry = 0;
    int sum = 0;
    string ans = "";

    // ---------------------- Add digits while both strings have characters ----------------------
    while (index2 >= 0)
    {
        sum = (num1[index1] - '0') + (num2[index2] - '0') + carry;
        carry = sum / 10;
        char ch = (sum % 10) + '0';
        ans += ch;
        index1--;
        index2--;
    }

    // ---------------------- Add remaining digits from num1 ----------------------
    while (index1 >= 0)
    {
        sum = (num1[index1] - '0') + carry;
        carry = sum / 10;
        char ch = (sum % 10) + '0';
        ans += ch;
        index1--;
    }

    // ---------------------- If there's a carry left, add it ----------------------
    if (carry)
    {
        ans += '1';
    }

    // ---------------------- Reverse the result to get correct order ----------------------
    reverse(ans.begin(), ans.end());
    return ans;
}

/**
 * @brief Main interface function to handle any input order.
 *
 * @param num1 First number as string
 * @param num2 Second number as string
 * @return string Sum of the numbers as string
 *
 * @note Time Complexity: O(n1) + O(n2) + O(n1+n2)(for reversing) = O(n1+n2)
 * @note Space Complexity: O(n1+n2), for storing the answer string
 *
 */
string addStrings(string num1, string num2)
{
    string ans;

    // ---------------------- Ensure num1 is longer ----------------------
    if (num1.size() < num2.size())
    {
        ans = add(num2, num1);
    }
    else
    {
        ans = add(num1, num2);
    }

    return ans;
}

/**
 * @brief Main function to demonstrate usage of addStrings.
 */
int main()
{
    // Example 1
    string num1 = "11", num2 = "123";
    cout << "Sum: " << addStrings(num1, num2) << endl; // Output: 134

    // Example 2
    num1 = "456", num2 = "77";
    cout << "Sum: " << addStrings(num1, num2) << endl; // Output: 533

    // Example 3
    num1 = "0", num2 = "0";
    cout << "Sum: " << addStrings(num1, num2) << endl; // Output: 0

    return 0;
}
