#include <iostream>
#include <string>
// header file for using map
#include <map>

using namespace std;
/*
difference between STL containers:

vectors – Vectors are sequence containers similar to arrays, with the additional flexibility the elements can be inserted / deleted
pairs – a pair of values which may be of different types
maps – container which stores key–value pairs
iterators - Iterators point to a location. C++ containers such as vectors and maps define .begin() and .end() iterators, which allows us to iterate over all values in the container.
map : key(unique)--> value.
-- the values will be arrange on the basis of ascending order based on keys.
multimap: key(not unique)--> value.

*/

/*
when to use which container?
 ==need an ordered sequence of items? Go for a vector.
== need to associate values with keys, so you can look them up efficiently (by key) later on? Use a map.
*/

/*
map is implemented using red blact tree data structure
 map stores data lexicographilly.
 means a first,then b,....c,d,...
 map only stores unique keys
 each element in map consists of a pair(key,value pair)
 this pairs are not stored in contiguous manner.
 so, map does not have contiguous memory allocation
 like vector and array.
 (so iterator it++ will work in map but unlike vector, it+1 will not work)
 key and value within map can be anything....
 from int,char,string data type to complex container(pair,map etc) anything

time complexity to access and insert element in map
 T:O(nlogn)
 n size map * logn complexity for accessing or inserting each map element
NOTE: for map<string,string> type, time complexity changes 
since string size varies and takes a lot time to peform insertion,accession operation
for map<string,string> type of map, time complexity
== inserted string size * logn (n is size of map)
// function to display map elements
*/
void display(map<string, int> &m)
{
    map<string, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++)
    {
        cout << (*iter).first << " -- " << (*iter).second << endl;
    }
    cout << endl;
}

int main()
{
    // map declaration syntax: map<data_type, value_type> name;

    // declaring a map
    map<string, int> age;
    // inserting in map
    // way 1: insert each element individually.
    age["ahnaf"] = 5; // O(log n), n = size of value in key-value pair. here, value is 5.
    age["arwa"] = 3;
    // way 2: using insert() function.
    age.insert({{"ayash", 1}, {"arisha", 2}, {"ayaan", 11}});
    // way 3: using emplace()
    age.emplace("maymuna:", 2);
    cout << "printing age: " << endl;
    display(age);
    // data can be overwritten in map elements.
    age["arwa"] = 5; // now arwa's age will be 5 which was 3 earlier.
    /*
    If a key is not present in the map and we try to access it, C++ creates the key with a default value. If the value of type int, the default value is 0.
    */
    cout << "value of not insertem item : " << age["thisWasNotInserted"] << endl;
    // now 'thisWasNotInserted' will be added with  0 value in the map.
    display(age);
    cout << endl;

    // some function usage in map.

    cout << "The size is " << age.size() << endl;
    cout << "The max size is " << age.max_size() << endl;
    cout << "The empty's return value is " << age.empty() << endl;

    // we can get values of map element using its key
    cout << "Age of ayash is : " << age["ayash"] << endl;
    /*
    We can also confirm the existence of key-value pair by another method.

    We do this with the help of find(key) function.
     This function will return the iterator pointing at key's memory address, if the key is present.
    If it is not, then it will return the iterator pointing at the end of the map i.e. map.end().
    */

    if (age.find("rahat") != age.end())
    {
        cout << "rahat's age found" << endl;
    }
    else
    {
        cout << "rahat does not exist in the map" << endl;
    }
    // deleting elements in map:
    //way 1: Use the erase() function for deleting elements.
    // syntax: map.erase(key)
    // way 2: deleting using iterator: map.erase(it);
    age.erase("thisWasNotInserted");
    display(age);

    // clear the whole map
    age.clear();
    // printing empty map shows 0 only
    cout << age.size() << endl;
    return 0;
}