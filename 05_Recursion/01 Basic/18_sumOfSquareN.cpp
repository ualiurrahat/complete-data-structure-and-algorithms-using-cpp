/*
    Problem Statement:
    Compute the sum of squares of the first N natural numbers using recursion.
    That is: 1^2 + 2^2 + 3^2 + ... + N^2.

    Requirements:
    - Use recursion.
    - Follow the user's C++ coding style.
    - Keep the logic the same, only rewrite with proper documentation,
      detailed explanations, and example test cases with expected outputs.
*/

#include <iostream>
using namespace std;

/**
 * @brief Recursively computes the sum of squares from 1^2 to n^2.
 *
 * Line-by-line intuition:
 * - Base Case: If n becomes 1, return 1 because 1^2 = 1.
 * - Recursive Case:
 *      - Compute n^2.
 *      - Add it to the result of sumOfSquareN(n - 1), which computes all previous squares.
 * - Each call reduces n by 1 until it hits the base case.
 *
 * @param n The number up to which squared values will be summed.
 * @return int The total sum of squares from 1 to n.
 *
 * Time Complexity: O(n)
 * - One recursive call for each number from n down to 1.
 *
 * Space Complexity: O(n)
 * - Due to recursion stack depth.
 */
int sumOfSquareN(int n)
{
    // base case
    if (n == 1)
    {
        return 1;
    }

    // small calculation + recursive call
    return (n * n) + sumOfSquareN(n - 1);
}

int main()
{
    // Test cases with expected output
    cout << sumOfSquareN(4) << endl; // Expected: 30  (1 + 4 + 9 + 16)
    cout << sumOfSquareN(6) << endl; // Expected: 91  (sum of squares 1..6)
    cout << sumOfSquareN(2) << endl; // Expected: 5   (1 + 4)

    return 0;
}
