/*
we are creating a Vehicle class.
then we will create derived class from this class using inheritance.
*/

#include <iostream>
using namespace std;

// base class Vehicle
class Vehicle
{
private:
    int maxSpeed;

public:
    string color;

protected:
    int numTyres;
};

// creating Car class from Vehicle class
// inheritance syntax: class derivedClassName : accessModifier baseClassName
class Car : public Vehicle
{

    // maxSpeed is private. so can not be inherited.
    // color is public. so it is publicly inherited.
    // numTyres is protectedly inherited.
public:
    int numGears;

    void print()
    {
        cout << "NumTyres: " << numTyres << endl;
        cout << "NumGears: " << numGears << endl;
        cout << "color: " << color << endl;
        // cout << "maxSpeed: " << maxSpeed << endl;
    }
};
int main()
{
    // creating a Vehicle class object
    Vehicle v;
    v.color = "blue";
    // v.numTyres = 4;
    // v.maxSpeed = 120;
    // both line show error. private,protected members can not be accessed directly.

    // creating a Car class object
    Car c;
    c.color = "red";
    c.numGears = 5;
    // c.numTyres = 4; protected,so can not be accessed directly.

    return 0;
}
