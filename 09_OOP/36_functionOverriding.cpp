/*
File: 36_functionOverriding.cpp

Topic: Function Overriding in C++

Function overriding is a type of **runtime polymorphism**.
It occurs when a **derived class provides its own implementation**
of a function that is already defined in its **base class**.

Key Points:
1) Function name, return type, and parameters must be exactly the same.
2) Overriding happens in the **derived class**, replacing the base class behavior.
3) If a **base class pointer** points to a derived class object, by default it calls the **base class version**.
   - To call the derived class version through the base class pointer, we use **virtual functions** (covered in runtime polymorphism).

*/

// ---------------------- Header Includes ----------------------
#include <iostream>
using namespace std;

// ---------------------- Base Class ----------------------
class Vehicle
{
public:
    // Base class function
    void print()
    {
        cout << "Vehicle" << endl;
    }
};

// ---------------------- Derived Class ----------------------
class Car : public Vehicle
{
public:
    // Overriding the base class print() function
    void print()
    {
        cout << "Car" << endl;
    }
};

// ---------------------- Main Function ----------------------
int main()
{
    // Creating base and derived class objects
    Vehicle v;
    Car c;

    // Calling functions directly
    v.print(); // calls Vehicle::print() => Vehicle
    c.print(); // calls Car::print() => Car

    // Base class pointer pointing to base class object
    Vehicle *v1 = &v;
    v1->print(); // Vehicle

    // Base class pointer pointing to derived class object
    Vehicle *v2 = &c;
    // v2 can only access Vehicle class properties directly
    // Even though it points to a Car object
    v2->print(); // calls Vehicle::print(), NOT Car::print()

    /*
    Explanation:
    - A base class pointer can point to a derived class object.
    - However, it can only access **functions and members of the base class type**.
    - This shows **compile-time behavior** of function overriding without virtual keyword.
    - To achieve runtime polymorphism (calling Car::print() via base pointer),
      we must declare print() as **virtual** in the base class.
    */

    return 0;
}
