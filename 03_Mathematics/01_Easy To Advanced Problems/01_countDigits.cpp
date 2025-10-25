/**
 * @file 01countDigits.cpp
 * @brief Problem: Count the number of digits in a given integer.
 *
 * @details
 * Problem Statement:
 * You are given a number 'n'.
 * Return the number of digits in ‘n’.
 *
 * Example:
 * Input: n = 123
 * Output: 3
 * Explanation:
 * The 3 digits in ‘123’ are 1, 2, and 3.
 *
 * Expected Time Complexity: O(log n)
 * Constraints: 1 <= n <= 10^9
 */

#include <iostream>
#include <cmath> // for log10 function
using namespace std;

// ---------------------------------------------------------
// Brute Force Solution
// ---------------------------------------------------------

/**
 * @brief Counts digits by repeatedly dividing the number by 10.
 *
 * This method divides the number by 10 until it becomes 0.
 * Each division effectively removes the last digit of the number.
 *
 * @param n The given number.
 * @return The count of digits in the number.
 *
 * @note
 * Time Complexity: O(log₁₀ n)
 * - Explanation: Each division by 10 reduces one digit → about log₁₀(n) steps.
 * Space Complexity: O(1)
 * - Explanation: Uses a few constant-size variables.
 */
int countDigitsBrute(int n)
{
    int count = 0;
    while (n)
    {
        n = n / 10; // Remove last digit
        count++;    // Increase count for each digit
    }
    return count;
}

// ---------------------------------------------------------
// Optimal Solution
// ---------------------------------------------------------

/**
 * @brief Counts digits using the logarithmic property.
 *
 * Formula: number of digits in n = floor(log₁₀(n)) + 1
 * Works because log₁₀(n) gives the exponent when 10 is raised to reach n.
 *
 * @param n The given number.
 * @return The count of digits in the number.
 *
 * @note
 * Time Complexity: O(1)
 * - Explanation: Uses a single mathematical operation (logarithm).
 * Space Complexity: O(1)
 * - Explanation: Uses only constant extra memory.
 */

// ---------------------------------------------------------
// Better Solution
// ---------------------------------------------------------

/**
 * @brief Counts digits by converting the number into a string.
 *
 * This method uses the C++ built-in `to_string()` function to
 * convert the integer into its string representation.
 * Then, the length of the string gives the total number of digits.
 *
 * @param n The given number.
 * @return The count of digits in the number.
 *
 * @note
 * Time Complexity: O(log₁₀ n)
 * - Explanation: The conversion process runs once per digit (same as number length).
 *
 * Space Complexity: O(log₁₀ n)
 * - Explanation: A new string of digits is created, storing one character per digit.
 */
int countDigitsBetter(int n)
{
    string num = to_string(n); // Convert integer to string
    return num.length();       // Return number of characters (digits)
}

int countDigitsOptimal(int n)
{
    return floor(log10(n)) + 1;
}

// ---------------------------------------------------------
// Main Function (Test Cases)
// ---------------------------------------------------------

int main()
{
    // Test case 1
    int n1 = 121;
    cout << "Number of digits in " << n1 << " = " << countDigitsBrute(n1) << endl;
    // Expected Output: 3

    // Test case 2
    int n2 = 38;
    cout << "Number of digits in " << n2 << " = " << countDigitsBetter(n2) << endl;
    // Expected Output: 2

    // Test case 3
    int n3 = 12345;
    cout << "Number of digits in " << n3 << " = " << countDigitsOptimal(n3) << endl;
    // Expected Output: 5

    return 0;
}
