// Find the last index of an element inside an array
// ex: a[] = {5,6,5,4,5};
// last index of 5 is 4.

#include <bits/stdc++.h>

using namespace std;

int lastIndex(int a[], int n, int x)
{
    if (n == 0)
    {
        return -1;
    }

    int index = lastIndex(a + 1, n - 1, x);
    if (index != -1)
    {
        return index + 1;
    }
    else
    {
        if (a[0] == x)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
}

int main()
{

    int a[] = {18, 1, 8, 1, 20};
    int b[] = {20, 1, 13, 1, 14, 14, 1};
    int n = 5;
    int num = 1;
    cout << lastIndex(a, n, num) << endl;
    n = 7;
    num = 14;
    cout << lastIndex(a, n, num) << endl;
    return 0;
}