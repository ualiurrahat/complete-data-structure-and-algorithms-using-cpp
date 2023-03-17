#include <bits/stdc++.h>

using namespace std;

int main()
{

    int i = 10;
    int *p = &i;

    float f = 10.5;
    float *fp = &f;

    double d = 25.8;
    double *pd = &d;

    char c = 'a';
    char *pc = &c;

    // let's see size of all types of pointer
    cout << sizeof(p) << endl;
    cout << sizeof(fp) << endl;
    cout << sizeof(pd) << endl;
    cout << sizeof(pc) << endl;
    // no matter which types of pointer you use.
    // pointers will use either 4 or 8 byte size depending on machines

    cout << p << endl;
    p--;
    cout << p << endl;

    // increament, decrement and comapre( like p1 > p2) works well in pointer
    // when pointing array elements
    return 0;
}