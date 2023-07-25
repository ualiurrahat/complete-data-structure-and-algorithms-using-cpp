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
    f1.show();
    f2.show();
    f3.show();
    Fraction f4 = f1 + f2;
    f4.show();

    Fraction f5 = f1 * f2;
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