/*We will use initialisation list
to initialize const vars at the time of their memory allocation
before they go inside the constructor.

note: must have to use initialiser list if our class have
any const or reference variable. Using it we will be
able to initialize those vars at the time of their memory allocation
*/

#include <iostream>
using namespace std;

class Student
{
public:
    int age;
    const int roll;
    int &x; // reference variable for age

    // initializer list: used to initailise const properties of object at the time of memory allocation.
    // initializser-->case 1: only initializing const member only.
    // Student(int r) : roll(r)
    // // this is interpreted as: const int roll = r; hence it is error free.
    // {
    // }
    // initializer-->case 2: we can initialise non const property also
    // Student(int r, int age) : roll(r), age(age)
    // // here, age(age) does not create any confusion
    // // (age) is the paramter's name and age denotes to const int variable age
    // // here, this->age(age) is not allowed. It evens gives error.
    // {
    // }
    // initializer--> case 3: we can also initialise reference var.
    Student(int r, int age) : roll(r), age(age), x(this->age)
    // here,x(age) is not allowed,as compiler will be confused
    // might take the parameter age value
    {
    }
    // function to display
    void display()
    {
        cout << "roll: " << this->roll << endl;
        cout << "age: " << this->age << endl;
    }
};

int main()
{
    Student s1(135, 22);
    s1.display();
    cout << "value of x: " << s1.x << endl;
    return 0;
}