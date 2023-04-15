//#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;
// why write namespace?
// namespace is a scope for function and var
// c++ has written its functions on std

// own written namespace
// we can write our own namespace like this
namespace rahat
{
    int val = 25;
    int getVal()
    {
        return val * 10;
    }
}

// using struct in a professional way.
struct Person
{
    string name;
    int age;
    double income;

    Person(string a, int b, double c)
    {
        name = a;
        age = b;
        income = c;
    }
};

int main()
{
    // int a = 5;
    // double a = 2.5;
    // standard namespace shows error on above code.
    // if we don't use std namespace, we can't use cout like (cout << a;)
    // cout should be written as: std:: cout which is painful

    int val = 10;
    cout << val << endl;        // 10
    cout << rahat::val << endl; // 25
    cout << rahat::getVal() << endl; // 250

    // wrong way of defining struck
    // Person r;
    // r.name = "loser";
    // r.income = 0.00;
    // r.age = 25;

    // right way of defining struct
    Person *loser = new Person("rahat", 25,0.00);

   
    return 0;
}