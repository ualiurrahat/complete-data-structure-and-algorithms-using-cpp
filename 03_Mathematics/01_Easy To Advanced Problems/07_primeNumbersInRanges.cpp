/**
 * @file 07_primeNumbersInRanges.cpp
 * @brief Counts total prime numbers in a given range [start, end] (inclusive).
 *
 * Problem Statement:
 * Given two integers `start` and `end` (1 ≤ start ≤ end ≤ 10^6), compute the total number of
 * prime numbers in the range [start, end], inclusive.
 *
 * Example:
 *   Input:  start = 10, end = 30
 *   Output: Total Prime numbers: 6
 *   Primes: 11, 13, 17, 19, 23, 29
 *
 * New Topics Introduced:
 * - **Prime Number**: A number > 1 with no divisors other than 1 and itself.
 * - **Trial Division**: Checking primality by testing divisors up to √n.
 * - **Sieve of Eratosthenes**: Precomputes all primes up to n in O(n log log n).
 * - **Prefix Sum Optimization**: Precompute cumulative prime count for O(1) range queries.
 *
 * Use Case: Competitive programming, number theory, cryptography.
 *
 * Three Solutions:
 * 1. Brute Force: Check each number in range → O((end−start+1)×√n)
 * 2. Better: Precompute primes using Sieve → O(n log log n) + O(end−start+1)
 * 3. Optimal: Sieve + Prefix Sum → O(n log log n) preprocessing, O(1) per query
 *
 * Time Complexity:
 *   - Brute:    O((end−start+1) × √end)
 *   - Better:   O(end log log end) + O(end−start+1)
 *   - Optimal:  O(end log log end) preprocessing, O(1) query
 *
 * Space Complexity: O(end) for sieve and prefix array
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * @brief Checks if a number n is prime using trial division.
 * @param n Number to check.
 * @return int 1 if prime, 0 otherwise.
 *
 * Time Complexity: O(√n)
 * Space Complexity: O(1)
 */
int isPrime(int n)
{
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

/**
 * @brief Brute force: Counts primes in [start, end] by checking each number.
 * @param start Lower bound of range.
 * @param end Upper bound of range.
 *
 * Time Complexity: O((end−start+1) × √end)
 * Space Complexity: O(1)
 */
void countPrimesBrute(int start, int end)
{
    int count = 0;
    for (int i = start; i <= end; i++)
    {
        if (isPrime(i))
            count++;
    }
    cout << "Total Prime numbers (Brute): " << count << endl;
}

/**
 * @brief Generates a boolean sieve marking primes up to n using Sieve of Eratosthenes.
 * @param n Upper limit.
 * @return vector<int> Vector where primes[i] = 1 if i is prime, else 0.
 *
 * Time Complexity: O(n log log n)
 * Space Complexity: O(n)
 */
vector<int> sieveOfEratosthenes(int n)
{
    vector<int> primes(n + 1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = 0;
            }
        }
    }
    return primes;
}

/**
 * @brief Better: Uses sieve to precompute primes, then counts in range.
 * @param start Lower bound.
 * @param end Upper bound.
 *
 * Time Complexity: O(end log log end) + O(end−start+1)
 * Space Complexity: O(end)
 */
void countPrimesBetter(int start, int end)
{
    vector<int> primes = sieveOfEratosthenes(end);
    int count = 0;
    for (int i = start; i <= end; i++)
    {
        if (primes[i])
            count++;
    }
    cout << "Total Prime numbers (Better): " << count << endl;
}

/**
 * @brief Optimal: Sieve + Prefix Sum → O(1) range query after O(n log log n) preprocessing.
 * @param start Lower bound.
 * @param end Upper bound.
 *
 * Time Complexity: O(end log log end) preprocessing, O(1) query
 * Space Complexity: O(end)
 */
void countPrimesOptimal(int start, int end)
{
    vector<int> isPrime = sieveOfEratosthenes(end);
    vector<int> prefix(end + 1, 0);

    // Build prefix sum: prefix[i] = total primes from 0 to i
    for (int i = 1; i <= end; i++)
    {
        prefix[i] = prefix[i - 1] + isPrime[i];
    }

    int count = prefix[end] - prefix[start - 1];
    cout << "Total Prime numbers (Optimal): " << count << endl;
}

/**
 * @brief Main function to test all three solutions.
 * @return int Exit status.
 */
int main()
{
    int start, end;
    cout << "Enter start: ";
    cin >> start;
    cout << "Enter end: ";
    cin >> end;

    cout << "\n--- Brute Force ---\n";
    countPrimesBrute(start, end);

    cout << "\n--- Better (Sieve) ---\n";
    countPrimesBetter(start, end);

    cout << "\n--- Optimal (Prefix) ---\n";
    countPrimesOptimal(start, end);

    return 0;
}