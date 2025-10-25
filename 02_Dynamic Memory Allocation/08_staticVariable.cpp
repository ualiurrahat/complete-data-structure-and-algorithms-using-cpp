#include <iostream>

// Static variables in C++ retain their value between function calls
// Scope: Either local to function (if declared inside a function) or file scope (if declared globally with static)
// Lifetime: Entire program execution
// Unlike global variables, static variables inside functions are not accessible outside that function.

using namespace std;

// Global variable (for comparison)
int globalCounter = 0;

// Function demonstrating local static variable
void staticExample()
{
    static int staticCounter = 0; // Initialized only once, retains value across calls
    staticCounter++;
    cout << "Static Counter inside function: " << staticCounter << endl;
}

// Function demonstrating global variable
void globalExample()
{
    globalCounter++;
    cout << "Global Counter inside function: " << globalCounter << endl;
}

int main()
{
    cout << "Demonstrating static vs global variables:" << endl;

    // Calling staticExample multiple times
    staticExample(); // staticCounter = 1
    staticExample(); // staticCounter = 2
    staticExample(); // staticCounter = 3

    // Calling globalExample multiple times
    globalExample(); // globalCounter = 1
    globalExample(); // globalCounter = 2
    globalExample(); // globalCounter = 3

    /* Observations:
       1. Static variable retains value between function calls like a global variable.
       2. But its scope is limited to the function it is declared in, unlike a global variable.
       3. Static variables are safer than global variables if you want to retain value but limit scope.
    */

    return 0;
}

/*
Important Notes on Static Variables:

1. Pros:
   - Retain value between calls.
   - Limited scope (better than global variable for encapsulation).
   - Useful for counters, caching values, memoization in recursive functions.

2. Cons:
   - Lifetime is still entire program, so they occupy memory for full execution.
   - Overuse can increase program memory usage unnecessarily.

3. Alternative to static local variable:
   - Pass values between function calls using parameters.
   - Use class member variables for object-specific data.
*/
