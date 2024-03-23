#include <iostream>
using namespace std;
// including header file containing Student class.
#include "02_studentClass.cpp"

int main()
{
     // creating object statically
     Student s1, s2;
     // here, we did not assign values of these objects properties.
     // so, now they are given garbage value
     // ex: s1.age = garbage value,...so on
     // accessing static object properties and assigning value
     // syntax: objectName.propertyName = value;
     s1.age = 20;
     s1.roll = 1;

     s2.age = 21;
     s2.roll = 2;

     // printing static objects
     cout << "Student 1: "
          << " Roll: " << s1.roll << " Age: " << s1.age << endl;
     cout << "Student 2: "
          << " Roll: " << s2.roll << " Age: " << s2.age << endl;

     cout << endl;

     // creating object dynamically
     // structure: dataType *objectName = new dataType
     Student *s3 = new Student;
     // accessing properties of object using dereferencing
     (*s3).age = 25; // s3->age
     (*s3).roll = 5;

     Student *s4 = new Student;
     s4->age = 23;
     s4->roll = 18;

     cout << "Student 3: "
          << " Roll: " << s3->roll << " Age: " << s3->age << endl;
     cout << "Student 4: "
          << " Roll: " << s4->roll << " Age: " << s4->age << endl;

     delete s4;
     delete s3;

     return 0;
}