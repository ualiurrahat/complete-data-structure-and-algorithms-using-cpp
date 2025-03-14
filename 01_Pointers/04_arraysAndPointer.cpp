#include <iostream>

using namespace std;

int main()
{
    /*
    Key Differences Between Arrays and Pointers:

    1. **Memory Allocation:**
       - An array occupies a contiguous block of memory.
       - A pointer only occupies 4 or 8 bytes (depending on the system) and can be reassigned.

    2. **Symbol Table Entry:**
       - The name of an array (`a`) is a fixed address stored in the symbol table and cannot be modified.
       - A pointer (`p`) can be reassigned to point to different memory locations.

    3. **Operations:**
       - Arrays behave like pointers in many cases, but they are not fully interchangeable.
       - Example: `p = p + 1;` (valid for pointers) but `a = a + 1;` (invalid for arrays).

    */

    int a[10]; // Declare an integer array of size 10.

    cout << a << endl;     // Prints the address of the array (same as &a[0]).
    cout << &a << endl;    // Prints the address of the entire array.
    cout << &a[0] << endl; // Also prints the address of the first element.

    // Since `a` represents the starting address of the array, all three print statements output the same address.

    int *p = &a[0]; // Pointer `p` stores the address of the first element of the array.

    a[0] = 25;
    a[1] = 35;
    cout << *a << endl;       // Dereferencing `a` gives the value at a[0] (25).
    cout << *(a + 1) << endl; // Equivalent to a[1], prints 35.
    cout << a[1] << endl;     // Directly prints a[1], which is 35.

    cout << a << endl;  // Address of the first element of `a`.
    cout << &a << endl; // Address of the whole array (same as `a` in this case).
    cout << p << endl;  // Address stored in `p` (which is `&a[0]`).
    cout << &p << endl; // Address of the pointer `p` itself (different from `a`).

    /*
    **Memory Allocation Differences:**
    - `p` is a pointer that occupies 4 or 8 bytes of memory (depending on the system).
    - `a` is an array that occupies a contiguous block of memory (e.g., 40 bytes for 10 integers).
    */

    cout << sizeof(p) << endl; // Size of pointer `p` (4 or 8 bytes).
    cout << sizeof(a) << endl; // Size of the entire array `a` (e.g., 40 bytes for int[10]).

    /*
    **Three Key Differences Between Arrays and Pointers in Memory Allocation:**
    1. `sizeof()`:
       - For arrays, `sizeof(a)` returns the total memory occupied by all elements.
       - For pointers, `sizeof(p)` returns the size of the pointer itself.

    2. `&a` vs `&p`:
       - `a` and `&a` point to the same memory location since `a` has no separate memory allocation.
       - `p` and `&p` are different; `p` stores an address, whereas `&p` gives the address of `p` itself.

    3. Reassignment:
       - `p = p + 1;` is valid since `p` is a pointer.
       - `a = a + 1;` is invalid since `a` is a fixed memory address and cannot be modified.
    */

    return 0;
}
