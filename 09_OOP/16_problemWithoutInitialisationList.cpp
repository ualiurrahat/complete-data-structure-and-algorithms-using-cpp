/*
====================================================================
   FILE: 16_problemWithInitializationList.cpp
   TOPIC: Initialization List in C++
====================================================================

PURPOSE:
--------
This program explains the problem with assigning values to
`const` and reference variables inside a constructor and
introduces the concept of an **initialization list** in C++.

Key Points:
-----------
1. Const and reference variables must be initialized at the
   time of creation; assignment after creation is not allowed.
2. Using a constructor body to assign values to const/reference
   variables will cause a compilation error.
3. Initialization lists provide a way to initialize such variables
   at the time of memory allocation.

====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    int age;        // normal variable, can be assigned inside constructor or after object creation
    const int roll; // const variable, must be initialized at the time of creation

    /*
    Example of a constructor body (WRONG approach):
    -----------------------------------------------
    Student(int r)
    {
        roll = r; // ❌ Error: cannot assign value to const variable here
    }
    */
};

int main()
{
    /*
    Demonstration of const variable assignment problem:
    --------------------------------------------------

    // Student s1;
    // s1.age = 22;
    // s1.roll = 135; // ❌ Error: roll is const and must be initialized at creation

    Explanation:
    ------------
    - 'roll' is a const variable.
    - Memory for 'roll' is already allocated when object is created.
    - Assigning a value in the constructor body is equivalent to
      "reassigning" it after creation, which is illegal.

    Solution:
    ---------
    - Use a **parameterized constructor with initialization list**.

    Example (still wrong if using assignment inside constructor body):
    Student s1(135);
    Why error occurs:
    - Writing 'roll = r;' inside the constructor body attempts to
      assign after creation.
    - Const variable must be initialized during memory allocation.

    Correct approach (not implemented yet in this file):
    -----------------------------------------------------
    - Use initialization list in constructor:
      Student(int r) : roll(r) {}
    - This assigns value to const variable at the time of creation.
    */

    /*
    Additional Note:
    ----------------
    Similar rules apply to reference variables:

    int i = 25;
    int &j = i;   // ✅ allowed
    int &j;       // ❌ not allowed
    j = i;        // ❌ not allowed
    */

    return 0;
}
