#include <iostream>
// header file for vector
#include <vector>

using namespace std;

int main()
{
    // static initialization
    vector<int> v;
    // dynamic initialiation
    // vector<int>*vp = new vector<int>();

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    // we can use [] to change value of elements just like we do in array
    // use [] to get/access or update values of elements
    // do not use [] to insert an element in vector
    // use push_back() function to do so.
    // as push_back() controls the increasing or shrinking of internal dynamic array inside the vectors.

    // don't use for inserting element
    // v[3] = 25;
    // v[4] = 100;

    v.push_back(40);
    v.push_back(50);

    // showing here v[4] and v[5] value form push_back elements
    // as vector priotize push_back() for inserting elements.
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    // they will show garbage value
    cout << v[5] << endl;
    cout << v[6] << endl;

    return 0;
}