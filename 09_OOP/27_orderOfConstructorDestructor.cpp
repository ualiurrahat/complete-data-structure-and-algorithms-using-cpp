/*
    FILE: 27_orderOfConstructorDestructor.cpp

    --------------------------- Problem Summary ---------------------------
    In inheritance, constructor and destructor call order follows strict rules:

    1) When creating an object of a derived class:
           Base class constructor → Derived class constructor

    2) When destroying an object of a derived class:
           Derived class destructor → Base class destructor

    3) A class can call ONLY its immediate parent class constructor.
       Example: Vehicle → Car → HondaCity
           HondaCity can call only Car’s constructor.
           Car can call only Vehicle’s constructor.

    4) Private members (like Vehicle::maxSpeed) are NOT inherited.
       However, they can still be initialized via the parameterized constructor
       because the base constructor runs before the derived constructor.

    -----------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

// ----------------------------- Base Class ------------------------------ //

class Vehicle
{
private:
    int maxSpeed; // private: not inherited by derived classes

public:
    string color;

    // ----------------------- Default Constructor ----------------------- //
    Vehicle()
    {
        cout << "Vehicle class DEFAULT constructor called!" << endl;
        maxSpeed = 0;
    }

    // -------------------- Parameterized Constructor --------------------- //
    Vehicle(int speed)
    {
        cout << "Vehicle class PARAMETERIZED constructor called!" << endl;
        maxSpeed = speed;
    }

    // --------------------- Getter for maxSpeed -------------------------- //
    // We provide this function because maxSpeed is private and
    // cannot be accessed directly by derived classes.
    int getMaxSpeed() const
    {
        return maxSpeed;
    }

    // --------------------------- Destructor ----------------------------- //
    ~Vehicle()
    {
        cout << "Vehicle class destructor called!" << endl;
    }

protected:
    int numTyres;
};

// ---------------------------- Derived Class ----------------------------- //
// Car inherits publicly from Vehicle.

class Car : public Vehicle
{
public:
    int numGears;

    /* Explanation of constructor chaining:

        Car(int x) : Vehicle(x)
        - This explicitly calls Vehicle's parameterized constructor.
        - 'x' here will initialize Vehicle's private maxSpeed.
        - Car cannot access maxSpeed directly, since it is private.
        - But Car CAN call public getter getMaxSpeed() after construction.

        Now for HondaCity → Car → Vehicle:
        HondaCity's constructor can only call Car's constructor.
        Therefore, Car needs a constructor with two parameters
        (one for Vehicle's speed, one for Car's gears).
    */

    Car(int speed, int gears) : Vehicle(speed)
    {
        cout << "Car class constructor called!" << endl;
        numGears = gears;
        numTyres = 4; // protected member inherited
    }

    // --------------------------- Destructor ----------------------------- //
    ~Car()
    {
        cout << "Car class destructor called!" << endl;
    }

    void print()
    {
        cout << "NumTyres: " << numTyres << endl;
        cout << "NumGears: " << numGears << endl;
        cout << "Color: " << color << endl;
        cout << "MaxSpeed (via getter): " << getMaxSpeed() << endl;
    }
};

// --------------------- Multi-Level Derived Class ------------------------ //
// HondaCity → Car → Vehicle

class HondaCity : public Car
{
public:
    string modelName;

    /*
        HondaCity(int speed, int gears, string model)
        : Car(speed, gears)

        - HondaCity MUST call Car's constructor explicitly.
        - HondaCity cannot call Vehicle's constructor directly.
        - Car then internally calls Vehicle's constructor.

        Constructor call chain:
        Vehicle(speed) → Car(speed, gears) → HondaCity(...)
    */

    HondaCity(int speed, int gears, string model)
        : Car(speed, gears)
    {
        cout << "HondaCity class constructor called!" << endl;
        modelName = model;
    }

    ~HondaCity()
    {
        cout << "HondaCity class destructor called!" << endl;
    }

    void showDetails()
    {
        cout << "---- HondaCity Details ----" << endl;
        cout << "Model: " << modelName << endl;
        cout << "Color: " << color << endl;
        cout << "NumTyres: " << numTyres << endl;
        cout << "NumGears: " << numGears << endl;
        cout << "MaxSpeed: " << getMaxSpeed() << endl;
    }
};

// ------------------------------- MAIN ---------------------------------- //

int main()
{
    cout << "\n--- Creating Vehicle object ---\n";
    Vehicle v1;

    cout << "\n--- Creating Car object using parameterized constructor ---\n";
    Car c1(180, 5); // speed = 180, gears = 5
    c1.color = "Black";
    c1.print();

    cout << "\n--- Creating HondaCity object (multi-level inheritance) ---\n";
    HondaCity h1(220, 6, "ZX Edition");
    h1.color = "White";
    h1.showDetails();

    cout << "\n--- End of program, destructors will now be called automatically ---\n";

    return 0;
}
