/*
Problem Statement:
Generate the FizzBuzz sequence from 1 to n.

Rules:
- If a number is divisible by 3, output "Fizz".
- If divisible by 5, output "Buzz".
- If divisible by both 3 and 5, output "FizzBuzz".
- Otherwise, output the number itself as a string.

We will implement:
1. Brute Solution
2. Better Solution
3. Optimal Solution
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * @brief Brute-force FizzBuzz solution.
 *
 * This solution performs redundant modulo checks repeatedly.
 * It checks divisibility inside every condition without precomputing.
 *
 * @param n Upper limit for FizzBuzz.
 * @return vector<string> Sequence of FizzBuzz values.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
vector<string> fizzBuzzBrute(int n)
{
    vector<string> ans;

    for (int i = 1; i <= n; i++)
    {

        if (i % 3 == 0 && i % 5 == 0)
        {
            ans.push_back("FizzBuzz");
        }
        else if (i % 3 == 0)
        {
            ans.push_back("Fizz");
        }
        else if (i % 5 == 0)
        {
            ans.push_back("Buzz");
        }
        else
        {
            ans.push_back(to_string(i));
        }
    }

    return ans;
}

/**
 * @brief Better solution using string construction.
 *
 * Instead of if-else chains, we build the output string step-by-step.
 * If the string remains empty, we convert the number to string.
 *
 * @param n Upper limit for FizzBuzz.
 * @return vector<string> Sequence of FizzBuzz values.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
vector<string> fizzBuzzBetter(int n)
{
    vector<string> ans;

    for (int i = 1; i <= n; i++)
    {
        string temp = "";

        if (i % 3 == 0)
            temp += "Fizz";
        if (i % 5 == 0)
            temp += "Buzz";

        if (temp == "")
            temp = to_string(i);

        ans.push_back(temp);
    }

    return ans;
}

/**
 * @brief Optimal FizzBuzz solution.
 *
 * Performs modulo operations only once per number.
 * Uses booleans for clarity and performance.
 * Reserves vector capacity to avoid repeated reallocations.
 *
 * @param n Upper limit for FizzBuzz.
 * @return vector<string> Sequence of FizzBuzz values.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
vector<string> fizzBuzzOptimal(int n)
{

    vector<string> ans;
    ans.reserve(n); // Optimization: avoid dynamic resizing

    for (int i = 1; i <= n; i++)
    {

        bool divisibleBy3 = (i % 3 == 0);
        bool divisibleBy5 = (i % 5 == 0);

        if (divisibleBy3 && divisibleBy5)
        {
            ans.push_back("FizzBuzz");
        }
        else if (divisibleBy3)
        {
            ans.push_back("Fizz");
        }
        else if (divisibleBy5)
        {
            ans.push_back("Buzz");
        }
        else
        {
            ans.push_back(to_string(i));
        }
    }

    return ans;
}

int main()
{

    int n = 15;

    vector<string> brute = fizzBuzzBrute(n);
    vector<string> better = fizzBuzzBetter(n);
    vector<string> optimal = fizzBuzzOptimal(n);

    // Expected output for n = 15:
    // 1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz

    cout << "Brute: ";
    for (const auto &x : brute)
        cout << x << " ";
    cout << endl;

    cout << "Better: ";
    for (const auto &x : better)
        cout << x << " ";
    cout << endl;

    cout << "Optimal: ";
    for (const auto &x : optimal)
        cout << x << " ";
    cout << endl;

    return 0;
}
