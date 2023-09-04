/*
function overloading: having same name more than one funcitons
they differ by the number of paramters,
the type of paramters
NOTE: funciton overloading can not be happened
just by return type difference of the function

*/

#include <iostream>
using namespace std;

// function overloading of print() function
void print(int a)
{
    cout << a << endl;
}
void print(int a, int b)
{
    cout << a << " " << b << endl;
}
void print(string a)
{
    cout << a << endl;
}
// NOTE: we can not create function overloading just by
// using different return type of the function.
// the difference has to be either in the total no. of parameters used
// or the same number of paratemeters with different types
// ex: we can not create another funciton like:
// int test(){return 25;}
// void test(){cout <<"rahat"};
// it is not allowed. as both functions have no parameter
// only their return type is different.this is not right.
int main()
{
    print(25);
    print(25, 8);
    print("rahat");
    return 0;
}