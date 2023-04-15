#include <iostream>
#include <map>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    // map stores data lexicographilly.
    // means a first,then b,....c,d,...
    // map only stores unique keys
    map<string, int> mpp;
    mpp["abul"] = 5;
    mpp["kabul"] = 3;
    mpp["hanif"] = 1;
    mpp["swapnil"] = 11;
    mpp["nasim"] = 1;
    mpp["abul"] = 9; // map overwrites unique keys and takes updated value. so abul is 9 now

    // another way to fill map
    mpp.emplace("rasel", 35);

    // delete in map
    // mpp.erase(key)
    mpp.erase("hanif");

    // deleting single elements
    mpp.erase(mpp.begin());

    // check if map is empty or not
    if (mpp.empty())
    {
        cout << "mpp is empty" << endl;
    }
    else
    {
        cout << "mpp is not empty" << endl;
    }

    // printing map
    for (auto it : mpp)
    {
        cout << it.first << ": " << it.second << endl;
    }

    // print using iterator
    // for(auto it = mpp.begin(); it != mpp.end(); it++)
    // {
    //     cout << it->first << " " << it->second << endl;
    // }

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

    // unordered_map can not have pair
    // unordered_map<pair<int,int>, int> mpp; not possible

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