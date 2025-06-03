// File: 04_template1.cpp
// Demonstration of class templates with a single generic data type in C++

#include <iostream>
using namespace std;

// Template class to store a pair of elements of the same type
// T is a placeholder for any data type specified during object creation
template <typename T>
class Pair
{
    T x;
    T y;

public:
    // Setter for x
    void setX(T x)
    {
        this->x = x;
    }

    // Setter for y
    void setY(T y)
    {
        this->y = y;
    }

    // Getter for y
    T getY()
    {
        return y;
    }

    // Getter for x
    T getX()
    {
        return x;
    }
};

int main()
{
    // Creating a Pair object with int type
    Pair<int> p1;
    p1.setX(10);
    p1.setY(20);
    cout << p1.getX() << " " << p1.getY() << endl; // Output: 10 20

    // Creating a Pair object with double type
    Pair<double> p2;
    p2.setX(25.8);
    p2.setY(8.25);
    cout << p2.getX() << " " << p2.getY() << endl; // Output: 25.8 8.25

    // Creating a Pair object with char type
    Pair<char> p3;
    p3.setX('a');
    p3.setY('b');
    cout << p3.getX() << p3.getY() << endl; // Output: ab

    return 0;
}
