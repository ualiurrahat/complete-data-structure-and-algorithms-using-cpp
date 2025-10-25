/**
 * @file 02_printDigits.cpp
 * @brief Print each digit of a given number in a new line.
 *
 * ---------------------- Problem Statement ----------------------
 * You are given a positive integer 'n'.
 * Your task is to print each digit of 'n' on a new line, starting from
 * the most significant digit (leftmost) to the least significant digit (rightmost).
 *
 * Example:
 * Input:  n = 4729
 * Output:
 * 4
 * 7
 * 2
 * 9
 *
 * ---------------------------------------------------------------
 */

#include <iostream>
#include <cmath> // for pow() function
using namespace std;

/**
 * @brief Prints each digit of a number in a new line (from most significant to least significant).
 *
 * @param n The input integer whose digits are to be printed.
 *
 * @note
 * - Step 1: Count total digits of n.
 * - Step 2: Compute divisor = 10^(digits - 1).
 * - Step 3: Use divisor to extract and print digits one by one.
 *
 * @note
 * Time Complexity: O(log₁₀(n)) — because the number has log₁₀(n) digits.
 * Space Complexity: O(1) — we use only a few integer variables.
 */
void printDigits(int n)
{
    // Step 1️⃣: Find total number of digits
    int totalDigits = 0;
    int temp = n;

    while (temp)
    {
        temp = temp / 10; // remove one digit
        totalDigits++;    // increment count
    }

    // Step 2️⃣: Compute the divisor = 10^(totalDigits - 1)
    // Example: if n = 4729 → totalDigits = 4 → divisor = 10^(4-1) = 1000
    int divisor = pow(10, totalDigits - 1);

    // Step 3️⃣: Loop until divisor becomes 0
    while (divisor != 0)
    {
        // The quotient (n / divisor) gives the leftmost digit
        int digit = n / divisor;

        // Print that digit
        cout << digit << endl;

        // Remove that digit from n
        n = n % divisor;

        // Reduce divisor by a factor of 10 to move to next digit
        divisor = divisor / 10;
    }
}

/**
 * @brief Demonstrates the printDigits() function with sample input.
 */
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Function call to print all digits
    printDigits(n);

    /**
     * ---------------- Example ----------------
     * Input:
     * 4729
     *
     * Output:
     * 4
     * 7
     * 2
     * 9
     * ------------------------------------------
     */
    return 0;
}
