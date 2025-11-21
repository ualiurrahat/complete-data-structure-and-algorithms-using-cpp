/*
File: 37_runtimePolymorphism.cpp

Topic: Runtime Polymorphism Using Virtual Functions

Runtime polymorphism allows the program to decide which function to call
**during execution**, not during compilation.

We achieve runtime polymorphism using **virtual functions**.

Key Theory:
-----------
1) A virtual function is defined in the **base class**.
2) It must be **overridden** in the derived class.
3) When a base class pointer points to a derived class object:
        - If the function is NOT virtual → base class version is called.
        - If the function IS virtual → derived class version is called.
4) This selection happens at **runtime**, using **dynamic binding**.

This file demonstrates:
- Base class pointer pointing to derived class object
- How virtual keyword affects the output
*/

#include <iostream>
using namespace std;

// ---------------------- Base Class ----------------------
class Vehicle
{
public:
    /**
     * @brief Virtual function to demonstrate runtime polymorphism.
     */
    virtual void print()
    {
        cout << "Vehicle" << endl;
    }
};

// ---------------------- Derived Class ----------------------
class Car : public Vehicle
{
public:
    /**
     * @brief Overriding the base class print() function.
     */
    void print()
    {
        cout << "Car" << endl;
    }
};

// ---------------------- Main Function ----------------------
int main()
{
    Vehicle v;
    Car c;

    // Direct calls
    v.print(); // Vehicle
    c.print(); // Car

    // Base class pointer → Base class object
    Vehicle *v1 = &v;
    v1->print(); // Vehicle

    // Base class pointer → Derived class object
    Vehicle *v2 = &c;
    v2->print(); // Car (because print() is virtual)

    /*
    Explanation:
    - v2 is a pointer of type Vehicle*, but it stores the address of object c (Car).
    - Because Vehicle::print() is virtual, the program checks the REAL object type at runtime.
    - REAL object is Car → so Car::print() is executed.

    Case 1:
        If Car::print() is removed → calls Vehicle::print()

    Case 2:
        If Vehicle::print() is removed → ERROR
        Because v2 is a Vehicle* pointer. The compiler expects Vehicle to have print().
    */

    return 0;
}
