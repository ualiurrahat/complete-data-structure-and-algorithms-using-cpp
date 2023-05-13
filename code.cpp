#include <iostream>
using namespace std;

int lastIndex(int a[], int size, int x)
{
    if (size == 0)
    {
        return -1;
    }
    int smallOutput = lastIndex(a + 1, size - 1, x);
    if(a[0] == x)
    {
        if(smallOutput == -1)
        {
            return 0;
        }
        else 
        {
            return smallOutput + 1;
        }
    }
    else
    {
        if(smallOutput != -1)
        {
            return smallOutput + 1;
        }
        else
        {
            return -1;
        }
    }
}
int main()
{
    int a[] = {5, 5, 6, 5, 6};
    int b[] = {10, 5, 1, 20, 5};
    cout << lastIndex(a, 5, 5) << endl;
    cout << lastIndex(a, 5, 6) << endl;
    cout << lastIndex(a, 5, 20) << endl;

    return 0;
}