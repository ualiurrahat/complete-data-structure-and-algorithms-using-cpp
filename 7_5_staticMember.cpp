// static members of class
// static means the property belongs to the class
// not the objects.

// print:
// cout << class_name :: static_var_name;

#include <bits/stdc++.h>

using namespace std;

class Student
{
public:
    int age;
    int roll;

    static int totalStudents;
    // static members are only members of the class
    // but not the objects of the class

    Student()
    {
        totalStudents++;
    }

    // function to get static data member
    // to access static data member, we need static function
    // static function can only access static members.
    // static function does not have any this pointer.
    // how to call static function:
    // class_name :: function_name;
    static int getTotalStudents()
    {
        return totalStudents;
    }
};

// static members get initialized outside class.
// initialization:
// data_type class_name :: static_var_name = value;
int Student ::totalStudents = 0;

int main()
{
    Student s1;
    cout << s1.age << " " << s1.roll << endl;
    // will show garbage value
    cout << s1.totalStudents << endl;
    // this is bad practice
    // static members are not object's property
    //still compiler does not show error here.

    // right way to print static members.
    cout << Student::totalStudents << endl;

    // we can change value of static members with object's initialization
    //s1.totalStudents = 25;
    cout << s1.totalStudents << endl;

    Student s2;
    cout << s2.totalStudents << endl;
    // again this is very bad practice.

    Student s3, s4, s5, s6, s7, s8;
    cout << s8.totalStudents << endl;

    // using static functions to get static data members
    // useful when static members are private.
    cout << Student::getTotalStudents() << endl;

    return 0;
}