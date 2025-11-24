// Fibonacci series: 0 1 1 2 3 5 8 13 ..........
// Recursive function to find the nth Fibonacci number (where n starts from 0).
#include <iostream>

using namespace std;

// Calculate the nth Fibonacci number using recursion.
int fibonacci(int n)
{
    // Base case: if n is 0 or 1, return n itself (0th number is 0, 1st is 1).
    if (n == 0 || n == 1)
    {
        return n;
    }
    // if (n == 1)
    // {
    //     return 1;
    // }

    // Recursive call: compute Fibonacci number for (n-1).
    int smallOutput1 = fibonacci(n - 1);

    // Recursive call: compute Fibonacci number for (n-2).
    int smallOutput2 = fibonacci(n - 2);

    // Return the sum of (n-1)th and (n-2)th Fibonacci numbers.
    return smallOutput1 + smallOutput2;
}

int main()
{
    // Declare variable to store the input number.
    int n;

    // Prompt user to enter the index n for the Fibonacci sequence.
    cout << "Enter n : ";

    // Read the input number from the user.
    cin >> n;

    // Compute and display the nth Fibonacci number.
    cout << n << "th fibonacci number is : " << fibonacci(n - 1) << endl;

    // Indicate successful program termination.
    return 0;
}