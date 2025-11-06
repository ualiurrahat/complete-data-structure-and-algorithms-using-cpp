/**
 * @file 12_shallowCopy.cpp
 * @brief Demonstrates the concept of Shallow Copy using a simple Student class.
 *
 * In this program, we define a `Student` class with `age` and `name` properties.
 * The `name` is stored as a pointer, and when assigned directly from another character array,
 * it results in a shallow copy.
 *
 * A **Shallow Copy** only copies the reference (address) to the original data,
 * not the actual content. Hence, any modification to the original data will also
 * affect the copied object's data because both share the same memory address.
 */

#include <iostream>
#include <cstring>
using namespace std;

// ---------------------- Class Definition ----------------------
class Student
{
    int age;
    char *name;

public:
    /**
     * @brief Constructor implementing Shallow Copy.
     *
     * @param age The student's age.
     * @param name Pointer to the character array representing the student's name.
     *
     * We are assigning the address of the `name` character array (i.e., the address
     * of its 0th index) directly to `this->name`. This is called a **Shallow Copy**.
     *
     * Example:
     *  - `this->name = name;`
     *  - If the original `name` array is later modified, the change will also reflect
     *    in this object because both share the same memory.
     */
    Student(int age, char *name)
    {
        this->age = age;
        this->name = name; // Shallow Copy
    }

    /// @brief Displays the student's name and age.
    void display()
    {
        cout << name << " " << age << endl;
    }
};

// ---------------------- Main Function ----------------------
int main()
{
    char name[] = "rahat";
    Student a(25, name);
    a.display(); // Output: rahat 25

    // Changing the 3rd letter of the `name` array.
    name[2] = 'f';
    Student b(22, name);
    b.display(); // Output: rafat 22

    // Printing `a` again.
    a.display(); // Output: rafat 25 (unexpected)

    /**
     * Explanation:
     *  - The object `a` should ideally print "rahat 25".
     *  - But it prints "rafat 25" because of **Shallow Copy**.
     *  - The `this->name` pointer in `a` holds the same address as `name` array.
     *  - Since we modified the array, `a`’s `name` is also affected.
     */

    return 0;
}
