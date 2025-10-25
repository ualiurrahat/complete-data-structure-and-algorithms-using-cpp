/**
 * @file 03_palindromeNumber.cpp
 * @brief Problem: Check if an integer is a palindrome.
 *
 * @details
 * Problem Statement:
 * Given an integer x, return true if x is a palindrome, and false otherwise.
 *
 * Example 1:
 * Input: x = 121
 * Output: true
 * Explanation: 121 reads as 121 from left to right and from right to left.
 *
 * Example 2:
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it becomes 121-.
 * Therefore, it is not a palindrome.
 *
 * Example 3:
 * Input: x = 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 *
 * Constraints:
 * -2^31 <= x <= 2^31 - 1
 */

#include <iostream>
#include <climits> // for INT_MAX and INT_MIN
using namespace std;

// ---------------------------------------------------------
// Helper Function: Reverse an Integer
// ---------------------------------------------------------

/**
 * @brief Reverses the digits of a signed 32-bit integer.
 *
 * This helper function reverses the digits of the integer `x`.
 * If the reversed number overflows the 32-bit integer range, it returns 0.
 *
 * @param x The integer to reverse.
 * @return The reversed integer if within range, otherwise 0.
 *
 * @note
 * Time Complexity: O(log₁₀ |x|)
 * - Each iteration processes one digit of `x`.
 * Space Complexity: O(1)
 * - Uses only constant extra space.
 */
int reverseOptimal(int x)
{
    int reversedNumber = 0;

    while (x)
    {
        int lastDigit = x % 10; // Extract the last digit

        // Check for integer overflow or underflow before updating reversedNumber
        if ((reversedNumber > INT_MAX / 10) || (reversedNumber < INT_MIN / 10))
        {
            return 0; // Return 0 if reversing exceeds 32-bit signed range
        }

        reversedNumber = reversedNumber * 10 + lastDigit; // Append the digit
        x = x / 10;                                       // Remove the last digit
    }

    return reversedNumber;
}

/**
 * @brief Determines whether a given integer is a palindrome.
 *
 * A palindrome number reads the same backward and forward.
 * For negative numbers, we immediately return false since the minus sign
 * will make them non-palindromic.
 *
 * This function compares the original number with its reversed version.
 *
 * @param x The integer to check for palindrome property.
 * @return true if x is a palindrome, otherwise false.
 *
 * @note
 * Time Complexity: O(log₁₀ |x|)
 * - The reversal process and comparison depend on the number of digits.
 * Space Complexity: O(1)
 * - Only a few integer variables are used.
 */
bool isPalindromeOptimal(int x)
{
    // Negative numbers cannot be palindromes
    if (x < 0)
    {
        return false;
    }

    int originalNumber = x;
    int reversedNumber = reverseOptimal(x);

    // Compare original and reversed values
    if (originalNumber == reversedNumber)
    {
        return true;
    }
    return false;
}

// ---------------------------------------------------------
// Main Function (Test Cases)
// ---------------------------------------------------------

int main()
{
    // Test Case 1
    int x1 = 121;
    cout << x1 << " -> " << (isPalindromeOptimal(x1) ? "true" : "false") << endl;
    // Expected Output: true

    // Test Case 2
    int x2 = -121;
    cout << x2 << " -> " << (isPalindromeOptimal(x2) ? "true" : "false") << endl;
    // Expected Output: false

    // Test Case 3
    int x3 = 10;
    cout << x3 << " -> " << (isPalindromeOptimal(x3) ? "true" : "false") << endl;
    // Expected Output: false

    // Test Case 4
    int x4 = 1221;
    cout << x4 << " -> " << (isPalindromeOptimal(x4) ? "true" : "false") << endl;
    // Expected Output: true

    return 0;
}
