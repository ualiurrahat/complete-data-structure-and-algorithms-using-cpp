/*
File: 38_compileTimePolymorphism.cpp

Topic: Compile-Time Polymorphism in C++

Compile-time polymorphism is also known as:
    → Static polymorphism
    → Early binding

The correct function is selected by the compiler during compilation.

Types of Compile-Time Polymorphism:
-----------------------------------
1) Function Overloading
2) Operator Overloading

Important Notes:
----------------
- Overloaded functions must differ by:
      i) Number of parameters
     ii) OR type of parameters
- Overloading can NOT be done only by changing return type.

This file demonstrates:
- Function overloading in detail
- Why return type difference alone is not enough
*/

#include <iostream>
using namespace std;

// ---------------------- Function Overloading Examples ----------------------

/**
 * @brief Prints a single integer.
 */
void show(int a)
{
    cout << "Integer: " << a << endl;
}

/**
 * @brief Prints two integers.
 */
void show(int a, int b)
{
    cout << "Two Integers: " << a << ", " << b << endl;
}

/**
 * @brief Prints a string.
 */
void show(string s)
{
    cout << "String: " << s << endl;
}

// INVALID OVERLOADING EXAMPLE — EXPLAINED IN COMMENTS
// ---------------------------------------------------
// int test() { return 10; }
// void test() { cout << "Hello"; }
// ❌ Error: Same name, same parameter list.
// Only return type is different → NOT allowed.

// ---------------------- Main Function ----------------------
int main()
{
    // Calling overloaded versions of show()

    show(10);      // calls show(int)
    show(10, 20);  // calls show(int, int)
    show("Rahat"); // calls show(string)

    /*
    Concept Recap:
    --------------
    - The compiler chooses the correct function based on arguments.
    - This is why it is called compile-time polymorphism.
    */

    return 0;
}
