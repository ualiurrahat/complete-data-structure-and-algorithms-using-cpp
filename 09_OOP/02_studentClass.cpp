/*
====================================================================
   FILE: 02_studentClass.cpp
   TOPIC: Class, Object, Constructors, Destructor, Getters & Setters
====================================================================

🧠 PURPOSE:
-----------
This file demonstrates the basic structure of a class in C++ and introduces
key OOP concepts such as:
- Defining a user-defined class
- Understanding access modifiers (private & public)
- Constructor types (default, parameterized)
- Destructor
- Getter & Setter functions
- The concept of `this` pointer
- Importance of encapsulation and abstraction

====================================================================
*/

#include <iostream>
using namespace std;

// ------------------------------------------------------------------
// class: A user-defined data type used to create objects having the
// same set of properties (attributes) and functions (behaviors).
// ------------------------------------------------------------------

// To check for which numbered object the destructor was called.
int i = 1;

// ------------------------------------------------------------------
// Student Class Definition
// ------------------------------------------------------------------
class Student
{
    /*
    ----------------------------------------------------------------
        Access Modifiers and Data Members
    ----------------------------------------------------------------
    */

    // By default, all class members are private in C++.
    // The `private` access modifier restricts direct access to
    // the members outside the class in which they are declared.
private:
    double cgpa;

public:
    // The `public` access modifier allows access to members from
    // outside the class. Public members can be freely used by other
    // parts of the program.

    // NOTE: Private data can still be accessed indirectly using
    // public functions (getters and setters) defined inside the class.

    int roll;
    int age;

    /*
    ----------------------------------------------------------------
        CONSTRUCTORS
    ----------------------------------------------------------------
    */

    // A constructor is a special function that has the same name
    // as the class. It is automatically called at the time of object
    // creation and is used to initialize class properties.
    //
    // Characteristics:
    // - Has no return type.
    // - Called only once per object at creation.
    // - If no constructor is written, the compiler provides a
    //   default (inbuilt) constructor automatically.

    // ----------------------------------------------------------------
    // Default Constructor
    // ----------------------------------------------------------------
    // This will be called whenever an object of Student class is
    // created without passing any parameters.
    //
    // Example:
    //     Student s1;
    //     → default constructor is invoked automatically.
    //
    // Note:
    // 1) If you do not define your own constructor, the compiler
    //    creates a default constructor automatically.
    // 2) If you define any constructor manually, the compiler no longer
    //    provides the inbuilt one unless you explicitly define it yourself.
    Student()
    {
        cout << "this: " << this << endl;
        cout << "default constructor called!" << endl;
    }

    // ----------------------------------------------------------------
    // Parameterized Constructor (Single Parameter)
    // ----------------------------------------------------------------
    // A parameterized constructor is one that takes parameters to
    // initialize the class attributes.
    //
    // Note:
    // 2) If there is a parameterized constructor in our program,
    //    we must also write a default constructor; otherwise,
    //    creating an object without parameters will cause a compile error.
    //
    // Example:
    //     Student s1(20);
    //     → single parameterized constructor is invoked.
    //
    // `this` keyword:
    // - A special pointer that stores the address of the current object.
    // - Used to differentiate between class attributes and function parameters
    //   when they have the same name.
    Student(int age)
    {
        cout << "this: " << this << endl;
        this->age = age;
        cout << "Single Parameterized constructor called!" << endl;
    }

    // ----------------------------------------------------------------
    // Parameterized Constructor (Double Parameter)
    // ----------------------------------------------------------------
    // Example:
    //     Student s2(21, 101);
    //     → double parameterized constructor is invoked.
    Student(int age, int roll)
    {
        cout << "this: " << this << endl;
        this->age = age;
        this->roll = roll;
        cout << "Double Parameterized constructor called!" << endl;
    }

    /*
    ----------------------------------------------------------------
        DESTRUCTOR
    ----------------------------------------------------------------
    */

    // Destructor: A special function that has the same name as the class
    // prefixed with a tilde (~). It is automatically called just before
    // the object is destroyed or goes out of scope.
    //
    // Characteristics:
    // - No return type.
    // - No parameters.
    //
    // Example:
    //     Student s1(10, 20);
    //     → Destructor will be called automatically before
    //       the program executes `return 0` in main().
    ~Student()
    {
        cout << "destructor called for object " << i << "!" << endl;
        i++;
    }

    /*
    ----------------------------------------------------------------
        GETTERS AND SETTERS
    ----------------------------------------------------------------
    */

    // Getter Function: Used to access (get) the value of a property.
    int getRoll()
    {
        return roll;
    }

    // Setter Function: Used to modify (set) the value of a property.
    void setRoll(int a)
    {
        roll = a;
    }

    // Setter for private variable cgpa
    void setCgpa(double x)
    {
        cgpa = x;
    }

    /*
    ----------------------------------------------------------------
        DISPLAY FUNCTION
    ----------------------------------------------------------------
    */

    // Function to display all property values of the Student object.
    void display()
    {
        cout << "cgpa: " << cgpa << endl;
        cout << "roll : " << roll << endl;
        cout << "age: " << age << endl
             << endl
             << endl;
    }

    /*
    ----------------------------------------------------------------
        DEEP QUESTION & CONCEPT: WHY USE GETTERS/SETTERS?
    ----------------------------------------------------------------
    */

    // Question:
    // If private properties can be accessed through public getter
    // and setter functions, what did we actually gain from making
    // them private? Anyone can still modify them through setters.

    // Answer:
    // The benefit is that we can control the access level of these
    // functions. For instance, we can secure setter functions using
    // additional checks such as passwords or permission validation.
    //
    // This is how **abstraction** and **controlled access** are
    // implemented in real-world software systems.

    // Example: Using password protection for setter
    /*
    int setRoll(int a, int password)
    {
        if (password != 1234)
        {
            return;
        }
        roll = a;
    }
    */

    // If the password does not match, the person cannot use
    // the setter function — hence, cannot modify private data.
    // This demonstrates a real-world abstraction mechanism.
};
