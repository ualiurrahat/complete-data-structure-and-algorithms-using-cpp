#include <iostream>
using namespace std;

// including header file containing Student class.
#include "02_studentClass.cpp"

int main()
{
    Student s1;
    cout << "Address of s1: " << &s1 << endl;
    s1.display();

    Student s2(10);
    cout << "Address of s2: " << &s2 << endl;
    s2.display();

    Student s3(2, 25);
    cout << "Address of s3: " << &s3 << endl;
    s3.display();
    return 0;
}