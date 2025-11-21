/*
File: 35_functionOverloading.cpp

Topic: Function Overloading in C++

Function overloading is a type of **compile-time polymorphism**.
It allows multiple functions to have the same name **but differ in their parameters**.
The difference can be in:
1) Number of parameters
2) Type of parameters
3) Order of parameters (if types differ)

Important Note:
- Function overloading **cannot be done by return type alone**.
  Functions must differ in parameter list to be considered overloaded.

Example of function overloading:
*/

#include <iostream>
using namespace std;

// ---------------------- Function Overloading ----------------------

// Overloaded print() function: prints single integer
void print(int a)
{
    cout << a << endl;
}

// Overloaded print() function: prints two integers
void print(int a, int b)
{
    cout << a << " " << b << endl;
}

// Overloaded print() function: prints a string
void print(string a)
{
    cout << a << endl;
}

// NOTE:
// The following is NOT allowed, because only the return type is different:
// int test(){ return 25; }
// void test(){ cout << "rahat"; }
// ❌ Cannot overload by return type alone

// ---------------------- Main Function ----------------------
int main()
{
    // calling print() functions with different parameters
    print(25);      // calls print(int a)
    print(25, 8);   // calls print(int a, int b)
    print("rahat"); // calls print(string a)

    return 0;
}

/*
Explanation:
- Function overloading improves code readability by allowing the same function name
  for related operations.
- The compiler determines which function to call at **compile-time** based on
  the arguments provided.
- This is an example of **compile-time polymorphism** in C++.
*/
