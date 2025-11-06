/*
Problem Statement:
------------------
This program demonstrates how to **create and access objects** of a class in both
**static** and **dynamic** ways using C++.

It includes examples of:
- Static object creation
- Dynamic object creation using pointers
- Accessing object properties
- Understanding memory allocation differences between static and dynamic objects
- Using arrow operator (`->`) and dereferencing (`*`) to access members
*/

#include <iostream>
using namespace std;

// Including the header file containing the Student class definition.
#include "02_studentClass.cpp"

int main()
{
     // ---------------------- Static Object Creation ----------------------
     // Creating objects statically means that memory is allocated at compile time.
     // These objects are automatically destroyed when they go out of scope (e.g., when main() ends).
     Student s1, s2;

     // Initially, these objects have garbage values in their properties,
     // because the constructor didn’t explicitly assign any initial value.
     // Example: s1.age = garbage_value; s1.roll = garbage_value;

     // Accessing and assigning values to static object properties
     // Syntax: objectName.propertyName = value;
     s1.age = 20;
     s1.roll = 1;

     s2.age = 21;
     s2.roll = 2;

     // Printing static object properties
     cout << "Student 1: "
          << " Roll: " << s1.roll << " Age: " << s1.age << endl;
     cout << "Student 2: "
          << " Roll: " << s2.roll << " Age: " << s2.age << endl;

     cout << endl;

     // ---------------------- Dynamic Object Creation ----------------------
     // Dynamic objects are created at runtime using the 'new' keyword.
     // Memory is allocated in the heap segment.
     // Syntax: dataType *objectName = new dataType;

     Student *s3 = new Student; // dynamically creating Student object s3

     // Accessing properties of a dynamically created object using dereferencing.
     // Syntax 1 (using dereferencing operator *): (*objectPointer).propertyName = value;
     // Syntax 2 (using arrow operator ->): objectPointer->propertyName = value;
     (*s3).age = 25; // Equivalent to s3->age = 25;
     (*s3).roll = 5; // Equivalent to s3->roll = 5;

     // Creating another dynamic object
     Student *s4 = new Student;
     s4->age = 23;
     s4->roll = 18;

     // Printing dynamic object properties
     cout << "Student 3: "
          << " Roll: " << s3->roll << " Age: " << s3->age << endl;
     cout << "Student 4: "
          << " Roll: " << s4->roll << " Age: " << s4->age << endl;

     // ---------------------- Memory Deallocation ----------------------
     // Since dynamic objects are stored in heap memory,
     // we must manually release memory using 'delete' to avoid memory leaks.
     delete s4; // This will also call the destructor for s4.
     delete s3; // This will also call the destructor for s3.

     // Note: For static objects (s1, s2), destructors are called automatically
     // at the end of the main() function when they go out of scope.

     return 0;
}
