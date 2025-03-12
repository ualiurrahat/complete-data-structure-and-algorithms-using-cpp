#include <bits/stdc++.h>

using namespace std;

// it takes 3 steps to create int i = 30;
// i. memory allocation for i
// ii. entry of i in system table
// iii. assign value of i

// system table : a table where variable with their data type and address is stored

// what pointer does is storing address of a var
// so any data type of pointer usually take same bits of memory.
// size can be 8 or 4 byte depending on machines.

int main()
{
    // with variable, we access a block of memory to contain numbers
    // ex: with 'i' we control what will be stored in memory possessed by var i.
    // address of operator(&) : gives the address of a variable
    int i = 25;
    cout << "address of i(&i) = " << &i << endl;

    // pointer is a var which stores address of other var
    // if a var stores address of 'i', then it becomes pointer of i

    int *p = &i;
    // since &i is address of i,
    // and p storeds address of int var, so &i is assigned to p
    cout << "address of i (using pointer p) = " << p << endl;

    // checking size of pointer p
    cout << "size of pointer p :" << sizeof(p) << endl;
    cout << "size of integer: " << sizeof(int) << endl;
    cout << endl;
    cout << "value of i : " << i << endl;
    cout << "value of i(using *p): " << *p << endl;
    i++;
    cout << "after increment of i : " << endl;
    cout << "value of i : " << i << endl;
    cout << "value of i(using *p): " << *p << endl;

    int a = i;
    // same as int a = *p;
    a++;
    // a will be increased but not i
    // since i and a points different location
    cout << "value of i : " << i << endl;
    cout << "value of a: " << a << endl;

    // taking another pointer pointing the same address of i
    int *q = p;
    (*q)++;
    // q,p and i points the same location.
    // so increase of q means increase in p and i
    cout << "value of i: " << i << endl;
    cout << "value of *p: " << *p << endl;
    cout << "value of *q: " << *q << endl;

    return 0;
}