/*
let us write our Student class with age and name property.
we did not add name property in the earlier class.
Now will add name property to understand shallow copy and deep copy.
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
        this->name = name; // Shallow Copy
        // we are assigning the address of name character i.e. the 0th indrex address
        // of name character array to this pointer. this is called shallow copy
        // this->name = name;
        // if name array is changed later, the change will reflect here too.
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
    a.display(); // this print: rahat 25

    // now changing 3rd letter of name array
    name[2] = 'f';
    Student b(22, name);
    b.display(); // this print: rafat 22

    // now, printing a again.
    a.display();
    // a should print: rahat 25
    // but now it is printing : rafat 25
    // so the change in name array has affected it.
    // because we have used shallow copy.
    // the this pointer of the object a, holds the 0th address of character array.
    // since the value changed in the array, property value of a's also changed.

    return 0;
}