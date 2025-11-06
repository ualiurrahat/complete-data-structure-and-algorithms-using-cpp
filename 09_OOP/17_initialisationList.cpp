/*
====================================================================
   FILE: 17_initializationList.cpp
   TOPIC: Initialization List in C++ for const and reference members
====================================================================

🧠 PURPOSE:
-----------
This program demonstrates the use of **initializer lists** to properly
initialize **const** and **reference** members of a class.
Initializer lists allow us to assign values at the time of memory
allocation, which is required for const and reference variables.

⚠️ NOTE:
---------
1. Const and reference members **must** be initialized at creation.
2. Initializer lists are the correct way to initialize these members
   instead of assigning them in the constructor body.

====================================================================
*/

#include <iostream>
using namespace std;

class Student
{
public:
    int age;        // normal integer member
    const int roll; // const member (must initialize at creation)
    int &x;         // reference member (cannot be assigned in constructor body)

    /*
    ------------------------------------------------------------
       INITIALIZER LIST USAGE EXAMPLES
    ------------------------------------------------------------

    1️⃣ Case 1: Only initializing const member
       Student(int r) : roll(r) { }

       - Interpreted as: const int roll = r;
       - Error-free approach for const variables.

    2️⃣ Case 2: Initialize non-const member along with const
       Student(int r, int age) : roll(r), age(age) { }

       - No confusion even if parameter has the same name as member.
       - this->age(age) is not allowed, compiler error.

    3️⃣ Case 3: Initialize reference member
       - Must use another member or value to bind reference
       - Student(int r, int age) : roll(r), age(age), x(this->age) { }
       - Cannot use x(age), because compiler may confuse parameter and member
    ------------------------------------------------------------
    */

    // Correct constructor using initializer list for const and reference members
    Student(int r, int age) : roll(r), age(age), x(this->age)
    {
        // constructor body can remain empty for initializer list
    }

    // Function to display object data
    void display()
    {
        cout << "roll: " << this->roll << endl;
        cout << "age: " << this->age << endl;
    }
};

int main()
{
    // Creating Student object with roll = 135, age = 22
    Student s1(135, 22);

    s1.display();

    // Displaying reference member
    cout << "value of x: " << s1.x << endl;

    return 0;
}
