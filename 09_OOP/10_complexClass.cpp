/**
 * @file 10_complexClass.cpp
 * @brief Defines the Complex class for representing and performing arithmetic operations on complex numbers.
 */

#include <iostream>
using namespace std;

/**
 * @class Complex
 * @brief Represents a complex number and supports basic arithmetic operations like addition and multiplication.
 *
 * A complex number has two components — a real part and an imaginary part.
 * Example: c = 3 + 4i, where 3 is the real part and 4 is the imaginary part.
 */
class Complex
{
private:
    // ---------------------- Data Members ----------------------
    // A complex number has two parts: real and imaginary.
    // Example: c = 3 + 4i, where 3 → real, 4 → imaginary.
    int real;
    int imaginary;

public:
    // ---------------------- Constructor ----------------------
    /**
     * @brief Constructs a Complex object with given real and imaginary values.
     * @param real The real part of the complex number.
     * @param imaginary The imaginary part of the complex number.
     */
    Complex(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    // ---------------------- Print Function ----------------------
    /**
     * @brief Prints the complex number in the form "a + ib" or "a - ib".
     */
    void print()
    {
        if (imaginary >= 0)
        {
            cout << real << " + i" << imaginary << endl;
        }
        else
        {
            cout << real << " - i" << -imaginary << endl;
        }
    }

    // ---------------------- Addition Function ----------------------
    /**
     * @brief Adds the given complex number to the current one.
     *
     * Example: (a + ib) + (c + id) = (a + c) + i(b + d)
     *
     * @param c2 A constant reference to another Complex object.
     */
    void add(Complex const &c2)
    {
        this->real = this->real + c2.real;
        this->imaginary = this->imaginary + c2.imaginary;
    }

    // ---------------------- Multiplication Function ----------------------
    /**
     * @brief Multiplies the given complex number with the current one.
     *
     * Formula: (a + ib)(c + id) = (ac − bd) + i(ad + bc)
     *
     * @param c2 A constant reference to another Complex object.
     */
    void multiply(Complex const &c2)
    {
        int resultReal = (this->real * c2.real) - (this->imaginary * c2.imaginary);
        int resultImaginary = (this->real * c2.imaginary) + (this->imaginary * c2.real);

        // Updating current object with the result.
        this->real = resultReal;
        this->imaginary = resultImaginary;
    }
};
