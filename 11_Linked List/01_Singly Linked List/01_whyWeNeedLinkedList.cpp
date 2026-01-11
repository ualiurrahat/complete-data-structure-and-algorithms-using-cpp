/*
================================================================================
📌 Topic: Why Do We Need Linked Lists?
📁 Folder: 11_Linked List / 01_Singly Linked List
📄 File  : 01_whyWeNeedLinkedList.cpp
📘 Type  : Theory / Conceptual Discussion (No Code)
================================================================================

This file explains the motivation behind using Linked Lists, the problems
associated with arrays and vectors, how Linked Lists overcome those problems,
and what limitations still remain.

This discussion is especially important for:
- DSA beginners
- Fresh software engineering graduates
- Interview preparation
- Understanding real-world data structure trade-offs

--------------------------------------------------------------------------------
1️⃣ Problems with Arrays
--------------------------------------------------------------------------------

Arrays are one of the most fundamental data structures, but they come with
several limitations:

🔹 Fixed Size
- Once an array is declared, its size cannot be changed.
- If we need to store more elements later, we must create a new array and copy
  all existing elements, which is inefficient.

🔹 Contiguous Memory Requirement
- Arrays require a continuous block of memory.
- Even if enough total memory is available, allocation can fail if a contiguous
  block is not found.

🔹 Costly Insertion and Deletion
- Inserting or deleting an element requires shifting elements.
- This leads to O(n) time complexity in the worst case.

🔹 Memory Wastage or Shortage
- If the array size is overestimated → memory is wasted.
- If underestimated → resizing becomes necessary.

--------------------------------------------------------------------------------
2️⃣ Arrays vs Vectors vs Linked Lists
--------------------------------------------------------------------------------

🔸 Array
- Fixed size
- Fast random access: O(1)
- Insertion/Deletion: Costly due to shifting
- Memory: Contiguous

🔸 Vector (Dynamic Array)
- Size grows dynamically (usually doubles when full)
- Better than arrays, but:
  - Reallocation is expensive
  - Extra unused memory may exist
- Still requires contiguous memory

🔸 Linked List
- No fixed size
- Memory allocated as needed
- No need for contiguous memory
- Efficient insertion and deletion

👉 Linked Lists are designed to overcome the **rigidity of arrays**.

--------------------------------------------------------------------------------
3️⃣ What Is a Linked List?
--------------------------------------------------------------------------------

A Linked List is a **linear data structure** made up of **nodes**.

Each node contains:
1️⃣ Data — the actual value to store
2️⃣ Next — the address (pointer) to the next node in the list

Key Terms:
- Head → First node of the linked list
- Tail → Last node of the linked list (points to NULL)

Memory Layout:
- Nodes are stored at **non-contiguous** memory locations
- Nodes are connected using pointers

--------------------------------------------------------------------------------
4️⃣ Why Linked Lists Were Introduced
--------------------------------------------------------------------------------

Linked Lists solve major array-related problems:

✅ Dynamic Size
- Elements can be added or removed at runtime.

✅ Efficient Insertion and Deletion
- No shifting of elements required.
- Time complexity: O(1) (if position is known).

✅ Better Memory Utilization
- Memory allocated only when needed.
- No pre-allocation required.

✅ Flexible Structure
- Easy to modify and reorganize.

--------------------------------------------------------------------------------
5️⃣ Types of Linked Lists
--------------------------------------------------------------------------------

🔹 Singly Linked List
- Each node has:
  - Data
  - Address of the next node

🔹 Doubly Linked List
- Each node has:
  - Data
  - Address of previous node
  - Address of next node

🔹 Circular Singly Linked List
- Last node points back to the head
- No NULL pointer at the end

🔹 Circular Doubly Linked List
- Circular connection in both directions

--------------------------------------------------------------------------------
6️⃣ Limitations of Linked Lists
--------------------------------------------------------------------------------

Despite their advantages, Linked Lists are not perfect:

❌ No Random Access
- Cannot directly access elements like arr[i]
- Traversal required → O(n)

❌ Extra Memory Overhead
- Each node stores additional pointer(s)

❌ Cache Unfriendly
- Non-contiguous memory reduces cache efficiency

❌ More Complex Implementation
- Pointer management increases chances of bugs

--------------------------------------------------------------------------------
7️⃣ When Should You Use a Linked List?
--------------------------------------------------------------------------------

✔ Use Linked Lists when:
- Frequent insertions and deletions are required
- Size of data is unknown beforehand
- Memory allocation needs to be flexible

❌ Avoid Linked Lists when:
- Fast random access is required
- Memory efficiency is critical
- Cache performance matters

--------------------------------------------------------------------------------
8️⃣ Interview-Oriented Questions to Think About
--------------------------------------------------------------------------------

❓ Why is insertion faster in Linked Lists than arrays?
❓ Why do Linked Lists consume more memory than arrays?
❓ Why is binary search not efficient on Linked Lists?
❓ When would a vector be preferred over a Linked List?
❓ How does a doubly linked list improve traversal?

--------------------------------------------------------------------------------
9️⃣ Final Takeaway
--------------------------------------------------------------------------------

Linked Lists are a powerful alternative to arrays that provide flexibility
and efficient modification operations. However, they come with trade-offs in
terms of access speed and memory overhead.

Understanding **when to use** Linked Lists is far more important than just
knowing **how to implement** them.

================================================================================
*/
