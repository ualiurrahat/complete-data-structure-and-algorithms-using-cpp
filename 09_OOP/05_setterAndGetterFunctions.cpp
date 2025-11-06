/*
Problem Statement:
------------------
This program demonstrates the **concept of Setter and Getter functions** in Object-Oriented Programming (OOP)
using the `Student` class defined in another file (02_studentClass.cpp).

We explore:
1. How to access and modify private data members using public functions (setters/getters)
2. Why private access modifiers are useful for encapsulation
3. How encapsulation ensures data security and controlled access to object properties

-------------------------------------------------------------
Concepts Explained:
-------------------------------------------------------------

Encapsulation:
--------------
Encapsulation is one of the four main pillars of OOP (along with Inheritance, Polymorphism, and Abstraction).

It means **binding data (variables) and functions (methods) together into a single unit (class)**
and **restricting direct access** to the internal data of that class.

In C++, we use **access modifiers** like `private`, `protected`, and `public` to achieve encapsulation.

Why Encapsulation is Needed:
----------------------------
- Prevents direct modification of sensitive data.
- Provides **controlled access** through public functions (getters/setters).
- Makes the code more secure, modular, and easier to debug.
- Allows for additional checks or logic before assigning new values.

-------------------------------------------------------------
Private vs. Public:
-------------------
- **Private members** can only be accessed **inside the class**.
- **Public members** can be accessed **from anywhere in the program**.

In the `Student` class:
- `cgpa` is private.
- `roll` and `age` are public.

Hence, we can directly modify `roll` and `age`, but not `cgpa`.
To modify or access `cgpa`, we must use **setter** and **getter** functions.

-------------------------------------------------------------
Setter and Getter Functions:
----------------------------

1️⃣ **Setter Function** — used to assign or modify a private data member.
   - Example: `void setCgpa(double x) { cgpa = x; }`
   - Purpose: Controls how data is written into a private property.
   - We can add security checks, like passwords or validation.

2️⃣ **Getter Function** — used to access (read) a private data member.
   - Example: `double getCgpa() { return cgpa; }`
   - Purpose: Allows safe access to private data without directly exposing it.

-------------------------------------------------------------
Example Scenario in This Program:
---------------------------------
1. A `Student` object `a` is created.
2. `age` and `roll` are assigned directly (since they are public).
3. `cgpa` cannot be accessed directly → must use `setCgpa()` to assign a value.
4. Later, we use `getRoll()` to retrieve and print the roll number.
5. Finally, `setRoll()` is used to modify roll safely.

-------------------------------------------------------------
Deep Concept:
-------------
If private properties can be accessed via public getters and setters,
you might ask — "what’s the point of making them private?"

Answer:
- We can add **control mechanisms** in setters/getters (e.g., password protection or validation rules).
- Example: Only authorized users can change certain values.
- This is how **real-world abstraction** and **data protection** are achieved in software design.
*/

#include <iostream>
using namespace std;

// Including header file containing Student class definition
#include "02_studentClass.cpp"

int main()
{
    // ---------------------- Object Creation ----------------------
    Student a;

    // Assigning values to public properties directly
    a.age = 22;
    a.roll = 25;

    // Display current data (cgpa is garbage value here)
    a.display();

    // ---------------------- Using Setter for Private Property ----------------------
    // We cannot do this: a.cgpa = 2.95; because cgpa is private.
    // Instead, we use the public setter function to assign it.
    a.setCgpa(2.95);

    // Display again to confirm cgpa has been updated
    a.display();

    // ---------------------- Using Getter and Setter ----------------------
    // Accessing roll using getter function
    cout << "Accessing roll via getter: " << a.getRoll() << endl;

    // Changing roll using setter function
    a.setRoll(5);

    // Display updated data
    a.display();

    // ---------------------- Destructor Calls ----------------------
    // Destructor will automatically be called when object 'a' goes out of scope.

    return 0;
}
