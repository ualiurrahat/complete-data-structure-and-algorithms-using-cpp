// Map in c++ STL.
/*
map : key(unique)--> value.
-- the values will be arrange on the basis of ascending order based on keys.
multimap: key(not unique)--> value.


*/
#include <iostream>
#include <string>
#include <map> // header files for map

using namespace std;

int main()
{
    // map declaration.
    // map<data_type, value_type> name;
    map<string, int> marksMap;
    marksMap["Rahat"] = 74;
    marksMap["Nasim"] = 84;
    marksMap["Arfan"] = 88;
    marksMap["Naeem"] = 94;

    // insertion in map.
    marksMap.insert({{"tofa", 85}, {"shihab", 79}});
    // iterator.
    map<string, int>::iterator iter;
    //display map;

    for (iter = marksMap.begin(); iter != marksMap.end(); iter++)
    {
        cout << (*iter).first << " " << (*iter).second << endl;
    }

    // some function usage in map.

    cout << "The size is " << marksMap.size() << endl;
    cout << "The max size is " << marksMap.max_size() << endl;
    cout << "The empty's return value is " << marksMap.empty();

    cout << endl
         << endl;

    // another map.
    map<string, string> couple;

    couple["mahbub"] = "amena";
    couple["mamun"] = "jhumi";
    couple["rasel"] = "rupa";

    couple.insert({{"shihab", "nafisa"}, {"adeeb", "jenia"}});

    map<string, string>::iterator i = couple.begin();

    for (i = couple.begin(); i != couple.end(); i++)
    {
        cout << (*i).first << " + " << (*i).second << endl;
    }

    // we can get values of map by its key_value.
   cout << couple["rasel"] << endl;
    map<string, int> age;

    age["Alice"] = 23;
    age["Bob"] = 18;
    age["Charlie"] = 28;
    age["Eve"] = 22;

    cout << age["Bob"] << endl; // Output - 18
    cout << age["Eve"] << endl; // Output - 22

    return 0;
}