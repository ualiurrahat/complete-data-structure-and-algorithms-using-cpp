// template for two different variables.

#include <iostream>
using namespace std;

template <typename T, typename V>
class Pair
{
    T x;
    V y;

public:
    // setters for x and y
    void setX(T x)
    {
        this->x = x;
    }

    void setY(V y)
    {
        this->y = y;
    }

    // getters for x and y

    V getY()
    {
        return y;
    }

    T getX()
    {
        return x;
    }
};

int main()
{
    Pair<int, double> p1;
    p1.setX(25);
    p1.setY(25.8);
    Pair<double, double> p2;
    p2.setX(2.5);
    p2.setY(10.25);

    cout << p1.getX() << " " << p1.getY() << endl;
    cout << p2.getX() << " " << p2.getY() << endl;
    return 0;
}