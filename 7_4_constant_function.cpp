// constant functions: functions that do not change
// any properties of the current object

#include <bits/stdc++.h>

using namespace std;

class Fraction
{
private:
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
        // this should be written as
        // cout << this->numerator << " / " << this->denominator << endl;
        // but still working fine.
        // as we have used no parameter
        // so compiler automatically taking values
        // from this pointer reference.
    }

    // function to simply the fraction
    // means dividing them with their GCD
    // to maintain their value at lower number
    // ex: f1 = 70 / 8....GCD(70,8) = 2;
    // so, f1 = 35 / 4.
    // will do this using this simplify function
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
    // function to add two fraction
    // f1 = f1 + f2
    // function does not return anything
    // it stores addition result in f1.
    // means, it stores result in the function which calls the function.

    void add(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator; // denominator = this->denominator
        int x = (lcm / denominator);
        int y = (lcm / f2.denominator);

        int ans_numerator = (x * numerator) + (y * f2.numerator);

        // now updating f1.
        numerator = ans_numerator;
        denominator = lcm;

        // after adding the fractions, we will call simplify function.
        simplify();
        // meaning:  this->simplify() == f1.simplify();
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
    Fraction f1(25, 8);
    Fraction f2(3, 11);
    f1.show();
    f2.show();

    // const object
    Fraction const f3;
    // though we have not passed any value.
    // if printed, we will get garbage value.

    // const object can be called with constant function only
    // const function: that does not change any properties of the current object.

    cout << " " << f3.getNumerator() << " " << f3.getDenominator() << endl;
    f3.show();

    return 0;
}