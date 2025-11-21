/*
    Types of Inheritance in C++

    Inheritance is one of the most powerful features of Object-Oriented Programming (OOP).
    It allows us to create new classes based on existing classes. These new classes
    (called derived classes) inherit properties and behaviors from the existing classes
    (called base classes).

    C++ supports five major types of inheritance:

    ------------------------------------------------------------------------------------
    1) SINGLE INHERITANCE
       ----------------------------------------
       - One base class → One derived class.
       - This is the simplest and most common type of inheritance.
       - Example:
            Vehicle → Car
       - Here, Car is derived from Vehicle.
       - Car inherits all accessible members (public/protected) from Vehicle.

    ------------------------------------------------------------------------------------
    2) MULTILEVEL INHERITANCE
       ----------------------------------------
       - A class is derived from another derived class.
       - So inheritance goes in multiple "levels".
       - Example:
            Vehicle → Car → HondaCity
       - Explanation:
            - Car is derived from Vehicle
            - HondaCity is derived from Car
       - This forms a chain of inheritance.
       - Useful when building more specialized versions of already derived classes.

    ------------------------------------------------------------------------------------
    3) HIERARCHICAL INHERITANCE
       ----------------------------------------
       - One base class → Many derived classes.
       - Multiple classes inherit from a single base class.
       - Example:
            Vehicle → Car, Bus, Truck
       - Here Car, Bus, and Truck all separately inherit the properties of Vehicle.
       - This is used when you want multiple classes to share a common base.

    ------------------------------------------------------------------------------------
    4) MULTIPLE INHERITANCE
       ----------------------------------------
       - One derived class inherits from **more than one** base class.
       - Example:
            class LuxuryCar : public Vehicle, public Engine
       - The derived class receives properties from both Vehicle and Engine.
       - This allows a class to combine functionalities from multiple sources.
       - But careful usage is needed to avoid ambiguity issues (such as diamond problem).

    ------------------------------------------------------------------------------------
    5) HYBRID INHERITANCE
       ----------------------------------------
       - A combination (mix) of different types of inheritance.
       - Typically includes multilevel + multiple inheritance.
       - Example:
            Vehicle → HybridBase
            HybridCar → HybridBase + Engine   (multiple inheritance)
       - So the overall structure becomes hybrid.
       - Hybrid inheritance often forms a complex structure, such as the "diamond" shape.

    ------------------------------------------------------------------------------------
    Summary:
       1. Single       → One base → One derived
       2. Multilevel   → Derived from derived
       3. Hierarchical → One base → Many derived
       4. Multiple     → One derived → Many bases
       5. Hybrid       → Combination of above types

    We will discuss each of these types in detail through code examples in future files.
*/
