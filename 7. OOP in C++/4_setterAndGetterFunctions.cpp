#include <iostream>
using namespace std;

// including header file containing Student class.
#include "2_studentClass.cpp"
int main()
{
    Student a;
    a.age = 22;
    a.roll = 25;
    a.display();
    // display will show a garbage cgpa since we did not assign any value
    // now assigning value of cgpa
    // a.cgpa = 2.95; we can't do this as cgpa is a private property
    a.setCgpa(2.95);

    // now printing a again
    a.display();
    // accessing roll with getter
    cout << a.getRoll() << endl;
    // setting roll with setter
    a.setRoll(5);
    a.display();

    return 0;
}