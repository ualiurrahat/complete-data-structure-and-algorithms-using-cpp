#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> a;
    // insert elements in vector using push_back(): add elements at the end of vector.
    a.push_back(18); // a= 18
    a.push_back(1);  // a = 18, 1
    a.push_back(8);
    a.push_back(5);
    a.push_back(20); // a = 18,1,8,5,20

    // printing vector a
    cout << "a = ";
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;

    // copying entire vector

    vector<int> b = a;                 // b(a)
    vector<int> c(a.begin(), a.end()); // [)

    // copying first two elements of a.
    vector<int> d(a.begin(), a.begin() + 2); //{18,1}
    // the last elment not included...8 was excluded

    // push_back() = emplace_back()
    // emplace_back() is faster than push_back()

    // upper bound, lower bound
    // swap(v1,v2)
    // begin(), end(), rbegin(), rend()

    // defining vecotr of vectors: 2d vector
    vector<vector<int>> vec;

    vector<int> v1 = {10, 20, 30};
    vector<int> v2 = {1, 2};

    vec.push_back(v1);
    vec.push_back(v2);
    cout << vec[1][1] << endl; // prints 2, second element of v2

    // printing 2d vector
    cout << "printing 2d vector: " << endl;
    for (auto v : vec)
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;

    // define a 2d vector of 10*20 size with 0 as assigned value
    vector<vector<int>> vec2(10, vector<int>(20, 0));
    // vector<int>v(20,0);
    // means: v has 20 elements, each has 0 value as initial.
    // for different values we have to run a for loop

    // array of vectors
    vector<int> ara[4];
    // means you create an array of 4 vectors
    // you can increase size of each vectors
    // but not increase or add any new vector.
    ara[0].push_back(20);
    ara[0].push_back(1);
    ara[0].push_back(13);
    ara[0].push_back(1);
    ara[0].push_back(14);
    ara[0].push_back(14);
    ara[0].push_back(1);

    cout << "arr[0] = ";
    for (auto it : ara[0])
    {
        cout << it << " ";
    }
    cout << endl;

    // 10 x 20 x 30 vector
    vector<vector<vector<int>>> vec3d(10, vector<vector<int>>(20, vector<int>(30, 0)));

    // functions that can be applied on array STL
    // can be applied too on vectors

    return 0;
}