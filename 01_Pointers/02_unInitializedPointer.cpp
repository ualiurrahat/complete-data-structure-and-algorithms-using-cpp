#include <iostream>

using namespace std;

int main()
{
    // Declare an integer variable without initializing it
    int i;
    cout << "Value of uninitialized i: " << i << endl;

    // Since 'i' is uninitialized, it contains a garbage value (random memory content)
    i++; // Incrementing an uninitialized variable
    cout << "After incrementing i:" << endl
         << "Value of uninitialized i: " << i << endl;

    // Declaring a pointer without initializing it
    int *p; // 'p' points to an arbitrary (garbage) memory address
    cout << "Garbage address stored in p: " << p << endl;

    // Dereferencing an uninitialized pointer is dangerous
    cout << "Garbage value pointed by *p: " << *p << endl;

    // Attempting to modify a value at an uninitialized (garbage) memory location
    (*p)++;

    // This is extremely unsafe as it modifies an unknown memory location,
    // potentially leading to memory corruption or system crashes.
    cout << "Modified garbage value of *p: " << *p << endl;

    // Instead of leaving pointers uninitialized, they should be explicitly set to NULL or nullptr
    // This prevents accidental access to random memory locations
    // Example:
    // int *p = NULL; // 'p' now does not point to an invalid memory location
    // Dereferencing 'p' in this state will cause a runtime error rather than undefined behavior
    // cout << *p; // This will result in a segmentation fault (access violation)

    return 0;
}
