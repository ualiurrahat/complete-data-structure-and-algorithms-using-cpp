/*
    Problem Statement:
    ------------------
    This file demonstrates the concept of **pure virtual functions** and **abstract classes**
    in C++.

    THEORY:
    -------
    1) Pure Virtual Function:
       -----------------------
       A pure virtual function is declared in a base class but has NO definition
       inside that class.
       Syntax:
           virtual returnType functionName(parameters) = 0;

       Meaning:
       --------
       - It tells the compiler that "this function must be overridden in derived classes".
       - The base class provides only a declaration, no implementation.

    2) Abstract Class:
       ----------------
       A class that contains **at least one pure virtual function** becomes an "abstract class".

       Properties:
       -----------
       - Abstract classes **cannot create objects**.
         Why?
         Because the class contains at least one unimplemented function,
         so object creation is impossible.

       - Derived classes from an abstract class have two options:

         (A) Implement *all* pure virtual functions → It becomes a complete class
         (B) Leave any pure virtual function undefined → It becomes an abstract class too

       - Abstract classes act as **interfaces or blueprints** that enforce certain behaviors
         on derived classes.

    In this file:
    -------------
    - Vehicle is an abstract class because it contains the pure virtual function print().
    - Car class inherits Vehicle and provides the implementation for print().
    - Because Car implements the pure virtual function, Car becomes a complete class
      and objects of Car can be created.
*/

#include <iostream>
using namespace std;

/**
 * @class Vehicle
 * @brief Abstract base class containing a pure virtual function.
 */
class Vehicle
{
public:
    string color;

    /**
     * @brief Pure virtual print function (must be overridden).
     */
    virtual void print() = 0;
};

/**
 * @class Car
 * @brief Derived from Vehicle and implements the pure virtual function.
 */
class Car : public Vehicle
{
public:
    int numGears;

    /**
     * @brief Overrides the pure virtual print() function from Vehicle.
     */
    void print() override
    {
        cout << "Car" << endl;
    }
};

/**
 * @brief Main function demonstrating pure virtual function and abstract class behavior.
 */
int main()
{
    // Vehicle v;  // ❌ Not allowed — Vehicle is an abstract class.

    Car c;     // ✔ Allowed — Car implements all pure virtual functions.
    c.print(); // Calls Car's print().

    return 0;
}
