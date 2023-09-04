/*We achieve run time polymorphism using virtual funcitons.
Virtual funcitons are funciton that are present in base class
and overridden in the derived class.
here, we have made base class print funciton
a virtual one to achieve run time polymorphism.
*/
#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual void print()
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

    // taking a base class pointer and pointing derived class object
    Vehicle *v2 = &c;
    v2->print();
    // this time it is, Car. not Vehicle like previous code
    // since base class print is a virtual funciton
    // so in run time, compiler is checking that
    // v2 points to car class object. so it calls print() from car class.
    // case 1: if we remove print() from car class, compiler will run
    // print() from the base class.
    // case 2: if we remove base class print(), then compiler gives error.
    // because v2 is a pointer of base class. and base class has no
    // function named print(). that is why it gives error.

    return 0;
}