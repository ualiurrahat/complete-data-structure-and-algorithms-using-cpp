// sort an array using recursion.
#include <bits/stdc++.h>

using namespace std;

bool isSorted(int a[], int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return true;
    }
    // small calculation: condition to check sorted or not
    if (a[0] > a[1])
    {
        return false;
    }
    // recursive call
    bool isSmallerSorted = isSorted(a + 1, n - 1);

    return isSmallerSorted;
}

// check what is the difference between the first and second function
// funciton 1 does check condition first and then perform recursion
// function 2 first does recursive call then compare sorted or not.

bool isSorted2(int a[], int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return true;
    }
    // recursive call
    bool isSmallerSorted = isSorted(a + 1, n - 1);

    if (!isSmallerSorted)
    {
        return false;
    }
    // condition to check sorted or not
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