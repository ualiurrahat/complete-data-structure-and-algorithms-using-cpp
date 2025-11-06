/*
============================================================================
   FILE: 18_needForConstantFunction.cpp
   TOPIC: Need for Constant Functions in C++
============================================================================

🧠 PURPOSE:
-------------
This program demonstrates the concept of **constant member functions**.

- Constant function: A member function that **does not modify the properties** of
  the current object.
- The current object refers to the object that can be accessed using the `this` pointer.

📌 NEED:
---------
- In order to access a **constant object**, only **constant functions** can be used.
- Trying to call a non-const function with a const object results in a compilation error.
============================================================================
*/
#include <iostream>
using namespace std;

/*
here, we are writing our Fraction class again
with some additinal function such as:
setNumerator(),setDenominator(),
getNumerator(), getDenominator().
*/

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
    // default constructor
    // in case we just want to declare a class object
    Fraction()
    {
    }
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

    // additional functions that are not present
    // in the previous Fraction class

    // to get numerator
    int getNumerator()
    {
        return numerator;
    }

    // to get donimator
    int getDenominator()
    {
        return denominator;
    }
    // to set numerator
    void setNumerator(int n)
    {
        numerator = n;
    }
    // to set denominator
    void setDenominator(int n)
    {
        denominator = n;
    }
};

int main()
{
    /// Creating a constant object of Fraction class
    const Fraction f1;

    /*
    ❌ ERROR EXAMPLES:
    -------------------
    f1.print();            // Error
    f1.getNumerator();     // Error
    f1.getDenominator();   // Error

    REASON:
    - Constant objects can **only be accessed through constant functions**.
    - Non-const member functions (like print(), getNumerator(), getDenominator())
      are not allowed because they may modify the object.
    - A member function can only be declared const if it **does not change the object's properties**.

    NEXT STEP:
    - To make these functions accessible for constant objects,
      we need to declare them as **const member functions**.
    */

    return 0;
}