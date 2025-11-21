/*
File: 33_virtualInheritance.cpp

Topic: Virtual Inheritance in C++

- In hybrid inheritance, diamond problem may occur when a class inherits
  the same base class through multiple paths.
- Virtual inheritance ensures that the base class is shared among all
  derived classes, preventing multiple copies of the base class in memory.

Key Points:
1) Car and Truck virtually inherit Vehicle.
2) Now, Bus inherits from both Car and Truck, but only **one** Vehicle subobject exists.
3) Constructor call sequence is different in virtual inheritance.
4) In normal inheritance, each derived class has its own copy of the base class.
   In virtual inheritance, derived classes share a single base class object.
*/

#include <iostream>
using namespace std;

// ======================= Base Class: Vehicle =======================
class Vehicle
{
private:
    int maxSpeed; // private: cannot be accessed directly by derived classes

protected:
    int numTyres; // protected: accessible by derived classes

public:
    string color; // public: accessible anywhere

    // parameterized constructor
    Vehicle(int z)
    {
        cout << "Vehicle class parameterized constructor! Value: " << z << endl;
        maxSpeed = z;
    }

    // print function
    void print()
    {
        cout << "Vehicle print() called!" << endl;
    }

    // destructor
    ~Vehicle()
    {
        cout << "Vehicle class destructor!" << endl;
    }
};

// ======================= Derived Class: Car =======================
class Car : virtual public Vehicle
{
public:
    int numGears; // specific to Car

    // constructor of Car calls Vehicle parameterized constructor
    // since Vehicle is virtually inherited, actual Vehicle constructor
    // call is controlled by the most derived class (Bus here)
    Car() : Vehicle(20) // this value will be ignored when Bus calls Vehicle constructor
    {
        cout << "Car parameterized constructor!" << endl;
    }

    // destructor
    ~Car()
    {
        cout << "Car class destructor!" << endl;
    }
};

// ======================= Derived Class: Truck =======================
class Truck : virtual public Vehicle
{
public:
    // constructor of Truck calls Vehicle parameterized constructor
    // in virtual inheritance, this will also be ignored by most derived class
    Truck() : Vehicle(4)
    {
        cout << "Truck parameterized constructor!" << endl;
    }
};

// ======================= Derived Class: Bus =======================
// Bus inherits from both Car and Truck
// Because Car and Truck are virtually inheriting Vehicle,
// Bus contains only ONE shared Vehicle object
class Bus : public Car, public Truck
{
public:
    // Bus explicitly calls Vehicle parameterized constructor
    // This is the one Vehicle constructor that will actually be executed
    Bus() : Vehicle(5)
    {
        cout << "Bus default constructor!" << endl;
    }
};

// ======================= Main Function =======================
int main()
{
    // creating Bus object
    Bus b;

    /*
    Constructor call sequence in virtual inheritance:

    1) Vehicle constructor (single shared object) --> 5 printed
    2) Car constructor
    3) Truck constructor
    4) Bus constructor

    This ensures that Vehicle is not duplicated via Car and Truck.
    */

    return 0;
}
