/*
====================================================================
   FILE: 01_introductionToOOP.cpp
   TOPIC: Introduction to Object-Oriented Programming (OOP)
====================================================================

🧠 PURPOSE:
-----------
This file introduces the fundamental concept of **Object-Oriented Programming (OOP)**.
It explains what OOP is, why we use it, and the key foundational terms such as
**objects**, **classes**, and the general motivation behind using OOP in programming.

====================================================================
   🧩 WHAT IS OOP?
====================================================================

OOP stands for **Object-Oriented Programming** — a modern programming paradigm
that structures software design around **objects** rather than **functions** or **procedures**.

In traditional (procedural) programming, the focus is on **functions** that perform operations
on data. But in OOP, the focus shifts to **objects**, which combine both data and functions
that operate on that data into a single logical unit.

This approach makes code:
- Easier to understand
- Easier to maintain and scale
- Closer to how we perceive the real world

====================================================================
   🧱 BASIC IDEA OF OOP:
====================================================================

Imagine the real world — it’s full of objects:
laptops, cameras, humans, cars, and phones.
Each of these has:
- **Properties** (attributes or data)
- **Behaviors** (functions or actions)

For example:
- A car has properties like `color`, `brand`, and `speed`.
- A car has behaviors like `accelerate()`, `brake()`, and `turn()`.

In programming, OOP allows us to model such entities as **objects**
so that our code mirrors the real world more closely.

====================================================================
   ⚙️ WHY USE OBJECTS IN PROGRAMMING?
====================================================================

✅ **1. Real-world modeling:**
   - OOP helps us represent real-world entities in code naturally.
   - This makes software design more intuitive and organized.

✅ **2. Modularity:**
   - Each object is a self-contained unit.
   - You can build complex systems by combining simple, reusable objects.

✅ **3. Reusability:**
   - Once a class (blueprint) is written, it can be reused to create multiple objects
     without rewriting the same logic again.

✅ **4. Scalability and Maintainability:**
   - OOP supports extensible and maintainable code.
   - When you need to add new functionality, you can modify or extend existing classes
     instead of rewriting code from scratch.

✅ **5. Data Security (Encapsulation):**
   - OOP allows hiding the internal state of objects and only exposing necessary parts.
   - This improves security and prevents unintended modifications.

====================================================================
   🧍 OBJECT:
====================================================================

An **object** is a real-world or conceptual entity that has:
- **Attributes (Data Members):** describe the object’s state
- **Behaviors (Member Functions):** describe the object’s actions

🔹 Example in real life:
   - Object: Laptop
   - Attributes: brand, processor, RAM, price
   - Behaviors: turnOn(), turnOff(), runProgram()

In programming, an object is an **instance** of a **class**.

====================================================================
   🏗️ CLASS:
====================================================================

A **class** is a **blueprint** or **template** that defines what an object will look like.

It defines:
- The properties (variables) each object will have.
- The functions (methods) each object can perform.

🔹 Analogy:
   - A class is like an architectural design of a house.
   - The actual houses built from that design are the objects.

For example:
   Class → Car
   Object → Toyota, BMW, Tesla

Each object shares the structure defined by the class but can have its own unique data values.

====================================================================
   🧩 RELATIONSHIP BETWEEN CLASS AND OBJECT:
====================================================================

- **Class:** defines how something should look and behave.
- **Object:** is the actual instance created from the class.

In other words:
- A **class** is like a mold.
- An **object** is what comes out of that mold.

When you define a class, you are not allocating memory.
Memory is allocated only when an object is created from that class.

====================================================================
   🧠 CORE IDEA:
====================================================================

OOP allows us to design software in a way that reflects how humans naturally think.
Instead of focusing purely on logic and sequence (as in procedural programming),
we think in terms of **entities** (objects) and their **interactions**.

This paradigm shift makes complex systems much easier to design, visualize, and maintain.

====================================================================
   🔍 CONCLUSION:
====================================================================

OOP is a powerful paradigm that:
- Models code after real-world entities,
- Improves code reusability,
- Simplifies maintenance and debugging,
- Enables modular, scalable software development.

This foundational understanding of **OOP, Objects, and Classes**
serves as the base for upcoming concepts such as:
- Encapsulation
- Abstraction
- Inheritance
- Polymorphism

These four pillars together form the **core of Object-Oriented Programming**,
which we will explore in the following files.

====================================================================
*/
