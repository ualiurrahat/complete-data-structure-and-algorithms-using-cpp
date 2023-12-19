// introduction to templates
// used when we want to create class or function of generic data types
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Pair
{
    T x;
    T y;

public:
    // setters for x and y
    void setX(T x)
    {
        this->x = x;
    }

    void setY(T y)
    {
        this->y = y;
    }

    // getters for x and y

    T getY()
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
    // object declaration in template variable
    // className <varType> objName;
    Pair<int> p1;
    p1.setX(10);
    p1.setY(20);
    cout << p1.getX() << " " << p1.getY() << endl;

    Pair<double> p2;
    p2.setX(25.8);
    p2.setY(8.25);
    cout << p2.getX() << " " << p2.getY() << endl;

    Pair<char> p3;
    p3.setX('a');
    p3.setY('b');

    cout << p3.getX() << p3.getY() << endl;

    return 0;
}