/*
----------------------------------------------------------
File: 25_OOPsConcepts.cpp
Topic: 4 Pillars of Object-Oriented Programming in C++
----------------------------------------------------------
Main Concepts:
1️⃣ Encapsulation
2️⃣ Abstraction
3️⃣ Inheritance
4️⃣ Polymorphism
----------------------------------------------------------

Encapsulation:
    - Combining data members and methods (functions) into a single unit (class).
    - Achieved by using classes.
    - It hides internal state and requires all interaction through public methods.
    Example: Data hiding using private variables and public setter/getter.

Abstraction:
    - Hiding unnecessary internal details and showing only functionality.
    - Example: We use sort() from STL but we do not know its internal code.
    - Why abstraction?
        1) Code updates won’t affect the end user.
        2) It simplifies usage and reduces potential errors.

Inheritance:
    - Process of inheriting properties and behaviors (data and functions)
      from a base (parent) class into derived (child) classes.
    - Promotes code reusability.
    Example: Creating Car, Bus, Truck classes from a Vehicle class.

Access Modifiers:
    public     → accessible from anywhere
    private    → accessible only within the class
    protected  → accessible within the class and its derived classes
----------------------------------------------------------

Access Modifiers in Inheritance:
    Using **public** inheritance:
        Base Class     → Derived Class
        public      → public
        private     → ❌ not inherited
        protected   → protected

    Using **protected** inheritance:
        Base Class     → Derived Class
        public      → protected
        protected   → protected
        private     → ❌ not inherited

    Using **private** inheritance:
        Base Class     → Derived Class
        public      → private
        protected   → private
        private     → ❌ not inherited

Note:
    By default, inheritance in C++ is private.
    Example:
        class Coder : Employee {};  // private inheritance
----------------------------------------------------------
*/

#include <iostream>
using namespace std;

// ----------------------------------------------------------
// Example 1: Encapsulation
// ----------------------------------------------------------

/**
 * @brief Demonstrates encapsulation using private data members
 * and public getter/setter functions.
 */
class Student
{
private:
    int age;
    string name;

public:
    void setName(string newName)
    {
        name = newName;
    }

    void setAge(int newAge)
    {
        // Validation logic: age must be positive
        if (newAge > 0)
            age = newAge;
        else
            cout << "Invalid age!" << endl;
    }

    void display()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// ----------------------------------------------------------
// Example 2: Abstraction
// ----------------------------------------------------------

/**
 * @brief Demonstrates abstraction by hiding internal logic.
 * The user only interacts with the `startEngine()` method
 * and does not know how it works internally.
 */
class Car
{
public:
    void startEngine()
    {
        // Complex internal steps hidden from the user
        ignition();
        fuelInjection();
        powerFlow();
        cout << "Car started successfully!" << endl;
    }

private:
    void ignition()
    {
        cout << "[System] Ignition started..." << endl;
    }

    void fuelInjection()
    {
        cout << "[System] Fuel injected..." << endl;
    }

    void powerFlow()
    {
        cout << "[System] Power flowing to engine..." << endl;
    }
};

// ----------------------------------------------------------
// Example 3: Inheritance
// ----------------------------------------------------------

/**
 * @brief Base class: Vehicle
 */
class Vehicle
{
public:
    string brand;
    int wheels;

    void setVehicleInfo(string brandName, int totalWheels)
    {
        brand = brandName;
        wheels = totalWheels;
    }

    void showVehicleInfo()
    {
        cout << "Vehicle Brand: " << brand << ", Wheels: " << wheels << endl;
    }
};

/**
 * @brief Derived class: Car inherits from Vehicle
 * Public inheritance → retains same access levels.
 */
class SportsCar : public Vehicle
{
public:
    int topSpeed;

    void setTopSpeed(int speed)
    {
        topSpeed = speed;
    }

    void showCarInfo()
    {
        showVehicleInfo();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};

// ----------------------------------------------------------
// Example 4: Polymorphism
// ----------------------------------------------------------

/**
 * @brief Base class with virtual function for runtime polymorphism
 */
class Shape
{
public:
    virtual void draw()
    {
        cout << "Drawing a generic shape..." << endl;
    }
};

/**
 * @brief Derived class overriding draw()
 */
class Circle : public Shape
{
public:
    void draw() override
    {
        cout << "Drawing a Circle." << endl;
    }
};

/**
 * @brief Another derived class overriding draw()
 */
class Rectangle : public Shape
{
public:
    void draw() override
    {
        cout << "Drawing a Rectangle." << endl;
    }
};

// ----------------------------------------------------------
// Main Function — Demonstrating All 4 OOP Concepts
// ----------------------------------------------------------
int main()
{
    cout << "--------------------------------------------------\n";
    cout << "1️⃣ Encapsulation Example\n";
    cout << "--------------------------------------------------\n";
    Student s1;
    s1.setName("Rahat");
    s1.setAge(22);
    s1.display(); // Output: Name: Rahat, Age: 22

    cout << "\n--------------------------------------------------\n";
    cout << "2️⃣ Abstraction Example\n";
    cout << "--------------------------------------------------\n";
    Car c1;
    c1.startEngine();
    /*
        Output:
        [System] Ignition started...
        [System] Fuel injected...
        [System] Power flowing to engine...
        Car started successfully!
    */

    cout << "\n--------------------------------------------------\n";
    cout << "3️⃣ Inheritance Example\n";
    cout << "--------------------------------------------------\n";
    SportsCar ferrari;
    ferrari.setVehicleInfo("Ferrari", 4);
    ferrari.setTopSpeed(340);
    ferrari.showCarInfo();
    /*
        Output:
        Vehicle Brand: Ferrari, Wheels: 4
        Top Speed: 340 km/h
    */

    cout << "\n--------------------------------------------------\n";
    cout << "4️⃣ Polymorphism Example (Runtime)\n";
    cout << "--------------------------------------------------\n";
    Shape *shapePtr;

    Circle circle;
    Rectangle rect;

    // Base class pointer holding derived class objects
    shapePtr = &circle;
    shapePtr->draw(); // Output: Drawing a Circle.

    shapePtr = &rect;
    shapePtr->draw(); // Output: Drawing a Rectangle.

    cout << "\n--------------------------------------------------\n";
    cout << "All 4 OOP pillars demonstrated successfully.\n";
    cout << "--------------------------------------------------\n";

    return 0;
}
