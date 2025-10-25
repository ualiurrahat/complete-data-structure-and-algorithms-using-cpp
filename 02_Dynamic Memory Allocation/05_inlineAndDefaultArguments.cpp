#include <iostream>

using namespace std;

// Inline function to compute the maximum of two numbers
// Inline functions are expanded at the point of call,
// eliminating function call overhead and making execution faster.
inline int maximum(int a, int b)
{
  return (a > b) ? a : b;
}

// Function with default parameter values
// Default values allow calling the function with fewer arguments.
// If values for c and d are not provided, they default to 0.
// Note: Always assign default values from the rightmost parameters.
int sum(int a, int b, int c = 0, int d = 0)
{
  return a + b + c + d;
}

int main()
{
  int a = 18;
  int b = 20;
  int c = 1;
  int d = 5;

  int e = maximum(a, b); // Inline function replaces this call with its body
  int f = maximum(c, d);

  cout << "e = " << e << " , f = " << f << endl;

  /* Explanation of inline functions:
     - Normal function:
       int e = maximum(a, b);
       Function is invoked, parameters are passed, and result is returned.

     - Inline function:
       int e = maximum(a, b);
       Compiler replaces this with: int e = (a > b) ? a : b;
       This removes function call overhead, improving performance.
  */

  // Demonstrating function with default parameters
  cout << sum(25, 8) << endl;        // c = 0, d = 0
  cout << sum(25, 8, 9) << endl;     // c = 9, d = 0
  cout << sum(25, 8, 9, 10) << endl; // c = 9, d = 10

  return 0;
}
// Where to use inline functions:
// 1. For small, frequently called functions – Removes function call overhead.
// 2. When function execution time is less than function call overhead – Useful for simple operations.
// 3. When performance is critical – Helps optimize execution speed in real-time systems.
// 4. For getters and setters in classes – Commonly used in OOP for accessing private members.
// 5. For functions used in tight loops – Reduces overhead when called repeatedly.

// Where NOT to use inline functions:
// - For large functions – Increases binary size (code bloat).
// - When function contains loops, recursion, or static variables – Can lead to inefficient compilation.
// - When function needs address retrieval – Inline functions don’t have an actual memory address.

/*NOTE:
 for inline functions of 1 line, compiler usually accepts that and performs.
 inline functions of 2-3 lines, it is upto the compiler whether it will work or not.
 for more than 3 lines of inline function, compiler does not accept it.
*/