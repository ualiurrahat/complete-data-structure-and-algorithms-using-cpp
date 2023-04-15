#include <iostream>
#include <string>
#include <map>

using namespace std;
/*
vectors – Vectors are sequence containers similar to arrays, with the additional flexibility the elements can be inserted / deleted
pairs – a pair of values which may be of different types
maps – container which stores key–value pairs
iterators - Iterators point to a location. C++ containers such as vectors and maps define .begin() and .end() iterators, which allows us to iterate over all values in the container.
*/

/*
 need an ordered sequence of items? Go for a vector.
 need to associate values with keys, so you can look them up efficiently (by key) later on? Use a map.

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
    map<string, int> age;
    age["ahnaf"] = 5;
    age["arwa"] = 3;
    age["ayash"] = 1;
    age["arisha"] = 2;
    age["ayaan"] = 11;

    display(age);
    /*
    If a key is not present in the map and we try to access it, C++ creates the key with a default value. If the value of type int, the default value is 0.
    */
    cout << age["thisWasNotInserted"] << endl;

    // now 'thisWasNotInserted' will be added with  0 value in the map.
    display(age);
    cout << endl;

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
        cout << "rahat does not exits" << endl;
    }

    //Use the erase() function for deleting elements.
    age.erase("thisWasNotInserted");
    display(age);

    return 0;
}