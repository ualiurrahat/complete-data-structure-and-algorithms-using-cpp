#include <iostream>
#include <utility>

using namespace std;

// pair is a class to contain two different data types together

int main()
{
    // delcaring pair
    pair<int, string> p;
    // initialization in two ways
    // 1. use make_pair() function
    p = make_pair(22, "rahat");
    // 2. simply initialize
    p = {23, "rahat"}; // values overwritten

    // printing value
    cout << p.first << " " << p.second << endl;

    // we can use reference also
    pair<int, string> &p1 = p;
    // p1 = p; shallow copy. if p1 is changed it will not changed value of p
    // &p1 = p; deep copy. p1 is using reference of p. so changing in p1 will be seen in p
    p1.second = "murr";
    // p.second will also be changed
    cout << p.first << " " << p.second << endl;

    // array of pairs
    pair<int, int> p_array[3];
    p_array[0] = {1, 10};
    p_array[1] = {2, 20};
    p_array[2] = {3, 30};
    // printing values
    for (int i = 0; i < 3; i++)
    {
        cout << p_array[i].first << " " << p_array[i].second << endl;
    }
    // we can also swap entire pair with another pair
    swap(p_array[0], p_array[2]);
    cout << "pair after swapping: " << endl;
    cout << "p_array[0]: " << p_array[0].first << " " << p_array[0].second << endl;
    cout << "p_array[2]: " << p_array[2].first << " " << p_array[2].second << endl;

    return 0;
}