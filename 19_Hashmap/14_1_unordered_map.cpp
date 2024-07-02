// intro to unordered map
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> ourmap;
    // insert
    //  way 1: using pair
    pair<string, int> p("rahat", 23);
    // or, pair.first = "rahat";
    // pair.second = 25
    ourmap.insert(p);
    // way 2: use square bracket
    ourmap["rasel"] = 32;
    cout << ourmap.size() << endl;
    cout << "value of rahat: " << ourmap["rahat"] << endl;

    // find or access
    // way 1: using at() function
    cout << ourmap.at("rasel") << endl;
    // cout << ourmap.at("ahnaf") << endl;
    // will show error. as "ahnaf" does not exist in the ourmap

    // way 2: using square bracket
    cout << ourmap["rasel"] << endl;
    // size of map
    cout << "size : " << ourmap.size() << endl;
    cout << ourmap["mahbub"] << endl;
    // see that "mahbub" was not added before
    // accessing a non-exist element using square bracket does not show error
    // instead, it gets added in the map with initial value as zero.
    // so, above cout will print 0
    cout << "size : " << ourmap.size() << endl;
    // difference between map[key] and map.at(key):
    // if we use at(), it will either show value or show error(if key does not exist)
    // [] will show value if key already exists or add the key if it was not existed before
    // so we can't use map[key] to check if a particular key exists or not
   
    // solution: use count() function
    // map stores a key just once only
    // so a key will have value 1 if it exists, either 0 for non-exist
    // so count() will give 1 if exits, or 0 if element not exists.


    // check presence
    
    // checking if "mahbub" exist in the map
    if (ourmap.count("mahbub") > 0)
    {
        cout << "mahbub exists" << endl;
    }
    else
    {
        cout << "mahbub doesn't" << endl;
    }

    // checking presence of mamun
    if (ourmap.count("mamun") > 0)
    {
        cout << "mamun exists" << endl;
    }
    else
    {
        cout << "mamun does not" << endl;
    }

    // erase
    // ourmap.erase(key)
    // ourmap.erase(iterator)-->will delete the key and value at the iterator point
    // ourmap.erase(starting_iterator, ending_iterator)-->wiil delete from index starting_iterator to ending_iterator -1.
    ourmap.erase("rahat");
    cout << "size: " << ourmap.size() << endl;

    return 0;
}