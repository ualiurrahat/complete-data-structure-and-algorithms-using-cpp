#include <iostream>

// Global variables in C++ are declared outside any function, usually at the top of the file.
// They are accessible by all functions in the program after their declaration.
// Scope: Entire file (or project if declared extern in other files)
// Lifetime: Entire duration of program execution

using namespace std;

// Global variable example
int globalCounter = 0; // This variable can be accessed and modified by any function

// Function demonstrating local variables
void incrementLocal()
{
    int localCounter = 0; // Local variable, only exists inside this function
    localCounter++;
    cout << "Local Counter inside function: " << localCounter << endl;
}

// Function demonstrating global variable usage
void incrementGlobal()
{
    globalCounter++;
    cout << "Global Counter inside function: " << globalCounter << endl;
}

int main()
{
    cout << "Initial Global Counter: " << globalCounter << endl;

    // Using local variable function
    incrementLocal(); // localCounter = 1
    incrementLocal(); // localCounter = 1 again, resets each time

    // Using global variable function
    incrementGlobal(); // globalCounter = 1
    incrementGlobal(); // globalCounter = 2 (retains value)

    // Direct access to global variable
    globalCounter += 5;
    cout << "Global Counter after direct modification in main: " << globalCounter << endl;

    /* Observations:
       1. Local variables are temporary and exist only inside the function they are declared.
       2. Global variables exist for the entire program lifetime and can be accessed/modified anywhere.
       3. Changes to global variables persist across functions.
    */

    return 0;
}

/*
Important Notes on Global Variables:

1. Using global variables is generally considered bad practice:
   - They can be modified by any function, making debugging harder.
   - Any part of the code can unintentionally change its value.
   - Reduces modularity and increases dependency between functions.

2. Alternatives to using global variables:
   - Pass variables as function arguments.
   - Use class member variables (encapsulation).
   - Use static variables inside a function (if you want to retain value across calls but limit scope).
   - Use singletons or configuration objects in large projects.
*/
