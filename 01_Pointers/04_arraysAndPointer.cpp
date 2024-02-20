#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
    The differnces between array and pointer arise, are because of one thing
    array takes a single block of continuous element, so it can not be reassigned.
    pointer takes a 4 or 8 bit of memory. so it can be reassigned.

    int a[10];
    here, a behaves like a poiter but not a pointer completely
    ex: a = a+1 or a++, not possible in array
    because once a's address is stored in the symbol table
    it cannot be changed
    *** symbol table entry can't be changed ever
    ex: p = p+1, p++, p = &a[0] and then p = &a[3], possible in pointer.
    */

    int a[10];

    cout << a << endl;
    cout << &a << endl;
    cout << &a[0] << endl;
    // a points to the a[0] address. so a, &a, &a[0] is same location

    int *p = &a[0];

    a[0] = 25;
    a[1] = 35;
    cout << *a << endl;
    cout << *(a + 1) << endl;
    cout << a[1] << endl;

    cout << a << endl;
    cout << &a << endl;
    cout << p << endl;
    cout << &p << endl;
    // there is difference between &p and &a.
    // because pointer p is given an 8 or 4 bytes of memory
    // where it stores address of other variable.
    // but a is not given any other extra memory
    // array a has total 40 bit of memory where a points to the a[0] address
    // and a[0] holds 4 bytes of memory

    cout << sizeof(p) << endl;
    cout << sizeof(a) << endl;
    // see, the p pointer is 4 bytes where a has full 40 bytes
    // cause array is given a continuous block of memory

    // 3 key differnce in memory allocation between pointers and array:
    // 1. sizeof() operator
    // in array sizeof() shows whole array size where pointer shows only its size
    // 2. &a vs &p
    // a and &a has same location as no other memory is alloted to a
    // but &p shows the address where p is located
    // and p shows address of other var
    // so a and &a is same but p and &p is not same

    // p = p+1, is possible
    // but a = a+1 is not possible

    free(p);

    // things we can't do with array
    // a = a+1    array can't be reassigned.
    // hence, a++ is not possible.
    // p = p+1  (pointer can be reassigned)

    return 0;
}