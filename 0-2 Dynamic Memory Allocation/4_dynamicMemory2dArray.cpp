// dynamic memory allocation of 2D array.
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // creating a 2d array like this a[10][20] dynamically
    int **p = new int *[10];
    for (int i = 0; i < 10; i++)
    {
        p[i] = new int[20];
    }

    // how to delete 2d array?
    // remember: wherever new is written, we have to delete that
    // so first delete rows
    // then delete the pointer
    for (int i = 0; i < 10; i++)
    {
        // deleting each rows
        // like p[0],p[1],........p[9].
        delete[] p[i];
    }

    // now deleting the pointer p itself
    delete[] p;

    return 0;
}