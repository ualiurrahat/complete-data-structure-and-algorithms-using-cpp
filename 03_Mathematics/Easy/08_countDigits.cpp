// Count total no. of digits in a number

#include <bits/stdc++.h>

using namespace std;

int countDigits(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}
int main()
{
    int n;
    cout << "Enter a number:";
    cin >> n;

    // shortcut: (floor) log10(n) + 1;
    cout << "digits:" << (int)log10(n) + 1 << endl;
    return 0;
}