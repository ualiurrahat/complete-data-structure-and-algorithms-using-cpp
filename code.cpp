#include <iostream>
using namespace std;

int firstIndex(int a[], int size, int x)
{
    if (size == 0)
    {
        return -1;
    }
    if (a[0] == x)
    {
        return 0;
    }
    int smallOutput = firstIndex(a + 1, size - 1, x);
    int ans = (smallOutput == -1) ?  smallOutput : smallOutput + 1;
    return ans;
}
int main()
{
    int a[] = {5,5,6,5,6};
    int b[] = {10, 5, 1, 20, 5};
    cout << firstIndex(a, 5,5) << endl;
    cout << firstIndex(a,5,6) << endl;
    cout << firstIndex(a,5,20) << endl;

    return 0;
}