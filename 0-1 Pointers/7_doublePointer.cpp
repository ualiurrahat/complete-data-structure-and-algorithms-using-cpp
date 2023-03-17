#include <bits/stdc++.h>

using namespace std;

// ask yourself which function will make actual changes here

void increment1(int **p)
{
    // taking a double pointer and trying to change itself
    // won't work
    p = p + 1;
}

void increment2(int **p)
{
    // dereferencing double pointer
    // so changing address of the pointer stored in the double pointer
    // will work
    *p = *p + 1;
}

void increment3(int **p)
{
    // dereferencing double pointer
    // so changing in the value of the integer
    // through dereferncing i.e. going by address
    // so changes will show
    **p = **p + 1;
}

int main()
{

    int i = 25;
    int *p = &i;

    int **p2 = &p;

    cout << &i << endl;
    cout << p << endl;
    cout << *p2 << endl;
    // &i means address of i and so is p
    // p2 means address of p
    // so *p2 is derefernce of p2
    // p2 holds address of pointer p
    // *p2 will show what is written on address of p
    // means address of i
    cout << endl;

    cout << i << endl;
    cout << *p << endl;
    cout << **p2 << endl;

    cout << endl;

    free(p);
    free(p2);
    return 0;
}