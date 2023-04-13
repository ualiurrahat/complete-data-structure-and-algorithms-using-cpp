#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    // auto is keyword in c++
    // it automatically determines type of any variables.
    // we can assign auto as data type to any kind of object or variable we are using on the code

    vector<int> v = {10,20,30,40,50};
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<pair<int,int>>vp = {{1,10}, {2,20}, {3,30}};
    for(auto a : vp)
    {
        cout << a.first << " : " << a.second << endl;
    }
    // auto reduces code writing and increase efficiency
    // for example: iterator for a vector of pairs would be declared like this:
    // vector<pair<int,int>>vp:: iterator it = vp.begin();
    // using auto it would be like:
    // auto it = vp.begin();
    return 0;
}