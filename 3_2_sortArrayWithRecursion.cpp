// sort an array using recursion.
#include <bits/stdc++.h>

using namespace std;

bool isSorted(int a[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (a[0] > a[1])
    {
        return false;
    }
    bool isSmallerSorted = isSorted(a + 1, n - 1);

    return isSmallerSorted;
}

// check what is the difference between the first and second function

bool isSorted2(int a[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    bool isSmallerSorted = isSorted(a + 1, n - 1);
    if (!isSmallerSorted)
    {
        return false;
    }
    if (a[0] > a[1])
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{

    int a[] = {2, 3, 4, 5, 6};
    int n = 5;
    cout << isSorted(a, n) << endl;
    cout << isSorted2(a, n) << endl;

    int b[] = {2, 3, 5, 4, 6};

    cout << isSorted(b, n) << endl;
    cout << isSorted2(b, n) << endl;

    return 0;
}