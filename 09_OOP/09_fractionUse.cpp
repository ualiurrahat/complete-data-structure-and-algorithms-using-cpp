/**
 * @file 09_fractionUse.cpp
 * @brief Demonstrates the use of the Fraction class by creating, adding, and multiplying fraction numbers.
 */

#include <iostream>
using namespace std;

// ---------------------- Including Fraction Class ----------------------
#include "08_fractionClass.cpp"

/**
 * @brief Main function demonstrating the creation and manipulation of Fraction objects.
 *
 * Here, we will:
 * 1. Create two fraction objects.
 * 2. Display their values.
 * 3. Perform addition and multiplication using the member functions of the Fraction class.
 */
int main()
{
    // ---------------------- Object Creation ----------------------
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    // ---------------------- Displaying Initial Values ----------------------
    f1.print();
    f2.print();

    // ---------------------- Performing Addition ----------------------
    // Adding f2 with f1 and storing the result in f1.
    f1.add(f2);
    f1.print();
    f2.print();

    // ---------------------- Performing Multiplication ----------------------
    // Multiplying f2 with f1 and storing the result in f1.
    f1.multiply(f2);
    f1.print();
    f2.print();

    return 0;
}
