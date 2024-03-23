#include <iostream>
using namespace std;
// class: a user defined data types used to create objects
// having same properties and funcitons of each
// writing our Student class here

// to check for which number object destructor was called
int i = 1;
class Student
{
    // private is by default access modifier
    // private access modifier does not allow to use properties outside the class where
    // the properties were declared
private:
    double cgpa;

public:
    // public modifier gives access to use all the properties in any other program
    // note: in order to access private modifier,
    // we can use public funcion written inside the same class

    int roll;
    int age;

    // constructor: a function having the same name of the class.
    // it has no return type.
    // *** for one object, constructor is called only one time,
    // and it is called, at the time of object creation ***
    // whenever a class is declared, an inbuilt default constructor is created to that class
    // ex: when we create Student s1;
    // the inbuilt or default constructor is called
    // the default constructor has no parameter.
    // note:1) if we don't write our own constructor, then default constructor is called
    // if we write our own constructor, then default constructor is restricted.
    // compiler uses our written constructor

    // default constructor
    // this will be called whenever any object of Student class will be created.
    // ex: student s1;
    // this will be called and when program is run,
    // it will be printed, "default constructor called!"
    // and all properties of s1 will have garbage value

    Student()
    {
        cout << "this: " << this << endl;
        cout << "default constructor called!" << endl;
    }

    // parameterized constructor: a constructor having parameter.
    // note: 2) if there is parameterized constructor in our program,
    // then we must have to write our default constructor also.
    // otherwise, initiliazing object without any parameter will produce error.
    // ex: if we do not write our own constructor without parameter, i.e. default parameter
    // and write student s1; it will produce error.
    // since there is no constructor without parameter in our code.
    // as whenever we write our own constructor,
    // the inbuilt constructor is overwritten

    // this keyword: a pointer which holds the address of current object
    Student(int age)
    {
        cout << "this: " << this << endl;
        this->age = age;
        cout << "Single Parameterized constructor called!" << endl;
    }
    // double parameterized constructor
    Student(int age, int roll)
    {
        cout << "this: " << this << endl;
        this->age = age;
        this->roll = roll;
        cout << "Double Parameterized constructor called!" << endl;
    }

    // Destructor: a function having the same name as the class
    // no return type and no parameter.
    // it is called just before destroying the object.
    // ex: Student s1(10,20);
    // for s1, destructor will be called just before reading the return 0 instruction of main function
    ~Student()
    {
        cout << "destructor called for object " << i << "!" << endl;
        i++;
    }
    // getter function for roll property
    // getter funciton: to get object's particular property value
    int getRoll()
    {
        return roll;
    }

    // setter function for roll
    // setter function: to set a value of an object's particular property.
    void setRoll(int a)
    {
        roll = a;
    }
    // setter for cgpa
    void setCgpa(double x)
    {
        cgpa = x;
    }
    // funciton to display properties
    void display()
    {
        cout << "cgpa: " << cgpa << endl;
        cout << "roll : " << roll << endl;
        cout << "age: " << age << endl
             << endl
             << endl;
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