#include <bits/stdc++.h>

using namespace std;

// static member: a static member belongs to entire class
// not a property of respective object
// but still can be accessed through object
// which is not a good practice
// static means belong to class not to any objct
// NOTE: static member has only one copy inside the class.
// it does not get copied for every object.
// though compiler does not show error if we try to
// access them with objects. but this is bad practice.

class Student
{
public:
    int roll;
    int age;
    // static data member
    static int totalStudent;
    // updating static value
    Student()
    {
        totalStudent++;
    }

    // static function to access static member.
    // static function can access only static data member
    // NOTE: static function does not have access to this pointer.
    // since it only accesses static member.
    static int getTotalStudent()
    {
        return totalStudent;
    }
};
// since static member is a property of the class, not its object
// it is initialized outside class
// initialation method:
// dataType className :: staticVarName = value;
int Student ::totalStudent = 0;

int main()
{
    Student s1;

    cout << s1.totalStudent << endl;
    // bad practice. because totalStudent is a static member.
    // it belongs to the class not to any object

    // good practice of displaying static data
    // syntax: className :: staticPropertyName;
    // :: is called scope resolution operator.
    cout << Student::totalStudent << endl;
    Student s2;
    Student a, b, c, d, e;
    cout << Student::totalStudent << endl;

    // we can also assign value of static members like this:
    // s2.totalStudent = 20;
    // bad practice. though it does not show error
    // cout << s1.totalStudent << endl;  // 20

    // calling out static functions
    cout << Student::getTotalStudent() << endl;

    return 0;
}