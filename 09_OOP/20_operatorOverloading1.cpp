/*
operator overloading: extending the functionality of pre-existing
operatetor so that it can work in our user defined classes also.
example: int c = a+b; is possible for int var a,b,c
but can we do Fraction f3 = f1 + f2?
No. why? cause the + operator does not know
how to add two fraction number.By using operator overloading,
we can achieve that. WOW!!!
here, we are overloading operator +,* and ==
*/

#include <bits/stdc++.h>

using namespace std;

class Fraction
{
    int numerator;
    int denominator;

public:
    // default constructor
    Fraction()
    {
    }
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    int getNumerator() const
    {
        return numerator;
    }
    int getDenominator() const
    {
        return denominator;
    }

    void setNumerator(int n)
    {
        numerator = n;
    }
    void setDenominator(int n)
    {
        denominator = n;
    }

    void show() const
    {
        cout << numerator << " / " << denominator << endl;
    }

    void simplify()
    {
        int gcd = 1;
        int j = min(this->numerator, this->denominator); // using this is optional
        for (int i = 1; i <= j; i++)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                gcd = i;
            }
        }

        // now minimizing the fraction.
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }

    // changing the add funciton from previous version
    // we write on the Fraction class
    // earlier the result was assigned to this pointer fraction object.
    // but here, we are assigning result fraction to a new fraction object.
    // and returning the result.
    Fraction add(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator; // denominator = this->denominator
        int x = (lcm / denominator);
        int y = (lcm / f2.denominator);

        int ans_numerator = (x * numerator) + (y * f2.numerator);

        // commenting this since we want f1 to be unchanged.
        // numerator = ans_numerator;
        // denominator = lcm;

        // creating new object to obtain result object value.
        Fraction fNew(ans_numerator, lcm);
        // simplifying the result.
        fNew.simplify();

        // returning result object
        return fNew;
    }

    // Operator Overloading: overloading the '+' operator
    // syntax: returnType operator(keyword)operatorSign(parameter){}
    Fraction operator+(Fraction const &f2) const
    {

        int lcm = denominator * f2.denominator; // denominator = this->denominator
        int x = (lcm / denominator);
        int y = (lcm / f2.denominator);

        int ans_numerator = (x * numerator) + (y * f2.numerator);

        // commenting this since we want f1 to be unchanged.
        // numerator = ans_numerator;
        // denominator = lcm;

        // creating new object to obtain result object value.
        Fraction fNew(ans_numerator, lcm);
        // simplifying the result.
        fNew.simplify();

        // returning result object
        return fNew;
    }

    // operator overloading: the '*' operator
    Fraction operator*(Fraction const &f2) const
    {
        int num = numerator * f2.numerator;
        int deno = denominator * f2.denominator;
        Fraction fNew(num, deno);
        fNew.simplify();
        return fNew;
    }
    // operator overloading
    // to check if two fractions are equal or not
    bool operator==(Fraction const &f2) const
    {
        return (numerator == f2.numerator && denominator == f2.denominator);
    }

    void multiply(Fraction const &f2)
    {
        numerator = numerator * f2.numerator;
        denominator = denominator * f2.denominator;

        simplify();
    }
};

int main()
{
    Fraction f1(5, 25);
    Fraction f2(8, 25);
    Fraction f3 = f1.add(f2);
    cout << "fraction f1 = " << endl;
    f1.show();
    cout << "fraction f2 = " << endl;
    f2.show();
    cout << "fraction f3 = f1.add(f2)=" << endl;
    f3.show();
    Fraction f4 = f1 + f2;
    // here, f1 goes in the this operator.
    // + sign calls the funciton : Fraction operator+(Fraction const $f2)
    // f2 goes inside the parameter
    cout << "fraction f4 = f1+f2 =" << endl;
    f4.show();

    Fraction f5 = f1 * f2;
    cout << "f5 = f1*f2 = " << endl;
    f5.show();

    if (f1 == f2)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not equal" << endl;
    }

    return 0;
}