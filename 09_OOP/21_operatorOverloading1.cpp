/*
============================================================================
   FILE: 21_operatorOverloading1.cpp
   TOPIC: Operator Overloading (Part 1)
============================================================================

🧠 PURPOSE:
-------------
To demonstrate **operator overloading** — extending the functionality of
pre-existing operators (like +, *, ==) so that they can also work with
user-defined data types (classes).

📘 EXAMPLE:
------------
✅ Works for built-in types:
    int c = a + b;

❌ Not directly possible for user-defined types:
    Fraction f3 = f1 + f2;   // Error without operator overloading

➡️ Solution: Define how the `+` operator behaves for the `Fraction` class
   using **operator overloading**.

This file demonstrates overloading:
- `+` → For addition of two fractions
- `*` → For multiplication of two fractions
- `==` → For equality comparison of two fractions
============================================================================
*/

#include <iostream>
using namespace std;

/*
====================================================================
   CLASS: Fraction
====================================================================

Models fractional numbers and demonstrates operator overloading.
*/

class Fraction
{
    int numerator;
    int denominator;

public:
    // ---------------------- Constructors ----------------------
    Fraction() {} // Default constructor

    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    // ---------------------- Getter Functions ----------------------
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // ---------------------- Setter Functions ----------------------
    void setNumerator(int n) { numerator = n; }
    void setDenominator(int n) { denominator = n; }

    // ---------------------- Display Function ----------------------
    void show() const
    {
        cout << numerator << " / " << denominator << endl;
    }

    // ---------------------- Simplify Function ----------------------
    /**
     * @brief Simplifies the fraction by dividing both numerator and denominator
     *        by their greatest common divisor (GCD).
     */
    void simplify()
    {
        int gcd = 1;
        int limit = min(numerator, denominator);

        for (int i = 1; i <= limit; i++)
        {
            if (numerator % i == 0 && denominator % i == 0)
                gcd = i;
        }

        numerator /= gcd;
        denominator /= gcd;
    }

    // ---------------------- Add Function (Non-Operator) ----------------------
    /**
     * @brief Adds the current fraction with another and returns a new fraction.
     */
    Fraction add(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int newNumerator = (x * numerator) + (y * f2.numerator);
        Fraction fNew(newNumerator, lcm);
        fNew.simplify();

        return fNew; // returning new result fraction
    }

    // ---------------------- Operator Overloading (+) ----------------------
    /**
     * @brief Adds two fractions using operator +.
     *
     * Syntax:
     *   returnType operator+(parameter)
     */
    Fraction operator+(Fraction const &f2) const
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int newNumerator = (x * numerator) + (y * f2.numerator);

        Fraction fNew(newNumerator, lcm);
        fNew.simplify();

        return fNew;
    }

    // ---------------------- Operator Overloading (*) ----------------------
    /**
     * @brief Multiplies two fractions using operator *.
     */
    Fraction operator*(Fraction const &f2) const
    {
        int num = numerator * f2.numerator;
        int den = denominator * f2.denominator;
        Fraction fNew(num, den);
        fNew.simplify();
        return fNew;
    }

    // ---------------------- Operator Overloading (==) ----------------------
    /**
     * @brief Compares if two fractions are equal.
     */
    bool operator==(Fraction const &f2) const
    {
        return (numerator == f2.numerator && denominator == f2.denominator);
    }

    // ---------------------- Multiply Function ----------------------
    /**
     * @brief Multiplies and stores result in the current object.
     */
    void multiply(Fraction const &f2)
    {
        numerator *= f2.numerator;
        denominator *= f2.denominator;
        simplify();
    }
};

/*
====================================================================
   MAIN FUNCTION
====================================================================

Demonstrates:
- Normal addition (using add())
- Operator overloading for +, *, and ==
====================================================================
*/

int main()
{
    Fraction f1(5, 25);
    Fraction f2(8, 25);

    // ---------- Normal add() method ----------
    Fraction f3 = f1.add(f2);
    cout << "fraction f1 = " << endl;
    f1.show();

    cout << "fraction f2 = " << endl;
    f2.show();

    cout << "fraction f3 = f1.add(f2) =" << endl;
    f3.show();

    // ---------- Operator Overloading: '+' ----------
    Fraction f4 = f1 + f2;
    // Here, f1 is the calling object (this pointer),
    // f2 is passed as argument to the operator function
    cout << "fraction f4 = f1 + f2 =" << endl;
    f4.show();

    // ---------- Operator Overloading: '*' ----------
    Fraction f5 = f1 * f2;
    cout << "f5 = f1 * f2 =" << endl;
    f5.show();

    // ---------- Operator Overloading: '==' ----------
    if (f1 == f2)
        cout << "Equal" << endl;
    else
        cout << "Not equal" << endl;

    return 0;
}
