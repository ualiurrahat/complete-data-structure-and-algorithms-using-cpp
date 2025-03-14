#include <iostream>

using namespace std;

// In C++, defining an integer variable involves three steps:
// 1. Memory allocation for the variable.
// 2. Registering the variable in the system table (which stores variable names, data types, and addresses).
// 3. Assigning a value to the variable.

// A pointer is a variable that stores the memory address of another variable.
// Regardless of the data type it points to, a pointer typically occupies the same memory size (e.g., 4 or 8 bytes, depending on the system architecture).

int main()
{
    // Declare an integer variable and assign a value
    int i = 25;

    // The '&' operator retrieves the memory address of a variable
    cout << "Address of i (&i) = " << &i << endl;

    // Declare a pointer to an integer and store the address of 'i'
    int *p = &i;
    cout << "Address of i (using pointer p) = " << p << endl;

    // Display memory size of the pointer and integer type
    cout << "Size of pointer p: " << sizeof(p) << " bytes" << endl;
    cout << "Size of integer: " << sizeof(int) << " bytes" << endl;
    cout << endl;

    // Accessing the value of 'i' directly and through pointer dereferencing
    cout << "Value of i: " << i << endl;
    cout << "Value of i (using *p): " << *p << endl;

    // Increment the value of 'i'
    i++;
    cout << "After incrementing i:" << endl;
    cout << "Value of i: " << i << endl;
    cout << "Value of i (using *p): " << *p << endl;

    // Assigning the value of 'i' to another variable 'a'
    int a = i; // Equivalent to int a = *p;
    a++;       // Incrementing 'a' does not affect 'i' since 'a' is a separate variable
    cout << "Value of i: " << i << endl;
    cout << "Value of a: " << a << endl;

    // Declare another pointer 'q' that also points to 'i'
    int *q = p;
    (*q)++; // Incrementing '*q' modifies the value at the same memory location as 'i'

    cout << "Value of i: " << i << endl;
    cout << "Value of *p: " << *p << endl;
    cout << "Value of *q: " << *q << endl;

    return 0;
}
