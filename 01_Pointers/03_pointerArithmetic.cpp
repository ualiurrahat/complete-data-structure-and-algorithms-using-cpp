// int arr[5] = [1,2,3,4,5];
// int * x = arr; correct
// int * x = &arr in incorrect.
// Why is `int *x = &arr;` incorrect?
// --------------------------------------------------
// In C++, `int *x = arr;` is correct because `arr` decays into a pointer to its first element.
// This is equivalent to writing `int *x = &arr[0];`, which correctly assigns the address of the
// first element of the array to `x`.
//
// However, `int *x = &arr;` is incorrect because `&arr` represents the address of the entire array,
// not just the first element. The type of `&arr` is `int (*)[5]` (a pointer to an array of 5 integers),
// which does not match `int *`, leading to a type mismatch.
//
// If you need a pointer to the whole array, use:
// `int (*x)[5] = &arr;` // Here, `x` is a pointer to an array of 5 integers.
//
// Correct usage:
// `int *x = arr;`  // Pointer to the first element (recommended for most cases)
// `int (*x)[5] = &arr;`  // Pointer to the entire array (use only if necessary)

#include <iostream>

using namespace std;

int main()
{
    // Declare variables of different data types
    int i = 10;
    int *p = &i; // Integer pointer storing the address of 'i'

    float f = 10.5;
    float *fp = &f; // Float pointer storing the address of 'f'

    double d = 25.8;
    double *pd = &d; // Double pointer storing the address of 'd'

    char c = 'a';
    char *pc = &c; // Char pointer storing the address of 'c'

    // Display the size of different types of pointers
    cout << "Size of integer pointer: " << sizeof(p) << " bytes" << endl;
    cout << "Size of float pointer: " << sizeof(fp) << " bytes" << endl;
    cout << "Size of double pointer: " << sizeof(pd) << " bytes" << endl;
    cout << "Size of char pointer: " << sizeof(pc) << " bytes" << endl;

    // Regardless of the data type, all pointers occupy the same size
    // (either 4 or 8 bytes depending on the system architecture)

    // Demonstrate pointer arithmetic
    cout << "Initial pointer value p: " << p << endl;
    p--; // Decrement pointer (moves to previous memory address)
    cout << "After decrement p: " << p << endl;
    p = p + 2; // Increment pointer by 2 (moves forward in memory)
    cout << "After adding 2 to p: " << p << endl;

    // Pointer arithmetic makes sense when working with arrays
    // Example: Incrementing a pointer moves to the next array element
    int arr[5] = {18, 1, 8, 5, 20};
    int *x = arr; // Pointer 'x' points to the first element of the array
    cout << "x = " << x << " , *x = " << *x << endl;

    x = x + 1; // Move pointer to the next array element
    cout << "x + 1 = " << x << " , *(x+1) = " << *x << endl;

    // Comparing pointers
    int *y = x + 1;                              // 'y' points to the next element after 'x'
    (x > y) ? cout << "x > y" : cout << "x < y"; // Compare memory addresses

    return 0;
}
