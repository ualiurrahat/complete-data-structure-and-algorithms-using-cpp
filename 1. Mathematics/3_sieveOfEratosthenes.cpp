// Using Sieve of eratosthenis to find prime numbers from 1 to n.

#include <iostream>
#include <string>

using namespace std;
// function to use sieve of eratosthenes algortihm to find prime numbers
void primeSieve(int n)
{
    // take an array of size n+1 to represent numbers from 0 to n
    int prime[n + 1] = {0};
    // initial value is given 0.
    // indicating they are prime numbers.
    prime[0] = 1;
    prime[1] = 1;
    // as 0, 1 are not prime so prime[0] = 1, prime[1] = 1.

    // to count total number of prime.
    int count = 0;

    for (int i = 2; i * i <= n; i++)
    {

        // checking if prime[i] is unmarked or zero.
        if (prime[i] == 0)
        {
            // marking all the values that are multiple of prime[i]
            // these are not prime numbers.
            // ex: if prime[2] = 0 and unmarked, then marking 4,6,8,10.... as not primes
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 1;
            }
        }
    }

    // now only unmarked elements(0 value in the ith index) are prime.
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            count++;
            cout << i << " "; // i is the number. remember that.
        }
    }
    cout << endl;
    cout << "Total count: " << count << endl;
    cout << endl;
}

int main()
{
    int n;

    while (1)
    {
        cout << "Enter number(0 to exit): ";
        cin >> n;

        if (n == 0)
        {
            cout << "Good Bye" << endl;
            break;
        }

        cout << "Prime numbers from 1 to " << n << ": " << endl;

        primeSieve(n);
    }

    return 0;
}