/**
 * @file 14_problemWithInbuiltConstructor.cpp
 * @brief Demonstrates the issue with the default (inbuilt) copy constructor.
 *
 * This program shows how the default copy constructor always performs a shallow copy,
 * which can lead to unexpected behavior when dynamically allocated memory is involved.
 */

#include <bits/stdc++.h>
using namespace std;

class Student
{
    int age;

public:
    // Changing the modifier of name property from "private" to "public"
    // just to see how it affects and to explore copy constructor behavior
    char *name;

    /**
     * @brief Constructor for Student class using deep copy for name
     * @param age Age of the student
     * @param name Character array representing student's name
     */
    Student(int age, char *name)
    {
        this->age = age;

        // Using deep copy to assign name to the object's name property
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name); // strcpy(destination, source)

        // Deep copy explanation:
        // We are creating a new character array dynamically with length = strlen(name)+1
        // Then copying the contents of the given name array to this new memory.
    }

    /// @brief Display function to print name and age
    void display()
    {
        cout << name << " " << age << endl;
    }
};

int main()
{
    // Creating a student
    char name[] = "rahat";
    Student s1(22, name);
    s1.display(); // Output: rahat 22

    // Now creating a new object using default copy constructor
    Student s2(s1);
    s2.display(); // Output: rahat 22

    // Changing 2nd index value of name array in s2 object
    s2.name[2] = 'f';

    // Print both s1 and s2
    cout << "After changing 2nd index character in object s2:" << endl;
    s1.display();

    // Explanation of the problem:
    // Before writing our own copy constructor:
    // s1 should print "rahat 22", but it prints "rafat 22"
    // Even though we made changes only in s2.
    // What actually happens:
    // - We take a character array 'name' (address e.g., 700)
    // - Create Student s1(22, name)
    //   - s1.age = 22
    //   - s1.name points to a new array of size strlen(name)+1 (deep copy, suppose at 800)
    // - Now, Student s2(s1) calls the default copy constructor
    //   - Default copy constructor does shallow copy
    //   - s2.age = s1.age = 22
    //   - s2.name = s1.name = 800 (shallow copy of pointer)
    // - Changing s2.name[2] = 'f' modifies the memory at 800
    // - Thus, s1.name[2] also changes
    // Solution:
    // - We need to write our own copy constructor to perform deep copy
    // - Done in next file: 15_ourOwnCopyConstructor.cpp

    s2.display(); // Output: rafat 22, correctly shows modification in s2

    return 0;
}
