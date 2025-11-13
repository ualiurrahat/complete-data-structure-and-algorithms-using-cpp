/*
============================================================================
   FILE: 20_staticDataMember.cpp
   TOPIC: Static Data Members and Static Member Functions in C++
============================================================================

🧠 PURPOSE:
-------------
This program demonstrates the concept of **static data members** and
**static member functions** in C++.

📘 THEORY:
-----------
- A **static member** belongs to the **entire class**, not to any specific object.
- It is **shared among all objects** of the class.
- There exists **only one copy** of a static member, regardless of how many
  objects of the class are created.

⚙️ CHARACTERISTICS:
--------------------
1. Static data members are declared inside the class but **defined outside** it.
2. Static members can be accessed using the **class name** and the **scope resolution operator (::)**.
3. Static members can also be accessed through objects (not recommended — bad practice).
4. Static member functions can access **only static data members**.
5. Static member functions **do not have access** to the `this` pointer,
   since they do not operate on any particular object instance.

============================================================================
*/

#include <iostream>
using namespace std;

/*
====================================================================
   CLASS: Student
====================================================================

Demonstrates how static data members and static functions work.

📌 Key Points:
---------------
- `totalStudent` is a static data member — belongs to the class, not to any object.
- The constructor increments the `totalStudent` count each time a new object is created.
- `getTotalStudent()` is a static function to access the total count safely.
*/

class Student
{
public:
    int roll; // Roll number of student
    int age;  // Age of student

    // ---------------------- Static Data Member ----------------------
    /**
     * @brief Shared among all objects of the class.
     *
     * - Belongs to the class, not any specific object.
     * - Only one copy exists, regardless of number of objects created.
     */
    static int totalStudent;

    // ---------------------- Constructor ----------------------
    /**
     * @brief Increments totalStudent count when a new object is created.
     */
    Student()
    {
        totalStudent++;
    }

    // ---------------------- Static Function ----------------------
    /**
     * @brief Returns the total number of students (static count).
     *
     * NOTE:
     * - Static function can access only static data members.
     * - Static functions do **not** have access to the `this` pointer,
     *   since they are not tied to any object.
     */
    static int getTotalStudent()
    {
        return totalStudent;
    }
};

/*
====================================================================
   STATIC DATA MEMBER INITIALIZATION
====================================================================

Since `totalStudent` is a class-level member, it must be defined and initialized
**outside** the class using the scope resolution operator (::).

📌 Syntax:
-----------
    dataType ClassName::staticMemberName = initialValue;
*/
int Student::totalStudent = 0;

/*
====================================================================
   MAIN FUNCTION
====================================================================

Demonstrates:
- Accessing static data through both objects and class (and why only
  the class-based access is good practice).
- Counting total number of students using static data members.
- Calling static functions.
*/

int main()
{
    Student s1;

    cout << s1.totalStudent << endl;
    /*
    ⚠️ BAD PRACTICE:
    -----------------
    Accessing static member using object (`s1.totalStudent`) is allowed,
    but misleading, since static members belong to the class itself.
    */

    // ✅ GOOD PRACTICE:
    // Accessing static data using the class name and scope resolution operator (::)
    cout << Student::totalStudent << endl;

    // Creating multiple objects to test shared static member
    Student s2;
    Student a, b, c, d, e;

    // totalStudent = 7 (s1, s2, a, b, c, d, e)
    cout << Student::totalStudent << endl;

    /*
    ⚠️ BAD PRACTICE EXAMPLE (not recommended):
    -------------------------------------------
    We can assign static data using object (e.g., s2.totalStudent = 20;)
    But it affects the single shared copy — misleading and confusing.
    */
    // s2.totalStudent = 20;     // Not recommended
    // cout << s1.totalStudent << endl;  // Would print 20 (same shared copy)

    // ✅ Calling static function properly through class name
    cout << Student::getTotalStudent() << endl;

    return 0;
}
