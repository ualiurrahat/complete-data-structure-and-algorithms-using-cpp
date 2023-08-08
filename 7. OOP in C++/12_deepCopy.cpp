/*
to get rid of the problem arises due to shallow copy,
we use deep copy.
*/

#include <bits/stdc++.h>

using namespace std;

class Student
{
    int age;
    char *name;

public:
    Student(int age, char *name)
    {
        this->age = age;
        // using deep copy to assign name to the object's name property
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name); // strcpy(destination,source)
        // deep copy: make entire copy of the array, then save it
        // here, we are creating a new array of characters dynamically.
        // with length of the given name array + 1( for the null character)
        // then we are coping the name character array content to the
        // current object's this pointer of the name property
    }

    void display()
    {
        cout << name << " " << age << endl;
    }
};

int main()
{
    char name[] = "rahat";
    Student a(25, name);
    a.display(); // rahat 25

    name[2] = 'f';
    Student b(22, name);
    b.display(); // rafat 22

    a.display(); // rahat 25
    // since we have used deep copy inside the constructor,
    // the problem due to shallow copy has been solved.
    return 0;
}