// Find the first index of a number in an array.
// ex: a = {18,1,8,1,20}, x = 1
// first index of 1 is 1.

#include <bits/stdc++.h>

using namespace std;

int firstIndex(int a[], int size, int x)
{
    // base case
    if (size == 0)
    {
        return -1;
    }
    // small calculation
    if (a[0] == x)
    {
        return 0;
    }
    // recursive call
    int index = firstIndex(a + 1, size - 1, x);
    
    if (index == -1)
    {
        return index;
    }
    else
    {
        return index + 1;
    }
}

int main()
{
    int a[] = {18, 1, 8, 1, 20};
    int size = 5;
    int num = 1;
    cout << firstIndex(a, size, num) << endl;

    int b[] = {20, 1, 13, 1, 14, 14, 1};
    size = 7;
    num = 14;
    cout << firstIndex(b, size, num) << endl;
    num = 25;
    cout << firstIndex(b, size, num) << endl;

    return 0;
}