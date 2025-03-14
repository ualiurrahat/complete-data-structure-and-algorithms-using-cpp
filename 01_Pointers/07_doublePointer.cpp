#include <iostream>

using namespace std;

// Function attempting to modify the double pointer itself
// This change will NOT reflect outside the function since the pointer is passed by value
void increment1(int **p)
{
    p = p + 1; // Modifies the local copy of the pointer, not the original
}

// Function modifying the single pointer stored in the double pointer
// This changes the address stored in the pointer, but not the actual value of 'i'
void increment2(int **p)
{
    *p = *p + 1; // Moves the single pointer forward, changing what it points to
}

// Function modifying the actual value of 'i' by dereferencing twice
// This change WILL reflect globally since we modify the actual integer
void increment3(int **p)
{
    **p = **p + 1; // Increments the integer 'i' itself
}

int main()
{
    int i = 25;
    int *p = &i;   // Pointer to 'i'
    int **p2 = &p; // Pointer to pointer 'p'

    cout << "Initial values:" << endl;
    cout << "Address of i using (&i): " << &i << endl;
    cout << "Address of i using (single pointer p): " << p << endl;
    cout << "Address of i using (double pointer p2): " << *p2 << endl;
    cout << "Value of i using i: " << i << endl;
    cout << "Value of i using single pointer p: " << *p << endl;
    cout << "Value of i using double pointer p2: " << **p2 << endl;
    cout << endl;

    // Calling increment1: No effect since it modifies a local copy of the pointer
    increment1(p2);
    cout << "After calling increment1 (no effect expected): " << endl;
    cout << "Value of i: " << i << endl;
    cout << endl;

    // Calling increment2: Changes the address stored in 'p', likely causing undefined behavior
    increment2(p2);
    cout << "After calling increment2 (pointer shift, possible undefined behavior): " << endl;
    cout << "Address stored in p: " << p << endl;
    cout << endl;

    // Reset 'p' to point back to 'i' before next test
    p = &i;

    // Calling increment3: Actually modifies the value of 'i'
    increment3(p2);
    cout << "After calling increment3 (value incremented): " << endl;
    cout << "Value of i: " << i << endl;

    return 0;
}
