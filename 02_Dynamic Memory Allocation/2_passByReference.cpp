#include <bits/stdc++.h>

using namespace std;

// int i = 10;
// int & k = i;
// here k is a reference var of i
// reference is not allowed any memory
// so its just like another name of i memory.

// benefits of reference memory:
// 1. it doesn't take any memory. so memory is saved
// 2. it can change the var inside main function
//     if send as a reference to any other function

void incrementbyValue(int n)
{
    n++;
    // this increment will not happen in main function var
    // it will happen only in the local var n
    // which will be vanished when the function
    // incrementbyValue is done.
}
void incrementbyReference(int &n)
{
    // this will change the var in the main function also
    n++;
}

// trying to access or return reference or address of a local var
// inside a local function, is a bad practice.
// because it may misbehave.
// very bad practice: returning reference of local var from function

// int &fun(int k)
// {
//     int a = k;
//     return a;
// }

// very bad practice:returning address of local var from funciton
// int *fun2()
// {
//     int a = 10;
//     return &a;
// }
int main()
{

    int i = 10;
    int &j = i; // j is referencing i;
    cout << i << endl;
    cout << j << endl;
    i++;
    cout << i << " " << j << endl;

    incrementbyValue(j);
    cout << j << endl; // j's value will not change.

    // don't return a refernce or address of local var from a function
    // as soon as the function work ends, you may not use the momory.
    // int &a = fun(i); // don't practice this
    // int *b = fun2(); // don't practice this

    incrementbyReference(j);
    // j's value will change this time
    cout << j << endl;

    int k = 100;
    j = k;
    // now j is coping k's value. so j and i will have k's value.
    // since j and k is same
    cout << j << " " << i << endl;

    return 0;
}