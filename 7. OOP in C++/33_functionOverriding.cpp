/*function overriding: override the same named base class funciton
in the derived class
*/

#include <iostream>
using namespace std;

class Vehicle
{
public:
    void print()
    {
        cout << "Vehicle" << endl;
    }
};
class Car : public Vehicle
{
public:
    // overriding the print function
    void print()
    {
        cout << "Car" << endl;
    }
};
int main()
{
    Vehicle v;
    Car c;
    v.print(); // Vehicle
    c.print(); // Car

    Vehicle *v1 = new Vehicle;
    v1 = &v;
    v1->print(); // vehicle
    //   NOTE: base class pointer can be appointed to
    //  the derived class object but vice versa not allowed

    // taking a base class pointer and pointing derived class object
    Vehicle *v2 = &c;
    // though v2 is pointing to derived class c
    // but it can not access c class properties
    // the pointer is allowed to access properties
    // of the class whose pointer it is itself.
    v2->print(); // not Car,Vehicle
    // but what if we want to access the car class print function
    // with the base class pointer?
    // that is where run time polymorphism comes in.
    // see the next code.

    return 0;
}