/**
 * @file 04_printAllDivisors.cpp
 * @brief Write a function to print all divisors of a given number.
 *
 * Example:
 * Input: 36
 * Output: 1 2 3 4 6 9 12 18 36
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ---------------------- Brute Force Approach ----------------------

/**
 * @brief Prints all divisors of a number using brute force approach.
 *
 * @param n The input number.
 * @note Time Complexity: O(n)
 * @note Space Complexity: O(1)
 */
void printDivisorsBrute(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
}

// ---------------------- Better Approach ----------------------

/**
 * @brief Prints all divisors of a number efficiently using square root method.
 *
 * This approach uses the fact that divisors occur in pairs:
 * If `i` divides `n`, then `n / i` is also a divisor.
 *
 * Example: For n = 36
 * - i = 2 ⇒ pair divisor = 18
 * - i = 3 ⇒ pair divisor = 12
 *
 * Finally, sort all divisors to print them in ascending order.
 *
 * @param n The input number.
 * @note Time Complexity: O(√n + k·log k + k(for printing)), where k = number of divisors
 * @note Space Complexity: O(k)
 */
void printDivisorsBetter(int n)
{
    vector<int> factors;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);

            // Avoid storing square roots twice (e.g., 6*6=36)
            if (n / i != i)
            {
                factors.push_back(n / i);
            }
        }
    }

    // sorting the divisors in ascending order
    sort(factors.begin(), factors.end());

    // printing the divisors.
    for (int factor : factors)
    {
        cout << factor << " ";
    }
}

// ---------------------- Main Function ----------------------

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "\nDivisors (Brute Force): ";
    printDivisorsBrute(n);

    cout << "\n\nDivisors (Better Approach): ";
    printDivisorsBetter(n);

    cout << endl;

    return 0;
}
