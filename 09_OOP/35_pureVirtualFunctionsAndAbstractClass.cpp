/*
pure virtual funcitons: those which are declared in the class but never defined.
syttax: virtual functionName() = 0;
abstract class: classes which have at least one pure virtual funciton
abstract class can not create objects. why?
cause object are initialized with all their data members and funcitons
since in abstract class, there is a pure virtual function,which is not defined,
object initialisation is not possible. So it can not create object.

The derived class from abstract class has 2 choices:
1) implement all the pure virtual functions of the base class
and work as a complete class
2) either if any of the pure virtual function remains undefined,
it also acts as an abstract class

*/

#include <iostream>
using namespace std;
// creating an abstract class named Vehicle
class Vehicle
{
public:
    string color;
    // pure virtual funciton
    virtual void print() = 0;
};
// inheriting the abstract class
class Car : public Vehicle
{
public:
    int numGears;
    // defining print() funciton
    void print()
    {
        cout << "Car" << endl;
    }
};
int main()
{
    // Vehicle v; not allowed.
    Car c;
    c.print();
    return 0;
}