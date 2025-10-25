/**
 * @file 06_isArmstrong.cpp
 * @brief Program to check whether a given number is an Armstrong number or not.
 *
 * Problem statement:
 * You are given an integer ‘NUM’. Your task is to find out whether this number is an Armstrong number or not.
 *
 * A k-digit number ‘NUM’ is an Armstrong number if and only if the k-th power of each digit sums to ‘NUM’.
 *
 * Example:
 * 153 = 1^3 + 5^3 + 3^3 = 153 → Armstrong number
 *
 * Constraints:
 * 1 <= T <= 100
 * 1 <= N <= 10^9
 *
 * Expected Time Complexity: O(k), where k is the number of digits.
 * Expected Space Complexity: O(1)
 */

#include <iostream>
#include <cmath> // for log10 and pow functions
using namespace std;

// ---------------------------------------------------------
// Helper Function: countDigits()
// ---------------------------------------------------------

/**
 * @brief Counts the number of digits in a given integer.
 *
 * @param n The input number.
 * @return The count of digits in 'n'.
 *
 * @note
 * Time Complexity: O(1)
 * - Uses log₁₀(n) which is a mathematical constant-time operation.
 * Space Complexity: O(1)
 */
int countDigits(int n)
{
    return log10(n) + 1;
}

// ---------------------------------------------------------
// Helper Function: power()
// ---------------------------------------------------------

/**
 * @brief Calculates the power of a number manually (base ^ exponent).
 *
 * This avoids using built-in `pow()` to demonstrate iterative power calculation.
 *
 * @param base The base number.
 * @param exponent The exponent.
 * @return Result of base raised to the exponent.
 *
 * @note
 * Time Complexity: O(exponent)
 * Space Complexity: O(1)
 */
int power(int base, int exponent)
{
    int result = 1; // Start from 1, since anything raised to 0 is 1

    // Multiply base 'exponent' number of times
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

// ---------------------------------------------------------
// Brute Force Solution
// ---------------------------------------------------------

/**
 * @brief Checks if a number is an Armstrong number using manual power computation.
 *
 * Steps:
 * 1. Count number of digits (k).
 * 2. Extract each digit using modulus.
 * 3. Compute digit^k manually and add to a running sum.
 * 4. Compare sum with original number.
 *
 * @param num The number to be checked.
 * @return true if 'num' is an Armstrong number, false otherwise.
 *
 * @note
 * Time Complexity: O(k²) because for each digit (k iterations), we compute power in O(k).
 * Space Complexity: O(1)
 */
bool isArmstrongBrute(int num)
{
    int powerExponent = countDigits(num); // Step 1: Count digits
    int temp = num;
    int sum = 0;

    while (temp)
    {
        int lastDigit = temp % 10;              // Extract last digit
        sum += power(lastDigit, powerExponent); // Add (digit ^ count)
        temp /= 10;                             // Remove last digit
    }

    return (sum == num);
}

// ---------------------------------------------------------
// Better Solution
// ---------------------------------------------------------

/**
 * @brief Checks if a number is an Armstrong number using pow() function from <cmath>.
 *
 * Steps are same as brute force, but uses built-in `pow()` for efficient power calculation.
 *
 * @param num The number to be checked.
 * @return true if 'num' is an Armstrong number, false otherwise.
 *
 * @note
 * Time Complexity: O(k)
 * - We loop once per digit, and pow() is efficient for small exponents.
 * Space Complexity: O(1)
 */
bool isArmstrongBetter(int num)
{
    int powerExponent = countDigits(num);
    int temp = num;
    int sum = 0;

    while (temp)
    {
        int lastDigit = temp % 10;            // Extract last digit
        sum += pow(lastDigit, powerExponent); // Use pow() instead of manual loop
        temp /= 10;                           // Remove last digit
    }

    return (sum == num);
}

// ---------------------------------------------------------
// Optimal Solution
// ---------------------------------------------------------

/**
 * @brief Optimized version to check if a number is an Armstrong number.
 *
 * This version avoids calling helper functions repeatedly and reduces computation slightly.
 * The logic is fundamentally same but designed for efficiency and readability.
 *
 * @param num The number to be checked.
 * @return true if 'num' is an Armstrong number, false otherwise.
 *
 * @note
 * Time Complexity: O(k)
 * Space Complexity: O(1)
 */
bool isArmstrongOptimal(int num)
{
    int powerExponent = (num == 0) ? 1 : floor(log10(num)) + 1; // Count digits efficiently
    int temp = num;
    int sum = 0;

    while (temp)
    {
        int lastDigit = temp % 10;
        sum += pow(lastDigit, powerExponent);
        temp /= 10;
    }

    return (sum == num);
}

// ---------------------------------------------------------
// Main Function (Test Cases)
// ---------------------------------------------------------

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    // Sample outputs
    cout << "Brute Force: " << (isArmstrongBrute(num) ? "YES" : "NO") << endl; // Expected: YES for 153
    cout << "Better: " << (isArmstrongBetter(num) ? "YES" : "NO") << endl;     // Expected: YES for 371
    cout << "Optimal: " << (isArmstrongOptimal(num) ? "YES" : "NO") << endl;   // Expected: NO for 13

    return 0;
}

/*
Example Input/Output:
--------------------
Input: 153
Output:
Brute Force: YES
Better: YES
Optimal: YES

Input: 13
Output:
Brute Force: NO
Better: NO
Optimal: NO
*/
