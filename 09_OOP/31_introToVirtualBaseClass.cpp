/*
======================== FILE 31: introToVirtualBaseClass ========================

Topic: Understanding the Diamond Problem in C++ and How Virtual Base Classes Solve It


------------------------------------------------------------------------------
1. Introduction to the Diamond Problem
------------------------------------------------------------------------------

In C++, the "Diamond Problem" occurs in multiple inheritance when the following
inheritance pattern (diamond shape) is used:

                 A
               /   \
             B       C
               \   /
                 D

- Class B inherits from A.
- Class C inherits from A.
- Class D inherits from BOTH B and C.

Because class D receives A’s properties from two separate paths (via B and C),
D ends up with **two copies** of A's data members.

This leads to several issues:

(1) MEMORY DUPLICATION:
    - Data members of A get duplicated inside D.
    - This wastes memory.

(2) AMBIGUITY:
    - If D tries to access a member of A (e.g., A::print()),
      compiler becomes confused:
         “Do you want A inherited through B, or A inherited through C?”

(3) Constructor and destructor confusion:
    - A’s constructor would run twice: once for B → A, once for C → A.
    - This is unnecessary and undesirable.

This combined issue is called the **Diamond Problem**.


------------------------------------------------------------------------------
2. Real-Life Analogy of the Diamond Problem
------------------------------------------------------------------------------

Imagine A is a "Parent" class.
B and C are two children of A.
Now D is a "grandchild" of A through both B and C.

If inheritance is not handled correctly, D ends up with:
- Two separate copies of A’s properties.
- Two conflicting "versions" of A.

This creates duplicate identity and confusion.


------------------------------------------------------------------------------
3. Why Does Ambiguity Occur?
------------------------------------------------------------------------------

Suppose A has a function:

    void print();

Both B and C inherit this function.

Since D inherits from both B and C, inside D there are:

- print() from B → A::print()
- print() from C → A::print()

When D calls print():
    D.print();

Compiler becomes unsure which one you want, so it reports an error:
    “Ambiguous access due to multiple base classes.”

This is the core of the diamond ambiguity.


------------------------------------------------------------------------------
4. How C++ Solves the Diamond Problem: Virtual Base Classes
------------------------------------------------------------------------------

To fix the problem, C++ provides **virtual inheritance**.

By writing:

    class B : virtual public A
    class C : virtual public A

we tell the compiler:

    “Even if multiple paths lead to A, create ONLY ONE shared A object.”

Thus, D will have:

- Only one A subobject.
- No duplication.
- No ambiguity.
- A’s constructor runs only once.

This ensures correct and efficient inheritance.


------------------------------------------------------------------------------
5. What Virtual Base Classes Actually Do Internally
------------------------------------------------------------------------------

- C++ ensures that there is only one instance of A,
  no matter how many derived classes inherit from it.

- Both B and C point to the same single A object.

- When D is constructed:
    - A's constructor executes only once.
    - B and C connect to that same A instance.

- D no longer faces ambiguity when accessing A’s members.


------------------------------------------------------------------------------
6. Constructor Call Order with Virtual Base Classes
------------------------------------------------------------------------------

Without virtual inheritance:

    A (via B)
    B
    A (via C)
    C
    D

A is called twice — undesirable.

With virtual inheritance:

    A (only once!)
    B
    C
    D

This is the correct and intended behavior.


------------------------------------------------------------------------------
7. Summary (Easy to Remember)
------------------------------------------------------------------------------

■ Diamond Problem happens when a class indirectly inherits from a base class twice.

■ Problems caused:
   - Ambiguity
   - Memory duplication
   - Double constructor calls

■ Solution:
   → Use **virtual inheritance** in intermediate classes:
        class B : virtual public A
        class C : virtual public A

■ Result:
   - Only ONE shared A object
   - Ambiguity removed
   - Efficient memory usage
   - Constructor/destructor called correctly

This file explains ONLY the theory.
The next file will contain code implementation demonstrating virtual inheritance.

================================================================================
*/
