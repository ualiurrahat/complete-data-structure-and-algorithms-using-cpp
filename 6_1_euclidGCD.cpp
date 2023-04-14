// find gcd using euclid's algo
#include <bits/stdc++.h>

using namespace std;

int findGCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return findGCD(b, a % b);
}
int main()
{
    cout << findGCD(12, 4) << endl;
    cout << findGCD(24, 60) << endl;
    cout << findGCD(13, 5) << endl;

    return 0;
}