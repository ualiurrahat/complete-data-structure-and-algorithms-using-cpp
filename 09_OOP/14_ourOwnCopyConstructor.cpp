/*
to get rid of the problem arises due to shallow copy,
we use deep copy.
*/

#include <bits/stdc++.h>

using namespace std;

class Student
{
    int age;

public:
    // changing modifier of name property from "private" to "public"
    // just to see how it afftecs and to explore copy constructor
    char *name;
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
    // inbuilt copy constructor always does shallow copy
    // so in order to avoid the copy constructor problem, we need to write our own copy constructor.
    // NOTE: WHEN WE WRITE OUR OWN COPY CONSTRUCTOR, THE INBUILT COPY CONSTRUCTOR IS VANISHED.
    // Student (Student s)....can't Write copy constructor like  that
    // WHY?
    // it is interpreted like Student s = main.s
    // we are copying the object s from main function to this scope
    // using copy assignment operator.
    // but copy assignment operator works by calling copy constructor
    // so as soon as we wrte Student(Student s)
    // to create Student s = main.s, the copy constructor
    // since we are writing our own copy constructor, the inbuilt copy constructor can not be used.
    // so it will call the copy constructor we are writing
    // then again to create the inner object, another copy constructor will be called
    // by this, there will be created an infinite loop of copy constructor call.
    // to avoid this, we will use object reference in the parameter.
    // will use const reference, so that it can not change the properties of the object written the main function
    // proper code: Student(Student const &s)
    Student(Student const &s)
    {
        this->age = s.age;
        // this->name = s.name    // shallow copy

        // deep copy
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }
    void display()
    {
        cout << name << " " << age << endl;
    }
};

int main()
{
    // creating a student
    char name[] = "rahat";
    Student s1(22, name);
    s1.display(); // rahat 22

    // now creating a object using copy constructor
    Student s2(s1);
    s2.display(); // rahat 22

    // changing 2nd index value at name array in the s2 object
    s2.name[2] = 'f';
    // now print both s1 and s2
    cout << "after changing 2nd index character in object s2 and writing our own copy constructor: " << endl;
    s1.display();
    // rahat 22, see s1 did not change.
    // since we have written our own copy constructor and used deep copy
    s2.display(); // rafat 22, it is correct as we changed the 2nd index character

    return 0;
}