#include <iostream>

using namespace std;

// Demonstrating the concept of references in C++
// int i = 10;               // Declare an integer i with initial value 10
// int & k = i;              // k is a reference to i, referring to the same memory location
// A reference variable does not consume additional memory and acts as an alias for the original variable.

// Benefits of using reference variables:
// 1. No additional memory is consumed since it directly refers to the original variable.
// 2. Changes made to the reference variable will affect the original variable, especially when passed to functions.

void incrementByValue(int n)
{
    n++; // Increment the local variable n, but this will not affect the original variable in main().
    // The increment only applies to the local copy of the argument passed to this function.
    // The local variable n goes out of scope when the function execution completes.
}

void incrementByReference(int &n)
{
    n++; // Increment the original variable through reference, which modifies the variable in the main function.
}

int main()
{
    int i = 10; // Declare an integer i and initialize it to 10
    int &j = i; // j is a reference to i, meaning j and i share the same memory location

    cout << "Value of variable i: " << i << endl;
    cout << "Value of j (reference to i): " << j << endl;
    cout << "Address of i: " << &j << endl; // The address of i (which j refers to)
    cout << "Address of j: " << &j << endl; // The address of j is the same as the address of i

    i++; // Increment i; this will also affect j since j is a reference to i
    cout << "After incrementing i: i = " << i << " , j = " << j << endl;

    incrementByValue(j); // Call the function with j (which refers to i)
    cout << "Value of j after executing function incrementByValue(): " << j << endl;
    // j will not change because the increment happens on a local copy inside the function.

    incrementByReference(j); // Call the function with j by reference
    cout << "Value of j after executing function incrementByReference(): " << j << endl;
    // j will change because the reference variable modifies the original value of i.

    int k = 100;
    j = k; // Assign the value of k to j. Since j refers to i, both i and j now hold the value of k.
    cout << "i = " << i << "; j = " << j << "; k = " << k << endl;

    return 0;
}
