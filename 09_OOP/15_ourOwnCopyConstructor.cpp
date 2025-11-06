/*
====================================================================
   FILE: 15_ourOwnCopyConstructor.cpp
   TOPIC: Deep Copy using User-Defined Copy Constructor
====================================================================

PURPOSE:
--------
This program demonstrates how to fix the shallow copy problem
caused by the inbuilt copy constructor by implementing a
user-defined deep copy constructor for the Student class.

It explains:
1. Shallow copy problem with inbuilt copy constructor
2. How deep copy solves it
3. Why using a non-reference parameter in copy constructor
   can lead to infinite recursion
4. Proper usage of const reference in copy constructor
====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Student
{
    int age; // age of the student

public:
    // Changing access modifier of 'name' from private to public
    // just to observe how shallow/deep copy affects it
    char *name;

    // Parameterized constructor
    Student(int age, char *name)
    {
        this->age = age;
        // Deep copy of 'name' to avoid shallow copy issues
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        /*
        Explanation:
        - We allocate a new array of characters dynamically.
        - strlen(name) + 1 accounts for the null terminator.
        - Copy the content of 'name' array into this object's 'name' pointer.
        - Now each object has its own copy of the name array.
        */
    }

    /*
    User-defined copy constructor:
    ------------------------------
    Inbuilt copy constructor always performs shallow copy.
    If we don't write our own, multiple objects will share the
    same memory for 'name', causing unexpected changes.

    WARNING:
    --------
    Do NOT write copy constructor as:
        Student(Student s)
    Why?
    -----
    - It appears as: "Student s = main.s"
    - This calls the copy constructor while creating 's' from main.s
    - Copy constructor parameter is passed by value
      → a new object needs to be created
      → to create it, the copy constructor is called again
    - This leads to infinite recursion and eventually stack overflow

    SOLUTION:
    ---------
    - Pass the object as const reference:
        Student(Student const &s)
    - 'const' ensures properties of the original object are not modified
    - '&' ensures no new object is created while passing
    */
    Student(Student const &s)
    {
        this->age = s.age;

        // Shallow copy (incorrect) would be:
        // this->name = s.name;

        // Deep copy (correct)
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
        /*
        Now, even if we change the 'name' of one object,
        the other object remains unaffected.
        */
    }

    // Display function
    void display()
    {
        cout << name << " " << age << endl;
    }
};

int main()
{
    // Creating first student object
    char name[] = "rahat";
    Student s1(22, name);
    s1.display(); // Output: rahat 22

    // Creating second student object using copy constructor
    Student s2(s1);
    s2.display(); // Output: rahat 22

    // Modifying 3rd character of name in s2
    s2.name[2] = 'f';

    cout << "After changing 2nd index character in object s2:" << endl;

    // Checking both objects
    s1.display(); // Output: rahat 22, unchanged
    s2.display(); // Output: rafat 22, changed

    /*
    Key Points:
    -----------
    1. Shallow copy would have caused s1.name to also change.
    2. By using deep copy in our copy constructor, each object
       has its own copy of the 'name' array.
    3. Passing the object as const reference prevents infinite
       recursion which would occur if parameter was passed by value.
    */

    return 0;
}
