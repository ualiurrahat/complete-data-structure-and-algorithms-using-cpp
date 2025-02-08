// here, we are nesting vectors with pair type data

#include <iostream>
#include <utility> // for pair class
#include <vector>  // for vector container
using namespace std;

// print vector
void printVec(vector<pair<int, int>> &v)
{
    cout << "size : " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    cout << endl;
}

int main()
{
    // nesting of pair with vector
    vector<pair<int, int>> v = {{1, 10}, {2, 20}, {3, 30}};
    printVec(v);

    // user input
    int n;
    cout << "Enter total no. of pairs: ";
    cin >> n;
    vector<pair<int, int>> p;
    cout << "Enter pair values: ";
    for (int i = 0; i < n; i++)
    {
        int x, y;

        cin >> x >> y;
        p.push_back({x, y});
        // p.push_back(make_pair(x,y));
    }
    printVec(p);

    return 0;
}