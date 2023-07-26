// class: a user defined data types used to create objects
// having same properties and funcitons of each
// writing our Student class here
class Student
{
    // private is by default access modifier
    // private access modifier does not allow to use properties outside the class where
    // the properties were declared
private:
    double cgpa;

public:
    // public modifier gives access to use all the properties in any other program
    int roll;
    int age;

    // note: in order to access private modifier,
    // we can use public funcion written inside the same class

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