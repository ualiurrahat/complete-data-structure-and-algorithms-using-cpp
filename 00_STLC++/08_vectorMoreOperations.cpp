#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {2, 3, 5, 6, 3};
    // replace(): replace all the old values within the vector.
    replace(v.begin(), v.end(), 3, 8);
    // now, v = {2, 8, 5, 6, 8} as all old values 3 get replaced with 8
    // merging two sorted vector
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {2, 2, 3, 4};
    vector<int> v3(v1.size() + v2.size()); // size of merging vector must be equal to v1.size + v2.size()
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    cout << "Merged Vector: ";
    for (int i = 0; i < v3.size(); i++)
        cout << v3[i] << " "; // 1 2 2 2 3 3 4
    cout << endl;
    return 0;
}