#include <bits/stdc++.h>

using namespace std;

// int n;
// cin >>n;
// int a[n]; this is bad practice
// cause a[n] is stored in stack memory
// a small memory is alloted in stack
// so, if n is a huge number, then a[n] might not get
// enough memory
// but heap is having a big memory
// so dynamic memory comes in to solve this problem

int main()
{

    int *p = new int;

    // p gets stored in stack and 4 bytes for new int stored in heap.
    *p = 10;
    cout << *p << endl;

    double *pd = new double;

    char *pc = new char;

    // array memory allocation

    int *pa = new int[5];

    int n = 35;
    // pa2 is good practice
    // since we are using heap memory
    int *pa2 = new int[n];

    // but how will store elements in the array.
    // just like we do in array
    // like a[0] = 25;
    pa[0] = 18;
    pa[1] = 1;

    pa2[0] = 20;
    pa2[1] = 1;

    cout << pa[0] << " " << pa[1] << " " << pa[1] << " " << pa[0] << endl;

    // deleting memory
    // 'delete p' = deletes the 4 bytes heap memory(new int) it used to point
    // the stack memory owned by p will be automatically free
    // once the program gets out of its scope

    delete p; // deleting single memory
    delete pd;
    delete pc;
    delete[] pa; // deleting memory
    delete[] pa2;

    // why deleting memory is so important?
    // example: 1
    // while(true)
    // {
    //     int n;
    // }
    // this program will run forever
    // every time n will take 4 bytes
    // will release the memory as soon as program comes out of its scope
    // so n will be recreated and will re-release its memory everytime
    // code will run forever.

    // example: 2
    // while(true)
    // {
    // int *p = new int;
    // }
    // p will release its memory once program gets out of its scope
    // but since new int is heap memory
    // it won't be deleted automatically
    // so program will crash once it
    // deavours all the heap memory.

    return 0;
}