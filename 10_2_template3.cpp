
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
    Pair<Pair<int, int>, int> p;
    p.setY(10);
    Pair<int, int> p4; // p is taking its x value from p4. (copy assignment operator)
    p4.setX(15);
    p4.setY(25);
    p.setX(p4);

    cout << p.getX().getX() << " " << p.getY() << endl;
    return 0;
}