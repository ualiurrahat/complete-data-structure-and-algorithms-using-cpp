// intro to constructor.
// copy constructor
// copy assignment operator
// Destructor

#include <bits/stdc++.h>

using namespace std;

int i = 1;

class Student
{
private:
    int age;

public:
    int roll;

    void show()
    {
        cout << "Roll: " << roll << " Age: " << age << endl;
    }

    int getAge()
    {
        return age;
    }

    void setAge(int a)
    {
        age = a;
    }

    // default constructor : a constructor without any parameter
    // if we don't write any default constructor, compiler uses a built in default one.
    // if we write parametrized constructor only,
    // compiler does not initialize its default constructor.
    // So, if we don't write any default constructor along with parameterized constructor
    //, then it would be wrong
    // to declare an object without any parametrized object.
    // ex: student s1; is wrong if there is any parameterized constructor
    // present in the code

    // default constructor.
    Student()
    {
        cout << "default contructor called!" << endl;
    }
    // parameterized constructor 1
    Student(int a)
    {
        cout << "parametrized constructor one called!" << endl;
        age = a;
    }
    // Student(int a,int r)
    // {
    //     age = a;
    //     roll = r;
    // }
    // what if we want to write like this Student(int age, int roll)?
    // this->age = age;
    // thir->roll = roll;

    // this: a pointer which holds the address of current object.

    // parameterized constructor2
    Student(int age, int roll)
    {
        cout << "Parametrized constructor two called!" << endl;
        this->age = age;
        this->roll = roll;
    }

    // destructor
    // destructor is called when the object
    // is going to be destroyed means out of scope.
    ~Student()
    {
        cout << "Destructor called for object " << i << endl;
        i++;
    }
};

int main()
{
    Student a;
    a.roll = 1;
    a.setAge(20);
    cout << "Student 1: ";
    a.show();
    cout << endl;

    Student b(2);
    b.setAge(25);
    cout << "Student 2: ";
    b.show();
    // roll is garbage since we dont give any roll value to Student b

    cout << endl;
    Student c(25, 3);
    cout << "Student 3: ";
    c.show();

    // copy constructor: creates object which is a copy of another object.
    // copy objects at the time of its creation
    // inbuilt copy constructor: compiler provides it when
    // we don't write our own copy constructor.

    Student d(a);
    // object d will have same value as object c
    // no constructor will be called here
    // as we use inbuilt copy constructor.
    cout << "Student 4: ";
    d.show();
    cout << endl;

    // dynamically creating an object
    Student *e = new Student(22, 8);
    // dynamic object coping another dynamic object
    Student *f = new Student(*e);

    // coping dynamic object into a static object
    Student g(*e);

    // copy assignment operator (=)
    // assigned one object's value to another when both
    // objects have already been created.

    Student h(17, 22);
    // statical copy assignment
    Student i;
    i = h;

    // dynamic copy assignment
    Student *j = new Student;
    *j = h;
    Student k = *j;

    // dynamic objects takes space from heap.
    // so their destructor will be called after we free their occupied space.
    delete e;

    delete f;
    delete j;

    return 0;
}