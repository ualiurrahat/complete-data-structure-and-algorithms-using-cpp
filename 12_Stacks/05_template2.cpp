// File: 05_template2.cpp
// Demonstration of class templates with two different generic data types

#include <iostream>
using namespace std;

// Template class to store a pair of elements with different types
// T and V are placeholders for any data types specified during object creation
template <typename T, typename V>
class Pair
{
    T x;
    V y;

public:
    // Setter for x (type T)
    void setX(T x)
    {
        this->x = x;
    }

    // Setter for y (type V)
    void setY(V y)
    {
        this->y = y;
    }

    // Getter for y (type V)
    V getY()
    {
        return y;
    }

    // Getter for x (type T)
    T getX()
    {
        return x;
    }
};

int main()
{
    // Creating a Pair object with int and double types
    Pair<int, double> p1;
    p1.setX(25);
    p1.setY(25.8);

    // Creating a Pair object with double and double types
    Pair<double, double> p2;
    p2.setX(2.5);
    p2.setY(10.25);

    cout << p1.getX() << " " << p1.getY() << endl; // Output: 25 25.8
    cout << p2.getX() << " " << p2.getY() << endl; // Output: 2.5 10.25

    return 0;
}
