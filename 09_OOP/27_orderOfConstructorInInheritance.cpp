/*In inheritance, first base class constructor is called.
then derived class constructor.
In case of destructor, it is reversed.
NOTE: one class can only call its immediate parent class constructor
for ex: if Vehicle-->Car-->Honda class are created,
then Honda class can call only Car class constructor,
and Car class can only call Vehicle class constructor.
And goes so on.
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
    // default constructor
    Vehicle()
    {
        cout << "Vehicle class constructor called!" << endl;
    }
    // parameterized constructor
    Vehicle(int z)
    {
        cout << "Vehicle class parameterized constructor called!" << endl;
        maxSpeed = z;
    }
    // destructor
    ~Vehicle()
    {
        cout << "Vehicle class destructor called!" << endl;
    }

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
    // constructor
    // Car()
    // {
    //     cout << "Car class constructor called!" << endl;
    // }
    // this is implicitly works like this:
    // Car():Vehicle(){
    // cout << "Car class conductor called!" << endl;
    // }
    // NOTE: derived class always implicitly initialize default
    // constructor of base class
    // if we want to initialize base class paramterized constructor
    // we will have to explictly mention it like below:
    Car(int x) : Vehicle(x)
    {
        cout << "Car class constructor!" << endl;
    }
    // destructor
    ~Car()
    {
        cout << "Car class destructor called!" << endl;
    }

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
    Vehicle v; // only Vehicle class constructor is called

    // creating a Car class object
    // Car c;
    // since Car is inherited from Vehicle,
    // first Vehicle class and then Car class constructor is called.

    // initializing car class with base class parameterized constructor.
    Car c(25);

    return 0;
}