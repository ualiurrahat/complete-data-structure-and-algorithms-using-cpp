#include <iostream>
#include <tuple> // to use tuple
using namespace std;

int main()
{

    // Tuples offer a versatile solution for consolidating multiple values of diverse types.
    // Unlike pairs, tuples can accommodate more than two elements, making them adaptable for various scenarios.

    // declaration
    tuple<int, double, string> t;
    // initialization
    tuple<int, double, string> tp(8, 25.8, "love");
    // accessing elements
    cout << get<0>(tp) << endl; // first index element of the tuple
    cout << get<1>(tp) << endl; // 2nd element
    cout << get<2>(tp) << endl; // 3rd element
    return 0;
}