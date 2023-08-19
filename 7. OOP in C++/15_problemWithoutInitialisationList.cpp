// initialization list: In object-oriented programming (OOP), an initialization list, also known as an initializer list or member initialization list, is a mechanism used in various programming languages to initialize the member variables of a class within the constructor of that class. It's a way to set initial values for the class's data members when an object of the class is created.

/*
let's oversee a point:
int a = 5; allowed
int a;
a = 5; allowed
int const a; ** not allowed
note: we have to assign values for const variables at the time of creation
int const a = 25;
same goes for reference variable also. They must be assigned at the time of creation only.
int i = 25;
int &j = i; allowed
int &j;** not allowed
j = i; ** not allowed
*/

#include <bits/stdc++.h>

using namespace std;

class Student
{
public:
    int age;
    const int roll;
    /*
    Student (int r)
    {
        roll = r;
    }
    */
};

int main()
{
    // Student s1;
    // s1.age = 22;
    // s1.roll = 135;
    // error occurs. cause roll is an const var and we have to initialise it at the time
    //  of creation. Student s1 created s1.roll but needs to be initialised i.e. assigned value
    //  Solution: parameterized constructor to initialize roll number

    //  example:Student s1(135);
    //  but this also gives error.why?
    // suppose we write: int a;
    // a = 5; here, we did not write int before a. because a is already created in the previous line.
    // same goes for const int roll.
    // we did not write const int before roll = r in the paramter.
    // it means roll is already created and contains a garbage value.
    // now we are reassigning r in the roll. that is why error is occurring.
    // problem: we can not assign values of const var inside the constructor.
    // then how will we use const vars in class and assign their values?
    // Solution: we have to assign value of the const vars at the time of its creation
    // i.e. memory allocation
    // HOW: using initialisation List

    return 0;
}