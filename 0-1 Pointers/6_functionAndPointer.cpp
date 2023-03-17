#include <bits/stdc++.h>

using namespace std;

// function to print the value of a given pointer
void print(int *p)
{
    cout << *p << endl;
}

// function to change the pointer address
void incrementPointer(int *p)
{
    cout << p << endl;
    p = p + 1;
    cout << p << endl;
}

// function to increase the value pointed by a pointer through dereferencing
void incrementPointerValue(int *p)
{
    (*p)++;
}
// }

int sum(int *a, int size)
{

    // in function parameter, a[] is not as array
    // it is as pointer
    // arrays work as pointer when sent as function parameter.
    // so, sizeof(a) will show size of a pointer i.e. 4 or 8 bytes depending on machines.
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += a[i];
    }

    return sum;
}
int main()
{
    int a = 25;
    int *p = &a;

    print(p);
    // print() will print the value 25 as
    // p holds the address of a
    cout << p << endl;

    incrementPointer(p);
    // when we pass a pointer as a function input
    // we just send a copy of the pointer
    // not the original pointer.
    // so guess the output below.
    cout << p << endl;

    cout << *p << endl;
    incrementPointerValue(p);
    // will the function change p's value or not.
    // address does not get changed.
    // but value gets change.
    // cause you are changing value with address reference.
    // like (*p)++
    // means, you are saying increase the value by 1 pointing at address p.
    cout << *p << endl;

    cout << endl;
    int b[] = {18, 1, 8, 1, 20};
    cout << sizeof(b) << endl;
    cout << sum(b, 5) << endl;
    // we can also pass address of any array element in a function.
    // we will be able to pass part of an array to a fucntion.
    cout << sum(b + 1, 3) << endl;

    free(p);

    return 0;
}