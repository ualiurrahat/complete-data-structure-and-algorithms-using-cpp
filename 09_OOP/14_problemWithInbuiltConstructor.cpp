/*
let see what is the issue with inbuilt copy constructor
*/

#include <bits/stdc++.h>

using namespace std;

class Student
{
    int age;

public:
    // changing modifier of name property from "private" to "public"
    // just to see how it afftecs and to explore copy constructor
    char *name;
    Student(int age, char *name)
    {
        this->age = age;
        // using deep copy to assign name to the object's name property
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name); // strcpy(destination,source)
        // deep copy: make entire copy of the array, then save it
        // here, we are creating a new array of characters dynamically.
        // with length of the given name array + 1( for the null character)
        // then we are coping the name character array content to the
        // current object's this pointer of the name property
    }

    void display()
    {
        cout << name << " " << age << endl;
    }
};

int main()
{
    // creating a student
    char name[] = "rahat";
    Student s1(22, name);
    s1.display(); // rahat 22

    // now creating a object using copy constructor
    Student s2(s1);
    s2.display(); // rahat 22

    // changing 2nd index value at name array in the s2 object
    s2.name[2] = 'f';
    // now print both s1 and s2
    cout << "after changing 2nd index character in object s2: " << endl;
    s1.display();
    // before we are writing our own copy constructor
    // s1 should print "rahat 22" but printing "rafat 22"
    // we used deep copy but still change has happend in the name of object s1.
    // though we made changes in object s2.
    // How? what actually happened?
    // we took a character array name. suppose its address is 700
    // created Student s1(22,name)
    // s1.age = 22
    // s1.name->here, we did deep copy. so a character array will be created first.
    // then array will have value as "rahat". s1.name will be pointing to the adreess of this array
    // suppose this array's address is 800
    // so s1.name =800 means it is pointing the array whose first index adrress is 800
    // then we did Student s2(s1), here copy constructor is called.
    // NOTE: COPY CONSTRUCTOR ALWAYS DOES SHALLOW COPY
    // so, s2.age = s1.age = 22
    // s2.name = s1.name = 800(which has "rahat" as value)
    // now when we write s2.name[2] = 'f'
    // it says to change the 3rd index of the name array
    // pointing to the array whose first index is 800.
    // that is why change is shown in both s1 and s2.
    // Solution: We can solve this problem by writing our own copy constructor.
    // which is done in the next code: 14_ourOwnCopyConstructor.cpp

    s2.display(); // rafat 22, it is correct as we changed the 2nd index character

    return 0;
}