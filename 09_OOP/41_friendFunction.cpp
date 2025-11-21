/*
    Problem Statement:
    ------------------
    Demonstrate the concept of **friend functions** in C++.

    THEORY:
    -------
    Friend Function:
    ----------------
    - A function that is NOT a member of a class, but has access to all
      private, protected, and public members of that class.
    - Declared using keyword: friend
    - Friend function does NOT have a "this" pointer because it is not part
      of the class.

    Notes:
    ------
    - A friend function can be declared under any access modifier
      (public/private/protected).
    - Friendship is NOT inherited and NOT mutual.

    In this example:
    ----------------
    - Bus::print() is made a friend of Truck.
    - Free function test() is also made a friend of Truck.
    - Both can access Truck’s private and protected data.
*/

#include <iostream>
using namespace std;

// Global friend function declaration
void test();

/**
 * @class Bus
 * @brief Contains a member function that will act as a friend function to Truck.
 */
class Bus
{
public:
    void print(); // This will be declared as a friend of Truck
};

/**
 * @class Truck
 * @brief Demonstrates how friend functions can access private and protected members.
 */
class Truck
{
public:
    int x;

    // Declaring Bus::print() as a friend function
    friend void Bus::print();

    // Declaring test() as a global friend function
    friend void test();

private:
    int y;

protected:
    int z;
};

// Definition of Bus::print() → can access Truck's private/protected data
void Bus::print()
{
    Truck t;
    t.x = 10; // public
    t.y = 20; // private → allowed (friend function)
    t.z = 30; // protected → allowed (friend function)

    cout << t.x << " " << t.y << " " << t.z << endl;
}

// Definition of test() → also has full access to Truck
void test()
{
    Truck t;
    t.x = 5;
    t.y = 10;
    t.z = 15;

    cout << t.x << " " << t.y << " " << t.z << endl;
}

/**
 * @brief Main function demonstrating friend function access.
 */
int main()
{
    Bus b;
    b.print(); // Calls Bus::print() → accesses Truck’s private members

    test(); // Global friend function → also accesses private members

    return 0;
}
