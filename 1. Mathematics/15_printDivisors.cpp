/*
write a function to print all divisors of a number.
ex: input = 36
output = 1,2,3,4,6,9,12,18,36

*/

#include <bits/stdc++.h>

using namespace std;

// brute force approach
// T:O(log n)
// S:O(1)
void printDivisor(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
}

// better approach
// T:O(sqrt n) + O(no. of factors) ~= O(sqrt n)
// S:O(number of factors)
void printDivisorBetter(int n)
{
    // to store all divisors
    // S:O(number of factors)
    vector<int> factors;

    // factors lie between 1 to square root of a number
    // so looping though 1 to sqrt of n
    // T:O(sqrt n)
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            // store i as factor
            factors.push_back(n);
            if ((n % i) != i)
            {
                // ex: n = 36, i = 4, so n%i == 36% 4 = 9 which is not equal to 4
                // so adding 9 also as a factor
                factors.push_back(n % i);
            }
        }
    }

    // now sorting the factors
    // T:O(no. of factors * log(no. of factors) )
    sort(factors.begin(), factors.end());
    // printing all iterators
    //  T:O(number of factors)
    for (auto i : factors)
    {
        cout << i << " ";
    }
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // printDivisor(n);
    printDivisorBetter(n);

    return 0;
}