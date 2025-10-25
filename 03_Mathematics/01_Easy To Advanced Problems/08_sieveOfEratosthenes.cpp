/*
--------------------------------------------------------
🧮 Problem Statement:
Using the Sieve of Eratosthenes algorithm, find and print
all the prime numbers between 1 and a given number 'n'.
Also print the total count of prime numbers found.

--------------------------------------------------------
Example:
Input:
    n = 20
Output:
    Prime numbers from 1 to 20 are:
    2 3 5 7 11 13 17 19
    Total count: 8
--------------------------------------------------------
*/

#include <iostream>
using namespace std;

// ------------------------------------------------------
// Function: primeSieve
// ------------------------------------------------------
/**
 * @brief Finds and prints all prime numbers from 1 to n using
 *        the Sieve of Eratosthenes algorithm.
 *
 * @param n The upper limit of the range.
 *
 * @note
 * - The sieve marks multiples of every prime as non-prime.
 * - Highly efficient for generating all primes ≤ n.
 * - Time Complexity: O(n * log(log n))
 * - Space Complexity: O(n)
 */
void primeSieve(int n)
{
    // ------------------------------------------------------
    // Step 1️⃣: Create an array of size n+1
    // ------------------------------------------------------
    // This array will mark whether a number is prime or not.
    // Index 'i' represents the number 'i'.
    int prime[n + 1];

    // ------------------------------------------------------
    // Step 2️⃣: Initially mark all numbers ≥ 2 as potential primes.
    // ------------------------------------------------------
    // 0 and 1 are not prime numbers by definition.
    for (int i = 2; i <= n; i++)
    {
        prime[i] = 1; // 1 means “assumed to be prime”
    }

    // ------------------------------------------------------
    // Step 3️⃣: Perform the Sieve of Eratosthenes process
    // ------------------------------------------------------
    // We'll start from 2, the first prime number.
    for (int i = 2; i * i <= n; i++)
    {
        // If prime[i] is still unmarked (== 1), then i is a prime.
        if (prime[i] == 1)
        {
            // Mark all multiples of 'i' (starting from i*i)
            // as non-prime (set to 0).
            // Example: if i = 2, mark 4,6,8,10,...
            //          if i = 3, mark 9,12,15,...
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 0;
            }
        }
    }

    // ------------------------------------------------------
    // Step 4️⃣: Display all numbers that remain unmarked (i.e., primes)
    // ------------------------------------------------------
    int count = 0;
    cout << "Prime numbers from 1 to " << n << " are: " << endl;

    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 1)
        {
            cout << i << " ";
            count++;
        }
    }

    cout << endl;
    cout << "Total count: " << count << endl;
    cout << "------------------------------------------" << endl;

    // ✅ Time Complexity: O(n * log(log n))
    // ✅ Space Complexity: O(n)
}

// ------------------------------------------------------
// Function: main
// ------------------------------------------------------
int main()
{
    int n;

    while (true)
    {
        cout << "Enter number (0 to exit): ";
        cin >> n;

        if (n == 0)
        {
            cout << "Good Bye 👋" << endl;
            break;
        }

        // Call the sieve function
        primeSieve(n);
    }

    /*
    Example Run:
    ----------------------
    Input:
        20
    Output:
        Prime numbers from 1 to 20 are:
        2 3 5 7 11 13 17 19
        Total count: 8
    ----------------------
    */

    return 0;
}
