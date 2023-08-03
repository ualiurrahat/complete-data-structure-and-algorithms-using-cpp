// creating a class Complex
// it will produce complex numbers and it can perform
// addition,multiplication of numbers.
#include <iostream>

using namespace std;

class Complex
{
private:
    // a complex number has two parts
    // real and imaginary
    // ex: c = 3+4i, here, 3 is real, 4 is imaginary
    int real;
    int imaginary;

public:
    // constructor
    Complex(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }
    // funciton to print complex numbers
    void print()
    {
        if (imaginary >= 0)
        {
            cout << real << " + i" << imaginary << endl;
        }
        else
        {
            cout << real << " - i" << imaginary << endl;
        }
    }
    // function to add two complex numbers.
    void add(Complex const &c2)
    {
        this->real = this->real + c2.real;
        this->imaginary = this->imaginary + c2.imaginary;
    }
    // function to multiply two complex numbers.
    void multiply(Complex const &c2)
    {
        int result_real = (this->real * c2.real) - (this->imaginary * c2.imaginary);
        int result_imaginary = (this->real * c2.imaginary) + (this->imaginary * c2.real);
        this->real = result_real;
        this->imaginary = result_imaginary;
    }
};