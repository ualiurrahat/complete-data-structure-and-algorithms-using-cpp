// Find if a given number is prime or not
#include <iostream>
#include <cmath>
using namespace std;

// brute force solution
// returns 1 if input number n is prime
// returns 0 otherwise.
int isPrimeBrute(int n)
{
    // count total no. of divisors
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    if (count > 2)
    {
        return 0;
    }
    return 1;
    // T:O(N), S:O(1)
}
// optimal function to check if a number is prime
// takes a number n as parameter
// return 1 if n is prime, otherwise false.

int isPrimeOptimal(int n)
{
    int i;
    // all number less than 2 is not prime
    if (n < 2)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    // all even number except 2 is not prime
    else if (n % 2 == 0)
    {
        return 0;
    }
    // now checking if n has any other dividor except 1 and n itself
    for (i = 3; i <= sqrt(n); i = i + 2)
    {
        // if n is divisible, it is not prime
        if (n % i == 0)
        {
            return 0;
        }
    }
    // function comes here when none of the condition came true
    // for n to be a non-prime number. so n is prime. returning 1
    return 1;
    // time complexity: O(sqrt(n))
    // S:O(1)
}
int main()
{

    while (true)
    {
        int n;
        cout << "Enter a number:(enter -1 to exit) : ";
        cin >> n;
        if (n == -1)
        {
            break;
        }
        if (isPrimeOptimal(n) == 1)
        {
            printf("%d is prime\n", n);
        }
        else
        {
            printf("%d not prime\n", n);
        }
    }

    return 0;
}