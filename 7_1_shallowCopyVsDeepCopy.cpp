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
        // Shallow Copy
        // coping the 0th index element(value i.e. address in case of array too) of the array
        // this->name = name;
        // if name is change later, the change will reflect here too.

        // deep copy
        // make entire copy of the array, then save it
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void display()
    {
        cout << name << " " << age << endl;
    }
};

int main()
{
    char name[] = "abcd";
    Student a(25, name);
    a.display();

    name[3] = 'f';
    Student b(22, name);
    b.display();

    a.display(); // a got changed due to shallow copy.
                 // a was acurate when we use deep copy

    return 0;
}