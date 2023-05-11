#include <bits/stdc++.h>

using namespace std;

// find a num from an array using STL
// note: lower bound , upper bound works only in sorted container
int main()
{
    int a[] = {1, 5, 8, 18, 20};
    int n = 5; // size
    int index = lower_bound(a, a + 5, 18) - a;
    if (index != n && a[index] == 18)
    {
        cout << " Found 18 at index: " << index << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    return 0;
}