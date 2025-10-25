/**
 * @file 02_reverseInteger.cpp
 * @brief Problem: Reverse digits of a signed 32-bit integer.
 *
 * @details
 * Problem Statement:
 * Given a signed 32-bit integer x, return x with its digits reversed.
 * If reversing x causes the value to go outside the signed 32-bit integer range
 * [-2^31, 2^31 - 1], then return 0.
 *
 * Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 *
 * Example 1:
 * Input: x = 123
 * Output: 321
 *
 * Example 2:
 * Input: x = -123
 * Output: -321
 *
 * Example 3:
 * Input: x = 120
 * Output: 21
 *
 * Constraints:
 * -2^31 <= x <= 2^31 - 1
 */

#include <iostream>
#include <climits> // for INT_MAX and INT_MIN
using namespace std;

// ---------------------------------------------------------
// Optimal Solution
// ---------------------------------------------------------

/**
 * @brief Reverses the digits of a signed 32-bit integer.
 *
 * This function takes an integer `x`, extracts its digits one by one using
 * the modulo operator, and constructs the reversed number.
 * It carefully checks for overflow or underflow conditions before multiplying
 * or adding digits, since we cannot use 64-bit data types.
 *
 * @param x The input integer to be reversed.
 * @return The reversed integer if it remains within 32-bit signed integer range,
 * otherwise returns 0 to indicate overflow/underflow.
 *
 * @note
 * Time Complexity: O(log₁₀ |x|)
 * - Explanation: Each iteration processes one digit of `x`.
 * Space Complexity: O(1)
 * - Explanation: Uses only a few constant variables for computation.
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

int main()
{
    // Test case 1
    int x1 = 123;
    cout << "Reversed of " << x1 << " = " << reverseOptimal(x1) << endl;
    // Expected Output: 321

    // Test case 2
    int x2 = -123;
    cout << "Reversed of " << x2 << " = " << reverseOptimal(x2) << endl;
    // Expected Output: -321

    // Test case 3
    int x3 = 120;
    cout << "Reversed of " << x3 << " = " << reverseOptimal(x3) << endl;
    // Expected Output: 21

    // Test case 4 (overflow check)
    int x4 = 1534236469;
    cout << "Reversed of " << x4 << " = " << reverseOptimal(x4) << endl;
    // Expected Output: 0 (overflow)

    return 0;
}
