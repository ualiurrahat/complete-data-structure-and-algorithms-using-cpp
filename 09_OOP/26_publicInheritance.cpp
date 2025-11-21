/*
Problem: Demonstrate the concept of public inheritance in C++ OOPs.

We will:
1. Create a base class `Vehicle`.
2. Create a derived class `Car` from `Vehicle` using public inheritance.
3. Observe which members are accessible and how access modifiers affect inheritance.

---------------------------------------------------------
Concept Recap:
---------------------------------------------------------
Inheritance:
- Mechanism that allows one class (derived class) to acquire properties and behaviors of another class (base class).
- Promotes code reusability and logical hierarchy.

Access Modifiers:
- public: Accessible anywhere.
- private: Accessible only within the same class.
- protected: Accessible in the same class and derived classes, but not outside them.

Public Inheritance:
- When a class publicly inherits another class,
  the base class's public members become public in the derived class,
  and the base class's protected members remain protected in the derived class.
- Private members of the base class are NOT inherited.

---------------------------------------------------------
Access Table for Public Inheritance:
---------------------------------------------------------
| Base class member | Inherited as in derived class |
|-------------------|-------------------------------|
| public            | public                        |
| protected         | protected                     |
| private           | not inherited                 |
---------------------------------------------------------
*/

#include <iostream>
using namespace std;

// ---------------------- Base Class Definition ----------------------
/**
 * @class Vehicle
 * @brief Represents a generic vehicle having color, number of tyres, and max speed.
 *
 * Explanation:
 * - maxSpeed: kept private so it cannot be accessed outside Vehicle class.
 * - color: public, can be accessed from anywhere (inside or outside the class).
 * - numTyres: protected, can only be accessed by Vehicle and its derived classes.
 */
class Vehicle
{
private:
    int maxSpeed; // Private → Not accessible outside this class or by derived classes

public:
    string color; // Public → Accessible everywhere

protected:
    int numTyres; // Protected → Accessible inside Vehicle and its derived classes
};

// ---------------------- Derived Class Definition ----------------------
/**
 * @class Car
 * @brief Derived class from Vehicle using public inheritance.
 *
 * Explanation of inheritance here:
 * - maxSpeed (private in Vehicle): NOT inherited (completely inaccessible).
 * - color (public in Vehicle): Remains public in Car.
 * - numTyres (protected in Vehicle): Remains protected in Car.
 */
class Car : public Vehicle
{
public:
    int numGears; // Additional property specific to Car class

    /**
     * @brief Prints the car’s properties.
     *
     * Demonstrates which base class members can be accessed by derived class.
     */
    void print()
    {
        cout << "Number of Tyres: " << numTyres << endl; // Accessible (protected)
        cout << "Number of Gears: " << numGears << endl; // Accessible (own property)
        cout << "Color: " << color << endl;              // Accessible (public)
        // cout << "Max Speed: " << maxSpeed << endl;   // ❌ Error: private → not inherited
    }
};

// ---------------------- Main Function ----------------------
int main()
{
    // ---------------------- Base Class Object ----------------------
    Vehicle v;
    v.color = "Blue"; // ✅ Accessible (public member)
    // v.numTyres = 4; // ❌ Error: protected → cannot access directly
    // v.maxSpeed = 120; // ❌ Error: private → cannot access

    cout << "Vehicle color: " << v.color << endl;

    // ---------------------- Derived Class Object ----------------------
    Car c;
    c.color = "Red"; // ✅ Inherited as public
    c.numGears = 5;  // ✅ Car’s own property
    // c.numTyres = 4;   // ❌ Protected → cannot access directly outside class

    // Printing all accessible details of Car
    cout << "\nCar Details (via print()):\n";
    c.print();

    // ---------------------- Example Test Cases ----------------------
    cout << "\n---------------------- Test Cases ----------------------\n";

    // Test Case 1
    Car car1;
    car1.color = "Black";
    car1.numGears = 6;
    cout << "Test Case 1:\n";
    car1.print();
    // Expected Output:
    // Number of Tyres: (garbage value if uninitialized)
    // Number of Gears: 6
    // Color: Black

    // Test Case 2
    Car car2;
    car2.color = "White";
    car2.numGears = 4;
    cout << "\nTest Case 2:\n";
    car2.print();
    // Expected Output:
    // Number of Tyres: (garbage value if uninitialized)
    // Number of Gears: 4
    // Color: White

    return 0;
}

/*
---------------------------------------------------------
Key Takeaways:
---------------------------------------------------------
1. Private members of the base class are not inherited.
2. Protected members can be accessed within derived classes, but not outside.
3. Public members remain public after public inheritance.
4. Always initialize protected members (like numTyres) through constructors.
5. Access base class members properly through the derived class or public methods.
---------------------------------------------------------
*/
