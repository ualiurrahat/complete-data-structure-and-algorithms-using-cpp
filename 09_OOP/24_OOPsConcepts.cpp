/*
4 pillars of OOP: abstraction,encapsulation,inheritance,polymorphism.
encapsulation: combinining the data members and funcitons
- we achieve encapsulation by using class.
abstraction: hiding unnecessary details of the code. showing up the funcitonality to the user.
-ex: we can use sort() from STL. but we do not know how it was coded.
-it was kept hidden from us.because this is not important for us to know
-how it  was implemented.this is called abstracdtion.
-why we need abstraction? So that-
-1)updation or changes in code should not affect end user
-2) to avoid errors.

inheritance : process to inherit the properties and
-characterstics from parents to children
-ex: creating Car,Bus,Truck classes from Vehicle class
-we use inheritance. To reuse our code.

access modifier: public,private,protected
-public: can be accessed anywhere outside the class
-private: can not be accessed anywhere outside the class.
to access this inside class, we need to have
public function of the same class.
-protected: can be accessed by the class itself
and the derived classes. but can not be direcly be accessed.
need public class funciton like private modifier to access them.


// using public as access modifier in inheritance:
    // Base class                Derived Class
    // public  ------> publicly inherited
    // private ------> xxxxx does not get inherited
    // protected -----> protected inherited.

// using protected as access modifier in inheritance
    // Base Class               Derived Class
    // public     ---------------> protected
    // protected  ---------------> protected
    // private    ---------------> xxxxxxxx

// using private as access modifier in inheritance
    // Base Class               Derived Class
    // public     ---------------> private
    // protected  ---------------> private
    // private    ---------------> xxxxxxxx

Note: By default private is used as access modifier during inheritance
ex: class Coder :  Employee
{

};
here, Coder is privately inherited Employee class

*/