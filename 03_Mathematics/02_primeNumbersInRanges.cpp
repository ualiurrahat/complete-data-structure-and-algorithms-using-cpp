/*
Print all prime numbers from given two numbers as a range.
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// function to check if a number is prime
// takes a number n as parameter
// return 1 if n is prime, otherwise false.
// time complexity: O(sqrt(n))
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
    // T:O(sqrt(N)), S:O(1)
}

// brute force solution to print prime numbers in a given range
// start = starting no. of the range
// end = last number of the range

void printPrimesBrute(int start, int end)
{
    // to count total no. or primes
    int count = 0;
    cout << "Prime Numbers are: ";
    for (int i = start; i <= end; i++)
    {

        if (1 == isPrime(i))
        {
            cout << i << " ";
            count++;
        }
    }
    cout << endl;
    cout << "Total Prime number: " << count << endl;
    // T:O(range*sqrt(N))
    // S:O(1)
}

int main()
{

    int n1, n2;
    cout << "enter initial range number: ";
    cin >> n1;
    cout << "enter the final range number: ";
    cin >> n2;

    // print primes between n1 and n2
    printPrimesBrute(n1, n2);

    return 0;
}