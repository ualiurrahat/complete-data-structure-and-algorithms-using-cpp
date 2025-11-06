/*
============================================================================
   FILE: 19_constantFunction.cpp
   TOPIC: Constant Member Functions in C++
============================================================================

🧠 PURPOSE:
-------------
This program demonstrates **constant member functions** in C++ and why they
are necessary to access **constant objects**.

- Syntax to declare a constant member function:
      returnType functionName() const
      {
          // function body
      }

- Constant functions guarantee that **they do not modify the properties**
  of the current object.
- Only such functions can be called on **const objects**.

============================================================================
*/

#include <iostream>
using namespace std;

/*
CLASS: Fraction
---------------
- Fraction numbers have two parts: numerator and denominator.
- We demonstrate how to declare member functions as const when they
  do not modify the object.
- This allows these functions to be called on const objects.
*/

class Fraction
{
private:
    int numerator;   // numerator of fraction
    int denominator; // denominator of fraction

public:
    // ---------------------- Constructors ----------------------
    Fraction() {} // default constructor

    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    // ---------------------- Display Function ----------------------
    /**
     * @brief Displays the fraction in "numerator / denominator" format.
     *
     * const is used because this function does not modify any property of the object.
     * This allows it to be called on constant objects.
     */
    void print() const
    {
        cout << numerator << " / " << denominator << endl;
        // `this` pointer points to the current object
        // using `this->numerator` would also work
    }

    // ---------------------- Simplify Function ----------------------
    /**
     * @brief Simplifies the fraction to its lowest terms.
     *
     * This function modifies the object, so it cannot be const.
     */
    void simplify()
    {
        int gcd = 1;
        int j = min(this->numerator, this->denominator);

        for (int i = 1; i <= j; i++)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                gcd = i;
            }
        }

        this->numerator /= gcd;
        this->denominator /= gcd;
    }

    // ---------------------- Addition Function ----------------------
    /**
     * @brief Adds f2 to the current fraction.
     *
     * Fraction f2 is passed as const reference:
     * - `const` prevents modification of f2 inside the function.
     * - Passing by reference avoids unnecessary copying.
     */
    void add(Fraction const &f2)
    {
        int lcm = this->denominator * f2.denominator;
        int x = lcm / this->denominator;
        int y = lcm / f2.denominator;

        int newNumerator = (x * this->numerator) + (y * f2.numerator);
        int newDenominator = lcm;

        this->numerator = newNumerator;
        this->denominator = newDenominator;

        simplify();
    }

    // ---------------------- Multiplication Function ----------------------
    void multiply(Fraction const &f2)
    {
        numerator *= f2.numerator;
        denominator *= f2.denominator;

        simplify();
    }

    // ---------------------- Getter Functions ----------------------
    /**
     * @brief Returns numerator.
     *
     * const is used because this function does not change any property.
     * Allows usage with constant objects.
     */
    int getNumerator() const
    {
        return numerator;
    }

    /**
     * @brief Returns denominator.
     *
     * const is used because this function does not change any property.
     * Allows usage with constant objects.
     */
    int getDenominator() const
    {
        return denominator;
    }

    // ---------------------- Setter Functions ----------------------
    /**
     * @brief Sets numerator. Modifies the object, cannot be const.
     */
    void setNumerator(int n)
    {
        numerator = n;
    }

    /**
     * @brief Sets denominator. Modifies the object, cannot be const.
     */
    void setDenominator(int n)
    {
        denominator = n;
    }
};

int main()
{
    // ---------------------- Constant Object ----------------------
    const Fraction f1;
    /*
    Explanation:
    - Constant objects cannot be modified.
    - Only functions declared as const can be called on them.
    - If print(), getNumerator(), getDenominator() were not const, the following
      would generate errors.
    */

    cout << "Printing const object f1:" << endl;
    f1.print();                                                   // allowed
    cout << "Numerator of f1: " << f1.getNumerator() << endl;     // allowed
    cout << "Denominator of f1: " << f1.getDenominator() << endl; // allowed

    return 0;
}
