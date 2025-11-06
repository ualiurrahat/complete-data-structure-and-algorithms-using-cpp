/*
====================================================================
   FILE: 06_copyConstructor_vs_assignmentOperator.cpp
   TOPIC: Copy Constructor, Copy Assignment Operator, and Destructor
====================================================================

🧠 PURPOSE:
-----------
This program demonstrates the concepts of:
1. Copy Constructor
2. Copy Assignment Operator (=)
3. Destructor

using the Student class defined earlier (in 02_studentClass.cpp).

It explores how objects can be copied, assigned, and destroyed — both
statically and dynamically — along with detailed explanations of
how memory handling and object lifecycle work in C++.

====================================================================
   🧩 CONCEPT 1: COPY CONSTRUCTOR
====================================================================

Definition:
------------
A copy constructor is a constructor that initializes an object using
another object of the same class.

Syntax:
-------
ClassName (const ClassName &oldObject)

Purpose:
--------
- To create a new object as a copy of an existing one.
- Automatically invoked when:
  - A new object is created from an existing object.
  - An object is passed by value to a function.
  - An object is returned by value from a function.

Types:
------
1. Default Copy Constructor (Implicit)
   - Provided automatically by the compiler if not defined explicitly.
   - Performs a shallow copy (member-wise copying).

2. User-Defined Copy Constructor
   - Can be written to perform deep copy when pointers or dynamic memory is involved.

Example:
--------
Student b(a);  // Calls the copy constructor

Internally:
b.age = a.age;
b.roll = a.roll;

====================================================================
   🧩 CONCEPT 2: COPY ASSIGNMENT OPERATOR (=)
====================================================================

Definition:
------------
The copy assignment operator (=) is used to copy the contents of
one object into another already existing object.

Syntax:
-------
obj1 = obj2;

Difference from Copy Constructor:
---------------------------------
- Copy constructor → works at the time of object creation.
- Copy assignment operator → works on objects that already exist.
- Copy constructor creates a new object; assignment operator replaces values in an existing object.
- Both are provided by default by the compiler if not defined explicitly.

Example:
--------
Student e(5, 29);
Student f(7, 31);
e = f; // Copy assignment operator

====================================================================
   🧩 CONCEPT 3: DESTRUCTOR
====================================================================

Definition:
------------
A destructor is a special function automatically called when an object
goes out of scope or is deleted.

Syntax:
-------
~ClassName()

Purpose:
--------
- Release resources like memory, files, network handles, etc.
- For dynamically created objects, must use delete to call destructor.

Example:
--------
delete ptr; // Calls destructor for dynamically created object

====================================================================
   ⚙️ OBJECTIVE OF THIS PROGRAM:
====================================================================
1. Demonstrate copy constructor (implicit version)
2. Show difference between copy constructor and assignment operator
3. Understand destructor calls (automatic and manual)
4. Explore dynamic object creation and deletion
====================================================================
*/

#include <iostream>
using namespace std;

// Including header file containing Student class definition
#include "02_studentClass.cpp"

int main()
{
    // ---------------------- Parameterized Constructor ----------------------
    // Creates object 'a' using two-parameter constructor
    Student a(1, 20);
    a.display();

    // ---------------------- Copy Constructor ----------------------
    // Creates a new object 'b' with same properties as 'a'
    Student b(a); // Default copy constructor invoked
    b.display();

    // ---------------------- Dynamic Object with Copy Constructor ----------------------
    // Dynamically create object 'c'
    Student *c = new Student(3, 22);
    c->display();

    // Create object 'd' by copying values from dynamically created '*c'
    Student d(*c); // Copy constructor called
    d.display();

    // ---------------------- Copy Assignment Operator ----------------------
    // Create objects 'e' and 'f'
    Student e(5, 29);
    e.display();

    Student f(7, 31);

    // Assign values of f to e using copy assignment operator
    e = f;

    // Equivalent to e.age = f.age; e.roll = f.roll;
    cout << "After assignment:" << endl;
    cout << "e.age:  " << e.age << endl;
    cout << "e.roll: " << e.roll << endl
         << endl;

    // ---------------------- Copying from Dynamically Created Object ----------------------
    // Copy values of e to dynamic object *c
    *c = e;

    // ---------------------- Destructor Calls ----------------------
    // Destructors are called automatically for:
    // a, b, d, e, f (static objects)
    // For dynamic object c, we need to delete to free memory
    delete c; // Destructor called for c

    return 0;
}
