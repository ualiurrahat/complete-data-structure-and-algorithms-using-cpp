// ===========================
// Introduction to Stack (ADT)
// ===========================

// A **Stack** is a linear data structure that follows a particular order
// for performing operations. It is an example of an Abstract Data Type (ADT).

// ---------------------------
// What is an Abstract Data Type (ADT)?
// ---------------------------
// An ADT defines a logical model of a data structure. The implementation
// details are hidden, and only a defined set of operations is allowed.
// In the case of a stack, random access to elements is *not* permitted.
// All operations must follow a strict order based on stack principles.

// ---------------------------
// Stack Characteristics
// ---------------------------
// 1. The **entry and exit point are the same** — the top of the stack.
// 2. **Insertion** operation is called `push(x)` — it inserts element `x` on top.
// 3. **Deletion** operation is called `pop()` — it removes the top element.
// 4. **Accessing the top element** is done via `top()` — returns the most recently inserted item.
// 5. Stack operates on the **LIFO (Last In, First Out)** principle:
//    - The element that is inserted last will be the first one to be removed.

// ---------------------------
// Real-World Analogy
// ---------------------------
// Think of a stack like a pile of plates:
// - You add (push) a plate to the top.
// - You remove (pop) a plate from the top.
// You cannot access the middle or bottom plates directly.

// ---------------------------
// Common Use-Cases of Stack
// ---------------------------
// 1. **Function Call Management**:
//    - The system uses a call stack to handle function calls and recursion.
//      Each function call is pushed onto the call stack, and popped when it returns.
// 2. **Undo Mechanisms** in editors.
// 3. **Expression Evaluation and Syntax Parsing** in compilers.
// 4. **Backtracking** algorithms (e.g., maze solving, game moves).
// 5. **Browser History Navigation** (back/forward button logic).
