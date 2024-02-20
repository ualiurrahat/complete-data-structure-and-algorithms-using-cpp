// Find the last index of an element inside an array
// ex: a[] = {5,6,5,4,5};
// x = 5, last index of 5 is 4.
// x = 20 last index of 20 is -1

#include <bits/stdc++.h>

using namespace std;

int lastIndex(int a[], int size, int x)
{
    // base case
    if (size == 0)
    {
        return -1;
    }
    // recursive call
    int index = lastIndex(a + 1, size - 1, x);
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
    cout << lastIndex(a,n,18) << endl;
    n = 7;
    num = 14;
    cout << lastIndex(b, n, num) << endl;
    return 0;
}