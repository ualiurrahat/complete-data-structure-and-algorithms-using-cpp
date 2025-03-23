/*
    Task:
    Given N integers, write a program to print:
    - The middle element if N is odd and is a multiple of 3.
    - The first and last element (space-separated) if N is even and is a multiple of 3.
    - Otherwise, print the sum of the first and last element.

    Input Format:
    - The first line of input contains a single integer T, denoting the number of test cases.
    - Each test case consists of two lines:
      - The first line contains a positive integer N (number of integers).
      - The second line contains N space-separated integers.

    Output Format:
    - For each test case, output on a new line:
      - Middle element if N is odd and a multiple of 3.
      - Space-separated first and last element if N is even and a multiple of 3.
      - Otherwise, print the sum of the first and last element.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tests, n, val;
    cin >> tests;

    vector<int> nums; // Vector to store the sequence of numbers

    while (tests--)
    {
        cin >> n;
        nums.clear(); // Clear the vector for each test case

        // Read N integers into the vector
        for (int i = 0; i < n; i++)
        {
            cin >> val;
            nums.push_back(val);
        }

        // Check if N is a multiple of 3
        if (n % 3 == 0)
        {
            if (n % 2 == 1)
            {                                // If N is odd
                cout << nums[n / 2] << endl; // Print the middle element
            }
            else
            {                                                       // If N is even
                cout << nums.front() << " " << nums.back() << endl; // Print first and last elements
            }
        }
        else
        {
            cout << nums.front() + nums.back() << endl; // Print the sum of first and last element
        }
    }

    return 0;
}
