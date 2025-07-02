/**
 * @file 03_factorialOfLargeNumber.cpp
 * @brief Compute the factorial of a number and return its digits.
 */

/**
 * Problem Statement:
 * Given an integer n, find its factorial.
 * Return a list of integers denoting the digits that make up the factorial of n.
 *
 * Examples:
 * Input: n = 5
 * Output: [1, 2, 0]
 *
 * Input: n = 10
 * Output: [3, 6, 2, 8, 8, 0, 0]
 *
 * Input: n = 1
 * Output: [1]
 *
 * Constraints:
 * 1 ≤ n ≤ 10^3
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief Computes factorial of an integer and returns digits as a vector.
 *
 * This function handles large factorials by storing the result as digits in a vector.
 * It multiplies numbers from n down to 2 using digit-wise multiplication, storing each result.
 *
 * @param n The integer whose factorial is to be computed.
 * @return vector<int> The digits of the factorial result in correct order.
 *
 * @note Time Complexity: O(n * d), where d is the number of digits in the result
 * @note Space Complexity: O(d), to store the result digits
 */
vector<int> factorial(int n)
{
    // ---------------------- Initialization ----------------------
    // Vector to store digits of the factorial result.
    // Initially, the factorial of 1 is 1, so we begin with [1].
    vector<int> ans(1, 1);

    // ---------------------- Multiply from n down to 2 ----------------------
    // We perform repeated multiplication: ans = ans * n * (n-1) * ... * 2
    while (n > 1)
    {
        int carry = 0;         // To hold carry from digit multiplication
        int res;               // Temporary variable to store product result
        int size = ans.size(); // Current number of digits in the result

        // ---------------------- Multiply each digit with n ----------------------
        for (int i = 0; i < size; i++)
        {
            // Multiply current digit with n and add any carry from previous operation
            res = ans[i] * n + carry;

            // Update carry for the next digit
            carry = res / 10;

            // Store the last digit of res back to ans[i]
            ans[i] = res % 10;
        }

        // ---------------------- Handle remaining carry ----------------------
        // After all digits are processed, we may still have carry digits left
        while (carry)
        {
            // Push the last digit of carry into the result
            ans.push_back(carry % 10);
            carry /= 10;
        }

        // Move on to next smaller multiplier
        n--;
    }

    // ---------------------- Reverse the result ----------------------
    // The digits are currently in reverse order (least significant digit first)
    // Reverse them to get the correct number order
    reverse(ans.begin(), ans.end());
    return ans;
}

/**
 * @brief Main function to demonstrate the factorial function.
 */
int main()
{
    // Example test cases
    vector<int> inputs = {5, 10, 1};

    for (int n : inputs)
    {
        vector<int> result = factorial(n);
        cout << n << "! = ";
        for (int digit : result)
            cout << digit;
        cout << endl;
    }

    return 0;
}
