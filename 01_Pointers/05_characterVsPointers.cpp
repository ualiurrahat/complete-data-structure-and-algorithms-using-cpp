#include <iostream>

using namespace std;

int main()
{
    /*
    **Difference in `cout` behavior for integer and character arrays:**
    - For integer arrays, `cout` prints the address.
    - For character arrays, `cout` prints the content instead of the address.
    */

    int a[] = {25, 8};  // Integer array.
    char c[] = "rahat"; // Character array (null-terminated string).

    cout << "Address of integer array a: " << a << endl; // Prints the address of `a` (equivalent to `&a[0]`).
    cout << "Address of char array c (using c): " << c << endl;
    // Prints the content of `c` instead of its address due to `cout` handling character arrays differently.

    // To correctly print the address of a character array, use a void pointer.
    cout << "Address of char array c (using void *c): " << (void *)&c << endl;

    /*
    **Why does `cout` behave differently for `char[]`?**
    - For integer arrays, `cout` prints the address because it treats `a` as a pointer.
    - For character arrays, `cout` assumes it is a string and prints the entire content instead.
    */

    char *b = &c[0]; // Pointer `b` stores the address of `c[0]`.

    cout << "Address of char array b (using b): " << b << endl;
    // Instead of printing the address, this prints the entire string stored in `c`
    // due to `cout` treating `char*` as a string.

    char e = 'l';
    char *f = &e; // Pointer `f` points to `e`.

    cout << e << endl; // Prints the character `l`.
    cout << f << endl;
    // Prints characters starting from `e`'s memory location, stopping only at a null character.

    // Bad practice: `char *str = "rahat";`
    // - Here we are storing the temporary memory.
    // where string "rahat" is written. This is very bad practice.
    // because we are trying to read in a memory that can be read-only or anything
    // which we don't have access to modify.
    // - Modifying it will result in undefined behavior.

    // Good practice: `char str[] = "rahat";`
    // - This creates a local copy of `"rahat"` in writable memory.
    // - and then we are given a copy of the string.
    // - we can modify the string according to our needs.

    return 0;
}
