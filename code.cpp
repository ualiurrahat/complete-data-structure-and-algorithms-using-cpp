#include <iostream>
using namespace std;

bool isSorted(int a[], int n)
{
    if (n == 1 || n == 0)
    {
        return true;
    }
    if (a[0] < a[1])
    {
        return isSorted(a+1,n-1);
    }
    else
    {
        return false;
    }
}
int main()
{
    int a[] = {1, 5, 10, 15, 20};
    int b[] = {10, 5, 1, 20, 5};
    cout << isSorted(a, 5) << endl;
    cout << isSorted(b, 5) << endl;

    return 0;
}