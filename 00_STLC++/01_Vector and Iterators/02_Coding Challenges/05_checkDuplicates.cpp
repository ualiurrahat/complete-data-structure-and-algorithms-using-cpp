/*
    Task: Check for duplicates in a list of integers

    Given N non-negative integers, check if there is any duplicate value present.

    Input Format:
    - The first line of input will contain a single integer T, denoting the number of test cases.
    - Each test case consists of two lines of input:
      - The first line contains a positive integer N - the number of integers.
      - The second line contains N space-separated integers.

    Output Format:
    - For each test case, output on a new line:
      - "YES" if input integers have duplicates.
      - "NO" if all integers are unique.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{

    int tests, n, val;
    cin >> tests; // Input number of test cases

    vector<int> nums; // Vector to hold integers

    while (tests--)
    {
        cin >> n;     // Input size of the vector for this test case
        nums.clear(); // Clear the vector before processing each test case
        for (int i = 0; i < n; i++)
        {
            cin >> val;          // Input each integer
            nums.push_back(val); // Add the integer to the vector
        }

        bool has_duplicate = false; // Flag to track duplicate values
        for (int i = 0; i < n - 1; i++)
        { // Loop through the vector
            for (int j = i + 1; j < n; j++)
            {                           // Compare each element with the rest
                if (nums[i] == nums[j]) // If a duplicate is found
                    has_duplicate = true;
            }
        }

        // Output result based on whether duplicates were found
        if (has_duplicate)
        {
            cout << "YES\n"; // Duplicates found
        }
        else
        {
            cout << "NO\n"; // No duplicates found
        }
    }

    return 0;
}
