// unary operator overloading.

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

    Fraction add(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator; // denominator = this->denominator
        int x = (lcm / denominator);
        int y = (lcm / f2.denominator);

        int ans_numerator = (x * numerator) + (y * f2.numerator);

        // // now updating f1.
        // numerator = ans_numerator;
        // denominator = lcm;
        Fraction fNew(ans_numerator, lcm);
        fNew.simplify();
        return fNew;
    }

    // Operator Overloading
    Fraction operator+(Fraction const &f2) const
    {
        int lcm = denominator * f2.denominator; // denominator = this->denominator
        int x = (lcm / denominator);
        int y = (lcm / f2.denominator);

        int ans_numerator = (x * numerator) + (y * f2.numerator);

        // // now updating f1.
        // numerator = ans_numerator;
        // denominator = lcm;
        Fraction fNew(ans_numerator, lcm);
        fNew.simplify();
        return fNew;
    }

    // operator overloading for multiplication
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

    // pre-increment (++)operator overloading
    // ***: nesting is possible in pre-increment operator overloading
    // ex: ++(++i) is possible.
    // if we don't return reference(Fraction&)
    // if we return only object(Fraction)
    // then function will create a copy of the value
    // as the same of this-> object value
    // but ++(++f1)won't work
    // as the outer++ works only in the copied buffer(temporary)
    // change does not reflect on this->operator object
    // so in order to work for any number of loop
    // inside pre-increment operation
    // we are return reference of the Fraction object
    Fraction &operator++()
    {
        numerator = numerator + denominator;
        simplify();
        return *this;
    }

    // post-increment operator overloading
    // *** nesting is not allowed in post-increment overloading
    // difference between post and pre-increment
    // pre-increment:
    // i = 5;
    // j = ++i;
    // cout << i << " " <<< j
    // ans : i = 6 , j = 6

    // post-increment:
    // i = 5;
    // j = i++
    // cout << i << " " << j << endl;
    // i = 6, j =5
    Fraction operator++(int) //(int) is given to make pc understand that this is post-increment
    {
        Fraction fNew(numerator, denominator);
        numerator = numerator + denominator;
        simplify();
        fNew.simplify();
        return fNew;
    }

    // plus-equal(+=) operator overloading
    Fraction &operator+=(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator; // denominator = this->denominator
        int x = (lcm / denominator);
        int y = (lcm / f2.denominator);

        int ans_numerator = (x * numerator) + (y * f2.numerator);

        numerator = ans_numerator;
        denominator = lcm;

        simplify();
        return *this;
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
    Fraction f1(10, 2);
    f1.show();
    ++f1;
    f1.show();

    Fraction f2 = ++f1;
    f2.show();

    Fraction f3 = ++(++f2);
    f3.show();
    f2.show();

    Fraction f4 = f1++;
    f1.show();
    f4.show();

    Fraction f5(10, 3);
    Fraction f6(5, 2);
    f5 += f6;
    f5.show();

    return 0;
}