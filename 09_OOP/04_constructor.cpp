/*
Problem Statement:
------------------
This program demonstrates the **concept of constructors** in Object-Oriented Programming (OOP)
using the `Student` class defined in another file (02_studentClass.cpp).

We explore:
1. Default constructor
2. Parameterized constructor (single and double)
3. How constructors are automatically invoked when objects are created
4. How the `this` pointer works in constructors
5. Relationship between object memory address and the `this` pointer

-------------------------------------------------------------
Concepts Explained:
-------------------------------------------------------------
Constructor:
------------
A **constructor** is a special function within a class that is automatically called
when an object of that class is created. Its main purpose is to **initialize** the object.

Key points:
- It has the **same name** as the class.
- It has **no return type** (not even void).
- It can be **default** (no parameters) or **parameterized** (one or more parameters).
- If no constructor is explicitly written, a **default constructor** is automatically
  created by the compiler.
- Once you write your own constructor, the compiler does **not** create the default one.

Types of Constructors:
-----------------------
1. **Default Constructor**:
   - Takes no arguments.
   - Used to create an object with default or uninitialized (garbage) values.
   - Example: `Student s1;`

2. **Parameterized Constructor**:
   - Takes one or more arguments.
   - Used to initialize objects with specific values.
   - Example: `Student s2(10);` or `Student s3(20, 5);`

3. **Copy Constructor (not shown here)**:
   - Used to create a new object as a copy of an existing one.
   - Syntax: `Student s4(s3);`

-------------------------------------------------------------
The `this` pointer:
-------------------
- Inside a class, `this` is a special pointer that stores the address of the current object.
- It helps the constructor (or any member function) know which object it’s referring to.
- Example: When you create `Student s1;`, `this` points to the address of `s1`.

-------------------------------------------------------------
Purpose of this program:
------------------------
- To verify that different constructors are automatically called when corresponding objects are created.
- To observe that the `this` pointer and the actual object address are the same.
- To print values initialized (or left uninitialized) by constructors.
*/

#include <iostream>
using namespace std;

// Including the header file containing Student class definition.
#include "02_studentClass.cpp"

int main()
{
    // ---------------------- Default Constructor ----------------------
    // This constructor is called automatically when no arguments are passed.
    // It prints "default constructor called!" and assigns garbage values to data members.
    Student s1;
    cout << "Address of s1: " << &s1 << endl;
    s1.display(); // prints uninitialized (garbage) values for cgpa, roll, and age

    // ---------------------- Single Parameterized Constructor ----------------------
    // This constructor takes one argument (age) and assigns it using the 'this' pointer.
    Student s2(10);
    cout << "Address of s2: " << &s2 << endl;
    s2.display(); // roll and cgpa remain uninitialized (garbage values)

    // ---------------------- Double Parameterized Constructor ----------------------
    // This constructor takes two arguments (age and roll) and assigns them.
    Student s3(2, 25);
    cout << "Address of s3: " << &s3 << endl;
    s3.display();

    // ---------------------- Destructor Calls ----------------------
    // When main() finishes execution, destructors for s3, s2, and s1 are automatically called
    // in reverse order of their creation (Last In, First Out).

    return 0;
}
