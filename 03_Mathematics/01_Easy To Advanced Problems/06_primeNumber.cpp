/**
 * @file 07_isPrime.cpp
 * @brief Program to check whether a given number is prime or not.
 *
 * Problem statement:
 * You are given an integer 'n'. Your task is to determine whether 'n' is a prime number.
 *
 * A number is called prime if it has exactly two distinct positive divisors: 1 and itself.
 * For example:
 * - 2, 3, 5, 7, 11 are prime numbers.
 * - 4, 6, 8, 9 are not prime because they have more than two divisors.
 *
 * Constraints:
 * 1 <= n <= 10^9
 *
 * Expected Time Complexity: O(√n)
 * Expected Space Complexity: O(1)
 */

#include <iostream>
#include <cmath> // for sqrt()
using namespace std;

// ---------------------------------------------------------
// Brute Force Solution
// ---------------------------------------------------------

/**
 * @brief Determines whether a number is prime using brute-force checking.
 *
 * The function counts the total number of divisors of the number.
 * If there are exactly two divisors (1 and the number itself), it's prime.
 *
 * @param n The number to check.
 * @return 1 if n is prime, 0 otherwise.
 *
 * @note
 * Time Complexity: O(n)
 * - Loops through all numbers from 1 to n.
 * Space Complexity: O(1)
 */
int isPrimeBrute(int n)
{
    int count = 0; // To count how many divisors n has

    // Loop through all numbers from 1 to n
    for (int i = 1; i <= n; i++)
    {
        // If i divides n evenly, increment count
        if (n % i == 0)
        {
            count++;
        }
    }

    // A prime number must have exactly 2 divisors: 1 and itself
    if (count == 2)
    {
        return 1; // Prime
    }

    return 0; // Not prime
}

// ---------------------------------------------------------
// Optimal Solution
// ---------------------------------------------------------

/**
 * @brief Efficiently checks whether a number is prime.
 *
 * The function eliminates all non-prime possibilities early:
 * - Numbers < 2 are not prime.
 * - 2 is the only even prime number.
 * - Any even number > 2 is not prime.
 * - For odd numbers, it checks divisibility only up to √n.
 *
 * @param n The number to check.
 * @return 1 if n is prime, 0 otherwise.
 *
 * @note
 * Time Complexity: O(√n)
 * - We only check divisors up to sqrt(n).
 * Space Complexity: O(1)
 */
int isPrimeOptimal(int n)
{
    // Step 1: Handle edge cases
    if (n < 2)
    {
        // Numbers less than 2 are not prime
        return 0;
    }
    else if (n == 2)
    {
        // 2 is the smallest and only even prime number
        return 1;
    }
    else if (n % 2 == 0)
    {
        // Any other even number cannot be prime
        return 0;
    }

    // Step 2: Check for factors from 3 up to √n
    // We skip even numbers by incrementing i by 2
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        // If n is divisible by i, it's not a prime
        if (n % i == 0)
        {
            return 0;
        }
    }

    // Step 3: If no divisors found, the number is prime
    return 1;
}

// ---------------------------------------------------------
// Main Function (Test Cases)
// ---------------------------------------------------------

int main()
{
    while (true)
    {
        int n;
        cout << "Enter a number (-1 to exit): ";
        cin >> n;

        if (n == -1)
        {
            cout << "Exiting program..." << endl;
            break;
        }

        // Using the optimal method by default
        if (isPrimeOptimal(n))
        {
            cout << n << " is a prime number." << endl;
        }
        else
        {
            cout << n << " is not a prime number." << endl;
        }
    }

    return 0;
}

/*
-------------------------------
Example Input/Output:
-------------------------------
Input:
Enter a number (-1 to exit): 7
Enter a number (-1 to exit): 10
Enter a number (-1 to exit): -1

Output:
7 is a prime number.
10 is not a prime number.
Exiting program...
*/
