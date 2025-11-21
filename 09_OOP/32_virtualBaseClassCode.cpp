/*
File: 32_virtualBaseClassCode.cpp

Topic: Solving the Diamond Problem Using Virtual Base Classes in C++

We are demonstrating the following concepts:
1) Diamond problem occurs in hybrid inheritance.
2) Virtual inheritance ensures only one shared base class object.
3) Constructor call order and ambiguity resolution.
*/

#include <iostream>
using namespace std;

// ======================= Base Class: Vehicle =======================
class Vehicle
{
private:
    int maxSpeed; // private member, not directly accessible in derived classes

protected:
    int numTyres; // protected member, accessible to derived classes

public:
    string color; // public member, accessible anywhere

    // Default constructor
    Vehicle()
    {
        cout << "Vehicle default constructor called!" << endl;
        maxSpeed = 0;
        numTyres = 4;
        color = "unknown";
    }

    // Parameterized constructor
    Vehicle(int speed, int tyres, string c)
    {
        cout << "Vehicle parameterized constructor called!" << endl;
        maxSpeed = speed;
        numTyres = tyres;
        color = c;
    }

    // Print function
    void print()
    {
        cout << "Vehicle Properties:" << endl;
        cout << "Color: " << color << endl;
        cout << "NumTyres: " << numTyres << endl;
        // maxSpeed is private, cannot be accessed outside class directly
    }

    // Destructor
    ~Vehicle()
    {
        cout << "Vehicle destructor called!" << endl;
    }
};

// ======================= Derived Class: Car =======================
// Virtual inheritance ensures only one shared Vehicle object
class Car : virtual public Vehicle
{
public:
    int numGears; // public property specific to Car

    // Default constructor
    Car()
    {
        cout << "Car default constructor called!" << endl;
        numGears = 5;
    }

    // Parameterized constructor
    Car(int gears)
    {
        cout << "Car parameterized constructor called!" << endl;
        numGears = gears;
    }

    // Destructor
    ~Car()
    {
        cout << "Car destructor called!" << endl;
    }

    // Print function
    void print()
    {
        cout << "Car Properties:" << endl;
        cout << "NumGears: " << numGears << endl;
        cout << "Color: " << color << endl;       // inherited
        cout << "NumTyres: " << numTyres << endl; // inherited
    }
};

// ======================= Derived Class: Truck =======================
// Virtual inheritance ensures only one shared Vehicle object
class Truck : virtual public Vehicle
{
public:
    int loadCapacity; // property specific to Truck

    // Default constructor
    Truck()
    {
        cout << "Truck default constructor called!" << endl;
        loadCapacity = 1000; // in kg
    }

    // Destructor
    ~Truck()
    {
        cout << "Truck destructor called!" << endl;
    }

    // Print function
    void print()
    {
        cout << "Truck Properties:" << endl;
        cout << "Load Capacity: " << loadCapacity << " kg" << endl;
        cout << "Color: " << color << endl;       // inherited
        cout << "NumTyres: " << numTyres << endl; // inherited
    }
};

// ======================= Derived Class: Bus =======================
// Bus inherits from BOTH Car and Truck
// Without virtual inheritance, there would be two Vehicle subobjects
class Bus : public Car, public Truck
{
public:
    int numSeats;

    // Constructor of Bus
    // Explicitly calling Vehicle constructor to initialize the single shared Vehicle object
    Bus(int speed, int tyres, string c, int gears, int capacity, int seats)
        : Vehicle(speed, tyres, c), Car(gears), Truck() // Vehicle constructor called only once
    {
        cout << "Bus constructor called!" << endl;
        numSeats = seats;
    }

    // Destructor
    ~Bus()
    {
        cout << "Bus destructor called!" << endl;
    }

    // Print function
    void print()
    {
        cout << "Bus Properties:" << endl;
        cout << "Color: " << color << endl;                         // inherited
        cout << "NumTyres: " << numTyres << endl;                   // inherited
        cout << "NumGears: " << numGears << endl;                   // inherited from Car
        cout << "Load Capacity: " << loadCapacity << " kg" << endl; // inherited from Truck
        cout << "NumSeats: " << numSeats << endl;                   // Bus own property
    }
};

// ======================= Main Function =======================
int main()
{
    /*
    Here we are creating a Bus object with full parameter initialization.
    Virtual inheritance ensures only ONE Vehicle object exists, resolving the diamond problem.
    */
    Bus b(120, 6, "Yellow", 6, 5000, 50);

    cout << "\nPrinting Bus details:" << endl;
    b.print();

    /*
    Constructor call order:
    1) Vehicle (virtual base, called first)
    2) Car
    3) Truck
    4) Bus

    Destructor call order (reverse):
    1) Bus
    2) Truck
    3) Car
    4) Vehicle
    */

    return 0;
}
