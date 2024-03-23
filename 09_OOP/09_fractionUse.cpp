/*
here, we will use our fraction class and create fraction numbers
*/
#include <bits/stdc++.h>
using namespace std;
// including fraction class
#include "08_fractionClass.cpp"

int main()
{

    Fraction f1(10, 2);
    Fraction f2(15, 4);
    f1.print();
    f2.print();
    // adding f2 with f1 and storing it in f1
    f1.add(f2);
    f1.print();
    f2.print();
    // multiplying f2 with f1 and storing it in f1
    f1.multiply(f2);
    f1.print();
    f2.print();
    return 0;
}