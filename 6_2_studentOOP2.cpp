#include <bits/stdc++.h>

using namespace std;

class Student
{
private:
    int roll;

public:
    int age;

    // to access private property of a class. we need public function within that class

    // getter for roll
    int getRoll()
    {
        return roll;
    }

    // setter for roll
    void setRoll(int a)
    {
        roll = a;
    }

    //     deep question: if private properties can be accessed through
    //     public function then what did we gain? anyone can access them through
    //     getters and setters. So what did we achieve actually?

    // answer: we can control user of setter getters using passwords.
    // that is how real abstraction is done in softwares.

    // int setRoll(int a, int password)
    // {
    //     if(password != 1234)
    //     {
    //         return;
    //     }
    //     roll = a;
    // }
    // so if password does not match, person can not use setter function
    // hence, cant change private property setRoll
};

int main()
{
    Student s1, s2;
    s1.age = 20;
    s2.age = 21;

    // s1.roll = 25;
    // can't access roll property directly. since it is a private property.

    s1.setRoll(10);
    s2.setRoll(12);

    cout << s1.age << " " << s1.getRoll() << endl;
    cout << s2.age << " " << s2.getRoll() << endl;

    return 0;
}