/*
here, we virutally inherited Vehicle class in order to
create Car and Truck class. Now, it is like Car,Truck class
have no direct access to the property of Vehicle class.
Rather they have a pointer which point to those propery of Vehicle class

NOTE: in normal inheritance, a child class can only implicitly access only its base class
but in virtual inheritance, a child class can access not only its immediate base class
but also base class of its own base class.
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
    // Vehicle()
    // {
    //     cout << "Vehicle default constructor!" << endl;
    // }
    // parameterized constructor
    Vehicle(int z)
    {
        cout << "Vehicle class parameterized constructor!" << z << endl;
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
class Car : virtual public Vehicle
{

    // maxSpeed is private. so can not be inherited.
    // color is public. so it is publicly inherited.
    // numTyres is protectedly inherited.
public:
    int numGears;
    // constructor
    // Car()
    // {
    //     cout << "Car default constructor!" << endl;
    // }
    Car() : Vehicle(20)
    {
        cout << "Car parameterized constructor!" << endl;
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
class Truck : virtual public Vehicle
{
public:
    // Truck()
    // {
    //     cout << "Truck default constructor!" << endl;
    // }
    Truck() : Vehicle(4)
    {
        cout << "Truck parameterized constructor" << endl;
    }
};

// Since both Car,Truck class are virtually inherited
// class Bus will not copy properties of class A
// twice through inheriting class Car,Truck
// rather it is like Bus class has access to all the
// 3 classes.
class Bus : public Car, public Truck
{
public:
    Bus() : Vehicle(5)
    {
        cout << "Bus default constructor!" << endl;
    }
};
int main()
{
    // Bus b;
    // look at the constructor call pattern.
    // it is different from previous code.
    // as Car,Truck are virtually created.
    // call: vehicle,car,truck,bus

    // now commenting Vehicle class default constructor
    // to call parameterized Vehicle constructor
    // we need to pass parameterized constructor
    // in bus,car and truck class. did it in their classes.
    Bus b;
    // look we send value 5 with Bus class parameterized constructor
    // and Vehicle class parameterized constructor printed 5
    // so it is like Bus class directly calling
    // Behicle class constructor.
    return 0;
}