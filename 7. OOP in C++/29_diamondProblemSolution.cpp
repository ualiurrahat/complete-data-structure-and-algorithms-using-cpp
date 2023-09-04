/*
In hybrid inheritance, a problem named diamond problem may occur.
It happens when B and C is derived from Clas A
and then D is derived from B and C.
so D inherits properties of A class
by the help of B and C, since they are inherited from A
So, if D tries to access A class property,
compiler gets confused thinking of from
which derived class(B or C) D is trying to
access property of A.
This is called Diamond Problem.
 */

#include <iostream>
using namespace std;

// class Vehicle
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
    }
    // parameterized constructor
    Vehicle(int z)
    {
        cout << "Vehicle class parameterized constructor!" << endl;
        maxSpeed = z;
    }
    // print funciton
    void print()
    {
        cout << "vehicle" << endl;
    }
    // destructor
    ~Vehicle()
    {
        cout << "Vehicle class destructor!" << endl;
    }
};

// creating Car class from Vehicle class
class Car : public Vehicle
{

    // maxSpeed is private. so can not be inherited.
    // color is public. so it is publicly inherited.
    // numTyres is protectedly inherited.
public:
    int numGears;
    // constructor
    Car()
    {
        cout << "Car default constructor!" << endl;
    }
    // destructor
    ~Car()
    {
        cout << "Car class destructor!" << endl;
    }

    // void print()
    // {
    //     cout << "NumTyres: " << numTyres << endl;
    //     cout << "NumGears: " << numGears << endl;
    //     cout << "color: " << color << endl;
    //     // cout << "maxSpeed: " << maxSpeed << endl;
    // }
};
// creating Truck class from Vehicle
class Truck : public Vehicle
{
public:
    Truck()
    {
        cout << "Truck default constructor!" << endl;
    }
};

// now creating a Bus class,
// taking Truck,Car as its base class.
class Bus : public Car, public Truck
{
public:
    Bus()
    {
        cout << "Bus default constructor!" << endl;
    }
};
int main()
{
    Bus b;
    // look at the constructor call pattern:
    // vehicle,car,vehicle,truck and then bus constructor.

    // b.print(); show error as ambiguity occurs
    // Bus is inherited Car,Truck classes
    // these both classes inherited print() function
    // from the base Vehcile class.
    // so compiler is confused on which print()
    // function user is pointing to.
    // solution 1: use write Bus class own print() function
    // solution 2: explicitly mention whose print() funciton
    // you want to acquire. like this:
    // b.Car::print();

    // NOTE: if we want to restrict double coping of Vehicle class
    // properties in class Bus(through inheritance of class Car,Truck)
    // we can made class Car,Truck virtual
    // check out the next code.
    return 0;
}