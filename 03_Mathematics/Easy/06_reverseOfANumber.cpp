// reverse a number within 32 bit range
// if the reversed number exceeds the int range, then return 0
#include <bits/stdc++.h>
using namespace std;

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

    cout << reverse(n) << endl;

    return 0;
}