// checking if hashMap class working properly
#include <bits/stdc++.h>
#include "14_6_hashMapClass.cpp"

using namespace std;

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
        cout << m.loadFactor() << endl;
    }

    // checking size() function
    cout << "size: " << m.size() << endl;
    // checking remove() function
     m.remove("abc2");
     m.remove("abc7");

    cout << "size: " << m.size() << endl;

    // checking getValue() function
    for (int i = 0; i < 10; i++)
    {
        char c = i + '0'; // converting i into char
        string key = "abc";
        key = key + c;
        cout << key << " : " << m.getValue(key) << endl;
    }
    cout << m.size() << endl;

    return 0;
}