#include <iostream>
using namespace std;
// including header file containing Student class.
#include "2_studentClass.cpp"
int main()
{
    Student a(1, 20);
    // here, two parameterized constructor called after a is declared
    a.display();

    /* copy constructor: a constructor which creates objects taking same property values of another objects
    note: Every class has default copy constructor. if we don't write our own copy constructor
    this default one will be used.
   */

    // creating object b with same property values of a using inbuilt copy constructor
    Student b(a);
    /*this is same as....
     Student b(a.age, a.roll);
     look, here no copy constructor is called after writing: Student b(a);
     as we did not write our own copy constructor,and used the default copy constructor.
     */
    b.display();

    // dynamically creating object using copy constructor
    Student *c = new Student(3, 22);
    c->display();

    Student d(*c);
    d.display();

    /*
    copy assignment operator (=) : work as same as copy assignment operator
    difference is, copy construtor works at the time of object creation
    and copy assignment operator works on two objects which are already
    exist. and we are just assigning one values to the other
     */

    Student e(5, 29);
    e.display();
    Student f(7, 31);
    // assigning values of f to e using copy assignment operator
    e = f;
    // this is equal as
    // e.age = f.age;
    // e.roll = f.roll;

    cout << "value of e: age:  " << e.age << endl;
    cout << "value of e: roll:  " << e.roll << endl;

    // but how will we copy value from dynamically created objects?
    // soln: Student k = *c;
    // k will have properties of dynamic object c
    // copying value of e to object c
    // *c = e;

    // now if we run the code, we will see 5 times destructor called
    // but here is 6 objects: a,b,c,d,e,f
    // destructor was called for a,b,d,e,f
    // since c is dynamically created, we have to perform delete operation to free its space
    // then destructor will be called

    // deleting memory for object c
    delete c;
    // now destructor will be called total 6th time
    return 0;
}