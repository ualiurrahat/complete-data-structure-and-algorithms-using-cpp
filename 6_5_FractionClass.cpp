#include <bits/stdc++.h>

using namespace std;

class Fraction
{
    // fraction number has two parts: numerator and denominator
    // ex: 3/4
    // numerator = 3
    // denominator = 4
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void show()
    {
        cout << numerator << " / " << denominator << endl;
        // this should be written as
        // cout << this->numerator << " / " << this->denominator << endl;
        // but still working fine.
        // as we have used no parameter
        // nameds as numerator or denominator
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
        int j = min(this->numerator, this->denominator); // using this-> is optional
        // the max value of a gcd for two numbers
        // will be the minimum of these numbers.
        // j takes min among numerator and denominator
        // so j is the greates value that gcd
        // of numerator and denominator can become
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
        // could have used void add(Fraction f2)
        // this works like that: void add (Fraction f2 = main.f2)
        // so it creates a new object and copies all values
        // from f2 and then use the object as a parameter
        // so it takes time and space also
        // but void add(Fraction const &f2)
        // like Fraction const &f2 = Fraction const f2;
        // here we are sending reference of f2
        // so no coping is done. reduces space and time
        // const is making sure we cant change f2 values
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
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    f1.show();
    f2.show();
    f1.add(f2);
    f1.show();

    f1.multiply(f2);
    f1.show();

    return 0;
}