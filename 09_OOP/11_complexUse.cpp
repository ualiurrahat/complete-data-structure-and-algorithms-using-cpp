/**
 * @file 11_complexUse.cpp
 * @brief Demonstrates the creation and arithmetic operations on complex numbers using the Complex class.
 */

#include <iostream>
using namespace std;

// ---------------------- Including Complex Class ----------------------
#include "10_complexClass.cpp"

/**
 * @brief Main function demonstrating creation, addition, multiplication, and printing of complex numbers.
 *
 * The program uses the Complex class to:
 * 1. Create complex numbers.
 * 2. Perform addition and multiplication.
 * 3. Display the results.
 */
int main()
{
    // ---------------------- Object Creation ----------------------
    Complex c1(3, 6);
    Complex c2(7, 9);

    // Uncomment these lines to see the initial values of c1 and c2.
    // c1.print();
    // c2.print();

    // ---------------------- Multiplication ----------------------
    // Performing multiplication: c1 = c1 * c2
    c1.multiply(c2);
    c1.print(); // Output of multiplication result

    // ---------------------- Addition ----------------------
    Complex c3(10, 15);
    Complex c4(12, 40);

    // Performing addition: c3 = c3 + c4
    c3.add(c4);
    c3.print(); // Output of addition result

    return 0;
}
