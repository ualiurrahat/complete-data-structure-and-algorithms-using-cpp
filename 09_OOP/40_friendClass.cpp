/*
    Problem Statement:
    ------------------
    Demonstrate the concept of:
    1) friend class
    2) friend member functions
    in C++.

    THEORY:
    -------
    Friend Class:
    --------------
    - A class can declare another class as a "friend".
    - The friend class gets access to ALL (private, protected, public) members
      of the class in which it is declared friend.
    - Friendship is NOT mutual. If A is a friend of B, B does NOT automatically
      become a friend of A.

    Friend Member Function:
    ------------------------
    - A specific function (not the entire class) can be declared as a friend.
    - That function (even if it belongs to another class) gets complete access.

    Forward Declaration:
    --------------------
    - Since Calculator uses Complex objects in function declarations, we have
      to forward declare Complex before defining Calculator.

    In this file:
    -------------
    - Calculator is a friend class of Complex.
    - Calculator can access private members of Complex.
*/

#include <iostream>
#include <string>
using namespace std;

// Forward declaration of Complex class
class Complex;

/**
 * @class Calculator
 * @brief Provides functions to add real and imaginary parts of Complex numbers.
 */
class Calculator
{
public:
    /**
     * @brief Adds two integers.
     */
    int add(int a, int b)
    {
        return a + b;
    }

    /**
     * @brief Adds real parts of two Complex numbers.
     */
    int sumRealPart(Complex, Complex);

    /**
     * @brief Adds imaginary parts of two Complex numbers.
     */
    int sumComplexPart(Complex, Complex);
};

/**
 * @class Complex
 * @brief Represents a complex number with real and imaginary parts.
 */
class Complex
{
    int a; // real part
    int b; // imaginary part

    // Declaring Calculator as a friend → gives full access
    friend class Calculator;

public:
    /**
     * @brief Sets the real and imaginary parts.
     */
    void setNumber(int realPart, int imagPart)
    {
        a = realPart;
        b = imagPart;
    }

    /**
     * @brief Prints the complex number.
     */
    void printNumber()
    {
        cout << "Your complex number is " << a << " + " << b << "i" << endl;
    }
};

// Definition of Calculator friend functions

int Calculator::sumRealPart(Complex ob1, Complex ob2)
{
    return ob1.a + ob2.a; // Allowed because Calculator is a friend of Complex
}

int Calculator::sumComplexPart(Complex ob1, Complex ob2)
{
    return ob1.b + ob2.b; // Allowed because Calculator is a friend of Complex
}

/**
 * @brief Main function demonstrating friend classes and friend functions.
 */
int main()
{
    Complex obj1, obj2;
    obj1.setNumber(1, 4);
    obj2.setNumber(5, 9);

    Calculator calc;

    int realSum = calc.sumRealPart(obj1, obj2);
    cout << "The sum of real parts: " << realSum << endl;

    int imagSum = calc.sumComplexPart(obj1, obj2);
    cout << "The sum of imaginary parts: " << imagSum << endl;

    return 0;
}
