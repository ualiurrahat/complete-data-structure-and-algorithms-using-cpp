// File: 06_template3.cpp
// Demonstration of  nested class templates in C++

#include <iostream>
using namespace std;

// Template class to store a pair of two different types
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
    // Creating a Pair object where the first type is another Pair object
    Pair<Pair<int, int>, int> p;
    p.setY(10); // Set the y value of outer pair

    Pair<int, int> p4;
    p4.setX(15);
    p4.setY(25);

    // Assign p4 as the x value of outer pair
    p.setX(p4);

    // NOTE: p is having its value for x from p4 (using copy assignment operator)
    // Output nested x and outer y
    cout << p.getX().getX() << " " << p.getY() << endl; // Output: 15 10

    return 0;
}
