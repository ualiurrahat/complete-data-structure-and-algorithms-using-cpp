// introduction to initialization list
#include <bits/stdc++.h>

using namespace std;

class Student
{
public:
    int age;
    const int roll;
    int &x; // age reference variable.
            // here, we will initialize both const int and refernce var
            // using initialization list

    // since roll is const so we can't set roll using constructor like this:
    // Student(int a, int r)
    // {
    //     age = a;
    //     roll = r;
    // }
    // this is not legal. as first we are creating space for roll
    // here, roll gets a garbage value
    // then initializing it with another value
    // which is not allowed
    // since roll is const
    // both needs to be done at the same time.
    // use of initializer:
    // reference and const object initialization
    // done by only initialization list
    // initialization list: initialiazing value of const var
    // along with constructor call
    // just before going inside the constructor function
    // we can also use non-const var

    Student(int age, int roll) : age(age), roll(roll), x(this->age)
    {
        // age(age) means coping value of(age) into age
        // this->age(age) is not allowed here.
    }
};

int main()
{
    Student naeem(24, 26);
    cout << naeem.age << endl;
    cout << naeem.roll << endl;
    cout << naeem.x << endl;

    return 0;
}