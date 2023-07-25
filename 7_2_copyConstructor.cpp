#include <bits/stdc++.h>

using namespace std;

class Student
{
    int age;

public:
    char *name;
    Student(int age, char *name)
    {
        this->age = age;
        // Shallow Copy
        // sending the address of the array
        // this->name = name;

        // deep copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void display()
    {
        cout << name << " " << age << endl;
    }

    // inbuilt copy constructor always does shallow copy
    // our own copy constructor
    // Student (Student s)....can't use that
    // here, in parameter is like Student s = main.s
    // so this function will make a copy of s object
    // which is in main function
    // in order to copy the s object, it will
    // call the copy constructor
    // so it is not right
    // we are writing copy constructor function
    // where parameter itself is calling the copy construct function
    // to avoid thir error, we took reference of s object
    // took constant referecne so that no one
    // can change data arbitrarily.
    Student(Student const &s)
    {
        this->age = s.age;
        // this->name = s.name    // shallow copy

        // deep copy
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }
};

int main()
{
    char name[] = "abcd";
    Student a(25, name);

    Student b(a);
    b.display(); // abcd 25
    a.display(); // abcd 25

    // inbuilt copy constructor always does shallow copy.

    b.name[0] = 'x';
    a.display(); // xbcd 25 , when we were not using our copy constructor.
    b.display(); // xbcd 25
    // this happened cause of shallow copy
    // to avoid shallow copy,
    // we should always write our own copy constructor.

    return 0;
}