/*
    FILE: 29_multipleInheritance.cpp

    ------------------------------ THEORY --------------------------------

    Multiple Inheritance:
    ---------------------
    A derived class can inherit from more than one base class.
    Example:
        class TA : public Teacher, public Student

    Meaning:
        TA object inherits properties and behaviors from BOTH Teacher and Student.

    Constructor Call Order:
    -----------------------
    When creating an object of a multiple-inherited class:
        - Constructors of base classes are called in the order they are inherited.
        - Here: TA : public Teacher, public Student
            → Teacher constructor runs first
            → Student constructor runs second
            → Finally TA constructor (if defined)

    Ambiguity Issue:
    ----------------
    If multiple base classes contain a member with the same name (e.g., print()),
    then calling obj.print() causes ambiguity because the compiler cannot determine
    which base class version to call.

    Solution:
        Use Scope Resolution Operator:
            objectName.BaseClassName::memberFunction()

    But:
        If the derived class overrides that function with its own version,
        then the derived class version will always be called directly.

*/

#include <iostream>
using namespace std;

// ----------------------------- Base Class 1 ------------------------------ //
class Teacher
{
public:
    string name;
    string age;

    Teacher()
    {
        cout << "Teacher class constructor called!" << endl;
    }

    void print()
    {
        cout << "Teacher:" << endl;
    }
};

// ----------------------------- Base Class 2 ------------------------------ //
class Student
{
public:
    Student()
    {
        cout << "Student class constructor called!" << endl;
    }

    void print()
    {
        cout << "Student:" << endl;
    }
};

// ---------------------------- Derived Class ------------------------------ //
// TA class inherits from BOTH Teacher and Student.
// Syntax of multiple inheritance:
//      class Derived : accessModifier Base1, accessModifier Base2, ...
//
// Constructor Call Order:
//      Since Teacher is inherited first, Teacher constructor executes first.
//      Then Student constructor executes.
//      Finally TA constructor (if defined).
class TA : public Teacher, public Student
{
public:
    // Derived class having its own print() function.
    // This will resolve the ambiguity issue automatically because
    // TA's own print() overrides both base versions.
    void print()
    {
        cout << "TA:" << endl;
    }
};

int main()
{
    TA a; // Teacher constructor → Student constructor → (TA constructor if existed)

    // Trying to call print() when TA does NOT yet have its own print():
    // a.print();      // would give ambiguity error because both Teacher and Student have print().

    // To access an inherited function when names clash:
    // Syntax:
    //      objectName.BaseClassName::functionName();
    a.Student::print(); // Calling Student's print() explicitly.

    // NOTE:
    // If the derived class (TA) has its own print(),
    // it overrides both inherited versions. So:
    a.print(); // Calls TA's own print() with NO ambiguity.

    return 0;
}
