/*
    Problem Statement:
    Implement a recursive function to compute a^b (a raised to the power b).

    Requirements:
    - Use recursion.
    - Follow the user's C++ coding style.
    - Include detailed explanations, Doxygen documentation,
      and a main() function with example test cases.
*/

#include <iostream>
using namespace std;

/**
 * @brief Computes a^b using simple recursion.
 *
 * Line-by-line intuition:
 * - If exponent becomes 0, we return 1 because any number to the power 0 is 1.
 * - Otherwise, we recursively compute a^(b-1) and multiply it by 'a'.
 * - Each call reduces the exponent by 1, moving toward the base case.
 *
 * @param base The number 'a'.
 * @param exponent The power 'b'.
 * @return int The result of a^b.
 *
 * Time Complexity: O(b)
 * - One recursive call per decrement of exponent.
 *
 * Space Complexity: O(b)
 * - Due to recursion call stack.
 */
int power(int base, int exponent)
{
    if (exponent == 0)
    {
        return 1; // base case
    }

    int smallAns = power(base, exponent - 1); // recursive reduction of exponent
    return base * smallAns;                   // multiply base with smaller result
}

int main()
{
    // Sample test cases with expected output
    cout << power(2, 0) << endl; // Expected: 1
    cout << power(2, 5) << endl; // Expected: 32
    cout << power(3, 3) << endl; // Expected: 27
    cout << power(4, 3) << endl; // Expected: 64

    return 0;
}
