/**
 * @file 13_deepCopy.cpp
 * @brief Demonstrates the concept of Deep Copy using a simple Student class.
 *
 * A **Deep Copy** creates a completely new copy of the data in a separate memory location.
 * Thus, changes made to the original data do not affect the copied object.
 *
 * This approach solves the problem of shared memory references seen in **Shallow Copy**.
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
     * @brief Constructor implementing Deep Copy.
     *
     * @param age The student's age.
     * @param name Pointer to a character array representing the student's name.
     *
     * **Deep Copy Process:**
     *  1. Dynamically allocate memory for the new `name` array of size `strlen(name) + 1`
     *     (the `+1` is for the null terminator `'\0'`).
     *  2. Copy the contents of the provided `name` array into the newly allocated memory
     *     using `strcpy(destination, source)`.
     *
     * Thus, each object gets its own independent copy of the `name` string.
     */
    Student(int age, char *name)
    {
        this->age = age;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name); // Deep Copy
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

    // Changing 3rd letter of `name` array.
    name[2] = 'f';
    Student b(22, name);
    b.display(); // Output: rafat 22

    a.display(); // Output: rahat 25

    /**
     * Explanation:
     *  - Since we used **Deep Copy**, the change in `name` array does not affect object `a`.
     *  - Each `Student` object now holds an independent copy of the `name` string.
     *  - The problem seen in shallow copy is now resolved.
     */

    return 0;
}
