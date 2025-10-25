/**
 * @file 10_PrimeFactorsSolutions.cpp
 * @brief Demonstrates three approaches to print all prime factors of a number.
 *
 * This file implements brute force, better, and optimal solutions for prime factorization,
 * where a number is expressed as a product of prime numbers (e.g., 12 = 2 * 2 * 3).
 *
 * New Topics Introduced:
 * - **Prime Numbers**: A number greater than 1 divisible only by 1 and itself.
 * - **Prime Factorization**: Decomposing a number into its prime factors.
 * - **Efficient Divisor Checking**: Checking divisors up to √n reduces iterations, as larger divisors have corresponding smaller ones.
 * - **Optimal Factorization**: Dividing out each prime factor as found minimizes the number of iterations.
 * - **isPrime Function**: Syntax: `int isPrime(int n)`. Checks primality by testing divisors up to √n.
 * - **Use Case**: Prime factorization is used in number theory, cryptography, and algorithms like GCD or LCM computation.
 *
 * The program provides three solutions:
 * 1. Brute Force: Checks all numbers up to n for divisibility and primality.
 * 2. Better: Checks divisors up to √n and their pairs, reducing iterations.
 * 3. Optimal: Divides out prime factors as found, checking up to √n, and handles the remaining prime.
 *
 * The main function tests the optimal solution for n = 780, outputting "2 2 3 5 13".
 */

#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Checks if a number is prime.
 * @param n The number to check.
 * @return int 1 if n is prime, 0 otherwise.
 *
 * This function efficiently checks primality by:
 * - Returning 0 for numbers less than 2 (not prime).
 * - Returning 1 for n = 2 (the only even prime).
 * - Checking if n is even (except 2, even numbers are not prime).
 * - Testing odd divisors up to √n to confirm n has no divisors other than 1 and itself.
 *
 * Time Complexity: O(√n), as it checks divisors up to √n.
 * Space Complexity: O(1), using only a few variables.
 */
int isPrime(int n)
{
    if (n < 2)
    {
        return 0; // Numbers less than 2 are not prime
    }
    if (n == 2)
    {
        return 1; // 2 is prime
    }
    if (n % 2 == 0)
    {
        return 0; // Even numbers except 2 are not prime
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            return 0; // Divisible by i, so not prime
        }
    }
    return 1; // No divisors found, so prime
}

/**
 * @brief Prints all prime factors of a number using a brute force approach.
 * @param n The number to factorize.
 *
 * This function iterates from 2 to n, checks if each number is a divisor of n,
 * and uses isPrime to verify if the divisor is prime. If so, it prints the divisor.
 *
 * Time Complexity: O(n * √n), as it loops up to n and calls isPrime (O(√n)) for each divisor.
 * Space Complexity: O(1), as it uses constant extra space.
 */
void printPrimeFactorsBrute(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        { // Check if i is a divisor
            if (isPrime(i))
            { // Check if i is prime
                cout << i << " ";
            }
        }
    }
}

/**
 * @brief Prints all prime factors of a number using a better approach.
 * @param n The number to factorize.
 *
 * This function iterates up to √n, checks if i and n/i are divisors, and uses isPrime
 * to verify if they are prime. It avoids checking the same divisor twice (i != n/i).
 *
 * Time Complexity: O(√n * √n) = O(n), due to looping up to √n and calling isPrime.
 * Space Complexity: O(1), as it uses constant extra space.
 */
void printPrimeFactorsBetter(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        { // Check if i is a divisor
            if (isPrime(i))
            {
                cout << i << " ";
            }
            if ((n / i) != i)
            { // Check pair divisor n/i
                if (isPrime(n / i))
                {
                    cout << n / i << " ";
                }
            }
        }
    }
}

/**
 * @brief Prints all prime factors of a number using an optimal approach.
 * @param n The number to factorize.
 *
 * This function iterates up to √n to find divisors. For each divisor i, it prints i
 * and divides n by i as long as possible. If n remains > 1, it is a prime factor.
 *
 * Time Complexity: O(√n), as the loop runs up to √n, and division reduces n logarithmically.
 * Space Complexity: O(1), as it uses constant extra space.
 */
void printPrimeFactorsOptimal(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        { // Check if i is a divisor
            cout << i << " ";
            while (n % i == 0)
            { // Divide out all occurrences of i
                n /= i;
            }
        }
    }
    if (n != 1)
    { // Remaining n is prime
        cout << n;
    }
}

/**
 * @brief Main function to test prime factorization.
 * @return int Program exit status.
 *
 * Tests the optimal solution for n = 780, outputting "2 2 3 5 13".
 * Other solutions (brute, better) can be tested by uncommenting their calls.
 */
int main()
{
    int n = 780;
    cout << "Prime factors of " << n << " : ";
    // printPrimeFactorsBrute(n); // Uncomment to test brute force
    // printPrimeFactorsBetter(n); // Uncomment to test better approach
    printPrimeFactorsOptimal(n); // Outputs: 2 2 3 5 13
    cout << endl;
    return 0;
}