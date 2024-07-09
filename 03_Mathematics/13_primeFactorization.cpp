// print all the prime factors of a number.
// ex: for number 12, output: 2, 2, 3

#include <bits/stdc++.h>
using namespace std;

// optimal function to check if a number is prime
// takes a number n as parameter
// return 1 if n is prime, otherwise false.

int isPrime(int n)
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
// brute force solution
void printPrimeFactorsBrute(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            if (isPrime(i))
            {
                cout << i << " ";
            }
        }
    }
    // S:O(n*sqrt(n))
    // T:O(1)
}
// better solution
void printPrimeFactorsBetter(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (isPrime(i))
            {
                cout << i << " ";
            }
            if ((n / i) != i)
            {
                if (isPrime(n / i))
                {
                    cout << n / i << " ";
                }
            }
        }
    }
    // T:O(sqrt(n)*2*sqrt(n))
    // S:O(1)
}
// optimal solution
void printPrimeFactorsOptimal(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            // reduce n as long as it gets
            // divided by i
            while (n % i == 0) // T:logn
            {
                n = n / i;
            }
        }
    }
    // check if remaining value of n is a prime
    if (n != 1)
    {
        cout << n << endl;
    }
    // T:O(sqrt(n)*logn)
    // S:O(1)
}
int main()
{
    int n = 780;

    cout << "Prime factors of " << n << " : ";
    // printPrimeFactors(n);
    // printPrimeFactorsBrute(n);
    // printPrimeFactorsBetter(n);
    printPrimeFactorsOptimal(n);

    return 0;
}