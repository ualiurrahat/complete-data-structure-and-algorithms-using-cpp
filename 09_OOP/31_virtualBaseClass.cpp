// virtual base class in C++.

#include <iostream>
#include <string>

using namespace std;

// Student --> Test
// Student --> Sports
// Test -- > Result
// Sports --> Result

class Student
{
protected:
    int roll_number;

public:
    void set_number(int a)
    {
        roll_number = a;
    }
    void print_number()
    {
        cout << "Your roll number is " << roll_number << endl;
    }
};

class Test : public virtual Student
{
    // protected inherited:
    //roll_number
    //public inherited:
    // set_number(int)
    //print_number()
protected:
    float maths, physics;

public:
    void set_marks(float x, float y)
    {
        maths = x;
        physics = y;
    }

    void print_marks()
    {
        cout << "Your result is : " << endl
             << "Maths: " << maths << endl
             << "Physics: " << physics << endl;
    }
};

class Sports : public virtual Student
{
    // protected inherited:
    //roll_number
    //public inherited:
    // set_number(int)
    //print_number()
protected:
    float score;

public:
    void set_score(float m)
    {
        score = m;
    }
    void print_score()
    {
        cout << "Your score was " << score << endl;
    }
};

class Result : public Test, public Sports
{
    // now Test and Sports class have same inherited memebers from Student class.
    // but they will be inherited only once by the Result function.
    // since, both Test and Sports class inherit Student class,we will inherit them as  virtual base class

    // protected inherited:
    //roll_number
    // score
    // maths
    // physics

    //public inherited:
    // set_number(int)
    //print_number
    // set_marks(float,float)
    // print_marks()
    // set_score(float)
    // print_score()
private:
    float total;

public:
    void display()
    {
        total = maths + physics + score;
        print_number();
        // if Test and Score classes are not inherited as virtual base class of Student,
        // ambiguity will arise using print_number() function here
        // as compiler does not understand from which classes it will take the copy of this function.
        print_marks();
        print_score();
        cout << "Your total mark is: " << total << endl;
    }
};
int main()
{

    Result rahat;
    rahat.set_number(35);
    rahat.set_marks(98, 73.5);
    rahat.set_score(6);
    rahat.display();
    return 0;
}