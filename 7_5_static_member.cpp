#include <bits/stdc++.h>

using namespace std;

// static member: a static member belongs to entire class
// not a property of respective object
// but still can be accessed through object
// which is not a good practice
// static means belong to class not to any objct

class Student
{
public:
    int roll;
    int age;

    static int totalStudent;

    // updating static value
    Student()
    {
        totalStudent++;
    }

    // static function
    // static function can access only static data member
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
    // bad practice

    // good practice of displaying static data
    cout << Student::totalStudent << endl;
    Student s2;
    Student a, b, c, d, e;
    cout << Student::totalStudent << endl;
    // s2.totalStudent = 20;
    // bad practice. though it does not show error
    // cout << s1.totalStudent << endl;  // 20

    // calling out static functions
    cout << Student::getTotalStudent() << endl;

    return 0;
}