#include <iostream>

using namespace std;

// Demonstrating dynamic memory allocation in C++

// The following is an example of a bad practice:
// int n;
// cin >> n;
// int a[n];  // This is not recommended because a[n] is allocated on the stack, which has limited memory.
// If n is a large number, the stack might not have enough memory for the array.
// Instead, dynamic memory allocation should be used to allocate large memory blocks from the heap, which has more space.
// we should do this:
// int * a = new int[n];
// by doing this, we are allocating memory for array a from the heap memory. So there will be no problem.

int main()
{
    // Allocating memory dynamically for a single integer
    int *p = new int;

    // The pointer p is stored on the stack, but the memory for the integer is allocated on the heap.
    *p = 10;            // Assign value to the dynamically allocated memory
    cout << *p << endl; // Output the value stored at the memory location pointed by p

    // Allocating memory dynamically for other data types
    double *pd = new double;
    char *pc = new char;

    // Dynamically allocating memory for an array of integers (size 5)
    int *pa = new int[5];

    // Dynamically allocating memory for an array of integers with size n
    int n = 35;
    // pa2 uses heap memory, which is good practice when working with large arrays
    int *pa2 = new int[n];

    // Storing elements in the dynamically allocated arrays
    pa[0] = 18;
    pa[1] = 1;

    pa2[0] = 20;
    pa2[1] = 1;

    // Output values stored in dynamically allocated arrays
    cout << pa[0] << " " << pa[1] << " " << pa[1] << " " << pa[0] << endl;

    // Deallocating dynamically allocated memory using delete
    // 'delete p' frees the 4 bytes of memory (new int) that p was pointing to.
    // Memory allocated on the stack (the pointer p itself) is automatically freed when the program exits the scope of p. So stack memory automatically gets deleted on the basis of scope of variables.
    // Deleting memory manually for dynamically allocated is required.
    // NOTE: if a memory is acquired using "new", it needs to be deleted manually.

    delete p;     // Free the memory allocated for a single integer
    delete pd;    // Free the memory allocated for a double
    delete pc;    // Free the memory allocated for a character
    delete[] pa;  // Free the memory allocated for the dynamic array pa
    delete[] pa2; // Free the memory allocated for the dynamic array pa2

    // Why is deleting dynamically allocated memory important?
    // Example 1: If memory is allocated in an infinite loop
    // while (true)
    // {
    //     int n;  // Memory for n is released when the loop iterates, but this memory is reallocated every time.
    // }
    // This would run forever, and the memory used for variable n will keep getting recreated and released repeatedly.

    // Example 2: If memory is allocated in an infinite loop but on the heap
    // while (true)
    // {
    //     int *p = new int;  // Memory is allocated on the heap but not freed, causing a memory leak.
    // }
    // This program will crash once all the heap memory is exhausted, as heap memory is not automatically freed like stack memory.

    return 0;
}
