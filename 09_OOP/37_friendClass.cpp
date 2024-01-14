// friend classes and member friend function in c++.

#include <iostream>
#include <string>

using namespace std;

// forward declaration.
class Complex;

/*
complex class is declared at the top which is known as forward declaration. Forward declaration hints the compiler that this class is declared somewhere forward in the code. After that calculator class is defined this consists of three public member functions, “add”, “sumRealComplex”, and “sumCompComplex”. The “add” function will add the values of “a” and “b” and return the value. The “sumRealComplex” and “sumCompComplex” are taking two objects of the complex class
*/

class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    int sumRealPart(Complex, Complex);
    int sumComplexPart(Complex, Complex);
    // here we have just delare the two functions.
    // can't define here
    // as they are taking complex object input
    // and we only know there is a class Complex exits seeing the forward declaration
    // but we don't know what are data members.
    // so we can only use declaraton here
    // ex: can't do this......
    // int sumRealPart(Complex ob1, Complex ob2)
    //{return ob1.a + ob2.a}
    // we can't do this because we don't know
    // a is a member of complex class
};

class Complex
// to generate complex numbers.
/*
complex class is defined which consists of, two private data members “a” and “b”, and two public member functions “setNumber” and “printNumber”. The function “setNumber” will assign the values to the variables “a” and “b”. The function “printNumber” will print the values of the variables “a” and “b”. Two functions “sumRealComplex” and “sumCompComplex” are defined at the end. The function “sumRealComplex” will add the real values and the function “sumCompComplex” will add the complex value.
*/
{
    int a;
    int b;

    // individually declaring functions of Calculator class as friend function.
    // syntax: friend return_type class_name :: funtion_name(parameters)
    // friend int Calculator :: sumRealPart(Complex o1, Complex o2);
    // friend int Calculator :: sumComplexPart(Complex o1, Complex o2);

    // alter: we can declare the whole Calculator class as frined of this class.
    friend class Calculator;

public:
    void setNumber(int m, int n)
    {
        a = m;
        b = n;
    }

    void printNumber()
    {
        cout << "Your complex number is " << a << " + " << b << "i" << endl;
    }
};

// definition of sumRealPart function.
int Calculator ::sumRealPart(Complex ob1, Complex ob2)
{
    return (ob1.a + ob2.a);
}

// definition of sumComplexPart function.
int Calculator ::sumComplexPart(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}

int main()
{
    Complex o1, o2;
    o1.setNumber(1, 4);
    o2.setNumber(5, 9);
    Calculator cal;

    int result = cal.sumRealPart(o1, o2);
    cout << "The sum of real part of o1 and o2 is " << result << endl;

    int result2 = cal.sumComplexPart(o1, o2);
    cout << "The sum of complex part of o1 and o2 is " << result2 << endl;

    return 0;
}