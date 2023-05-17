#include <bits/stdc++.h>

using namespace std;

int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    int smallAns = power(a, b - 1);
    return a * smallAns;
}

int main()
{
    cout << power(2, 0) << endl;
    cout << power(2, 5) << endl;
    cout << power(3, 3) << endl;
    cout << power(4, 3) << endl;

    return 0;
}