/**
 * @file 11_findMissingNumber.cpp
 *
 * @brief Problem Statement:
 * Given an array containing numbers from 1 to N, but exactly one number is missing.
 * The array size is N-1. Find the missing number.
 *
 * Example:
 * Input:  a[] = {1, 2, 3, 5}
 * Output: 4
 */

#include <iostream>
using namespace std;

/* ------------------------------------------------------------------------- */
/*                               BRUTE FORCE                                 */
/* ------------------------------------------------------------------------- */

/**
 * @brief Brute Force Approach
 *
 * Logic:
 *  - For every number i from 1 to N:
 *      - Scan entire array to check if i exists.
 *      - If i is not found, that is the missing number.
 *
 * @param arr Input array of size N-1
 * @param n The expected largest number N
 * @return Missing number
 *
 * Time Complexity: O(N*N) — Nested loops
 * Space Complexity: O(1)
 */
int missingNumberBrute(int arr[], int n)
{
    int ans = -1;

    // Outer loop: checking each number from 1 to N
    for (int i = 1; i <= n; i++)
    {
        int flag = 0; // Flag used to check whether 'i' exists in array

        // Inner loop: scan entire array (size N-1)
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] == i)
            {
                flag = 1; // Found the number
                break;
            }
        }

        // If flag remained 0 → i does not exist → missing number found
        if (flag == 0)
        {
            ans = i;
            break;
        }
    }

    return ans;
}

/* ------------------------------------------------------------------------- */
/*                               BETTER APPROACH                             */
/* ------------------------------------------------------------------------- */

/**
 * @brief Better Approach — Frequency Array
 *
 * Explanation:
 *  - Create a hash array `freq[]` of size N+1 initialized to 0.
 *  - Mark freq[a[i]] = 1 for all existing array elements.
 *  - The index whose freq is still 0 is the missing number.
 *
 * Why loop from 0 to N-1?
 *  - Because the input array contains only N-1 numbers.
 *  - Accessing index N would be out-of-bounds.
 *
 * @param a Input array of size N-1
 * @param N The expected largest number N
 * @return Missing number
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
int missingNumberBetter(int a[], int N)
{
    int ans = -1;

    // Frequency array of size N+1 (index 0 unused)
    int freq[N + 1] = {0};

    // Mark frequencies for elements present in array
    for (int i = 0; i < N - 1; i++)
    {
        freq[a[i]] = 1;
    }

    // Checking which number from 1 to N is missing
    for (int i = 1; i <= N; i++)
    {
        if (freq[i] == 0)
        {
            ans = i;
            break;
        }
    }

    return ans;
}

/* ------------------------------------------------------------------------- */
/*                          OPTIMAL APPROACH 1 (SUM)                         */
/* ------------------------------------------------------------------------- */

/**
 * @brief Optimal Approach 1 — Mathematical Sum Method
 *
 * Logic:
 *  - Compute sum of first N natural numbers.
 *  - Subtract all array values.
 *  - Remaining value is the missing number.
 *
 * @param arr Input array
 * @param n Expected largest number N
 * @return Missing number
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
int missingNumberOptimalOne(int arr[], int n)
{
    int sum = (n * (n + 1)) / 2;

    for (int i = 0; i < n - 1; i++)
    {
        sum -= arr[i];
    }

    return sum;
}

/* ------------------------------------------------------------------------- */
/*                          OPTIMAL APPROACH 2 (XOR)                         */
/* ------------------------------------------------------------------------- */

/**
 * @brief Optimal Approach 2 — XOR Method
 *
 * Logic:
 *  - XOR all numbers from 1 to N. (call this xor1)
 *  - XOR all array elements. (call this xor2)
 *  - The XOR of xor1 and xor2 gives missing number.
 *
 * @param arr Input array
 * @param n Expected largest number N
 * @return Missing number
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
int missingNumberOptimalTwo(int arr[], int n)
{
    int xor1 = 0, xor2 = 0;

    for (int i = 1; i <= n; i++)
    {
        xor1 ^= i;
    }

    for (int i = 0; i < n - 1; i++)
    {
        xor2 ^= arr[i];
    }

    return xor1 ^ xor2;
}

/* ------------------------------------------------------------------------- */
/*                                   MAIN                                     */
/* ------------------------------------------------------------------------- */

int main()
{
    int a[] = {1, 2, 3, 5};
    int b[] = {1, 2, 3, 5, 4, 7, 8};

    cout << missingNumberBetter(a, 5) << endl; // Expected 4
    cout << missingNumberBetter(b, 8) << endl; // Expected 6

    return 0;
}
