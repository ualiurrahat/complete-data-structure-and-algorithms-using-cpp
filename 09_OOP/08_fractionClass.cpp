/*
====================================================================
   FILE: 08_fractionClass.cpp
   TOPIC: Fraction Class Implementation (with Addition & Multiplication)
====================================================================

🧠 PURPOSE:
-----------
This program demonstrates the creation of a simple **Fraction** class in C++
to represent and operate on fractional numbers.

The Fraction class supports:
1. Printing a fraction.
2. Simplifying a fraction to its lowest form.
3. Adding two fractions.
4. Multiplying two fractions.

Concepts Covered:
-----------------
- Use of constructors and member functions.
- Accessing members via `this` pointer.
- Passing objects by reference and using `const` for safety.
- Real-world class design and method functionality in OOP.
*/

#include <iostream>
#include <algorithm> // for min()
using namespace std;

/*
====================================================================
   CLASS: Fraction
====================================================================

This class models fractional numbers and defines behaviors such as:
- Printing
- Simplifying
- Adding
- Multiplying fractions
*/

class Fraction
{
private:
    // A fraction number has two parts: numerator and denominator.
    // Example: For 3/4 → numerator = 3 and denominator = 4
    int numerator;
    int denominator;

public:
    // ---------------------- Constructor ----------------------
    /**
     * @brief Initializes a Fraction object with given numerator and denominator.
     *
     * @param numerator   The numerator of the fraction.
     * @param denominator The denominator of the fraction.
     *
     * Explanation:
     * - The `this` pointer is used to differentiate between class members
     *   and parameters with the same name.
     */
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    // ---------------------- Display Function ----------------------
    /**
     * @brief Displays the fraction in the format "numerator / denominator".
     *
     * Note:
     * - Technically we should write:
     *      cout << this->numerator << " / " << this->denominator << endl;
     *   But since the parameter names do not shadow the member names,
     *   we can omit `this->` safely.
     *
     * - Whenever we access an object's properties using the dot operator
     *   inside the main function, that object’s address is stored in the
     *   hidden pointer `this`.
     */
    void print()
    {
        cout << numerator << " / " << denominator << endl;
    }

    // ---------------------- Simplify Function ----------------------
    /**
     * @brief Simplifies the fraction to its lowest terms.
     *
     * Example:
     *   If f1 = 70/8, gcd(70,8) = 2 → f1 = 35/4.
     *
     * Logic:
     *   - Find the greatest common divisor (gcd) of numerator and denominator.
     *   - Divide both numerator and denominator by gcd.
     */
    void simplify()
    {
        int gcd = 1;

        // Take minimum value between numerator and denominator
        int j = min(this->numerator, this->denominator);

        // Even if we write: j = min(numerator, denominator)
        // it will still work since compiler uses the implicit this pointer.

        // The maximum possible value for gcd will be the smaller of numerator or denominator.
        for (int i = 1; i <= j; i++)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                gcd = i;
            }
        }

        // Now minimizing (simplifying) the fraction.
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }

    // ---------------------- Addition Function ----------------------
    /**
     * @brief Adds two fractions (this + f2) and stores the result in the current object.
     *
     * @param f2 Another fraction (passed by const reference).
     *
     * Example:
     *   f1.add(f2);  // means f1 = f1 + f2
     *
     * Why use `const Fraction&` instead of `Fraction f2`?
     * --------------------------------------------------
     * - If we write `Fraction f2`, it will call the copy constructor and create
     *   a new fraction object, wasting memory and time.
     * - Passing by reference (`Fraction&`) avoids copying.
     * - Adding `const` ensures that we don’t accidentally modify the original object.
     *
     * Logic:
     *   1. Find LCM of denominators.
     *   2. Adjust numerators accordingly.
     *   3. Compute new numerator = (n1 * multiplier1) + (n2 * multiplier2)
     *   4. Denominator = LCM
     *   5. Simplify the result.
     */
    void add(Fraction const &f2)
    {
        // LCM of the denominators of current and f2
        int lcm = this->denominator * f2.denominator;
        int x = lcm / this->denominator;
        int y = lcm / f2.denominator;

        // Numerator of the resultant fraction
        int newNumerator = (x * this->numerator) + (y * f2.numerator);

        // Denominator of resultant fraction equals LCM
        int newDenominator = lcm;

        // Store the result in the calling object itself
        this->numerator = newNumerator;
        this->denominator = newDenominator;

        // Simplify the result
        simplify(); // Equivalent to this->simplify();
    }

    // ---------------------- Multiplication Function ----------------------
    /**
     * @brief Multiplies two fraction numbers and stores the result in the current object.
     *
     * Example:
     *   f1.multiply(f2); // f1 = f1 * f2
     *
     * Logic:
     *   - Multiply numerators together.
     *   - Multiply denominators together.
     *   - Simplify the resulting fraction.
     */
    void multiply(Fraction const &f2)
    {
        numerator = numerator * f2.numerator;
        denominator = denominator * f2.denominator;

        simplify();
    }
};
