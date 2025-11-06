/*
====================================================================
   FILE: 07_playingWithConstructor.cpp
   TOPIC: Exploring Constructors and Copy Assignment Operator
====================================================================

🧠 PURPOSE:
-----------
This program demonstrates:
1. Default constructor
2. Parameterized constructors (single and double)
3. Copy constructor
4. Copy assignment operator

using the Student class defined in 02_studentClass.cpp.
It also explains when constructors and assignment operators are invoked
and highlights the subtle difference between copy constructor and copy assignment operator.
*/

#include <iostream>
using namespace std;

// Including header file containing Student class definition
#include "02_studentClass.cpp"

int main()
{
    // ---------------------- Default Constructor ----------------------
    // Creates object 's1' using default constructor
    Student s1; // default constructor called

    // ---------------------- Parameterized Constructors ----------------------
    // Creates object 's2' using single-parameter constructor
    Student s2(25); // single parameter constructor called

    // Creates object 's3' using two-parameter constructor
    Student s3(25, 3); // double parameter constructor called

    // ---------------------- Copy Constructor ----------------------
    // Creates object 's4' by copying 's3'
    Student s4(s3); // copy constructor called

    // ---------------------- Copy Assignment Operator ----------------------
    // Assigning values of s2 to already existing object s1
    s1 = s2; // copy assignment operator used, no constructor called

    // ---------------------- Copy Initialization ----------------------
    // Creates new object 's5' and initializes it with 's3'
    Student s5 = s3; // copy constructor called

    /*
       Explanation:

       Copy assignment operator works when two objects already exist in memory.
       Example: s1 = s2; // both s1 and s2 already have memory allocated

       But in the case of:
           Student s5 = s3;
       s5 is being created at the same time it is initialized.
       Compiler interprets it as:
           Student s5(s3);
       Therefore, copy constructor is called, not the assignment operator.

       Key Note:
       - Assignment operator requires pre-existing objects.
       - Copy initialization of a new object invokes the copy constructor.
    */

    return 0;
}
