/**
 * @file 01_printFibonacci.cpp
 * @brief Print the first 'n' terms of the Fibonacci series without using an array.
 *
 * ------------------------- Problem Statement -------------------------
 * You are given an integer 'n'. Your task is to print the first 'n' terms
 * of the Fibonacci sequence, starting from 0 and 1.
 *
 * The Fibonacci sequence is defined as:
 * F(0) = 0
 * F(1) = 1
 * F(n) = F(n-1) + F(n-2), for n >= 2
 *
 * Condition: Do NOT use arrays.
 *
 * Example:
 * Input:  n = 7
 * Output: 0 1 1 2 3 5 8
 *
 * ---------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

/**
 * @brief Prints the first 'n' Fibonacci numbers without using an array.
 *
 * @param n Number of Fibonacci terms to print.
 *
 * @note
 * Time Complexity: O(n) — we calculate each term once.
 * Space Complexity: O(1) — we use only three integer variables (a, b, current).
 */
void printFibonacci(int n)
{
    // Handle base case: if n <= 0, no valid Fibonacci term to print
    if (n <= 0)
    {
        cout << "Invalid input. 'n' must be greater than 0." << endl;
        return;
    }

    // Case 1: If only the first term is requested
    if (n == 1)
    {
        cout << "0" << endl;
        return;
    }

    // Case 2: If only the first two terms are requested
    if (n == 2)
    {
        cout << "0 1" << endl;
        return;
    }

    // Case 3: General case (n >= 3)
    int a = 0;       // First Fibonacci term
    int b = 1;       // Second Fibonacci term
    int currentFibo; // To store the next Fibonacci term
    int i = 3;       // Loop counter starts from 3rd term

    // Print the first two terms manually
    cout << a << " " << b << " ";

    // Loop to calculate and print remaining Fibonacci terms
    while (i <= n)
    {
        // Next term = sum of the previous two terms
        currentFibo = a + b;

        // Print current Fibonacci term
        cout << currentFibo << " ";

        // Shift values: previous becomes current, and current becomes next
        a = b;
        b = currentFibo;

        // Move to the next term
        i++;
    }

    cout << endl; // Print a new line at the end
}

/**
 * @brief Demonstrates the printFibonacci() function with sample inputs.
 */
int main()
{
    int n;

    cout << "Enter how many Fibonacci terms you want to see: ";
    cin >> n;

    // Call the function to print the Fibonacci series
    printFibonacci(n);

    /**
     * ---------------- Example ----------------
     * Input:
     * 7
     *
     * Output:
     * 0 1 1 2 3 5 8
     *
     * ------------------------------------------
     */
    return 0;
}
