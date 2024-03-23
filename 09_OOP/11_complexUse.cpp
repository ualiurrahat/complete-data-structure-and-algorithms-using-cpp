/*
creating and performing creation,addition,multiplication,printing of complex numbers
using complex class
*/

#include <iostream>
using namespace std;
// adding the complex class
#include "10_complexClass.cpp"

int main()
{
    Complex c1(3, 6);
    Complex c2(7, 9);
    // c1.print();
    // c2.print();

    // c1.add(c2);
    // c1.print();

    c1.multiply(c2);
    c1.print();
    Complex c3(10, 15);
    Complex c4(12, 40);
    c3.add(c4);
    c3.print();

    return 0;
}