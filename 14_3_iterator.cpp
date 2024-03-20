// iterator in STL
// iterator is a pointer that points to an element in STL container
#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<string, int> brothers;
    brothers["rahat"] = 23;
    brothers["mahbub"] = 39;
    brothers["mamun"] = 36;
    brothers["rasel"] = 34;

    // iterator for unordered_map
    unordered_map<string, int>::iterator it = brothers.begin();
    while (it != brothers.end())
    {
        cout << "key: " << it->first << " --value: " << it->second << endl;
        it++;
    }

    // find in map
    // find() returns an iterater pointing to the key which was given as parameters
    unordered_map<string, int>::iterator it3 = brothers.find("rasel");
    cout << it3->second << endl;

    cout << "size: " << brothers.size() << endl;

    // erase
    brothers.erase("mamun");
    cout << "size: " << brothers.size() << endl;
    brothers.erase(it3); // erasing rasel now

    cout << "size: " << brothers.size() << endl;

    // erasing whole map
    // mapName.erase(starting_iterator, ending_iterator)
    // ourmap.erase(it, it+4).....-> will delete 4 elements(it,it+1,it+2,it+3).

    // iterators in vector
    vector<int> v = {18, 1, 8, 5, 20};
    vector<int>::iterator it2;

    for (it2 = v.begin(); it2 != v.end(); it2++)
    {
        cout << *it2 << endl;
    }

    return 0;
}