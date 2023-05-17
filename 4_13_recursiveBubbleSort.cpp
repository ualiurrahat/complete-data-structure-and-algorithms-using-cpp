#include <bits/stdc++.h>

using namespace std;

void bubbleSortRecursive(int a[], int n)
{
    // base case- already sorted
    if (n == 0 || n == 1)
    {
        return;
    }

    // small calculation- placing the last elemetn to its right postion
    bool swapped = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            swapped = true;
            swap(a[i], a[i + 1]);
        }
    }
    // if swapped remains false, means array already sorted
    if (swapped == false)
    {
        return;
    }

    // recursive call- place all the other n-1 largest elements to their right place
    bubbleSortRecursive(a, n - 1);
}

int main()
{
    int a[] = {18, 1, 8, 5, 20};
    int b[] = {1, 2, 3, 4, 5};
    bubbleSortRecursive(a, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    bubbleSortRecursive(b, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}