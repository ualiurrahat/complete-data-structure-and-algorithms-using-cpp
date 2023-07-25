// how constructor is called

#include <bits/stdc++.h>

using namespace std;

class Student
{
private:
    int age;

public:
    int roll;

    Student()
    {
        cout << "default contructor called!" << endl;
    }
    Student(int a)
    {
        cout << "parametrized constructor one called!" << endl;
        age = a;
    }

    Student(int age, int roll)
    {
        cout << "Parametrized constructor two called!" << endl;
        this->age = age;
        this->roll = roll;
    }
};

int main()
{

    Student s1;        // default constructor called
    Student s2(25);    // one parameter constructor called
    Student s3(25, 3); // two parameter constructor called

    Student s4(s3); // copy constructor called

    s1 = s2; // no constructor calling. just using copy assignment operator

    Student s5 = s3; // copy constructor called
    // copy assignment works when two objects are already having space in the program
    // means objects are already created before copy assingment operationg in performed
    // then what is Student s5 = s3;
    // s5 was not created before. How it works?
    // soln: Student s5 = s3 -->
    // student s5(s3);
    // program calls copy constructor
    // when new objects are given copy assignment operation directly
    // before it creats space in the program for itself.
    return 0;
}