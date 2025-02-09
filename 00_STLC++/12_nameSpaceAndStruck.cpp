#include <iostream>
#include <string>

using namespace std;

// Why use namespaces?
// A namespace defines a scope that holds functions, variables, and other identifiers.
// The standard C++ library is encapsulated within the "std" namespace.

// Defining a custom namespace
// We can create our own namespace to avoid name conflicts and organize code better.
namespace rahat
{
    int val = 25;
    int getVal()
    {
        return val * 10;
    }
}

// Using struct in a professional way
// A struct (short for structure) is a user-defined data type that groups related variables together.
struct Person
{
    string name;
    int age;
    double income;

    // Constructor to initialize struct members
    Person(string a, int b, double c)
    {
        name = a;
        age = b;
        income = c;
    }
};

int main()
{
    // Demonstrating namespace usage
    int val = 10;                    // Local variable in main function
    cout << val << endl;             // Outputs 10 (local variable in main)
    cout << rahat::val << endl;      // Outputs 25 (variable from "rahat" namespace)
    cout << rahat::getVal() << endl; // Outputs 250 (function from "rahat" namespace)

    // The standard namespace (std) is required for using cout and other standard functions.
    // If we don't include "using namespace std;", we must explicitly write std::cout.

    // Incorrect way of defining a struct instance
    // This won't work as Person doesn't have a default constructor.
    // Person r;
    // r.name = "loser";
    // r.income = 0.00;
    // r.age = 25;

    // Correct way 1: using constructor
    Person r("rahat", 25, 40000);
    // Correct way 2: Using dynamic allocation to instantiate the struct
    Person *coder = new Person("rahat", 25, 0.00);
    // delete dynamic memory
    delete coder;

    return 0;
}
