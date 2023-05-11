/*
for a given number, check if it is a palindrome or not.
If a number and its reverse one, both are equal, then the number is called
a palindrome number
ex: 121, 323, etc

*/

#include <bits/stdc++.h>
using namespace std;

// function to reverse a number
// T:O(log10(n))
// S:O(1)
long long int reverse(long long int n)
{
    long long ans = 0;
    while (n)
    {
        int digit = n % 10;
        // check range for number
        // if ans is greater than INT_MAX or lesser than INT_MIN, return 0
        if ((ans > (INT_MAX / 10)) || (ans < (INT_MIN) / 10))
        {
            // number is outside the range
            return 0;
        }
        ans = ans * 10 + digit;
        n = n / 10;
    }
    return ans;
}
int main()
{
    long long int n;
    cout << "Enter a number: ";
    cin >> n;

    long long int reversedNumber = reverse(n);
    (n == reversedNumber) ? cout << "Palindrome" : cout << "Not Palindrome";

    return 0;
}