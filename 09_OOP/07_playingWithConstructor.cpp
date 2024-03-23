#include <iostream>
using namespace std;
// including header file containing Student class.
#include "02_studentClass.cpp"

int main()
{

    Student s1;        // default constructor called
    Student s2(25);    // one parameter constructor called
    Student s3(25, 3); // two parameter constructor called

    Student s4(s3); // copy constructor called

    s1 = s2; // no constructor calling. just using copy assignment operator

    Student s5 = s3; // copy constructor

    // copy assignment works when two objects are already having space in the program
    // means objects are already created before copy assingment operationg in performed
    // then what is Student s5 = s3 ??
    // s5 was not created before.
    // it is like doing:
    //  Student s5;
    // s5 = s3;
    // but compiler understands it like: Student s5(s4);
    // so program calls copy constructor
    // note: when new objects are given copy assignment operation directly
    // before it creats space in the program for itself.
    // compiler takes it as copy constructor.
    return 0;
}