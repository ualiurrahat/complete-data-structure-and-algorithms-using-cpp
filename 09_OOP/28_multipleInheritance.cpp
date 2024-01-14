/*
multiple inheritance: one derived class is inherited from many base classes.
here, we are creating class TA by inheriting Student and Teacher class.
*/

#include <iostream>
using namespace std;

class Teacher
{
public:
    string name;
    string age;

    void print()
    {
        cout << "Teacher: " << endl;
    }
};

class Student
{
public:
    void print()
    {
        cout << "Student: " << endl;
    }
};

// creating TA class by using multiple classes:Teacher,Student
// syntax for multiple inheritance:
// class clsName : accessModifier1 baseClass1,accessModifier2 baseClass2,....so on
// Note: In multiple inheritance, the first declared base class constructor
// will be called first, then followedy by the order class was inherited.
// here, when a TA object is created, first Teacher class
// constructor will be called then the Student class costructor.
class TA : public Teacher, public Student
{
public:
    void print()
    {
        cout << "TA:" << endl;
    }
};
int main()
{
    TA a;
    // a.print();
    // shows error. because we had not written the print()
    // funciton of the TA class (which we did later).
    // here, till now TA has no function of its own named print()
    // but it inherited print() from both classes
    // cause compiler is confused which print() funciton
    // user is pointing to.So we have to explicitly tell the compiler
    // syntax to write data members of funciton having same name in both class:
    // objName.className::data member;
    a.Student::print();
    // now it shows no error.

    // Note: but if we have a data member in the derived class
    //  same name as inherited from the derived classes,
    //  then compiler will execute derived class data member first.
    //  for ex: if TA had its own print() funcition,
    //  then a.print() will show no error.
    //  it is practiced below:

    a.print(); // TA class own print function is called
    return 0;
}