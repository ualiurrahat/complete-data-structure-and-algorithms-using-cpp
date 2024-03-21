#include <iostream>
// header file for unordered map
#include <unordered_map>
#include <vector>
#include <set>
#include <utility>
#include <map>
using namespace std;

/*
differences between map and unordered_map
1. inbuilt implementation
-map uses red black tree
-keys are stored in map comparing their lengths and in lexographical order
-unordered_map is implemented using hashmap
-keys are given hash value and using which is how it is stored
2. time complexity
: for map --> O(logn) for each operation
: for unordered_map --> O(1)


3.valid keys data type
map: any kind of data type, even complex container is allowed
unordered_map: can not contain pair
 ex: unordered_map<pair<int,int>, int> mpp; not possible
 why pair can not be used in unordered_map??
 solution: cause, pair has no inbuilt hash function defined
 so unordered_map can not take pair as input
 but map compares data type given as input
 since pair can be compared, we can use pair in map 
 NOTE: data type which can be compared, can be used in map
 but not in unordered_map.
*/
int main()
{

    unordered_map<string, int> mpu;

    // same like unordered set
    // does not store keys lexicographily.

    pair<int, int> p = {8, 25};
    pair<pair<int, int>, int> pp = {{1, 10}, 17};

    // how to print the 10
    cout << pp.first.second << endl;

    // pair of pairs
    pair<pair<int, int>, pair<int, int>> pr = {{2, 4}, {6, 8}};

    cout << pr.first.first << " " << pr.first.second << endl;
    cout << pr.second.first << " " << pr.second.second << endl;

    // pair is not actually a container
    // it acutually works like element
    // vec,set,map can have pairs

    vector<pair<int, int>> p2;
    set<pair<int, int>> s;
    map<pair<int, int>, int> m;

    // multimap:similar to multiset
    // contains duplicate key

    multimap<string, int> mm;
    mm.insert(pair<string, int>("rahat", 25));
    mm.insert(pair<string, int>("rahat", 250));

    for (auto it : mm)
    {
        cout << it.first << "= " << it.second << endl;
    }

    return 0;
}