/*
In hybrid inheritance, a problem named diamond problem may occur.
It happens when B and C are derived from class A,
and then D is derived from both B and C.

So, class D indirectly inherits A's properties twice:
(1) Through B
(2) Through C

Therefore, when D tries to access A's members,
the compiler becomes confused about **which A subobject**
(from B or from C) should be referenced.

This is called the Diamond Problem.
*/

#include <iostream>
using namespace std;

// ======================= Base Class: Vehicle =======================
class Vehicle
{
private:
    int maxSpeed;

protected:
    int numTyres;

public:
    string color;

    // default constructor
    Vehicle()
    {
        cout << "Vehicle default constructor!" << endl;
        maxSpeed = 0;
    }

    // parameterized constructor
    Vehicle(int z)
    {
        cout << "Vehicle class parameterized constructor!" << endl;
        maxSpeed = z;
    }

    void print()
    {
        cout << "Vehicle print() called!" << endl;
    }

    ~Vehicle()
    {
        cout << "Vehicle class destructor!" << endl;
    }
};

// ======================= Derived Class: Car =======================
class Car : public Vehicle
{
public:
    int numGears;

    Car()
    {
        cout << "Car default constructor!" << endl;
    }

    ~Car()
    {
        cout << "Car class destructor!" << endl;
    }
};

// ======================= Derived Class: Truck =======================
class Truck : public Vehicle
{
public:
    Truck()
    {
        cout << "Truck default constructor!" << endl;
    }
};

// ======================= Derived Class: Bus =======================
// Bus inherits from BOTH Car and Truck,
// which means it contains **two separate Vehicle subobjects**
// → one from Car, and one from Truck.
class Bus : public Car, public Truck
{
public:
    Bus()
    {
        cout << "Bus default constructor!" << endl;
    }
};

// ======================= Main Function =======================
int main()
{
    Bus b;

    // Constructor order:
    // Vehicle (via Car)
    // Car
    // Vehicle (via Truck)
    // Truck
    // Bus

    // b.print();   // ❌ ERROR: Ambiguous!
    // Because Bus has TWO Vehicle subobjects
    // one through Car and one through Truck.

    // Solution: explicitly specify which path to follow:
    b.Car::print();
    b.Truck::print();

    return 0;
}
