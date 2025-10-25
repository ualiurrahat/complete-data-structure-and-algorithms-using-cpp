/**
 * @file 12_primeFactorizationWithQueries.cpp
 * @brief Prints prime factorization of multiple numbers using brute force and SPF sieve.
 *
 * PROBLEM:
 * Given Q queries, each with a number N, print its prime factors in ascending order,
 * separated by " x ".
 *
 * Example:
 * Input:
 * 3
 * 780
 * 1230
 * 13
 *
 * Output:
 * 780 = 2 x 2 x 2 x 2 x 3 x 5 x 5
 * 1230 = 2 x 3 x 5 x 41
 * 13 = 13
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Brute force: Finds and prints prime factors by trial division
 * @param n The number to factorize (n >= 2)
 *
 * HOW IT WORKS (Step-by-step):
 * 1. Start from i = 2 up to sqrt(n)
 * 2. While n is divisible by i:
 *      - Print i
 *      - Divide n by i
 *      - Add " x " if more factors remain
 * 3. After loop, if n > 1 → n is a prime factor → print it
 *
 * INTUITION:
 * - Smallest factor of any number ≤ sqrt(n)
 * - Keep dividing by same factor as long as possible
 *
 * TIME PER QUERY  : O(sqrt(n))
 * SPACE PER QUERY : O(1)
 * TOTAL (Q queries): O(Q * sqrt(maxN))
 */
void smallestPrimeFactorizationBrute(int n)
{
    bool first = true; // Tracks if this is the first factor (to avoid leading " x ")

    // Step 1: Try all possible factors from 2 to sqrt(n)
    for (int i = 2; i * i <= n; ++i)
    {
        // Step 2: While i divides n, keep dividing
        while (n % i == 0)
        {
            if (!first)
            {
                cout << " x "; // Separator between factors
            }
            cout << i;     // Print the prime factor
            first = false; // Now we've printed at least one
            n /= i;        // Reduce n by dividing out i
        }
    }

    // Step 3: If n is still > 1, it means n is a prime number itself
    if (n > 1)
    {
        if (!first)
        {
            cout << " x "; // Add separator if other factors existed
        }
        cout << n; // Print the last prime factor
    }

    cout << endl; // End the line for this factorization
}

/**
 * @brief Builds Smallest Prime Factor (SPF) array using sieve
 * @param n Maximum number across all queries
 * @return spf vector where spf[i] = smallest prime factor of i
 *
 * HOW IT WORKS:
 * 1. Initialize: spf[i] = i for all i → assume every number is prime initially
 * 2. For i from 2 to sqrt(n):
 *      - If spf[i] == i → i is prime
 *      - For multiples j = i*i, i*i+i, ...:
 *          - If spf[j] == j → not yet marked
 *          - Set spf[j] = i → i is the smallest prime factor
 *
 * INTUITION:
 * - Smaller primes mark their multiples first
 * - We start from i*i because smaller multiples (like 2i, 3i) already marked
 *
 * TIME  : O(n log log n)
 * SPACE : O(n)
 */
vector<int> buildSPF(int n)
{
    vector<int> spf(n + 1);

    // Step 1: Every number is initially its own smallest prime factor
    for (int i = 0; i <= n; ++i)
    {
        spf[i] = i;
    }

    // Step 2: Sieve to find and mark smallest prime factors
    for (int i = 2; i * i <= n; ++i)
    {
        // If spf[i] == i → i has not been marked → i is prime
        if (spf[i] == i)
        {
            // Start marking from i*i (smaller multiples already done)
            for (int j = i * i; j <= n; j += i)
            {
                // Only update if j hasn't been assigned a smaller factor yet
                if (spf[j] == j)
                {
                    spf[j] = i; // i is the smallest prime factor of j
                }
            }
        }
    }

    return spf; // Ready for fast factorization
}

/**
 * @brief Optimal: Prints prime factors using precomputed SPF array
 * @param n Number to factorize
 * @param spf Precomputed smallest prime factor array
 *
 * HOW IT WORKS:
 * 1. While n > 1:
 *      - The smallest prime factor of n is spf[n]
 *      - Print it
 *      - Divide n by spf[n]
 *      - Add " x " if more factors
 * 2. Repeat until n == 1
 *
 * INTUITION:
 * - Each division reduces n by at least a factor of 2
 * - So maximum log₂(n) steps → O(log n)
 * - Factors come in ascending order naturally
 *
 * TIME PER QUERY  : O(log n)
 * SPACE PER QUERY : O(1)
 * TOTAL (after preprocessing): O(Q * log maxN)
 */
void smallestPrimeFactorizationOptimal(int n, const vector<int> &spf)
{
    bool first = true;

    // Keep dividing n by its smallest prime factor until n becomes 1
    while (n > 1)
    {
        if (!first)
        {
            cout << " x "; // Separator
        }
        cout << spf[n]; // Print smallest prime factor
        first = false;
        n /= spf[n]; // Reduce n
    }

    cout << endl;
}

int main()
{
    int t;
    cout << "Enter number of queries: ";
    cin >> t;

    vector<int> queries(t);
    int maxN = 0;

    // Step 1: Read all queries and find the maximum value
    // Why? So we can precompute SPF up to the largest N
    for (int i = 0; i < t; ++i)
    {
        cin >> queries[i];
        if (queries[i] > maxN)
        {
            maxN = queries[i];
        }
    }

    // Step 2: Precompute SPF array once for all queries
    // This is the key optimization — expensive once, cheap per query
    vector<int> spf = buildSPF(maxN);

    // Step 3: Process each query with both methods
    for (int i = 0; i < t; ++i)
    {
        int n = queries[i];

        // Brute Force Method
        cout << n << " = ";
        smallestPrimeFactorizationBrute(n);

        // Optimal SPF Method
        cout << n << " = ";
        smallestPrimeFactorizationOptimal(n, spf);

        // Add blank line between queries (except last)
        if (i < t - 1)
        {
            cout << endl;
        }
    }

    return 0;
}