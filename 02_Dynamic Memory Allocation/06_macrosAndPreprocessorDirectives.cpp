#include <iostream>

// Macros in C++ are a feature provided by the preprocessor. They allow us to define constants or code snippets
// that are replaced before compilation. The preprocessor performs these substitutions before the actual compilation
// of the program, meaning macros do not exist in the final compiled code.

using namespace std;

#define PI 3.14159            // Defining a macro named PI with a constant value
#define SQUARE(x) ((x) * (x)) // Defining a macro for calculating the square of a number
#define X 10
#define Y 20

int main()
{
    // The macro PI will be replaced with 3.14159 in the code wherever it is used
    double radius = 5.0;
    double area = PI * SQUARE(radius); // Using both PI and SQUARE macro to calculate area of a circle

    cout << "Area of circle with radius " << radius << " is: " << area << endl;

    // Here, SQUARE(x) macro is also used to compute the square of a number.
    int num = 4;
    cout << "Square of " << num << " is: " << SQUARE(num) << endl;

    // Why use macros instead of regular variables or functions?
    // Macros are replaced at compile-time, not run-time. This can improve performance for simple expressions.

    // Example of using macros for constant values

    int sum = X + Y; // Using macros to represent constant values

    return 0;
}

// Preprocessor Directives: These are commands that the compiler uses to process the source code before actual compilation begins.
// Preprocessor directives begin with a '#' symbol and are processed by the preprocessor before the actual compilation.
// Examples include #include, #define, #if, #ifdef, #endif, etc.

// The difference between a macro and a function:
// 1. A macro is a preprocessor directive, and it works by simple text substitution before the code is compiled.
//    Macros are fast because they don't incur the overhead of function calls.

// 2. A function, on the other hand, is part of the compiled code and incurs overhead for the call, including pushing arguments to the stack and returning the result.

// Why is using `#define` beneficial?
// 1. It improves performance in certain cases (like constant values and simple expressions).
// 2. It allows easier updates to common values or code snippets across multiple places in a program.
// 3. Macros like `SQUARE(x)` allow reusability of logic without the need to write the same expression multiple times.

// Important Note:
// Use parentheses in macro definitions (e.g., SQUARE(x) => ((x)*(x))) to avoid issues with operator precedence.
// Without parentheses, expressions like SQUARE(1+2) might give incorrect results due to precedence issues.
