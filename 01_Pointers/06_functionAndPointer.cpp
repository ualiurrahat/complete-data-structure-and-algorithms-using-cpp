#include <iostream>

using namespace std;

// Function to print the value stored at a given pointer address
void print(int *p)
{
    cout << "Inside print function: " << endl;
    cout << *p << endl; // Dereferencing pointer to print value
    cout << "Leaving print function." << endl;
}

// Function to change the pointer address (passed by value, so it won't affect the original pointer)
void incrementPointer(int *p)
{
    cout << "Inside incrementPointer(): " << endl;
    cout << "Pointer before increment: " << p << endl;
    p = p + 1; // Moves the pointer to the next memory location
    cout << "Pointer after increment: " << p << endl;
    cout << "Leaving incrementPointer()" << endl;
}

// Function to increase the value stored at the pointer's address (modifies original value)
void incrementPointerValue(int *p)
{
    cout << "Inside incrementPointerValue(): " << endl;
    (*p)++; // Increment the value at the memory location
    cout << "Pointer remains the same: " << p << endl;
    cout << "Leaving incrementPointerValue()" << endl;
}

// Function to calculate the sum of an array's elements
int sum(int *a, int size)
{
    // In function parameters, `a[]` is treated as a pointer (`int *a`).
    // Arrays decay into pointers when passed to functions.
    // sizeof(a) will return the size of the pointer (4 or 8 bytes), not the array.
    cout << "size of array a inside sum function: " << sizeof(a) << endl;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += a[i]; // Summing array elements
    }
    return sum;
}

int main()
{
    int a = 25;
    int *p = &a; // Pointer to variable 'a'

    print(p); // Print the value stored at address p (which is 25)
    cout << endl
         << "Pointer in main after print(): " << p << endl;

    incrementPointer(p);
    // The pointer 'p' is passed by value, so its address inside this function changes,
    // but it does not affect the original pointer in main().
    cout << endl
         << "Pointer in main after incrementPointer(): " << p << endl;

    cout << "Value before incrementPointerValue(): " << *p << endl;
    incrementPointerValue(p);
    // Since the function modifies the value using dereferencing,
    // it actually changes the value stored at p's address.
    cout << endl
         << "Value after incrementPointerValue(): " << *p << endl;

    cout << endl;

    // Demonstrating array pointer behavior
    int b[] = {18, 1, 8, 1, 20};
    cout << "Size of array b (in bytes): " << sizeof(b) << endl;

    cout << "Sum of all elements in b: " << sum(b, 5) << endl;
    // We can also pass the address of any specific array element to a function,
    // allowing us to work with a subsection of an array.
    cout << "Sum of 3 elements starting from index 1: " << sum(b + 1, 3) << endl;

    return 0;
}
