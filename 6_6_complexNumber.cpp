// complex number homework
#include <iostream>

using namespace std;

class Complex
{
    int real;
    int imaginary;

public:
    Complex(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

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

    void add(Complex const &c2)
    {
        this->real = this->real + c2.real;
        this->imaginary = this->imaginary + c2.imaginary;
    }

    void multiply(Complex const &c2)
    {
        int result_real = (this->real * c2.real) - (this->imaginary * c2.imaginary);
        int result_imaginary = (this->real * c2.imaginary) + (this->imaginary * c2.real);
        this->real = result_real;
        this->imaginary = result_imaginary;
    }
};

int main()
{
    Complex c1(8, 5);
    Complex c2(5, 1);
    c1.print();
    c2.print();

    // c1.add(c2);
    // c1.print();

    c1.multiply(c2);
    c1.print();

    return 0;
}