/*
we are using a user defined data type and saving them in a set.
to observe how it works.

*/

#include <iostream>
#include <string>
#include <bits/stdc++.h>

class Person
{
public:
    int age;
    string name;
};

using namespace std;

int main()
{
    set<Person> people = {{22,"rahat"}, {25,"kabir"}, {32, "aslam"}};

    return 0;
}