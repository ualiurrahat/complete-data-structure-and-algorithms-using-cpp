
// adding  our coded hashmap header file
#include "07_hashMapClass.h"

int main()
{
    ourmap<int> m;
    // did not write ourmap<string,int>
    //  as key as string always in our ourmap

    // checking loadFactor() and insert() function
    for (int i = 0; i < 10; i++)
    {
        char c = i + '0'; // converting i into char
        string key = "abc";
        key = key + c;
        int value = i + 1;
        m.insert(key, value);
        cout << "load factor: " << m.getLoadFactor() << endl;
    }

    // total no. of entries in the hashmap
    cout << "size: " << m.size() << endl;
    // removing two entries
    m.remove("abc2");
    m.remove("abc7");

    // checking getValue() function
    for (int i = 0; i < 10; i++)
    {
        char c = i + '0'; // converting i into char
        string key = "abc";
        key = key + c;
        cout << key << " : " << m.getValue(key) << endl;
    }
    cout << "size: " << m.size() << endl;
    return 0;
}