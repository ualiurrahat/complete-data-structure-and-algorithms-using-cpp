

/**
 * @file 02_PowerFunction.cpp
 * @brief Implements pow(x, n) to calculate x raised to the power n using binary exponentiation.
 *
 * This file implements an efficient algorithm to compute \( x^n \), handling both positive and negative exponents.
 * The solution uses binary exponentiation to reduce the number of multiplications.
 *
 * New Topics Introduced:
 * - **Binary Exponentiation**: Reduces the number of multiplications by expressing the exponent in binary form.
 *   - For each bit of the exponent, square the base and multiply the result by the base if the bit is 1.
 *   - Example: \( 2^{10} = 2^{1010_2} = (2^8) * (2^2) \).
 * - **Handling Negative Exponents**: For \( x^{-n} \), compute \( 1/x^n \).
 * - **Integer Overflow with INT_MIN**: Using `long long` to handle the negation of the minimum 32-bit integer (`-2147483648`).
 * - **Use Case**: Binary exponentiation is used in numerical computations, cryptography, and scientific simulations.
 *
 * The function computes \( x^n \) by iteratively squaring \( x \) and multiplying the result when the exponent’s binary bit is 1.
 * It handles negative exponents by computing the positive power and taking the reciprocal.
 *
 * Time Complexity: O(log n), where n is the exponent, as the algorithm processes each bit of n.
 * Space Complexity: O(1), as it uses a constant amount of extra space.
 */

#include <iostream>
using namespace std;

// brute force solution

double powerBrute(double x, int n)
{
    double val = 1.0;
    // when n is positive value
    if (n > 0)
    {
        for (int i = n; i >= 1; i--)
        {
            val = val * x;
        }
    }
    else
    // when n is nagative.
    {
        val = val * x;
        for (int i = n; i < 0; i++)
        {
            val = val / x;
        }
        val = val / x;
    }
    return val;
    // T:O(n)
    // S:O(1)
}
/**
 * @brief Computes x raised to the power n using binary exponentiation.
 * @param x The base (double).
 * @param n The exponent (int).
 * @return double The result of x^n.
 *
 * This function uses binary exponentiation to efficiently compute \( x^n \):
 * - Converts the exponent to `long long` to handle INT_MIN without overflow.
 * - For negative n, computes \( 1/x^{|n|} \).
 * - Iteratively processes the binary representation of n:
 *   - If n is odd, multiplies the result by x and decrements n.
 *   - If n is even, squares x and divides n by 2.
 * - Continues until n becomes 0.
 *
 * Time Complexity: O(log n), as it processes each bit of n (log n bits).
 * Space Complexity: O(1), using only a few variables.
 */
double myPowOptimal(double x, int n)
{
    double ans = 1.0;
    long long N = n; // Use long long to avoid overflow with INT_MIN

    // Handle negative exponent
    if (N < 0)
    {
        x = 1.0 / x; // For negative n, compute 1/x^n
        N = -N;      // Use long long to safely negate
    }

    // Binary exponentiation
    while (N > 0)
    {
        if (N % 2 == 1)
        { // If n is odd, multiply result by x
            ans *= x;
            N -= 1;
        }
        else
        { // If n is even, square x and divide n by 2
            x *= x;
            N /= 2;
        }
    }

    return ans;
}

/**
 * @brief Main function to test the power function.
 * @return int Program exit status.
 *
 * Tests myPow with example inputs and prints results.
 */
int main()
{
    // Test cases
    cout << "Test 1: 2^10 = " << myPowOptimal(2.0, 10) << endl;   // Output: 1024
    cout << "Test 2: 2.1^3 = " << myPowOptimal(2.1, 3) << endl;   // Output: 9.261
    cout << "Test 3: 2^(-2) = " << myPowOptimal(2.0, -2) << endl; // Output: 0.25
    return 0;
}
