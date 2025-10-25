/**
 * @file 09_findGCD.cpp
 * @brief Find GCD and LCM of two numbers using multiple approaches
 *
 * Problem Statement:
 * Given two numbers a and b, find their Greatest Common Divisor (GCD)
 * and Least Common Multiple (LCM). Demonstrate multiple approaches:
 * 1. Brute-force method
 * 2. Better approach using Euclidean algorithm (iterative)
 * 3. Recursive Euclidean method
 * 4. Optimized Euclidean approach
 *
 * Notes:
 * - GCD(a,0) = a
 * - LCM(a,b) = (a * b) / GCD(a,b)
 *
 * All functions demonstrate educational line-by-line logic and are ready for GitHub.
 */

#include <iostream>
using namespace std;

// ---------------------- Brute-force GCD ----------------------
/**
 * @brief Finds GCD of two numbers using brute-force method
 *
 * @param a First number
 * @param b Second number
 * @return int Greatest common divisor of a and b
 *
 * @note Time Complexity: O(min(a,b))
 * @note Space Complexity: O(1)
 */
int findGCDBrute(int a, int b)
{
    int res = 0;

    if (a == 0) // Edge case: a is 0, GCD = b
        res = b;
    else if (b == 0) // Edge case: b is 0, GCD = a
        res = a;
    else if (a < b) // Loop from 1 to a to find largest divisor
    {
        for (int i = 1; i <= a; i++)
        {
            if (a % i == 0 && b % i == 0)
                res = i; // Update result if i divides both
        }
    }
    else if (a > b) // Loop from 1 to b to find largest divisor
    {
        for (int i = 1; i <= b; i++)
        {
            if (b % i == 0 && a % i == 0)
                res = i;
        }
    }
    else // Case a == b
        res = a;

    return res;
}

// ---------------------- Better Iterative GCD ----------------------
/**
 * @brief Finds GCD of two numbers using Euclidean subtraction method
 *
 * @param a First number
 * @param b Second number
 * @return int Greatest common divisor of a and b
 *
 * @note Time Complexity: O(max(a,b))
 * @note Space Complexity: O(1)
 */
int findGCDBetter(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    while (a != b)
    {
        if (a > b)
            a = a - b; // Subtract smaller number from larger
        else
            b = b - a;
    }
    return a;
}

// ---------------------- Recursive Euclidean GCD ----------------------
/**
 * @brief Finds GCD of two numbers recursively using Euclidean algorithm
 *
 * @param a First number
 * @param b Second number
 * @return int Greatest common divisor of a and b
 *
 * @note Time Complexity: O(log(min(a,b)))
 * @note Space Complexity: O(log(min(a,b))) due to recursion stack
 */
int findGCDBetterRecursive(int a, int b)
{
    if (a < b)
        return findGCDBetterRecursive(b, a); // Ensure a >= b
    if (b == 0)
        return a;                            // Base case: GCD(a,0) = a
    return findGCDBetterRecursive(b, a % b); // Recursive call
}

// ---------------------- Optimized Euclidean GCD ----------------------
/**
 * @brief Finds GCD using optimized Euclidean algorithm with modulo
 *
 * @param a First number
 * @param b Second number
 * @return int Greatest common divisor of a and b
 *
 * @note Time Complexity: O(log(min(a,b)))
 * @note Space Complexity: O(1)
 */
int findGCDOptimized(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    while (a % b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return b;
}

// ---------------------- Main Function ----------------------
int main()
{
    int queries;
    cout << "Enter how many queries you want: ";
    cin >> queries;

    while (queries--)
    {
        int a, b;
        cout << "Enter two numbers: ";
        cin >> a >> b;

        // Brute-force GCD
        int gcdBrute = findGCDBrute(a, b);
        int lcmBrute = (a * b) / gcdBrute;
        cout << "\n[Brute-force] GCD(" << a << ", " << b << ") = " << gcdBrute
             << ", LCM = " << lcmBrute << "\n";

        // Better iterative GCD
        int gcdBetter = findGCDBetter(a, b);
        int lcmBetter = (a * b) / gcdBetter;
        cout << "[Better Iterative] GCD(" << a << ", " << b << ") = " << gcdBetter
             << ", LCM = " << lcmBetter << "\n";

        // Recursive GCD
        int gcdRecursive = findGCDBetterRecursive(a, b);
        int lcmRecursive = (a * b) / gcdRecursive;
        cout << "[Recursive] GCD(" << a << ", " << b << ") = " << gcdRecursive
             << ", LCM = " << lcmRecursive << "\n";

        // Optimized Euclidean GCD
        int gcdOptimized = findGCDOptimized(a, b);
        int lcmOptimized = (a * b) / gcdOptimized;
        cout << "[Optimized] GCD(" << a << ", " << b << ") = " << gcdOptimized
             << ", LCM = " << lcmOptimized << "\n";
    }

    return 0;
}

/**
Example Input/Output:

Enter how many queries you want: 2
Enter two numbers: 20 35

[Brute-force] GCD(20, 35) = 5, LCM = 140
[Better Iterative] GCD(20, 35) = 5, LCM = 140
[Recursive] GCD(20, 35) = 5, LCM = 140
[Optimized] GCD(20, 35) = 5, LCM = 140

Enter two numbers: 15 1

[Brute-force] GCD(15, 1) = 1, LCM = 15
[Better Iterative] GCD(15, 1) = 1, LCM = 15
[Recursive] GCD(15, 1) = 1, LCM = 15
[Optimized] GCD(15, 1) = 1, LCM = 15
*/
