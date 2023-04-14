// find gcd and lcm of two numbers.
// brute force method

// function to find GCD of two numbers
// GCD is the common largest divisor exists among 2 numbers
// es: GCD(20,35) = 5, GCD(1,15) = 1
// GCD(a,0) = a.
// according to euclidean algorithm,
// if(a > b), then gcd(a,b) = gcd(b, a%b)

// LCM: least common multiple of two numbers
//  lcm(5,20) = 20, lcm(3,7) = 21
//  for two numbers a and b,
//  a*b = lcm(a,b) * gcd(a,b)
//  so we can write,
//  LCM(a,b) = (a*b) / gcd(a,b)

// brute force method to find gcd
int findGCD(int a, int b)
{
    int res = 0;
    if(a == 0)
    {
        res = b;
    }
    else if( b == 0)
    {
        res = a;
    }
    // case when a is lesser than b
    else if (a < b)
    {
        // loop from 1 to a
        // find the largest divisor for a and b
        for (int i = 1; i <= a; i++)
        {
            // i divides both a and b.
            // so update res.
            if (a % i == 0 && b % i == 0)
            {
                res = i;
            }
        }
    }
    // case when a is greater than b
    else if (a > b)
    {
        for (int i = 1; i <= b; i++)
        {
            if (b % i == 0 && a % i == 0)
            {
                res = i;
            }
        }
    }
    // case when a equals b.
    // than assign a or b as res
    else
    {
        res = a;
    }
    return res;
}
// T:O(min(a,b))
// S:O(1)

#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "enter how many query you want: ";
    cin >> n;

    while (n--)
    {
        int a, b;
        cout << "Enter two numbers: ";
        cin >> a >> b;
        int gcd = findGCD(a, b);
        int lcm = (a * b) / gcd;
        cout << "GCD of " << a << " and " << b << " : " << gcd << endl;
        cout << "lcm of " << a << " and " << b << " : " << lcm << endl;
    }
    return 0;
}