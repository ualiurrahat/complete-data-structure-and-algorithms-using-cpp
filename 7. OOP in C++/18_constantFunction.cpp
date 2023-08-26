/*
syntax to declare any function as const:
returnType funcitonName() const
{

}
*/

#include <bits/stdc++.h>
using namespace std;

/*
same fraction class like previous code.
but here, we have declared print(),setNumerator(),
setDonominaor() as const functions.
*/
class Fraction
{
private:
    // fraction number has two parts: numerator and denominator
    // ex: 3/4, here, numerator = 3 and denominator = 4
    int numerator;
    int denominator;

public:
    // default constructor
    // in case we just want to declare a class object
    Fraction()
    {
    }
    // parameterized constructor
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    // function to display fraction numbers.
    void print() const
    {
        cout << numerator << " / " << denominator << endl;
        /*
         this should be written as
         cout << this->numerator << " / " << this->denominator << endl;
         but still working fine.
         as we have used no parameter
         nameds as numerator or denominator
         so compiler automatically taking values
         from this pointer reference.

         note: whenever we access object's properties using dot operation
        inside main function, that object's address is saved in the this pointer
        */
    }

    // function to simply the fraction numbers
    // ex: if f1 = 70/8, we can simplify it to f1 = 35/4.
    // how?
    // solution: divide numerator and denominator of f1 by their gcd.
    // here, gcd of (70,8) = 2
    // so 70/2 = 35 and 8/2 = 4
    // so, f1 = 70/8 becomes f1 = 35/4
    void simplify()
    {
        int gcd = 1;
        // take minimum value between numerator and denominator
        int j = min(this->numerator, this->denominator);
        // even if we write, j = min(numerator,denominator), it will work
        // as computer will explicitly take the values from this pointer.

        // the max value of a gcd for two numbers
        // will be the minimum of these numbers.
        // j takes min among numerator and denominator
        // so j is the greatest value that can be the gcd
        // of numerator and denominator
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

    // function to add two fraction numbers.
    // f1. add(f2) ---> means = f1 + f2
    // so, function is called by a fraction number object
    // a number which needs to be added is used as a parameter.
    // function doesn't return anything, void type.
    // resultant number is saved in the number f1(the number which called the add function)

    // why we are not writing function like: void add(Fraction f2) ??
    // it is interpret as Fraction f2 = main.f2
    // so a new fraction object f2 is created using copy constructor and values of f2 object from main function
    // but this wastes time and space as complete object is again created
    // and we just want to add f2 with the number by which add function was called
    // so we are taking reference of a f2 number
    // and making it const so that no one can change f2 object of the main function
    // better write function : void add(Fraction const &f2)

    void add(Fraction const &f2)
    {
        // lcm of the denomiators of f1 and f2
        int lcm = this->denominator * f2.denominator;
        int x = lcm / this->denominator;
        int y = lcm / f2.denominator;
        // numerator of the resultant fraction number
        int newNumerator = (x * this->numerator) + (y * f2.numerator);
        // denominator of the resulatnt fraction number is equal to lcm value
        int newDenominator = lcm;

        // now store the result number within the f1(the number which called the function) itself
        this->numerator = newNumerator;
        this->denominator = newDenominator;

        // calling simplifying function to simplify the result
        simplify();
        // this works as: f1.simplify();
    }

    // function to multiply fraction numbers
    void multiply(Fraction const &f2)
    {
        numerator = numerator * f2.numerator;
        denominator = denominator * f2.denominator;

        simplify();
    }

    // additional functions that are not present
    // in the previous Fraction class

    // to get numerator
    int getNumerator() const
    {
        return numerator;
    }

    // to get donimator
    int getDenominator() const
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
    // creating constant object from Fraction class.
    const Fraction f1;
    // constant objects are provided garbage
    // value at the time of their creation.

    // now since print(),getNumerator(),getDenominator()
    // are const functions, we can access f1 using them
    cout << "printing f1 const object: " << endl;
    f1.print();
    cout << "numerator of f1 is  : " << f1.getNumerator() << endl;
    cout << "denominator of f1 is : " << f1.getDenominator() << endl;

    return 0;
}