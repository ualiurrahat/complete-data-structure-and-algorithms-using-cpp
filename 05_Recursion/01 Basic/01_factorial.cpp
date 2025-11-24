/*
Recursion: the method of calling a function by itself
until a specified condition is met.
Use of Recursion:
When a problem exhibits the same nature as a smaller instance of itself,
we use recursion to solve the larger problem by breaking it down.
*/

#include <iostream>

using namespace std;

// Function to calculate the factorial of a given number n using recursion.
int factorial(int n)
{
    // Print the current value of n to trace the recursion call stack.
    cout << "calling for n = " << n << endl;

    // Base case: if n is 0, factorial is 1.
    if (n == 0)
    {
        return 1;
    }

    // Recursive call: calculate factorial of (n-1).
    int smallOutput = factorial(n - 1);

    // Print the value of n to trace the recursion unwind process.
    cout << "going back for n =" << n << endl;

    // Small calculation: multiply n with the factorial of (n-1).
    return n * smallOutput;
}

int main()
{
    // Declare variable to store the input number.
    int n;

    // Prompt user to enter a number for factorial calculation.
    cout << "Enter a number to find its factorial: ";

    // Read the input number from the user.
    cin >> n;

    // Call the factorial function and store the result.
    int output = factorial(n);

    // Display the factorial result.
    cout << output << endl;

    // Indicate successful program termination.
    return 0;
}