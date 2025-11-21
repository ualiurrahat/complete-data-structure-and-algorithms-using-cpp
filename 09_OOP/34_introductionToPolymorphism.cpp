/*
File: 34_introductionToPolymorphism.cpp

Topic: Polymorphism in C++

Polymorphism literally means "many forms".
In programming, it allows the same function, operator, or object to behave differently in different contexts or situations.

Polymorphism is one of the **four pillars of OOP** (along with Abstraction, Encapsulation, and Inheritance).

There are **two main types of polymorphism** in C++:

1) **Compile-Time Polymorphism (Static Polymorphism):**
   - The behavior of a function or operator is determined at **compile time**.
   - Examples:
     a) **Function Overloading:**
        - Multiple functions with the same name but different parameters (number or type of parameters) exist in the same scope.
        - The compiler determines which function to call based on the arguments provided.
        - Example scenario: `add(int a, int b)` and `add(double a, double b)`.

     b) **Operator Overloading:**
        - C++ allows you to redefine the behavior of operators for user-defined data types.
        - Example scenario: Using `+` operator to add two objects of a `Complex` class.

     c) **Function Overriding (with static context in derived class, e.g., default parameters)**

   - Advantages: Faster execution because decisions are made at compile time.
   - Limitation: Cannot decide at runtime which version to call based on object type.

2) **Run-Time Polymorphism (Dynamic Polymorphism):**
   - The behavior of a function is determined at **runtime**, based on the object calling it.
   - Achieved through **inheritance** and **virtual functions**.
   - Example scenario:
     - A base class `Shape` has a virtual function `draw()`.
     - Derived classes `Circle` and `Rectangle` override `draw()`.
     - A pointer of type `Shape*` can point to `Circle` or `Rectangle`.
     - The call `shapePtr->draw()` executes the correct function depending on the actual object type at runtime.

   - Advantages: Flexible and allows dynamic method resolution.
   - Limitation: Slightly slower than compile-time polymorphism due to runtime lookup (vtable mechanism).

**Key Points to Remember:**
- Compile-time polymorphism = function/operator is resolved at **compile time**.
- Run-time polymorphism = function is resolved at **runtime** (needs virtual functions).
- Polymorphism improves **code reusability**, **extensibility**, and **maintainability**.
- It allows a single interface (function/operator) to work with **different data types** or **different objects**.

*/
