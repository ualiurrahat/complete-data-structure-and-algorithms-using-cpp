/*friend funciton: a funciton of a class A that can access all
(public,private,protected) properties of class B it is frined of B
NOTE: friend funciton has no access to this pointer.
cause they are not part of the class they have been friend with.
*/

#include <iostream>
using namespace std;

// globally declaring test function
void test();
class Bus
{
public:
    void print();
    // will use this print as a friend funciton
    // for class Truck. friend function can not
    // be declared inside its class. it is just declared
    // and defined outside all classes.
    // NOTE: friend function can be declared in inside any
    // access modifier. we wrote the friend funcion here
    // inside access modifier. Could also write inside
    // private or protected modifier.
};

class Truck
{
public:
    int x;
    // declaring print() from Bus class as
    // friend function for this class

    friend void Bus ::print();
    friend void test();

private:
    int y;

protected:
    int z;
};

// friend funcitn definition
void Bus::print()
{
    Truck t;
    t.x = 10;
    t.y = 20;
    t.z = 30;
    cout << t.x << " " << t.y << " " << t.z << endl;
}
// defining test function
void test()
{
    Truck t;
    t.x = 5;
    t.y = 10;
    t.z = 15;
    cout << t.x << " " << t.y << " " << t.z << endl;
}
int main()
{
    Bus t;
    t.print();
    test();
    return 0;
}